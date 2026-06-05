#ifndef CORELOGIC_H
#define CORELOGIC_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

struct DataTask
{
    int id = 0;
    QString title, description, status, created_at, deadline, tag;

    DataTask() {}
    DataTask(QString title, QString description = "",
             QString created_at = "", QString deadline = "",
             QString tag = "", QString status = "Активная")
        : title(title), description(description),
          created_at(created_at), deadline(deadline),
          tag(tag), status(status) {}
};

class CoreLogic : public QObject
{
    Q_OBJECT
    QSqlDatabase db;

public:
    CoreLogic(QString name_db);

    QList<DataTask> GetListTask();

public slots:
    bool SaveTask(DataTask task);
    bool UpdateTaskStatus(int taskId, const QString &status);
    bool DeleteTask(int taskId);
};

#endif // CORELOGIC_H
