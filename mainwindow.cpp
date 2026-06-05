#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMinimumSize(720, 520);
    menuBar()->hide();
    statusBar()->hide();

    logic = new CoreLogic("my_db.db");
    updateListTask();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addTask_clicked()
{
    CreateTask dialog(this);
    connect(&dialog, &CreateTask::taskCreated, logic, &CoreLogic::SaveTask);
    connect(&dialog, &CreateTask::taskCreated, this,  &MainWindow::updateListTask);
    dialog.exec();
}

void MainWindow::updateListTask()
{
    ui->listTask->clear();

    QList<DataTask> list = logic->GetListTask();

    ui->listTask->setVisible(!list.isEmpty());
    ui->emptyLabel->setVisible(list.isEmpty());

    for (const DataTask &task : list) {
        QListWidgetItem *item = new QListWidgetItem(ui->listTask);
        Task *widget = new Task(&task, ui->listTask);
        connect(widget, &Task::deleteRequested, this, &MainWindow::onTaskDeleted);
        connect(widget, &Task::statusChanged,   this, &MainWindow::onStatusChanged);
        item->setSizeHint(widget->sizeHint());
        ui->listTask->setItemWidget(item, widget);
    }
}

void MainWindow::onTaskDeleted(int taskId)
{
    logic->DeleteTask(taskId);
    updateListTask();
}

void MainWindow::onStatusChanged(int taskId, const QString &status)
{
    logic->UpdateTaskStatus(taskId, status);
}
