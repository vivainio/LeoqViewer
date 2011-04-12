import QtQuick 1.0
import com.meego 1.0
import com.nokia.extras 1.0


Page {
    id: root
    Button {
        id: bSearch
        text: "S"
        width: 64
        anchors {
            top: parent.top
            right: parent.right

        }
        onClicked: {
            leoEngine.startSearch(tSearchText.text)
            var mdl = leoEngine.searchModel
            for (var i=0; i < mdl.count; i++) {
                var el = mdl.at(i)
                console.log(el)


            }
        }
    }

    Component.onCompleted: {
        console.log(leoEngine.searchModel)
        ;
    }

    TextField {
        id: tSearchText

        anchors {
            top: parent.top
            left: parent.left
            right: bSearch.left
        }

    }

    ListModel {
        id: pagesModel
        ListElement {
            title: "Test 1"
            subtitle: "This is subtitle 1"
        }
        ListElement {
            title: "Test 2"
            buttonText: "Click Me"
            subtitle: "This is subtitle 2"
        }
        ListElement {
            title: "Test 3"
            buttonText: "Click Me More"
            subtitle: "This is subtitle 3"
        }
    }

    ListView {
        anchors {
            top: tSearchText.bottom; left: parent.left; right: parent.right; bottom: parent.bottom
        }


        model: pagesModel

        delegate: ListDelegate {
            Image {
                source: "image://theme/icon-m-common-drilldown-arrow" + (theme.inverted ? "-inverse" : "")
                anchors.right: parent.right;

                anchors.rightMargin: 16
                anchors.verticalCenter: parent.verticalCenter
            }

            subtitleColor: "#cc6633"
            onClicked: { openFile(model.page); }
        }
    }


}
