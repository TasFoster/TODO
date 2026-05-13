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
    ui->comboBox->setCurrentText(taskData->status);
    ui->Deadlinelabel->setText(taskData->deadline);
    ui->Create_Atlabel->setText(taskData->created_at);
    ui->Taglabel->setText(taskData->tag);


}

Task::~Task()
{
    delete ui;
}



