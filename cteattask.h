#ifndef CTEATTASK_H
#define CTEATTASK_H

#include <QMainWindow>

namespace Ui {
class CteatTask;
}

class CteatTask : public QMainWindow
{
    Q_OBJECT

public:
    explicit CteatTask(QWidget *parent = nullptr);
    ~CteatTask();

private:
    Ui::CteatTask *ui;
};

#endif // CTEATTASK_H
