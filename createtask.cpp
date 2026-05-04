#include "createtask.h"
#include "ui_createtask.h"

CreateTask::CreateTask(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateTask)
{
    ui->setupUi(this);

}

CreateTask::~CreateTask()
{
    delete ui;
}

void CreateTask::on_Add_clicked()
{
    DataTask data(ui->TitleLineEdit->text(), ui->DescriptionLineEdit->text());
    emit CreatTaskSignal(&data);
    this->close();
}

