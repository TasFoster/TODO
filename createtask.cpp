#include "createtask.h"
#include "ui_createtask.h"

CreateTask::CreateTask(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreateTask)
{
    ui->setupUi(this);
    setModal(true);

    ui->statusCombo->addItems({"Активная", "В процессе", "Завершена", "Отложена", "Провалена"});
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit->setDisplayFormat("dd.MM.yyyy");
    ui->timeEdit->setTime(QTime(23, 59));
    ui->timeEdit->setDisplayFormat("HH:mm");
}

CreateTask::~CreateTask()
{
    delete ui;
}

void CreateTask::on_addBtn_clicked()
{
    if (ui->titleEdit->text().trimmed().isEmpty())
        return;

    DataTask task(
        ui->titleEdit->text().trimmed(),
        ui->descEdit->text().trimmed(),
        QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm"),
        ui->dateEdit->date().toString("dd.MM.yyyy") + " " + ui->timeEdit->time().toString("HH:mm"),
        ui->tagEdit->text().trimmed(),
        ui->statusCombo->currentText()
    );

    emit taskCreated(task);
    accept();
}

void CreateTask::on_cancelBtn_clicked()
{
    reject();
}
