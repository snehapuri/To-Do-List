// DoublyLinkedList.cpp
#include <DoublyLinkedList.h>

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::addTask(const QString& task) {
    Node* newNode = new Node;
    newNode->task = task;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::removeTask(int index) {
    if (index < 0) return;

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        if (!current) return;
        current = current->next;
    }

    if (current) {
        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }
}

void DoublyLinkedList::clearAllTasks() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

QStringList DoublyLinkedList::getTaskList() {
    QStringList taskList;
    Node* current = head;
    while (current) {
        taskList << current->task;
        current = current->next;
    }
    return taskList;
}
