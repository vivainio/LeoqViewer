import QtQuick 1.0
import com.meego 1.0

PageStackWindow {
    id: rootWindow
   // platformStyle: defaultStyle
    NodeSearch {
        id: nodeSearch
    }

   initialPage: nodeSearch

}
