#ifndef CORELOGIC_H
#define CORELOGIC_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringListModel>

struct DataTask
{
    int id;
    QString title, description, status, created_at, deadline, tag;
    DataTask() {}
    DataTask(QString title, QString description = "",
             QString created_at = "", QString deadline = "",
            QString tag = ""){
        this->title = title;
        this->description = description;
        this->created_at = created_at;
        this->deadline = deadline;
        this->tag = tag;
    }
};
class CoreLogic : public QObject
{
    Q_OBJECT
    QSqlDatabase db;

    bool validDataTime(QString data, std::string mode = "data");

public:
    CoreLogic(QString name_db);

    QList<DataTask> GetListTask();


public slots:
    bool SaveTask(const DataTask *task);

};

#endif // CORELOGIC_H
