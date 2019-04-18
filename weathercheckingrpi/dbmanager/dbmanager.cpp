#include "dbmanager.h"
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickItem>

using namespace std;

DbManager::DbManager(const QString path)
{
    create(path);
    connection(path);

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

void DbManager::connection(QString path)
{
    m_sqlitDb = QSqlDatabase::addDatabase("QSQLITE");
    m_sqlitDb.setDatabaseName(path);

    if( !m_sqlitDb.open() ) {
        qDebug() << "erreur de connection avec la base";
    } else {
        qDebug() << "connection ok!";
    }

}

bool DbManager::create(QString path)
{
    bool exists = false;
    if( QFile::exists(path) )
    {
        exists = true;
        qDebug()<<"Database exist no need to create...";
    } else {
        qDebug()<<"Database does not exist creating new....";
        this->sendQuery("CREATE TABLE metrics(id INTEGER PRIMARY KEY, temperature TEXT, pressure TEXT, humidity TEXT, time TEXT);");
    }
    return exists;
}

void DbManager::insert(QString temperature, QString pressure, QString humidity, QString time )
{
    //"INSERT INTO metrics (name) VALUES ('bob')"
    this->sendQuery("INSERT INTO metrics (temperature) VALUES (\'"+ temperature+ "\')");
    this->sendQuery("INSERT INTO metrics (pressure) VALUES (\'"+ pressure+ "\')");
    this->sendQuery("INSERT INTO metrics (humidity) VALUES (\'"+ humidity+ "\')");
    this->sendQuery("INSERT INTO metrics (time) VALUES (\'"+ time+ "\')");
}

