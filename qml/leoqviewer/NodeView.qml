import QtQuick 1.0
import com.meego 1.0
import com.nokia.extras 1.0


Page {
    id: root
    ListModel {
        id: nodeList
        ListElement {
            title: "Test 1"
            subtitle: "sub"
        }
    }

    function setParent(parentid) {
        var children = leoEngine.childNodes(parentid)

        nodeList.clear()
        for (var i in children) {
            var v = children[i]
            nodeList.append({

                            title : v.h,
                            subtitle: "sub"
            })

        }

        //console.log(children)
    }

    ListView {
        anchors {
            top: parent.top; left: parent.left; right: parent.right; bottom: parent.bottom
        }


        model: nodeList

        delegate: ListDelegate {
            titleSize: 22
            property int titleWeight: Font.Normal
            //property color titleColor: theme.inverted ? UI.LIST_TITLE_COLOR_INVERTED : UI.LIST_TITLE_COLOR

            Image {
                source: "image://theme/icon-m-common-drilldown-arrow" + (theme.inverted ? "-inverse" : "")
                anchors.right: parent.right;

                anchors.rightMargin: 16
                anchors.verticalCenter: parent.verticalCenter
            }

            subtitleColor: "#cc6633"
            //onClicked: { openFile(model.page); }
        }
    }


}
