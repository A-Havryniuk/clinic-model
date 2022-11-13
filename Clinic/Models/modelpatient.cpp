#include "modelpatient.h"

const QString &ModelPatient::getFirstName() const
{
    return firstName;
}

const QString &ModelPatient::getLastName() const
{
    return lastName;
}

const QString &ModelPatient::getEmail() const
{
    return email;
}

int ModelPatient::getAge() const
{
    return age;
}

char ModelPatient::getSex() const
{
    return sex;
}

ModelPatient::ModelPatient()
{

}

ModelPatient::ModelPatient(QString firstName, QString lastName, QString email, int age, char sex) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->sex = sex;
}
