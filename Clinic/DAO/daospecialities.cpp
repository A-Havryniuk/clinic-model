#include "daospecialities.h"

DAOSpecialities::DAOSpecialities()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("dbtest");
    db.setUserName("root");
    db.setPassword("5239");
    bool isOpen = db.open();
    if(!isOpen)
    {
//throw a new data base exception
    }
}

DAOSpecialities::~DAOSpecialities() {
    db.close();
}

QList<ModelSpeciality>* DAOSpecialities::getAllSpeciality()
{
    QList<ModelSpeciality>* list = new QList<ModelSpeciality>();
    QString q = "SELECT speciality FROM specialities";
    QSqlQuery query;
    query.prepare(q);
    if(query.exec()) {
        while(query.next()) {
            ModelSpeciality model(query.value(0).toString());
            list->append(model);
        }
        return list;
    }
    else {
        delete list;
        return nullptr;
    }
}

bool DAOSpecialities::addSpec(QString name)
{
    QSqlQuery query;
    query.prepare("INSERT INTO specialities (speciality) VALUES ('"+name+"');");
    return query.exec();
}

int DAOSpecialities::getSpecId(QString name)
{
    QSqlQuery query;
    QString p = "";
    p += "SELECT id FROM specialities WHERE speciality = '"+name+"';";
    query.prepare(p);
    if(query.exec()) {
        query.next();
       return query.value(0).toInt();
    } else {
        return -1;
    }
}

EntitySpecialities *DAOSpecialities::getSpecById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT speciality FROM specialities WHERE id ='"+QString::number(id)+"';");
    if(query.exec()) {
        query.next();
        EntitySpecialities* speciality = new EntitySpecialities();
        speciality->setId(id);
        speciality->setName(query.value(0).toString());
        return speciality;
    } else {
        return nullptr;
    }
}
