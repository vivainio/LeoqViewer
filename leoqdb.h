#ifndef LEOQDB_H
#define LEOQDB_H

#include <QObject>
#include <QSqlDatabase>

class LeoqDb : public QObject
{
    Q_OBJECT
public:
    explicit LeoqDb(QObject *parent = 0);
    void openDb(const QString& fname);

signals:

public slots:
    void searchHeaders(const QString& pat);

private:
    QSqlDatabase m_db;

};

#endif // LEOQDB_H
