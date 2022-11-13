#ifndef HANDLE_SIGN_UP_H
#define HANDLE_SIGN_UP_H
#include <QString>
#include "Models/modelpatient.h"
class handle_sign_up
{
public:
    handle_sign_up();
    void signUpPatient(QString firstname,QString lastName, QString email, int age, char sex);
};

#endif // HANDLE_SIGN_UP_H
