#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    MonObjet obj; #TODO MonObjet classe a creer
    
    QQmlApplicationEngine engine(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    
    engine.rootContext()->setContextProperty("obj",&obj);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml"));

    return app.exec();
}
