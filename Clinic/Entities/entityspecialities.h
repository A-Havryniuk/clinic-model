#ifndef ENTITYSPECIALITIES_H
#define ENTITYSPECIALITIES_H
#include <QString>

class EntitySpecialities
{
    int id;
    QString name;
public:
    EntitySpecialities();

    int getId() const;
    void setId(int newId);
    const QString &getName() const;
    void setName(const QString &newName);
};

#endif // ENTITYSPECIALITIES_H
