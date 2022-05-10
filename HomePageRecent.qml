import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import RecentListModel 1.0
Rectangle {
    color:"#00000000"
    Label {
        font.family: 'Product Sans'
        text:"Recently Opened"
        color:"white"
        x:0
        y:0
        font.pixelSize: 17
        font.bold: true
    }
    GridView {
        x:0
        y:27
        cellWidth:parent.width
        cellHeight:82
        model:RecentListModel{
            list:recentlist
        }
        clip:true
        delegate: HomePageCard{cardLabel:model.label;cardIcon: model.icon;description: model.description}
        height:childrenRect.height
        width:parent.width
    }
}
