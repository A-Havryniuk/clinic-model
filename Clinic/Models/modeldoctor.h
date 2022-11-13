#ifndef MODELDOCTOR_H
#define MODELDOCTOR_H
#include <QString>
#include "Entities/entitydoctor.h"

class ModelDoctor
{
    QString firstName;
    QString lastName;
    QString email;
    int age;
    int yearsOfExp;
    QString spec;
public:
    ModelDoctor(EntityDoctor* doc);
    ModelDoctor();
    QString getFirstName();
    void setFirstName(QString mewFirstName);
    QString getLastName();
    void setLastName(QString newLastName);
    QString getEmail();
    void setEmail(QString newEmail);
    int getAge();
    void setAge(int newAge);
    int getYearsOfExp();
    void setYearsOfExp(int newYearsOfExp);
    QString getSpec();
    void setSpec(QString newSpec);
};

#endif // MODELDOCTOR_H
