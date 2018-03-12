import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 600
    height: 600
    title: qsTr("Jeu de l'araignée")

    Rectangle {
        id: rectangle
        x: 124
        y: 65
        width: 400
        height: 400
        color: "#ffffff"
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0
        border.color: "#000000"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Rectangle {
        id: rectangle1
        x: 18
        y: 299
        width: 565
        height: 2
        border.color: "#000000"
        rotation: 45
    }

    Rectangle {
        id: rectangle2
        x: 18
        y: 299
        width: 565
        height: 2
        border.color: "#000000"
        rotation: -45
    }

    Rectangle {
        id: rectangle3
        x: 101
        y: 299
        width: 400
        height: 2
        border.color: "#000000"
        rotation: 0
    }

    Rectangle {
        id: rectangle4
        x: 101
        y: 299
        width: 400
        height: 2
        rotation: 90
        border.color: "#000000"
    }
}
