#include "corelogic.h"



bool CoreLogic::validDataTime(QString data, std::string mode)
{
    return true;
}

CoreLogic::CoreLogic(QString name_db) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(name_db);
    db.open();
    db.close();
}

QList<DataTask> CoreLogic::GetListTask()
{
    db.open();
    QSqlQuery query(db);
    QList<DataTask> list;
    query.exec("SELECT * FROM Tasks");
    while (query.next()) {
        DataTask task(query.value("title").toString(), query.value("description").toString(),
                      query.value("created_at").toString(), query.value("deadline").toString(),
                      query.value("tags").toString() );
        task.status = query.value("status").toString();
        task.id = query.value("id").toInt();
        list.append(task);
    }
    db.close();
    return list;
}

bool CoreLogic::SaveTask(const DataTask *task)
{
    if(task != nullptr){

        db.open();
        QSqlQuery query(db);

        query.prepare("INSERT INTO Tasks (title, description) VALUES (:title, :description)");
        query.bindValue(":title", task->title);
        query.bindValue(":description", task->description);

        if (!query.exec()) {
            qDebug() << "Ошибка INSERT:" << query.lastError().text();
            qDebug() << "Последний запрос:" << query.lastQuery();
            qDebug() << "Привязанные значения:" << query.boundValues();
        }

        db.close();
        return true;
    }
    return false;
}
