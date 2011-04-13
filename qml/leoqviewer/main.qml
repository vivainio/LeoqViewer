import QtQuick 1.0
import com.meego 1.0

PageStackWindow {
    id: rootWindow
   // platformStyle: defaultStyle
    property Component nodeViewComponent
    NodeSearch {
        id: nodeSearch
    }


    NodeView {
        id: nodeView
    }

    function pushPage(parentid) {
        var p = pageStack.push(nodeViewComponent)
        console.log(p)
        p.setParent(parentid)

    }

    Component.onCompleted: {
        nodeViewComponent = Qt.createComponent("NodeView.qml")
        leoEngine.openDb("/home/ville/treefrag.db")
        pushPage(0)
        //nodeView.setParent(0)
    }

   initialPage: nodeView

}
