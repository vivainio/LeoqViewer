#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"

#include "leoqdb.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/leoqviewer/main.qml"));
    viewer.showExpanded();

    LeoqDb* db = new LeoqDb();
    db->openDb("/home/ville/treefrag.db");

    return app.exec();
}