#include "valcapt.h"

#include <QDebug>

#include <QObject>
#include <QTimer>
#include "socketdatareceiver.h"
#include <QSvgWidget>
#include <QWidget>
#include <QGridLayout>
#include <QtWidgets>

valcapt::valcapt(QObject *parent)
{
    auto timer = new QTimer();
    //timer->setInterval(500);

    //Connexion aux serveurs
    receiverBoussole.Connexion(65432);
    receiverGPS.Connexion(65433);
    receiverAccelero.Connexion(65434);
    receiverDirVent.Connexion(65435);
    receiverVitVent.Connexion(65436);




    connect(timer, SIGNAL(timeout()),this,SLOT(updateBoussole()));

    connect(timer, SIGNAL(timeout()),this,SLOT(updateGPS()));

    connect(timer, SIGNAL(timeout()),this,SLOT(updateVitVent()));

    connect(timer, SIGNAL(timeout()),this,SLOT(updateDirVent()));

    connect(timer, SIGNAL(timeout()),this,SLOT(updateAccelero()));


    timer->start();
}

void valcapt::updateGPS()
{
    if (receiverGPS.getNbByteAvailable()>0)
    {
    valGPS=receiverGPS.readyRead();
    qDebug()<<"valGPS"<<valBoussole;
    }
   // qDebug()<<"GPS "<<valGPS;
}


//Boussole--------------------
void valcapt::updateBoussole()
{


 if (receiverBoussole.getNbByteAvailable()>0)
 {
    valBoussole=receiverBoussole.readyRead();
    qDebug()<<"valBoussole"<<valBoussole;
 }


}



//VitVent--------------------
void valcapt::updateVitVent()
{
    if (receiverVitVent.getNbByteAvailable()>0)
    {
    valVitVent=receiverVitVent.readyRead();
    qDebug()<<"valVitvent"<<valBoussole;
    }

   // qDebug()<<"Vitesse Vent "<<valVitVent;
}



//DirVent--------------------
void valcapt::updateDirVent()
{
    if (receiverDirVent.getNbByteAvailable()>0)
    {
    valDirVent=receiverDirVent.readyRead();
    qDebug()<<"valDirVent"<<valBoussole;
    }

    //qDebug()<<"DirVent "<<valDirVent;
}



//Accelero--------------------
void valcapt::updateAccelero()
{
    if (receiverAccelero.getNbByteAvailable()>0)
    {
    valAccelero=receiverAccelero.readyRead();
    qDebug()<<"valAccelero"<<valBoussole;
    }

    //qDebug()<<"Accelero "<<valAccelero;
}



//Geter-----------------
float valcapt::getvalGPS()
{
    return valGPS;
}

float valcapt::getvalAccelero()
{
    return valAccelero;
}

float valcapt::getvalVitVent()
{
    return valVitVent;
}

float valcapt::getvalDirVent()
{
    return valDirVent;
}

float valcapt::getvalBoussole()
{
    return valBoussole;
}








