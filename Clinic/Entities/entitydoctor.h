#ifndef ENTITYDOCTOR_H
#define ENTITYDOCTOR_H
#include <QString>
#include "user.h"
class EntityDoctor : public User
{
    int id;
    QString email;
    QString firstName;
    QString lastName;
    int age;
    int yearsOfExperience;
    int specId;
public:
    EntityDoctor();
    EntityDoctor(int id, const QString &email, const QString &firstName, const QString &lastName, int age, int yearsOfExperience, int specId);

    int getId();
    const QString &getEmail() const;
    const QString &getFirstName() const;
    const QString &getLastName() const;
    int getAge() const;
    int getYearsOfExperience() const;
    int getSpecId() const;
    void setId(int newId);
    void setEmail(const QString &newEmail);
    void setFirstName(const QString &newFirstName);
    void setLastName(const QString &newLastName);
    void setAge(int newAge);
    void setYearsOfExperience(int newYearsOfExperience);
    void setSpecId(int newSpecId);
};

#endif // ENTITYDOCTOR_H
