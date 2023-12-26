#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow> // Include the QMainWindow header
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include "DoublyLinkedList.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addTask();
    void removeTask();
    void clearAllTasks();

private:
    DoublyLinkedList taskList;
    QListWidget *taskListView;
    QLineEdit *taskLineEdit;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *clearButton;
};

#endif // MAINWINDOW_H



