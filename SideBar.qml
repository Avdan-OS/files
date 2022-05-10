import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import QtQuick.Window 2.2
Item {
    id:itemContainer
    Rectangle{
        color:"#00000000"
        anchors.fill: parent
        border.color:"red"
        border.width:5
        Label{
            anchors.centerIn: parent
            color: "red"
            font.bold: true
            text:"IN DEVELOPMENT SECTION: SIDE PANE"
        }
    }
}
