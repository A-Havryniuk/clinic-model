#include "entitydoctor.h"

int EntityDoctor::getId()
{
    return id;
}

const QString &EntityDoctor::getEmail() const
{
    return email;
}

const QString &EntityDoctor::getFirstName() const
{
    return firstName;
}

const QString &EntityDoctor::getLastName() const
{
    return lastName;
}

int EntityDoctor::getAge() const
{
    return age;
}

int EntityDoctor::getYearsOfExperience() const
{
    return yearsOfExperience;
}

int EntityDoctor::getSpecId() const
{
    return specId;
}

void EntityDoctor::setId(int newId)
{
    id = newId;
}

void EntityDoctor::setEmail(const QString &newEmail)
{
    email = newEmail;
}

void EntityDoctor::setFirstName(const QString &newFirstName)
{
    firstName = newFirstName;
}

void EntityDoctor::setLastName(const QString &newLastName)
{
    lastName = newLastName;
}

void EntityDoctor::setAge(int newAge)
{
    age = newAge;
}

void EntityDoctor::setYearsOfExperience(int newYearsOfExperience)
{
    yearsOfExperience = newYearsOfExperience;
}

void EntityDoctor::setSpecId(int newSpecId)
{
    specId = newSpecId;
}

EntityDoctor::EntityDoctor()
{

}

EntityDoctor::EntityDoctor(int id, const QString &email, const QString &firstName, const QString &lastName, int age, int yearsOfExperience, int specId) : id(id),
    email(email),
    firstName(firstName),
    lastName(lastName),
    age(age),
    yearsOfExperience(yearsOfExperience),
    specId(specId)
{}
