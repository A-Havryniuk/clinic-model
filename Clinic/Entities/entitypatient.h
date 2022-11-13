#ifndef ENTITYPATIENT_H
#define ENTITYPATIENT_H
#include <QString>
#include "user.h"

class EntityPatient : public User
{
    int id;
    QString email;
    QString firstName;
    QString lastName;
    int age;
    char sex;
public:

    EntityPatient();
    void setId(int id);
    void setEmail(QString email);
    void setFirstName(QString firstName);
    void setLastName(QString lastName);
    void setAge(int age);
    void setSex(char sex);
    int getId() const;
    const QString &getEmail() const;
    const QString &getFirstName() const;
    const QString &getLastName() const;
    int getAge() const;
    char getSex() const;
};

#endif // ENTITYPATIENT_H
