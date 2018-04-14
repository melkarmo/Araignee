import QtQuick 2.9
import QtQuick.Window 2.2

Rectangle {
    id: rectangle
    width: 600
    height: 820
    color: "#ffffff"
    radius: 0
    property alias mouseArea8: mouseArea8
    property alias case8: case8
    property alias mouseArea7: mouseArea7
    property alias case7: case7
    property alias mouseArea6: mouseArea6
    property alias case6: case6
    property alias mouseArea5: mouseArea5
    property alias case5: case5
    property alias mouseArea4: mouseArea4
    property alias case4: case4
    property alias mouseArea3: mouseArea3
    property alias case3: case3
    property alias mouseArea2: mouseArea2
    property alias case2: case2
    property alias mouseArea1: mouseArea1
    property alias case1: case1
    property alias mouseArea0: mouseArea0
    property alias case0: case0
    property alias zoneNouvPartie: zoneNouvPartie
    property alias zoneRegles: zoneRegles
    property alias mouseAreaR: mouseAreaR
    property alias mouseAreaNP: mouseAreaNP
    property alias textInfos: textInfos
    border.width: 0
    border.color: "#000000"

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
        id: case0
        x: 62
        y: 65
        width: 75
        height: 75
        color: vueObjetMoteur.couleursQML[0]
        border.width: 3
        border.color: vueObjetMoteur.bordsQML[0]

        MouseArea {
            id: mouseArea0
            x: 0
            y: 0
            width: 75
            height: 75
            enabled: vueObjetMoteur.etatCasesQML
        }
    }

    Rectangle {
        id: case1
        x: 263
        y: 65
        width: 75
        height: 75
        color: vueObjetMoteur.couleursQML[1]
        border.width: 3
        border.color: vueObjetMoteur.bordsQML[1]

        MouseArea {
            id: mouseArea1
            x: 0
            y: 0
            width: 75
            height: 75
            enabled: vueObjetMoteur.etatCasesQML
        }
    }

    Rectangle {
        id: case2
        x: 461
        y: 65
        width: 75
        height: 75
        color: vueObjetMoteur.couleursQML[2]
        border.width: 3
        border.color: vueObjetMoteur.bordsQML[2]

        MouseArea {
            id: mouseArea2
            x: 0
            y: 0
            width: 75
            height: 75
            enabled: vueObjetMoteur.etatCasesQML
        }
    }

    Rectangle {
        id: case3
        x: 62
        y: 263
        width: 75
        height: 75
        color: vueObjetMoteur.couleursQML[3]
        border.width: 3
        border.color: vueObjetMoteur.bordsQML[3]

        MouseArea {
            id: mouseArea3
            x: 0
            y: 0
            width: 75
            height: 75
            enabled: vueObjetMoteur.etatCasesQML
        }
    }

    Rectangle {
        id: case4
        x: 263
        y: 263
        width: 75
        height: 75
        color: vueObjetMoteur.couleursQML[4]
        border.width: 3
        border.color: vueObjetMoteur.bordsQML[4]

        MouseArea {
            id: mouseArea4
            x: 0
            y: 0
            width: 75
            height: 75
            enabled: vueObjetMoteur.etatCasesQML
        }
    }

    Rectangle {
        id: case5
        x: 461
        y: 263
        width: 75
        height: 75
        color: vueObjetMoteur.couleursQML[5]
        border.width: 3
        border.color: vueObjetMoteur.bordsQML[5]

        MouseArea {
            id: mouseArea5
            x: 0
            y: 0
            width: 75
            height: 75
            enabled: vueObjetMoteur.etatCasesQML
        }
    }

    Rectangle {
        id: case6
        x: 62
        y: 460
        width: 75
        height: 75
        color: vueObjetMoteur.couleursQML[6]
        border.width: 3
        border.color: vueObjetMoteur.bordsQML[6]

        MouseArea {
            id: mouseArea6
            x: 0
            y: 0
            width: 75
            height: 75
            enabled: vueObjetMoteur.etatCasesQML
        }
    }

    Rectangle {
        id: case7
        x: 264
        y: 460
        width: 75
        height: 75
        color: vueObjetMoteur.couleursQML[7]
        border.width: 3
        border.color: vueObjetMoteur.bordsQML[7]

        MouseArea {
            id: mouseArea7
            x: 0
            y: 0
            width: 75
            height: 75
            enabled: vueObjetMoteur.etatCasesQML
        }
    }

    Rectangle {
        id: case8
        x: 461
        y: 460
        width: 75
        height: 75
        color: vueObjetMoteur.couleursQML[8]
        border.width: 3
        border.color: vueObjetMoteur.bordsQML[8]

        MouseArea {
            id: mouseArea8
            x: 0
            y: 0
            width: 75
            height: 75
            enabled: vueObjetMoteur.etatCasesQML
        }
    }

    Text {
        id: textInfos
        x: 64
        y: 579
        width: 474
        height: 52
        text: vueObjetMoteur.infosQML
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
