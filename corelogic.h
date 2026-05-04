#ifndef CORELOGIC_H
#define CORELOGIC_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringListModel>

struct DataTask
{
    QString title;
    QString description;
    DataTask() {}
    DataTask(QString title, QString description){
        this->title = title;
        this->description = description;
    }
};
class CoreLogic : public QObject
{
    Q_OBJECT
    QSqlDatabase db;
public:
    CoreLogic(QString name_db);

    QStringListModel GetListTask();


public slots:
    bool SaveTask(const DataTask *task);

};

#endif // CORELOGIC_H
