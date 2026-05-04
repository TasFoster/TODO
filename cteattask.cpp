#include "cteattask.h"
#include "ui_cteattask.h"

CteatTask::CteatTask(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CteatTask)
{
    ui->setupUi(this);
}

CteatTask::~CteatTask()
{
    delete ui;
}
