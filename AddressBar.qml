import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.15
Item {
    signal backButtonPressed()
    signal forwardButtonPressed()
    signal listButtonPressed()
    signal gridButtonPressed()
    signal detailButtonPressed()
    signal shareButtonPressed()
    id:itemContainer
    Rectangle{
        color:"#00000000"
        anchors.fill: parent

        //Back and forward buttons
        Button{
            id:backbutton
            x:10
            y:10
            onClicked: {
                backButtonPressed();
            }
            height:parent.height-20
            icon.name:"draw-arrow-back"
            icon.height: 16
            icon.color: "white"
            icon.width: 16
            width:height*1.8
            background:Rectangle{
                color:"#33ffffff"
                radius:5
            }
        }
        Button{
            onClicked: {
                forwardButtonPressed();
            }
            id:forwardbutton
            y:10
            x:parent.height+20
            height:parent.height-20
            icon.name:"draw-arrow-forward"
            icon.height: 16
            icon.color: "white"
            icon.width: 16
            width:height*1.8
            background:Rectangle{
                color:"#33ffffff"
                radius:5
            }
        }
        //Layout Buttons
        Rectangle{
            id:viewbuttons
            x:forwardbutton.width+backbutton.width+20+10
            y:10
            width:height*3
            color:"#33ffffff"
            radius:5
            clip:true
            height:parent.height-20
            Button{
                id:gridviewbutton
                width:parent.height
                onClicked: {
                    gridButtonPressed();
                }
                height: parent.height
                x:0
                y:0
                icon.name: "view-grid"
                icon.width: 16
                icon.height: 16
                icon.color: "white"
                background: Rectangle{
                    color:"#00000000"
                    radius: 5
                }
            }
            Button{
                id:listviewbutton
                onClicked: {
                    listButtonPressed();
                }
                width:parent.height
                height: parent.height
                x:gridviewbutton.width
                y:0
                icon.name: "fm-compact"
                icon.width: 16
                icon.height: 16
                icon.color: "white"
                background: Rectangle{
                    color:"#00000000"
                    radius: 5
                }
            }
            Button{
                id:detailviewbutton
                width:parent.height
                onClicked: {
                    detailButtonPressed();
                }
                height: parent.height
                x:gridviewbutton.width+listviewbutton.width
                y:0
                icon.name: "fm-details"
                icon.width: 16
                icon.height: 16
                icon.color: "white"
                background: Rectangle{
                    color:"#00000000"
                    radius: 5
                }
            }
        }
        //Share Button
        Button{
            id:sharebutton
            x:backbutton.width+forwardbutton.width+viewbuttons.width+40
            width:parent.height
            onClicked: {
                shareButtonPressed();
            }
            height:parent.height-20
            y:10
            icon.name:"forward"
            icon.color:"white"
            icon.height:32
            icon.width:32
            background:Rectangle{
                color:"#33ffffff"
                radius:5
            }
        }
        Rectangle{
            id:addressbox
            width:parent.width - (backbutton.width + forwardbutton.width + sharebutton.width + viewbuttons.width + 90 + tagbutton.width + morebutton.width + searchbox.width)
            height: parent.height-20
            x:backbutton.width + forwardbutton.width + sharebutton.width + viewbuttons.width + 50
            y:10
            color: "#33ffffff"
            radius:5
            TextField{
                x:0
                y:0
                height:parent.height
                width:parent.width-parent.height
                placeholderText: "Location of Directory"
                placeholderTextColor: "#66ffffff"
                color: "white"
                text:"Home"
                font.bold: true
                font.family: 'Product Sans'
                font.pixelSize: height/2
                background: Rectangle{color:"#00000000"}
            }
            Button{
                y:0
                width:parent.height
                height: parent.height
                x:parent.width-parent.height
                background: Rectangle{color:"#00000000"}
                icon.name: "reload_page"
                icon.width: 16
                icon.height: 16
                icon.color: "white"
            }
        }
        Button {
            id:tagbutton
            x:backbutton.width + forwardbutton.width + sharebutton.width + viewbuttons.width + addressbox.width + 60
            y:10
            height:parent.height-20
            icon.name:"tag"
            icon.height: 16
            icon.color: "white"
            icon.width: 16
            width:height
            background:Rectangle{
                color:"#33ffffff"
                radius:5
            }
        }

        Button {
            id:morebutton
            x:backbutton.width + forwardbutton.width + sharebutton.width + viewbuttons.width + addressbox.width + tagbutton.width + 70
            y:10
            height:parent.height-20
            icon.name:"view-more"
            icon.height: 16
            icon.color: "white"
            icon.width: 16
            width:height
            background:Rectangle{
                color:"#33ffffff"
                radius:5
            }
        }
        Rectangle{
            id:searchbox
            width:parent.width/6
            height: parent.height-20
            x:backbutton.width + forwardbutton.width + sharebutton.width + viewbuttons.width + addressbox.width + tagbutton.width + morebutton.width + 80
            y:10
            color: "#33ffffff"
            radius:5
            TextField{
                x:0
                y:0
                height:parent.height
                width:parent.width-parent.height
                placeholderText: "Find a file"
                placeholderTextColor: "#66ffffff"
                color: "white"
                font.bold: true
                font.family: 'Product Sans'
                font.pixelSize: height/2
                background: Rectangle{color:"#00000000"}
            }
            Button{
                y:0
                width:parent.height
                height: parent.height
                x:parent.width-parent.height
                background: Rectangle{color:"#00000000"}
                icon.name: "stock_search"
                icon.width: 16
                icon.height: 16
                icon.color: "white"
            }
        }
    }
}
