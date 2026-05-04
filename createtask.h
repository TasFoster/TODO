#ifndef CREATETASK_H
#define CREATETASK_H

#include <QMainWindow>
#include "corelogic.h"

namespace Ui {
class CreateTask;
}

class CreateTask : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateTask(QWidget *parent = nullptr);
    ~CreateTask();

private slots:
    void on_Add_clicked();

signals:
    void CreatTaskSignal(DataTask *task);

private:
    Ui::CreateTask *ui;
};

#endif // CREATETASK_H
