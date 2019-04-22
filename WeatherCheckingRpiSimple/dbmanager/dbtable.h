#ifndef DBTABLE_H
#define DBTABLE_H

#include <QString>

class DbTable {
public:
    DbTable(QString temperature, QString pressure, QString humidity, QString time);
    ~DbTable();

    QString getTemperature() const;
    QString getPressure() const;
    QString getHumidity() const;
    QString getTime() const;

    void setTemperature(const QString &value);
    void setPressure(const QString &value);
    void setHumidity(const QString &value);
    void setTime(const QString &value);

private:
    QString m_temperature;
    QString m_pressure;
    QString m_humidity;
    QString m_time;
};


#endif // DBTABLE_H
