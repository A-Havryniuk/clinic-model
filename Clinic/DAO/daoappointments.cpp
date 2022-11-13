#include "daoappointments.h"
#include <QMessageBox>
DAOAppointments::DAOAppointments()
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

DAOAppointments::~DAOAppointments() {
    db.close();
}

bool DAOAppointments::addAppointment(QString patEmail, QString docEmail, QDate date, QTime time)
{
    QString request;
    QSqlQuery query;
    request += "INSERT INTO appointments (doctor_id, patient_id, is_done, timeslot) VALUES ";
    request += "((SELECT id FROM doctors WHERE email = '"+docEmail+"'),(SELECT id FROM patients WHERE email = '"+patEmail+"'), '0', '";
    QDateTime dt;
    dt.setDate(date);
    dt.setTime(time);
    request += dt.toString("yyyy-MM-dd hh:mm:ss")+"');";
    query.prepare(request);
    if(query.exec()) {
        return true;
    }
    return false;
}

QSqlQueryModel *DAOAppointments::getMostPopularDoc()
{
    QString p = "SELECT doctors.email, doctors.first_name, doctors.last_name, doctors.age, doctors.years_of_experience, specialities.speciality ";
    p += "FROM (SELECT appointments.doctor_id, COUNT(*) AS number_of_appointments";
    p += " FROM appointments ";
    p += "GROUP BY doctor_id ";
    p += "ORDER BY number_of_appointments DESC) AS table1 ";
    p += "INNER JOIN doctors ON table1.doctor_id = doctors.id ";
    p += "INNER JOIN specialities ON doctors.speciality_id = specialities.id ";
    p += "LIMIT 3;";
    QSqlQuery query;
    query.exec(p);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    return model;
}

QList<QTime>* DAOAppointments::getFullSlotsByDateAndDocEmail(QDate date, QString email)
{
    QList<QTime>* times = new QList<QTime>();
    QSqlQuery query;
    QString p;
    p += "SELECT TIME(timeslot) FROM (SELECT timeslot from appointments) ";
    p += "WHERE date(timeslot) = '"+date.toString()+"' AND doctor_id = (";
    p += "SELECT id FROM doctors WHERE email = '"+email+"')) as timeslots;";
    query.prepare(p);
    if(query.exec()) {
        while(query.next()) {
            times->append(query.value(0).toTime());
        }
        return times;
    }
    delete times;
    return nullptr;
}

QSqlQueryModel *DAOAppointments::getPatientAppointments(QString patientEmail)
{
    QString request;
    request += "SELECT doctors.email, doctors.first_name, doctors.last_name, appointments.timeslot, speciality ";
    request += "FROM appointments INNER JOIN doctors ON doctor_id = doctors.id ";
    request += "INNER JOIN patients ON patient_id = patients.id ";
    request += "INNER JOIN specialities ON doctors.speciality_id = specialities.id ";
    request += "WHERE patients.email = '"+patientEmail+"' ";
    request += "AND is_done = 0 AND timeslot>=now() LIMIT 0,100";
    QSqlQuery query;
    query.prepare(request);
    if(query.exec()) {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(query);
        return model;
    } else {
        return nullptr;
    }
}

bool DAOAppointments::deleteAppointment(QString docEmail, QString dateTime)
{
    QString request;
    request += "DELETE FROM appointments WHERE doctor_id = ";
    request += "(SELECT id FROM doctors WHERE email = '"+docEmail+"') ";
    request += "AND timeslot = '"+dateTime+"'";
    QSqlQuery query;
    query.prepare(request);
    if(query.exec()) {
        return true;
    }
    return false;
}

QSqlQueryModel *DAOAppointments::getPatAppByDay(QString email, QString date)
{
    QString request;
    request += "SELECT doctors.email, doctors.first_name, doctors.last_name, appointments.timeslot, speciality FROM appointments ";
    request += "INNER JOIN patients ON appointments.patient_id = patients.id ";
    request += "INNER JOIN doctors ON appointments.doctor_id = doctors.id ";
    request += "INNER JOIN specialities ON doctors.speciality_id = specialities.id ";
    request += "WHERE patients.email = '"+email+"' AND date(timeslot) = '"+date+"'";

    QSqlQuery query;
    query.prepare(request);
    if(query.exec()) {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(query);
        return model;
    } else {
        return nullptr;
    }
}

QSqlQueryModel *DAOAppointments::getDocAppointments(QString docEmail)
{
    QString request;
    request += "SELECT patients.email, patients.first_name, patients.last_name, appointments.is_done, appointments.timeslot ";
    request += "FROM appointments INNER JOIN doctors ON doctor_id = doctors.id ";
    request += "INNER JOIN patients ON patient_id = patients.id ";
    request += "WHERE doctors.email = '"+docEmail+"' ";
    request += " ORDER BY appointments.timeslot LIMIT 0,100";
    QSqlQuery query;
    query.prepare(request);
    if(query.exec()) {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(query);
        return model;
    } else {
        return nullptr;
    }
}

bool DAOAppointments::makeAppDone(QString docEmail, QString timeslot)
{
    QString request;
    request += "update appointments set is_done = '1' ";
    request += "where doctor_id = (select id from doctors where email = '"+docEmail+"') ";
    request += "and timeslot = '"+timeslot+"'";
    QSqlQuery query;
    query.prepare(request);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel *DAOAppointments::getRangeApp(QString docEmail, QString date1, QString date2)
{
    QString request;
    request += "SELECT patients.email, patients.first_name, patients.last_name, appointments.is_done, appointments.timeslot ";
    request += "FROM appointments INNER JOIN doctors ON doctor_id = doctors.id ";
    request += "INNER JOIN patients ON patient_id = patients.id ";
    request += "WHERE doctors.email = '"+docEmail+"' ";
    request += "AND date(timeslot) BETWEEN '"+date1+"' AND '"+date2+"' ";
    request += "ORDER BY appointments.timeslot LIMIT 0,100";
    QSqlQuery query;
    query.prepare(request);
    if(query.exec()) {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(query);
        return model;
    } else {
        return nullptr;
    }
}

int DAOAppointments::getCompletedTask(QString docEmail)
{
    QString request;
    request += "SELECT COUNT(*) FROM appointments";
    request += " WHERE is_done = '1' ";
    request += "AND doctor_id = (SELECT id FROM doctors WHERE email = '"+docEmail+"') ";
    request += "AND timeslot <= now();";
    QSqlQuery query;
    query.prepare(request);
    if(query.exec()) {
        query.next();
        return query.value(0).toInt();
    }
    return 0;
}

int DAOAppointments::getMissedTask(QString docEmail)
{
    QString request;
    request += "SELECT COUNT(*) FROM appointments";
    request += " WHERE is_done = '0' ";
    request += "AND doctor_id = (SELECT id FROM doctors WHERE email = '"+docEmail+"') ";
    request += "AND timeslot <= now();";
    QSqlQuery query;
    query.prepare(request);
    if(query.exec()) {
        query.next();
        return query.value(0).toInt();
    }
    return 0;
}
