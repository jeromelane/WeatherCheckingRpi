#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>

class WeatherData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString dayOfWeek
               READ dayOfWeek WRITE setDayOfWeek
               NOTIFY dataChanged)
    Q_PROPERTY(QString weatherIcon
               READ weatherIcon WRITE setWeatherIcon
               NOTIFY dataChanged)
    Q_PROPERTY(QString weatherDescription
               READ weatherDescription WRITE setWeatherDescription
               NOTIFY dataChanged)
    Q_PROPERTY(QString temperature
               READ temperature WRITE setTemperature
               NOTIFY dataChanged)
    Q_PROPERTY(QString pressure
               READ pressure WRITE setPressure
               NOTIFY dataChanged)
    Q_PROPERTY(QString humidity
               READ humidity WRITE setHumidity
               NOTIFY dataChanged)

public:
    explicit WeatherData(QObject *parent = nullptr);
    WeatherData(const WeatherData &other);

    QString dayOfWeek() const;
    QString weatherIcon() const;
    QString weatherDescription() const;
    QString temperature() const;
    QString pressure() const;
    QString humidity() const;

    void setDayOfWeek(const QString &value);
    void setWeatherIcon(const QString &value);
    void setWeatherDescription(const QString &value);
    void setTemperature(const QString &value);
    void setPressure(const QString &pressure);
    void setHumidity(const QString &humidity);

signals:
    void dataChanged();
    //! [0]
private:
    QString m_dayOfWeek;
    QString m_weather;
    QString m_weatherDescription;
    QString m_temperature;
    QString m_pressure;
    QString m_humidity;
//! [1]
};


#endif // WEATHERDATA_H
