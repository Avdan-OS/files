import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
Rectangle {
    //Header
    Rectangle{
        id:header
        x:0
        y:0
        width:parent.width
        height: 125
        color:"#00000000"
        Label{
            id:headertext
            text:"Files"
            anchors.horizontalCenter: parent.horizontalCenter
            y:25
            font.pointSize: 20
            font.family: 'Product Sans'
            color:"#ffffff"
        }
        Rectangle{
            anchors.horizontalCenter: parent.horizontalCenter
            y:76
            width:parent.width/2.5
            TextField{
                id:searchbox
                placeholderText: "Find a file"
                placeholderTextColor: "#66ffffff"
                color: "white"
                font.family: 'Product Sans'
                font.pointSize: 12
                anchors.left: parent.left
                width:parent.width-(searchbutton.width)
                background: Rectangle{
                    color: "#33ffffff"
                    width:parent.parent.width
                    radius:5
                }
            }
            Button{
                id:searchbutton
                anchors.right:parent.right
                width:searchbox.height
                height:searchbox.height
                icon.color: transientParent
                icon.name:"stock_search"
                icon.width: height
                icon.height: height
                background: Rectangle{
                    color:"#00000000"
                }
            }
        }
    }
    Rectangle {
        id:mainitems
        width:parent.width-40
        x:20
        y:header.height+10
        height:parent.height-y-10
        color:"#00000000"
        ScrollView{
            clip:true
            width: parent.width-310
            height:parent.height
            Grid{
                columns: 1
                rowSpacing: 20
                x:0
                y:0
                width:mainitems.width-310
                height: childrenRect.height
                HomePageFavourites{width:parent.width;height:childrenRect.height}
                HomePagePinned{width:parent.width;height:childrenRect.height}
                HomePageTagged{width:parent.width;height:childrenRect.height}
            }
        }
        ScrollView{
            clip:true
            x:parent.width-300
            y:0
            width:300
            height:parent.height
            Grid{
                columns:1
                rowSpacing: 20
                y:0
                x:0
                width:300
                height:parent.height
                HomePageRecent{width:parent.width;height:childrenRect.height}
                HomePageDisks{width:parent.width;height: childrenRect.height}
            }
        }
    }
}
