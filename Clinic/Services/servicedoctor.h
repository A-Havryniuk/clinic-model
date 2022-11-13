#ifndef SERVICEDOCTOR_H
#define SERVICEDOCTOR_H

#include <QTableView>
#include <QList>
#include "Services/serviceuser.h"
#include "Models/modelspeciality.h"
#include "Entities/entityspecialities.h"
#include "DAO/daoappointments.h"
#include "DAO/daospecialities.h"
#include "DAO/daopatient.h"
#include "DAO/daodoctor.h"
#include "DAO/daoworking_hours.h"
#include <stdexcept>

class ServiceDoctor : public ServiceUser
{
    DAOPatient* daop;
    DAODoctor*  daod;
    DAOSpecialities* daosp;
    DAOAppointments* daoapp;
    DAOWorking_hours* daowh;
    const int secsPerHour = 3600;
public:
    ServiceDoctor();
    void printPatientsTable(QTableView* view);
    void printDoctorsTable(QTableView* view);
    QList<ModelSpeciality>* getListOfSpeciality();
    void addDoc(QString f, QString l, QString em, int age, int exp, QString spec, QString newSpec);
    void addWorkingHours(QString email, QStringList days, QTime start, QTime end);
    void fillWithFreeHours(QString day, QDate date, QString docEmail, QComboBox* comboBox);
    void addAppointment(QString docEm, QString patEm, QDate date, QTime time);
    void getAppointments(QTableView* view, QString email);
    void makeDone(QDateTime datetime,  QString email);
    void getRangeAppointments(QTableView* view, QString email, QDate date1, QDate date2);
    int getCompletedTask(QString docEmail);
    int getMissedTask(QString docEmail);
};

#endif // SERVICEDOCTOR_H
