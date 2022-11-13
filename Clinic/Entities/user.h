#ifndef USER_H
#define USER_H
#include <QString>

class User
{
    QString email;
    QString firstName;
    QString lastName;
public:
    User();
    virtual const QString &getEmail() const;
};

#endif // USER_H
