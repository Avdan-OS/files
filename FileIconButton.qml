import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.15

Button{
    width:64
    height:78
    icon.name:"folder-yellow"
    property alias label:label.text
    property string description: "value"
    property string path: "value"
    property bool contextVisible:false
    icon.width: width*4
    icon.height: width*4
    icon.color: transparent
    ToolTip{
        visible: hovered
        id:tooltip

        contentItem:Label{
                font.family: 'Product Sans'
                text:"<h2>"+label.text+"</h2><br>"+description
                color: "white"
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


    Rectangle{
        x:0
        y:66
        height:26
        width:parent.width
        color:"#00000000"
        clip: true
        Label{
            id:label
            clip:true
            text:"Folder"
            font.family: 'Product Sans'
            font.pixelSize: 12
            color:"white"
            maximumLineCount: 2
            wrapMode: Label.WordWrap
            anchors.centerIn: parent
            height: parent.height
            }
    }
    background: Rectangle{
        color:"#00000000"
    }

}
