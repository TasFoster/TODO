#include "task.h"
#include "ui_task.h"

Task::Task(const DataTask *taskData, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_StyledBackground, true);

    taskId = taskData->id;

    ui->title->setText(taskData->title);
    ui->description->setText(taskData->description);
}

Task::~Task()
{
    delete ui;
}

void Task::on_pushButton_clicked()
{
    this->setStyleSheet("background:#03ff1c;");
}

