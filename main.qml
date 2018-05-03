import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.1
import io.qt.examples.backend 1.0


Window {
    id: root
    visible: true
    width: 700
    height: 600
    title: qsTr("Connect 4")
    color: "grey"
    BackEnd {
        id: backend
    }
    Grid {
        anchors.fill: root
        id: board
        columns: 7
        rows:6
        spacing: 1
        Repeater {
            model: 42
        Rectangle { color: "darkgrey"; width: root.width/7; height: root.height/6; radius: root.width/6 }
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked:
        {
            backend.clickedColumn = ((mouseX - (mouseX % (root.width/7)))/(root.width/7))
            board.childAt(backend.clickedColumn * root.width/7+10, backend.clickedRow * root.height/6+10).color = "red"
            board.childAt(backend.clickedColumnOponent * root.width/7+10, backend.clickedRowOponent * root.height/6+10).color = "yellow"
            if(backend.situation === 7){
            messageDialog.text = "You win!"
            messageDialog.visible = true
            }
            if(backend.situation === 10){
            messageDialog.text = "You draw!"
            messageDialog.visible = true
            }
            if(backend.situation === 13){
            messageDialog.text = "You lose!"
            messageDialog.visible = true
            }
        }
    }
    MessageDialog {
        id: messageDialog
        title: "Connect 4"
        onAccepted: {
            Qt.quit()
        }
    }
}




