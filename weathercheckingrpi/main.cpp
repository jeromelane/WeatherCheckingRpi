/*!
 *\mainpage Brief Description
 *\author Jerome Lane, Katia Gasperi
 * \date 15 April 2019
 *\version 0.1
 *\section intro_sec Introduction
 *
 * <p>Project where humidity, pressure and temperature are mesured with a Raspberry Pi 3 and BME280 environmental sensor.\n
 * Provide a graphical interface displaying these metrics.\n
 * The interface provides a weather icon corresponding to the current weather.</p>
 *
 * \section requirements_sec Requirements
 * \subsection Hardware
 * <ul>
 * <li>Capteur BME 280</li>
 * <li> Raspberry PI</li>
 * </ul>
 * \subsection Software
 * <ul>
 *    <li>C/C++</li>
 *     <li>QML</li>
 *    <li>Qt</li>
 * </ul>
 *
 * \section install_sec Installation
 * Paquet debian
 * \section References
 * - Algorithme de Zambretti <small><a href="https://web.archive.org/web/20110610213848/http://www.meteormetrics.com/zambretti.htm">doc</a></small>

 *
 * <BR><BR>
*
*/

#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickItem>
#include <QLoggingCategory>

#include "appmodel.h"
//#include "dbmanager/dbmanager.h"
//#include "dbmanager/dbmanager.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    try {
        // activer le capteur initsensor
        // refreshsensor
        // faire moyenne de 60s de mesures toutes les minutes et stocker dans la bd averageCalculator
        // les deux pressions Zambretti recuperer de la bd
        // getTrend, getZNumber et stocker les valeurs
        // traiter ZNumber pur avoir la description
        // afficher valeur description de Zambretti, tendance, P, T, H quand stocker  (init)
        // rafraichir IHM toutes les 60s.

        QLoggingCategory::setFilterRules("wapp.*.debug=false");
        QGuiApplication application(argc, argv);

        qmlRegisterType<WeatherData>("WeatherChecking", 1, 0, "WeatherData");
        qmlRegisterType<AppModel>("WeatherChecking", 1, 0, "AppModel");

        qRegisterMetaType<WeatherData>();

        const QString mainQmlApp = QStringLiteral("qrc:///weathercheckingrpi.qml");
        QQuickView view;
        view.setSource(QUrl(mainQmlApp));
        view.setResizeMode(QQuickView::SizeRootObjectToView);

        QObject::connect(view.engine(), SIGNAL(quit()), qApp, SLOT(quit()));
        view.setGeometry(QRect(100, 100, 360, 640));
        view.show();
        application.exec();
    } catch (char const* chain) {
        cerr << chain << endl;
        return 1;
    }
    return 0;
}
