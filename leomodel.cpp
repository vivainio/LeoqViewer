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

void LeoEngine::startSearch(const QString &pat)
{
    m_db->searchHeaders(pat, m_searchModel);

}
