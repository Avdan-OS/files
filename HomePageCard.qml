import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.15

Button{
    width:300
    height:64
    property alias cardLabel: label.text
    property string cardIcon: "folder-yellow"
    property string description: ""
    background:Rectangle{
        color:"#44ffffff"
        radius:5
    }
    Rectangle{
        width:childrenRect.width
        height:parent.height
        color:"#00000000"
        x:parent.height+5
        y:0
        Label{
            id:label
            font.family: 'Product Sans'
            text:"Card Name"
            font.pixelSize: 17
            anchors.centerIn: parent
            color:"#fff"
        }
    }

    Button{
        background:Rectangle{
            color:"#00000000"
        }
        icon.name: cardIcon
        icon.color: "transparent"
        icon.height: parent.height*4
        icon.width: parent.height*4
        height: parent.height
        width: parent.height
        x:0
        y:0
    }
    ToolTip{
        visible: hovered
        id:tooltip
        contentItem:Label{
                text:"<h2>"+label.text+"</h2><br>"+description
                color: "white"
                font.family: 'Product Sans'
                wrapMode: Text.wrap
                x:64
                y:0
            }
        background: Rectangle{
            color:"#dd000000"

            Rectangle{
                color:"#f00"
                clip: true
                width:4
                height: parent.height
                x:0
                y:0
            }

        }
    }

}
