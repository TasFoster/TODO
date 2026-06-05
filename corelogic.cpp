#include "corelogic.h"

CoreLogic::CoreLogic(QString name_db)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(name_db);
    db.open();

    QSqlQuery query(db);
    query.exec(
        "CREATE TABLE IF NOT EXISTS Tasks ("
        "  id          INTEGER PRIMARY KEY AUTOINCREMENT,"
        "  title       TEXT    NOT NULL,"
        "  description TEXT,"
        "  created_at  TEXT,"
        "  deadline    TEXT,"
        "  tags        TEXT,"
        "  status      TEXT"
        ")"
    );

    db.close();
}

QList<DataTask> CoreLogic::GetListTask()
{
    db.open();
    QSqlQuery query(db);
    QList<DataTask> list;
    query.exec("SELECT * FROM Tasks ORDER BY id DESC");
    while (query.next()) {
        DataTask task;
        task.id          = query.value("id").toInt();
        task.title       = query.value("title").toString();
        task.description = query.value("description").toString();
        task.created_at  = query.value("created_at").toString();
        task.deadline    = query.value("deadline").toString();
        task.tag         = query.value("tags").toString();
        task.status      = query.value("status").toString();
        list.append(task);
    }
    db.close();
    return list;
}

bool CoreLogic::SaveTask(DataTask task)
{
    db.open();
    QSqlQuery query(db);
    query.prepare(
        "INSERT INTO Tasks (title, description, created_at, deadline, tags, status) "
        "VALUES (:title, :description, :created_at, :deadline, :tags, :status)"
    );
    query.bindValue(":title",       task.title);
    query.bindValue(":description", task.description);
    query.bindValue(":created_at",  task.created_at);
    query.bindValue(":deadline",    task.deadline);
    query.bindValue(":tags",        task.tag);
    query.bindValue(":status",      task.status.isEmpty() ? "Активная" : task.status);

    bool ok = query.exec();
    if (!ok)
        qDebug() << "SaveTask error:" << query.lastError().text();
    db.close();
    return ok;
}

bool CoreLogic::UpdateTaskStatus(int taskId, const QString &status)
{
    db.open();
    QSqlQuery query(db);
    query.prepare("UPDATE Tasks SET status = :status WHERE id = :id");
    query.bindValue(":status", status);
    query.bindValue(":id",     taskId);
    bool ok = query.exec();
    if (!ok)
        qDebug() << "UpdateTaskStatus error:" << query.lastError().text();
    db.close();
    return ok;
}

bool CoreLogic::DeleteTask(int taskId)
{
    db.open();
    QSqlQuery query(db);
    query.prepare("DELETE FROM Tasks WHERE id = :id");
    query.bindValue(":id", taskId);
    bool ok = query.exec();
    if (!ok)
        qDebug() << "DeleteTask error:" << query.lastError().text();
    db.close();
    return ok;
}
