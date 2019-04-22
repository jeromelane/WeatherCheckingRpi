#include "dbmanager.h"
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QFileInfo>

#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickItem>

#include <map>

using namespace std;

DbManager::DbManager()
{

}

DbManager::DbManager(QString path, QString name)
{
    openConnection(path, name);
    createTable();

}

DbManager::~DbManager()
{
    if( m_sqlitDb.isOpen( ) )
    {
        m_sqlitDb.close( );
    }
}



bool DbManager::isOpen() const
{
    return m_sqlitDb.isOpen( );
}

bool DbManager::sendQuery(QString query) const
{
    QSqlQuery * sqlQuery = new QSqlQuery(query);
    //sqlQuery->prepare(query);

    bool success = sqlQuery->exec( );

    if( !success )
    {
        qDebug( ) << "echec d'execution";
    }

    return success;
}

void DbManager::sendQueryAndRecieve(QString query)
{

    QSqlQuery * sqlQuery = new QSqlQuery(query);
    //sqlQuery->prepare(query);

    int idName = sqlQuery->record().indexOf("name");

    while( sqlQuery->next() )
    {
        QString name = sqlQuery->value(idName).toString();
        qDebug() << "===" << name;
    }

}

bool DbManager::createDb(QString path, QString name)
{
    openConnection(path, name);
    return createTable();
}

bool DbManager::removeDb(QString path, QString name)
{
    QFileInfo check_file(path+ "/" + name);
    if(check_file.exists() && check_file.isFile()) {
        QFile file (path+ "/" + name);
        if(file.remove()) {
            qDebug() << "db file removed";
            return true;
        }
        qDebug() << "db file could not be removed";
    }
    qDebug() << "db file does not exists";
    return false;
}

void DbManager::openConnection(QString path, QString name)
{
    m_sqlitDb = QSqlDatabase::addDatabase("QSQLITE");
    m_sqlitDb.setDatabaseName(path + "/" + name);

    if( !m_sqlitDb.open() ) {
        qDebug() << "erreur de connection avec la base";
    } else {
        qDebug() << "connection ok!";
    }

}

void DbManager::closeConnection()
{
    m_sqlitDb.close();
}



bool DbManager::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE metrics(id INTEGER PRIMARY KEY, temperature TEXT, pressure TEXT, humidity TEXT, time TEXT, forecast TEXT, zambrettiNum TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'metrics': one might already exist.";
        success = false;
    }

    return success;
}


bool DbManager::addMetric(QString metricValue, QString metricName)
{
    bool success = false;
    QString sqlquery = "INSERT INTO metrics ("+ metricName + ") VALUES (\'"+ metricValue+ "\')";

    if (!metricValue.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare(sqlquery);
        //queryAdd.bindValue(":name", metricValue);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add metrics failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add metrics failed: name cannot be empty";
    }
    return success;
}

bool DbManager::addMetrics(QString temperature, QString pressure, QString humidity, QString time)
{
    bool success = true;
    int count = 0;
    map<QString,QString> metrics;
    metrics["temperature"] = temperature;
    metrics["pressure"] = pressure;
    metrics["humidity"] = humidity;
    metrics["time"] = time;

    metrics.begin();

    for(std::pair<QString, QString> element : metrics) {
        bool partialsucces = addMetric( element.second,  element.first);
        if( count ==0 && !partialsucces) {
            success = false;
        }
    }
    return success;

}

bool DbManager::addZambForecast(QString forecast, QString zambrettiNum)
{

    addMetric(forecast,  "forecast");
    return  addMetric(zambrettiNum,  "zambrettiNum");
}


bool DbManager::removeMetric(const QString& metricName, QString value)
{
    bool success = false;

    if (metricExists(metricName, value))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM metrics WHERE "+metricName+" = (:value)");
        queryDelete.bindValue(":value", value);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove metric failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove metric failed: metric does not exist";
    }

    return success;
}

void DbManager::printAllMetrics() const
{
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM metrics");
    int pressure = query.record().indexOf("pressure");
    while (query.next())
    {
        QString value = query.value(pressure).toString();
        qDebug() << "===" << value;
    }
}

bool DbManager::metricExists(QString metricName, const QString& value) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT " + metricName + " FROM metrics WHERE "+ metricName +" = (:value)");
    checkQuery.bindValue(":value", value);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "metric exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool DbManager::removeAllMetrics()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM metrics");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all mretics failed: " << removeQuery.lastError();
    }

    return success;
}



