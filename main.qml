import QtQuick 2.9
import QtQuick.Window 2.2


Window {
    visible: true
    width: 600
    height: 820
    title: qsTr("Jeu de l'araignée")

    MainForm {
        anchors.fill: parent

        mouseAreaNP {
            onClicked : vueObjetMoteur.nouvellePartie();
            onEntered : zoneNouvPartie.color = "#ebebeb";
            onExited : zoneNouvPartie.color = "#ffffff";
        }

        mouseArea0 {
            onClicked : vueObjetMoteur.clique(0);
        }
        mouseArea1 {
            onClicked : vueObjetMoteur.clique(1);
        }
        mouseArea2 {
            onClicked : vueObjetMoteur.clique(2);
        }
        mouseArea3 {
            onClicked : vueObjetMoteur.clique(3);
        }
        mouseArea4 {
            onClicked : vueObjetMoteur.clique(4);
        }
        mouseArea5 {
            onClicked : vueObjetMoteur.clique(5);
        }
        mouseArea6 {
            onClicked : vueObjetMoteur.clique(6);
        }
        mouseArea7 {
            onClicked : vueObjetMoteur.clique(7);
        }
        mouseArea8 {
            onClicked : vueObjetMoteur.clique(8);
        }

    }

}
