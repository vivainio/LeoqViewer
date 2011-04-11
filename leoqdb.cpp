#include "leoqdb.h"

LeoqDb::LeoqDb(QObject *parent) :
    QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");

}


void LeoqDb::openDb(const QString &fname)
{



}
