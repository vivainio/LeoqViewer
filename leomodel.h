#ifndef LEOMODEL_H
#define LEOMODEL_H

#include <QObject>
#include "roleitemmodel.h"
#include "leoqdb.h"
class LeoEngine : public QObject
{
    Q_OBJECT
    RoleItemModel* m_searchModel;

public:
    explicit LeoEngine(QObject *parent = 0);

    Q_PROPERTY (QObject* searchModel READ searchModel)


    QObject* searchModel() const;

signals:
    void searchReady();

public slots:

    QVariantList startSearch(const QString& pat);
    QVariantList childNodes(int parent);
    void openDb(const QString& fname);

private:

    LeoqDb* m_db;

};

#endif // LEOMODEL_H
