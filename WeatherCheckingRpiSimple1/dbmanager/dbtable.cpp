#include "dbtable.h"

DbTable::DbTable(QString temperature, QString pressure, QString humidity, QString time):
{
    m_temperature = temperature;
    m_pressure = pressure;
    m_humidity = humidity;
    m_time = time;
}

QString DbTable::getTemperature() const
{
    return m_temperature;
}

QString DbTable::getPressure() const
{
    return m_pressure;
}

QString DbTable::getHumidity() const
{
    return m_humidity;
}

QString DbTable::getTime() const
{
    return m_time;
}

void DbTable::setTemperature(const QString &value)
{
    m_temperature = value;
}

void DbTable::setPressure(const QString &value)
{
    m_pressure = value;
}

void DbTable::setHumidity(const QString &value)
{
    m_humidity = value;
}

void DbTable::setTime(const QString &value)
{
    m_time = value;
}
