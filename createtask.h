#ifndef CREATETASK_H
#define CREATETASK_H

#include <QDialog>
#include <QDateTime>
#include "corelogic.h"

namespace Ui { class CreateTask; }

class CreateTask : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTask(QWidget *parent = nullptr);
    ~CreateTask();

signals:
    void taskCreated(DataTask task);

private slots:
    void on_addBtn_clicked();
    void on_cancelBtn_clicked();

private:
    Ui::CreateTask *ui;
};

#endif // CREATETASK_H
