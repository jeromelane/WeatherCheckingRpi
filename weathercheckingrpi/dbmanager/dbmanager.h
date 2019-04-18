#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql/QSqlDatabase>

class DbManager {
public:
    DbManager(const QString path);
    ~DbManager();

    bool isOpen() const;
    bool sendQuery(QString query) const;
    void sendQueryAndRecieve(QString query);
    bool create(QString path);
    void connection(QString path);
    void insert(QString temperature, QString pressure, QString humidity, QString time);

private:
    QSqlDatabase m_sqlitDb;
};

#endif // DBMANAGER_H
