#include "leoqdb.h"
#include <QSqlQuery>
#include <QVariant>
#include "roleitemmodel.h"

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

class LeoNode {

public:

    QString h;
    int bodyid;

    QString body;

    enum NodeRoles {
        RoleH = Qt::UserRole + 1,
        RoleBody,
        RoleGnx

    };

    static RoleItemModel* createModel() {
        QHash<int, QByteArray> roleNames;
        roleNames[RoleH] =  "h";
        roleNames[RoleBody] = "body";
        roleNames[RoleGnx] = "gnx";
        return new RoleItemModel(roleNames);

    }

};

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

void LeoqDb::searchHeaders(const QString &pat, RoleItemModel& mdl)
{
    QSqlQuery q("select id, h from NODES where h like ?");
    q.bindValue(0,QVariant(pat));
    q.exec();

    while (q.next()) {
        int id = q.value(0).toInt();
        QString h = q.value(1).toString();
        QStandardItem* it = new QStandardItem();
        it->setData(h, LeoNode::RoleH);
        mdl.appendRow(it);
    }


}

