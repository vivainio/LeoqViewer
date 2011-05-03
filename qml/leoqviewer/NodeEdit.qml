import QtQuick 1.0
import com.meego 1.0
import com.nokia.extras 1.0


Page {
    tools: commonTools

    function setNodeInfo(ni) {
        priv.nodeInfo = ni
        tBody.text = ni.b
        tHeader.text = ni.h
    }

    QtObject {
        id: priv
        property variant nodeInfo

    }


    Flickable {
        id: container
        anchors.fill: parent
        anchors.topMargin: 6
        anchors.leftMargin: 6
        anchors.rightMargin: 6
        anchors.bottomMargin: 6
        contentWidth: col.width
        contentHeight: col.height
        flickableDirection: Flickable.VerticalFlick
        pressDelay: 100
        Column {
            id: col
            width: container.width

            TextField {
                id: tHeader
                anchors {
                    //top: parent.top
                    left: parent.left
                    right: parent.right
                }
            }

            TextArea {
                id: tBody
                anchors {
                    left: parent.left
                    right: parent.right
                    //bottom: parent.bottom
                }
            }
        }
    }



}
