#include "modeldoctor.h"

ModelDoctor::ModelDoctor(EntityDoctor *doc)
{
    this->firstName = doc->getFirstName();
    this->lastName = doc->getLastName();
    this->email = doc->getEmail();
    this->age = doc->getAge();
    this->yearsOfExp = doc->getYearsOfExperience();
}

ModelDoctor::ModelDoctor()
{
    //have a nice day ;)
}

QString ModelDoctor::getFirstName()
{
    return firstName;
}

void ModelDoctor::setFirstName(QString newFirstName)
{
    firstName = newFirstName;
}

QString ModelDoctor::getLastName()
{
    return lastName;
}

void ModelDoctor::setLastName(QString newLastName)
{
    lastName = newLastName;
}
QString ModelDoctor::getEmail()
{
    return email;
}

void ModelDoctor::setEmail(QString newEmail)
{
    email = newEmail;
}

int ModelDoctor::getAge()
{
    return age;
}

void ModelDoctor::setAge(int newAge)
{
    age = newAge;
}

int ModelDoctor::getYearsOfExp()
{
    return yearsOfExp;
}

void ModelDoctor::setYearsOfExp(int newYearsOfExp)
{
    yearsOfExp = newYearsOfExp;
}

QString ModelDoctor::getSpec()
{
    return spec;
}

void ModelDoctor::setSpec(QString newSpec)
{
    spec = newSpec;
}


