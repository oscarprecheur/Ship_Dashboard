#ifndef VALCAPT_H
#define VALCAPT_H

//#include <QMainWindow>
//#include <QObject>
//#include <QtWidgets>
//#include <QPushButton>
//#include "socketdatareceiver.h"
//#include <QSvgWidget>
//#include <QGraphicsScene>
//#include "mainwindow.h"

//class valcapt : public MainWindow
//{
//    Q_OBJECT

//    Q_PROPERTY(float valGPS READ valGPS)
//    Q_PROPERTY(float valBoussole READ valBoussole)
//    Q_PROPERTY(float valAccelero  READ valAccelero)
//    Q_PROPERTY(float valDirVent  READ valDirVent)
//    Q_PROPERTY(float valVitVent READ valVitVent)
//public:
//    explicit valcapt(QObject *parent = nullptr);

//private:
//    float valGPS();
//    float valBoussole();
//    float valAccelero();
//    float valDirVent();
//    float valVitVent();

//};

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>
#include <QPushButton>
#include "socketdatareceiver.h"
#include <QSvgWidget>
#include <QGraphicsScene>



class valcapt:public QObject
{
    Q_OBJECT

    Q_PROPERTY(float getvalBoussole READ getvalBoussole )
    Q_PROPERTY(float getvalGPS READ getvalGPS )
    Q_PROPERTY(float getvalVitVent READ getvalVitVent )
    Q_PROPERTY(float getvalDirVent READ getvalDirVent )
    Q_PROPERTY(float getvalAccelero READ getvalAccelero )




public:
    valcapt(QObject *parent = nullptr);


    float getvalGPS();
    float getvalBoussole();
    float getvalVitVent();
    float getvalDirVent();
    float getvalAccelero();

public slots:
   void updateGPS();
   void updateBoussole();
//   {
//       valBoussole=receiverBoussole.readyRead();
//       emit valBoussoleChanged();
//       qDebug()<<",ioa"<<valBoussole;
//   }
   void updateVitVent();
   void updateDirVent();
   void updateAccelero();




private:
   SocketDataReceiver receiverBoussole;//(65432 ) ;
   SocketDataReceiver receiverGPS;//(65433) ;
   SocketDataReceiver receiverAccelero;//(65434) ;
   SocketDataReceiver receiverDirVent;//(65435) ;
   SocketDataReceiver receiverVitVent;//(65436) ;

   float valGPS;
   float valBoussole;
   float valVitVent;
   float valDirVent;
   float valAccelero;





};

#endif // VALCAPT_H
