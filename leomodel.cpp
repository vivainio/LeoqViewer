#include "leomodel.h"

#include "leoqdb.h"
#include "leonode.h"

LeoEngine::LeoEngine(QObject *parent) :
    QObject(parent)
{
    m_searchModel =  LeoNode::createModel();
    m_db = new LeoqDb();

}

QObject * LeoEngine::searchModel() const
{
    return m_searchModel;
}

QVariantList LeoEngine::startSearch(const QString &pat)
{
    QVariantList vl = m_db->searchHeaders(pat);
    return vl;
}

QVariantList LeoEngine::childNodes(int parent)
{
    return m_db->childNodes(parent);
}

void LeoEngine::openDb(const QString &fname)
{
    m_db->openDb(fname);
}



