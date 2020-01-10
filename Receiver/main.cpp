#include "mainwindow.h"

#include <QApplication>
#include "socketdatareceiver.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtGui>

#include "valcapt.h"



int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    valcapt w;






//     qDebug()<<receiverBoussole.transmit();
//     qDebug()<<receiverGPS.transmit();
//     qDebug()<<receiverAccelero.transmit();
//     qDebug()<<receiverDirVent.transmit();
//     qDebug()<<receiverVitVent.transmit();




    QQmlApplicationEngine engine;

    qmlRegisterType<valcapt>("VAL.CAPT",1,0,"VALCAPT");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &a, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return a.exec();




}
