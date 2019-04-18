#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql/QSqlDatabase>

class DbManager {
public:
    DbManager(const QString path);
    ~DbManager();

    bool isOpen() const;
    bool sendQuery(QString query);
    void sendQueryAndRecieve(QString query);

private:
    QSqlDatabase m_sqlitDb;
};

#endif // DBMANAGER_H
