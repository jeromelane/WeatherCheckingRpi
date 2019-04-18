#include "dbmanager.h"
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

using namespace std;

DbManager::DbManager(const QString path)
{
    m_sqlitDb = QSqlDatabase::addDatabase("QSQLITE");
    m_sqlitDb.setDatabaseName(path);

    if( !m_sqlitDb.open() ) {
        qDebug() << "erreur de connection avec la base";
    } else {
        qDebug() << "connection ok!";
    }
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

bool DbManager::sendQuery(QString query)
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

