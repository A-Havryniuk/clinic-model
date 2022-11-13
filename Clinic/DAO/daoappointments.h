#ifndef DAOAPPOINTMENTS_H
#define DAOAPPOINTMENTS_H
#include <QtSql>
#include <QSqlDatabase>
#include "Entities/entityappointments.h"
#include "dao.h"
#include <QSqlQuery>
class DAOAppointments : public DAO
{
    QSqlDatabase db;
public:
    DAOAppointments();
    ~DAOAppointments();
    bool addAppointment(QString patEmail, QString docEmail, QDate date, QTime time);
    QSqlQueryModel* getMostPopularDoc();
    QList<QTime>* getFullSlotsByDateAndDocEmail(QDate date, QString email);
    QSqlQueryModel* getPatientAppointments(QString patientEmail);
    bool deleteAppointment(QString docEmail, QString dateTime);
    QSqlQueryModel* getPatAppByDay(QString email, QString date);
    QSqlQueryModel* getDocAppointments(QString docEmail);
    bool makeAppDone(QString docEmail, QString timeslot);
    QSqlQueryModel *getRangeApp(QString docEmail, QString date1, QString date2);
    int getCompletedTask(QString docEmail);
    int getMissedTask(QString docEmail);
};

#endif // DAOAPPOINTMENTS_H
