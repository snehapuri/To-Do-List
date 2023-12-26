// mainwindow.cpp
#include "mainwindow.h"
#include "DoublyLinkedList.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("To-Do List");

    taskListView = new QListWidget(this);
    taskListView->setGeometry(10, 10, 300, 200);

    taskLineEdit = new QLineEdit(this);
    taskLineEdit->setGeometry(10, 220, 200, 30);

    addButton = new QPushButton("Add", this);
    addButton->setGeometry(220, 220, 50, 30);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addTask);

    removeButton = new QPushButton("Remove", this);
    removeButton->setGeometry(10, 260, 80, 30);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeTask);

    clearButton = new QPushButton("Clear All", this);
    clearButton->setGeometry(100, 260, 80, 30);
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearAllTasks);
}

void MainWindow::addTask() {
    QString taskDescription = taskLineEdit->text();
    if (!taskDescription.isEmpty()) {
        taskList.addTask(taskDescription);
        taskListView->addItem(taskDescription);
        taskLineEdit->clear();
    }
}

void MainWindow::removeTask() {
    int selectedRow = taskListView->currentRow();
    if (selectedRow != -1) {
        taskList.removeTask(selectedRow);
        delete taskListView->takeItem(selectedRow);
    }
}

void MainWindow::clearAllTasks() {
    taskList.clearAllTasks();
    taskListView->clear();
}

MainWindow::~MainWindow() {
}
