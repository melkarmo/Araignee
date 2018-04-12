import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 600
    height: 820
    title: qsTr("Jeu de l'araignée")

    Rectangle {
        id: toile1
        x: 102
        y: 101
        width: 400
        height: 400
        color: "#ffffff"
        border.width: 2
        border.color: "#000000"
    }

    Rectangle {
        id: toile2
        x: 18
        y: 299
        width: 565
        height: 2
        border.width: 2
        border.color: "#000000"
        rotation: 45
    }

    Rectangle {
        id: toile3
        x: 18
        y: 299
        width: 565
        height: 2
        border.width: 2
        border.color: "#000000"
        rotation: -45
    }

    Rectangle {
        id: toile4
        x: 101
        y: 299
        width: 400
        height: 2
        border.width: 2
        border.color: "#000000"
        rotation: 0
    }

    Rectangle {
        id: toile5
        x: 101
        y: 299
        width: 400
        height: 2
        border.width: 2
        rotation: 90
        border.color: "#000000"
    }

    Rectangle {
        id: case1
        x: 62
        y: 65
        width: 75
        height: 75
        color: "#ffffff"
        border.width: 3

        MouseArea {
            id: mouseArea1
            x: 0
            y: 0
            width: 75
            height: 75
            //onClicked:
        }
    }

    Rectangle {
        id: case2
        x: 263
        y: 65
        width: 75
        height: 75
        color: "#ffffff"
        border.width: 3

        MouseArea {
            id: mouseArea2
            x: 0
            y: 0
            width: 75
            height: 75
            hoverEnabled: false
        }
    }

    Rectangle {
        id: case3
        x: 461
        y: 65
        width: 75
        height: 75
        color: "#ffffff"
        border.width: 3

        MouseArea {
            id: mouseArea3
            x: 0
            y: 0
            width: 75
            height: 75
        }
    }

    Rectangle {
        id: case4
        x: 62
        y: 263
        width: 75
        height: 75
        color: "#ffffff"
        border.width: 3

        MouseArea {
            id: mouseArea4
            x: 0
            y: 0
            width: 75
            height: 75
        }
    }

    Rectangle {
        id: case5
        x: 263
        y: 263
        width: 75
        height: 75
        color: "#ffffff"
        border.width: 3

        MouseArea {
            id: mouseArea5
            x: 0
            y: 0
            width: 75
            height: 75
        }
    }

    Rectangle {
        id: case6
        x: 461
        y: 263
        width: 75
        height: 75
        color: "#ffffff"
        border.width: 3

        MouseArea {
            id: mouseArea6
            x: 0
            y: 0
            width: 75
            height: 75
        }
    }

    Rectangle {
        id: case7
        x: 62
        y: 460
        width: 75
        height: 75
        color: "#ffffff"
        border.width: 3

        MouseArea {
            id: mouseArea7
            x: 0
            y: 0
            width: 75
            height: 75
        }
    }

    Rectangle {
        id: case8
        x: 264
        y: 460
        width: 75
        height: 75
        color: "#ffffff"
        border.width: 3

        MouseArea {
            id: mouseArea8
            x: 0
            y: 0
            width: 75
            height: 75
        }
    }

    Rectangle {
        id: case9
        x: 461
        y: 460
        width: 75
        height: 75
        color: "#ffffff"
        radius: 0
        border.width: 3

        MouseArea {
            id: mouseArea9
            x: 0
            y: 0
            width: 75
            height: 75
        }
    }

    Text {
        id: textInfos
        x: 64
        y: 579
        width: 474
        height: 52
        text: qsTr("Joueur 1, à vous de jouer !")
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 20
    }

    Rectangle {
        id: zoneJoueur1
        x: 64
        y: 645
        width: 230
        height: 35
        color: "#ffff09"

        Text {
            id: text1
            x: 0
            y: 0
            width: 230
            height: 35
            text: qsTr("Joueur 1")
            font.bold: true
            styleColor: "#000000"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 16
        }
    }

    Rectangle {
        id: zoneJoueur2
        x: 308
        y: 645
        width: 230
        height: 35
        color: "#04f2ff"

        Text {
            id: text2
            x: 0
            y: 0
            width: 230
            height: 35
            text: qsTr("Joueur 2")
            font.bold: true
            font.italic: false
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: zoneNouvPartie
        x: 64
        y: 706
        width: 230
        height: 65
        color: "#ffffff"
        border.width: 3

        Text {
            id: textNouvPartie
            x: 0
            y: 0
            width: 230
            height: 65
            text: qsTr("Nouvelle Partie")
            font.bold: true
            fontSizeMode: Text.FixedSize
            font.family: "MS Shell Dlg 2"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
        }

        MouseArea {
            id: mouseAreaNP
            x: 0
            y: 0
            width: 230
            height: 65
        }
    }

    Rectangle {
        id: zoneRegles
        x: 308
        y: 706
        width: 230
        height: 65
        color: "#ffffff"
        border.width: 3
        Text {
            id: textRegles
            x: 0
            y: 0
            width: 230
            height: 65
            text: qsTr("Règles")
            font.bold: true
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "MS Shell Dlg 2"
            fontSizeMode: Text.FixedSize
        }

        MouseArea {
            id: mouseAreaR
            x: 0
            y: 0
            width: 230
            height: 65
        }
    }




}
