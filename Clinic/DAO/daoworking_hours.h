#ifndef DAOWORKING_HOURS_H
#define DAOWORKING_HOURS_H
#include <QSqlDatabase>
#include <QTableView>
#include <QtSql>
#include "dao.h"
class DAOWorking_hours : public DAO
{
    QSqlDatabase db;
public:
    DAOWorking_hours();
    ~DAOWorking_hours();
    bool add(int docId, QString day, QTime start, QTime end);
    QStringList* getWorkingDays(QString email);
    QList<QTime> *getWorkingHoursByDay(QString docEmail, QString day);
};

#endif // DAOWORKING_HOURS_H
