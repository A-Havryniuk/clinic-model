#ifndef DAOPATIENT_H
#define DAOPATIENT_H
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "Entities/entitypatient.h"
#include "Models/modelpatient.h"
#include <QMessageBox>
#include "dao.h"
#include "Exceptions/dbexception.h"

class DAOPatient : public DAO
{
    QSqlDatabase db;
public:
    DAOPatient();
    ~DAOPatient();
    bool addPatient(ModelPatient* patient);
    EntityPatient* getByEmail(QString email);
    QSqlQueryModel* getAllPatients();
};

#endif // DAOPATIENT_H
