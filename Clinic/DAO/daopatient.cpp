#include "daopatient.h"

DAOPatient::DAOPatient()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("dbtest");
    db.setUserName("root");
    db.setPassword("5239");
    bool isOpen = db.open();
    if(!isOpen)
    {
        QMessageBox::warning(0, QObject::tr("Database Error"),
        db.lastError().text());
        throw new DBException("Connected to data base error.");
    }
}

DAOPatient::~DAOPatient(){
    db.close();
}

bool DAOPatient::addPatient(ModelPatient* patient)
{
    QSqlQuery query;
    QString q = "INSERT INTO patients (email,first_name,last_name,age,sex) VALUES ('"
            +patient->getEmail()+"','"
            +patient->getFirstName()+"','"
            +patient->getLastName()+"','"
            +QString::number(patient->getAge())+"','"
            +patient->getSex()
            +"')";
    if(query.exec())
        return true;
    else {
        throw new DBException("Invalid data. Check all fields.");
    }
}

EntityPatient *DAOPatient::getByEmail(QString email)
{
    EntityPatient* pat = new EntityPatient();
    QSqlQuery query;
    QString  q = "SELECT * FROM patients WHERE email = '"+email+"'";
    query.exec(q);
    if(!query.next()) {
        throw new DBException("The user doesn't exist!");
    }
    else{
        pat->setId(query.value(0).toInt());
        pat->setEmail(query.value(1).toString());
        pat->setFirstName(query.value(2).toString());
        pat->setLastName(query.value(3).toString());
        pat->setAge(query.value(4).toInt());
        pat->setSex(query.value(5).toInt());
    }
    return pat;
}

QSqlQueryModel *DAOPatient::getAllPatients()
{
    QSqlQuery query;
    query.prepare("SELECT email, first_name, last_name, age, sex FROM patients");
    if(query.exec()) {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(query);
        return model;
    } else {
    return nullptr;
    }
}
