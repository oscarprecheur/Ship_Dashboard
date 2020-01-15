import QtQuick 2.9
import QtQuick.Controls 2.0
import VAL.CAPT 1.0
import QtQuick.Layouts 1.0







ApplicationWindow{
    id: applicationWindow
    visible: true
    //visibility: "Maximized"

    title: qsTr("Dashboard_v1")







    GridLayout
    {
        anchors.fill:parent
        columns: 1
        Image {
            id: fond
            Layout.fillWidth: true
            Layout.fillHeight: true

            clip: true
            source: "Visu/Fond.svg"


        }
    }



    Item
    {

        id: tableaudebord
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        Layout.preferredWidth: -1

        Layout.fillHeight: true
        Layout.fillWidth: true

        Item {
            id: vent
            x: 351
            y: 610
            width: 220
            height: 220
            anchors.verticalCenterOffset: 10
            anchors.horizontalCenterOffset: -230
            anchors.horizontalCenter: boussole.horizontalCenter
            anchors.verticalCenter: boussole.verticalCenter

            Image {
                id: aiguille_vent
                x: 52
                y: 13
                width: 116
                height: 108
                anchors.top: cadran_vent.bottom
                anchors.right: parent.right
                anchors.bottom: cadran_vent.top
                anchors.left: cadran_vent.right
                anchors.bottomMargin: -125
                anchors.leftMargin: -165
                anchors.rightMargin: 52
                anchors.topMargin: -212
                source: "Visu/Vent/aiguille.svg"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: cadran_vent
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.top: parent.top
                source: "Visu/Vent/cadran.svg"
                fillMode: Image.PreserveAspectFit
            }

        }

        Item {
            id: accelero
            x: 741
            y: 313
            width: 220
            height: 220
            anchors.verticalCenterOffset: 10
            anchors.horizontalCenterOffset: 230
            anchors.horizontalCenter: boussole.horizontalCenter
            anchors.verticalCenter: boussole.verticalCenter


            Image {
                id: aiguille_accelero
                anchors.fill: parent
                clip: true
                source: "Visu/Accelero/aiguille2.svg"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: cadran_accelero
                width: 500
                anchors.rightMargin: 0
                anchors.fill: parent
                clip: true
                source: "Visu/Accelero/cadran2.svg"
                fillMode: Image.PreserveAspectFit
            }
        }

        Item {
            id: boussole
            x: 330
            y: 222
            width: 300
            height: 300
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Image {
                id: cadran_boussole
                anchors.fill: parent
                clip: true
                source: "Visu/Boussole/cadran2.svg"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: aiguille_boussole
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                anchors.fill: parent
                sourceSize.height: 0
                sourceSize.width: 0
                scale: 1

                Layout.fillWidth: true
                Layout.fillHeight: true
                clip: true


                source: "Visu/Boussole/aiguille2.svg"
                fillMode: Image.PreserveAspectFit
            }


        }







    }



    VALCAPT
    {
        id:valeur
    }




    Timer
    {
        property real rot: 0
        id:timer
        interval:1; running:true;repeat: true
        onTriggered:
        {
            rot=rot+1
            aiguille_boussole.rotation=valeur.getvalBoussole
            aiguille_accelero.rotation=valeur.getvalAccelero
            aiguille_vent.rotation=valeur.getvalDirVent

        }

    }





}

/*##^##
Designer {
    D{i:0;autoSize:true;height:540;width:960}D{i:1;invisible:false}D{i:7;anchors_y:313}
D{i:10;anchors_height:559;anchors_width:557;anchors_x:672;anchors_y:502}D{i:3;anchors_y:850}
}
##^##*/
