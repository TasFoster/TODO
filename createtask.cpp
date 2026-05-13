#include "createtask.h"
#include "ui_createtask.h"

CreateTask::CreateTask(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateTask)
{
    ui->setupUi(this);

    ui->TagsComboBox->addItems({
        "Активная",
        "В процессе",
        "Завершена",
        "Отложена",
        "Провалена"
    });

}

CreateTask::~CreateTask()
{
    delete ui;
}

void CreateTask::on_Add_clicked()
{
    QString date = ui->dateEdit->text();
    QString time = ui->timeEdit->text();
    DataTask data(ui->TitleLineEdit->text(), ui->DescriptionLineEdit->text(),
                  QDateTime::currentDateTime().toString(), date + time);
    QString tag = ui->TagsComboBox->currentText();
    data.tag = tag;
    emit CreatTaskSignal(&data);
    this->close();
}


