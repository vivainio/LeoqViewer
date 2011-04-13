import QtQuick 1.0
import com.meego 1.0

PageStackWindow {
    id: rootWindow
   // platformStyle: defaultStyle
    NodeSearch {
        id: nodeSearch
    }

    NodeView {
        id: nodeView
    }

    Component.onCompleted: {
        leoEngine.openDb("/home/ville/treefrag.db")
        nodeView.setParent(0)
    }

   initialPage: nodeView

}
