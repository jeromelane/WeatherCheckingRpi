#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql/QSqlDatabase>

class DbManager {
public:
    DbManager();
    DbManager(const QString path, const QString name);
    ~DbManager();

    bool isOpen() const;
    bool sendQuery(QString query) const;
    void sendQueryAndRecieve(QString query);
    bool createDb(QString path, QString name);
    bool removeDb(QString path, QString name);
    bool createTable();
    void openConnection(QString path, QString name);
    void closeConnection();
    bool addMetrics(QString temperature, QString pressure, QString humidity, QString time);
    bool addMetric(QString metricValue, QString metricName);

private:
    QSqlDatabase m_sqlitDb;
};

#endif // DBMANAGER_H
