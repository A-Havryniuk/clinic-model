#include "serviceuser.h"

ServiceUser::ServiceUser()
{
    daop = new DAOPatient();
    daod = new DAODoctor();
}

User* ServiceUser::signIn(QString email)
{
    User* user;
    if(!email.contains("@")) {
        throw new std::invalid_argument("Illegal argument!\n You entered:");
    }
    try {
    if(email.contains("@clinic.com")) {
       user = daod->getByEmail(email);
    } else {
         user = daop->getByEmail(email);
    }
    } catch (DBException* ex) {
        throw new std::invalid_argument(ex->what());
    }
    return user;
}
