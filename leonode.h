#ifndef LEONODE_H
#define LEONODE_H

#include <QString>
#include <QObject>

class RoleItemModel;

class LeoNode : public QObject {
    Q_OBJECT

public:
    LeoNode();
    QString m_headstring;

    Q_PROPERTY(QString headstring READ getHeadstring WRITE getHeadstring)
    int bodyid;

    QString body;

    enum NodeRoles {
        RoleH = Qt::UserRole + 1,
        RoleBody,
        RoleGnx

    };

    static RoleItemModel* createModel();

    QString getHeadstring() const
    {
        return m_headstring;
    }
public slots:
    void getHeadstring(QString arg)
    {
        m_headstring = arg;
    }
};

#endif // LEONODE_H
