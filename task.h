#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include "corelogic.h"

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT
    int taskId;

public:
    explicit Task(const DataTask *taskData, QWidget *parent = nullptr);

    ~Task();


private slots:
    void on_pushButton_clicked();

private:
    Ui::Task *ui;
};

#endif // TASK_H
