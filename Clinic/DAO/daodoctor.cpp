#include "daodoctor.h"
#include <QMessageBox>
DAODoctor::DAODoctor()
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
//throw a new data base exception
    }
}

DAODoctor::~DAODoctor() {
    db.close();
}

bool DAODoctor::addDoctor(ModelDoctor* doc, int spec_id)
{
    QString p = "";
    p+="insert into doctors (email, first_name, last_name, age, years_of_experience, speciality_id) VALUES ('";
    p+=doc->getEmail();
    p+="','";
    p+=doc->getFirstName();
    p+="','";
    p+=doc->getLastName();
    p+="','";
    p+=QString::number(doc->getAge());
    p+="','";
    p+=QString::number(doc->getYearsOfExp());
    p+="','";
    p+=QString::number(spec_id);
    p+="');";
    QSqlQuery query;
    query.prepare(p);
    bool isExec =  query.exec();
    if(isExec){
    }
    else {
        QMessageBox msg;
        msg.setText(p);
        msg.exec();
    }

    return true;
}
EntityDoctor* DAODoctor::getByEmail(QString email) {
    EntityDoctor* doc = new EntityDoctor();
    QSqlQuery query;
    QString  q = "SELECT * FROM doctors WHERE email = '"+email+"'";
    query.prepare(q);
    if(!query.exec()) {
        throw new DBException("Data base exception. Try again.");
    }
    if(!query.next()) {
        throw new DBException("The user doesn't exist.");
    }
    else{
        doc->setId(query.value(0).toInt());
        doc->setEmail(query.value(1).toString());
        doc->setFirstName(query.value(2).toString());
        doc->setLastName(query.value(3).toString());
        doc->setAge(query.value(4).toInt());
        doc->setYearsOfExperience(query.value(5).toInt());
        doc->setSpecId(query.value(6).toInt());
    }
    return doc;
}

QSqlQueryModel* DAODoctor::getAllDoctors()
{
    QSqlQuery query;
    query.prepare("SELECT email, first_name, last_name, age, years_of_experience, speciality FROM dbtest.doctors INNER JOIN dbtest.specialities ON speciality_id = specialities.id");
    if(query.exec()) {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(query);
        return model;
    } else {
    return nullptr;
    }
}

QSqlQueryModel *DAODoctor::getDoctorsByFilterParam(int from, int to, QString spec)
{
    QString q = "SELECT * ";
    q += "FROM (SELECT email,first_name, last_name, age, years_of_experience,speciality FROM doctors INNER JOIN ";
    q += "specialities ON speciality_id = specialities.id) AS docTable ";
    q += "WHERE docTable.years_of_experience BETWEEN ";
     q+= QString::number(from);
     q+= " AND ";
     q+= QString::number(to);
     q+= " AND docTable.speciality = '";
     q+= spec + "'";
    QSqlQuery query;
    query.prepare(q);
    if(query.exec()) {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(query);
        return model;
    } else {
        return nullptr;
    }
}
