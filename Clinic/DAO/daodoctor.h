#ifndef DAODOCTOR_H
#define DAODOCTOR_H
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "Entities/entitydoctor.h"
#include "Models/modeldoctor.h"
#include "dao.h"
#include <QSqlQueryModel>
#include "Exceptions/dbexception.h"
class DAODoctor : public DAO
{
    QSqlDatabase db;
public:
    DAODoctor();
    ~DAODoctor();
    bool addDoctor(ModelDoctor* doc, int spec_id);
    EntityDoctor* getById(int id);
    EntityDoctor* getByEmail(QString email);
    QSqlQueryModel* getAllDoctors();
    QSqlQueryModel* getDoctorsByFilterParam(int from, int to, QString spec);
};

#endif // DAODOCTOR_H
