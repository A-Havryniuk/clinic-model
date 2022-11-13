#include "entitypatient.h"

int EntityPatient::getId() const
{
    return id;
}

const QString &EntityPatient::getEmail() const
{
    return email;
}

const QString &EntityPatient::getFirstName() const
{
    return firstName;
}

const QString &EntityPatient::getLastName() const
{
    return lastName;
}

int EntityPatient::getAge() const
{
    return age;
}

char EntityPatient::getSex() const
{
    return sex;
}

EntityPatient::EntityPatient()
{

}

void EntityPatient::setId(int id)
{
    this->id = id;
}

void EntityPatient::setEmail(QString email)
{
    this->email = email;
}

void EntityPatient::setFirstName(QString firstName)
{
    this->firstName = firstName;
}

void EntityPatient::setLastName(QString lastName)
{
    this->lastName = lastName;
}

void EntityPatient::setAge(int age)
{
    this->age = age;
}

void EntityPatient::setSex(char sex)
{
    this->sex = sex;
}
