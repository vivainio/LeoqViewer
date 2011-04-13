#include "leoqdb.h"
#include <QSqlQuery>
#include <QVariant>
#include "roleitemmodel.h"
#include <QDebug>
#include <QSqlError>
#include "leonode.h"
/*

treefrag_schema = """
drop table if exists blobs;

CREATE TABLE blobs (
 id INTEGER PRIMARY KEY,
 format INTEGER,
 data BLOB
);

drop table if exists nodes;

CREATE TABLE nodes (
 id INTEGER PRIMARY KEY,
 gnx VARCHAR(20) NOT NULL,

 h TEXT,
 bodyid INTEGER REFERENCES blobs(id)
);

drop table if exists edges;

CREATE TABLE edges (
 a INTEGER NOT NULL REFERENCES nodes(id),
 b INTEGER NOT NULL REFERENCES nodes(id),
 pos INTEGER NOT NULL,
 PRIMARY KEY (a, b, pos)
);

CREATE INDEX a_idx ON edges (a);
CREATE INDEX b_idx ON edges (b);
"""

*/

namespace
{
    void doexec(QSqlQuery& q) {
        bool r = q.exec();
        if (!r)
            qDebug() << "Db error :" << q.lastError();
        else
            qDebug() << "ok exec";
    }
}

LeoqDb::LeoqDb(QObject *parent) :
    QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");

}


void LeoqDb::openDb(const QString &fname)
{
    m_db.setDatabaseName(fname);
    bool r = m_db.open();

}

QVariantList LeoqDb::searchHeaders(const QString &pat)
{

    QSqlQuery q("select id, h from NODES"); // where h like ?");
    //q.bindValue(0,QVariant(pat));
    doexec(q);
    QVariantList res;
    while (q.next()) {
        QVariantMap ent;
        ent["id"] = q.value(0);
        ent["h"] = q.value(1);
        qDebug() << ent;

        res.append(ent);
    }
    return res;
}

