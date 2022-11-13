#ifndef DAOSPECIALITIES_H
#define DAOSPECIALITIES_H
#include <QtSql>
#include <QSqlDatabase>
#include "dao.h"
#include "Models/modelspeciality.h"
#include "Entities/entityspecialities.h"
#include <QList>
class DAOSpecialities : public DAO
{
    QSqlDatabase db;
public:
    DAOSpecialities();
    ~DAOSpecialities();
    QList<ModelSpeciality>* getAllSpeciality();
    bool addSpec(QString name);
    int getSpecId(QString name);
    EntitySpecialities* getSpecById(int id);
};

#endif // DAOSPECIALITIES_H
