#include "leomodel.h"

#include "leoqdb.h"
#include "leonode.h"

LeoModel::LeoModel(QObject *parent) :
    QObject(parent)
{
    m_searchModel =  LeoNode::createModel();
}

QObject * LeoModel::searchModel() const
{
    return m_searchModel;
}
