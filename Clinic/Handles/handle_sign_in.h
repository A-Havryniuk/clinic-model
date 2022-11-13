#ifndef HANDLE_SIGN_IN_H
#define HANDLE_SIGN_IN_H
#include <QString>
#include "Services/serviceuser.h"
#include "Services/servicepatient.h"
#include "View/viewdoctor.h"
#include "View/viewpatient.h"
#include "View/registration_form_patient.h"
class Handle_sign_in
{
    QString email;
    ServiceUser* service_user;
    ServicePatient* service;
    ViewDoctor* viewdoc;
    ViewPatient* viewpat;

    registration_form_patient* form;
public:
    Handle_sign_in();
    bool execute(QString email);
    void registration();
    bool signUpPatient(QString first, QString last, QString email, int age, char sex);
};

#endif // HANDLE_SIGN_IN_H
