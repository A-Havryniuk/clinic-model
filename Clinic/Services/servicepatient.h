#ifndef SERVICEPATIENT_H
#define SERVICEPATIENT_H
#include "DAO/daopatient.h"
#include "DAO/daodoctor.h"
#include "DAO/daospecialities.h"
#include "DAO/daoappointments.h"
#include "DAO/daoworking_hours.h"
#include "Models/modelpatient.h"
#include "Models/modelspeciality.h"
#include "Services/serviceuser.h"
#include <QTableView>
#include <QList>
#include <stdexcept>
class ServicePatient : public ServiceUser
{
    DAOPatient* daop;
    DAODoctor* daod;
    DAOSpecialities* daosp;
    DAOAppointments* daoapp;
    DAOWorking_hours* daowh;

public:
    ServicePatient();
    void signUp(QString firstName, QString lastName, QString email, int age, char sex);
    void printDoctorsTable(QTableView* view);
    void printDoctorsByFilterParam(QTableView* view, int from, int to, QString speciality);
    QList<ModelSpeciality>* getListOfSpeciality();
    void printMostPopularDoctor(QTableView*);
    ModelDoctor* getDocByEmail(QString email);
    QList<QTime>* getFreeHours(QString email, QDate date);
    QStringList* getWorkingDays(QString email);
    void getAppointments(QString email, QTableView* view);
    void deleteAppointment(QString DocEmail, QDateTime datetime);
    void getAppByDay(QTableView* view, QDate date, QString email);
};

#endif // SERVICEPATIENT_H
