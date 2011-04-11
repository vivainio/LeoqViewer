#ifndef LEOMODEL_H
#define LEOMODEL_H

#include <QObject>
#include "roleitemmodel.h"

class LeoModel : public QObject
{
    Q_OBJECT
    RoleItemModel* m_searchModel;

public:
    explicit LeoModel(QObject *parent = 0);

    Q_PROPERTY (QObject* searchModel READ searchModel)

    QObject* searchModel() const;

signals:

public slots:

};

#endif // LEOMODEL_H
