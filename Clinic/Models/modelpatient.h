#ifndef MODELPATIENT_H
#define MODELPATIENT_H
#include <QString>

class ModelPatient
{
    QString firstName;
    QString lastName;
    QString email;
    int age;
    char sex;
public:
    ModelPatient();
    ModelPatient(const QString firstName, const QString lastName, const QString email, int age, char sex);

    void setFirstName(const QString &newFirstName);
    void setLastName(const QString &newLastName);
    void setEmail(const QString &newEmail);
    void setAge(int newAge);
    void setSex(char newSex);
    const QString &getFirstName() const;
    const QString &getLastName() const;
    const QString &getEmail() const;
    int getAge() const;
    char getSex() const;
};

#endif // MODELPATIENT_H
