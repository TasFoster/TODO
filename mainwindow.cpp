#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    s = new CoreLogic("my_db.db");

    updateListTask();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setings_clicked()
{

}


void MainWindow::on_addTask_clicked()
{
    CreateTask *createTaskModal = new CreateTask(this);
    connect(createTaskModal, &CreateTask::CreatTaskSignal, s, &CoreLogic::SaveTask );
    connect(createTaskModal, &CreateTask::CreatTaskSignal, this, &MainWindow::updateListTask);
    createTaskModal->setWindowModality(Qt::WindowModal);
    createTaskModal->show();
}

void MainWindow::updateListTask()
{
    QList<DataTask> list = s->GetListTask();

    for (DataTask i : list){
        QListWidgetItem *listUI = new QListWidgetItem(ui->listTask);
        Task *newTask = new Task(&i, ui->listTask);
        qDebug() << i.title;
        listUI->setSizeHint(newTask->sizeHint());
        ui->listTask->setItemWidget(listUI, newTask);
    }

}

