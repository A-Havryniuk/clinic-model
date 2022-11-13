#include "entityspecialities.h"

int EntitySpecialities::getId() const
{
    return id;
}

void EntitySpecialities::setId(int newId)
{
    id = newId;
}

const QString &EntitySpecialities::getName() const
{
    return name;
}

void EntitySpecialities::setName(const QString &newName)
{
    name = newName;
}

EntitySpecialities::EntitySpecialities()
{

}
