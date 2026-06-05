#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "createtask.h"
#include "corelogic.h"
#include "task.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addTask_clicked();
    void updateListTask();
    void onTaskDeleted(int taskId);
    void onStatusChanged(int taskId, const QString &status);

private:
    Ui::MainWindow *ui;
    CoreLogic *logic;
};

#endif // MAINWINDOW_H
