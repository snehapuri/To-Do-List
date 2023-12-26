// DoublyLinkedList.h
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <QString>
#include <QStringList>

struct Node {
    QString task;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    DoublyLinkedList();
    void addTask(const QString& task);
    void removeTask(int index);
    void clearAllTasks();
    QStringList getTaskList();

private:
    Node* head;
    Node* tail;
};

#endif // DOUBLYLINKEDLIST_H

