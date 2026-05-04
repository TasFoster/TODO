#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "createtask.h"
#include "corelogic.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    CoreLogic *s;

private slots:
    void on_setings_clicked();

    void on_addTask_clicked();

    void updateListTask();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
