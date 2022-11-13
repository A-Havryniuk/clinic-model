#ifndef SERVICEUSER_H
#define SERVICEUSER_H
#include <QString>
#include "DAO/daopatient.h"
#include "DAO/daodoctor.h"
#include "Entities/user.h"
#include "Models/modelpatient.h"
#include "Models/modeldoctor.h"
#include <stdexcept>
#include "Exceptions/dbexception.h"
class ServiceUser
{
    DAOPatient* daop;
    DAODoctor* daod;
public:
    ServiceUser();
    User* signIn(QString email);
};

#endif // SERVICEUSER_H
