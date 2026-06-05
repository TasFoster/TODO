#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include "corelogic.h"

namespace Ui { class Task; }

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const DataTask *taskData, QWidget *parent = nullptr);
    ~Task();

signals:
    void deleteRequested(int taskId);
    void statusChanged(int taskId, const QString &status);

private:
    Ui::Task *ui;
    int taskId;
    void applyStatusStyle(const QString &status);
};

#endif // TASK_H
