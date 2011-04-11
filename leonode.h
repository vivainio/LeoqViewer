#ifndef LEONODE_H
#define LEONODE_H

#include <QString>

class RoleItemModel;

class LeoNode {

    LeoNode();
public:

    QString h;
    int bodyid;

    QString body;

    enum NodeRoles {
        RoleH = Qt::UserRole + 1,
        RoleBody,
        RoleGnx

    };

    static RoleItemModel* createModel();

};

#endif // LEONODE_H
