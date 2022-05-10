import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import Backend 1.0
ApplicationWindow {
    width: 800
    height: 600
    visible: true
    title: qsTr("File Manager")
    flags:Qt.WA_TranslucentBackground
    color:"#88000000"
    SwipeView{
        id:maalmasala
        width:parent.width
        x:0
        y:50
        Component.onCompleted: {currentIndex = 0}
        height:parent.height-50
        HomePage{color:"#00000000"}
        ContentPage{}
        //currentIndex:0
    }

   //HomePage{

       /*width:parent.width
       x:0
       y:0
       height:parent.height*/
   //}

   AddressBar{
       width:parent.width
       x:0
       y:0
       height:50
       onBackButtonPressed:{
            var currentViewPageIndex = maalmasala.currentIndex;
            var totalItems = maalmasala.count - 1;
            if(currentViewPageIndex == 0){
                console.log("You are on first Page");
            } else {
                maalmasala.currentIndex -= 1;
            }
       }
       onForwardButtonPressed: {
           var currentViewPageIndex = maalmasala.currentIndex;
           var totalItems = maalmasala.count - 1;
           if(currentViewPageIndex == totalItems){
               console.log("You are on last Page");
           } else {
               maalmasala.currentIndex += 1;
           }
      }
   }/*
   SideBar{
       height:parent.height-50
       x:0
       y:50
       width:250
   }*/
}
