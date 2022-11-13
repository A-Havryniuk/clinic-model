#include "daoworking_hours.h"
#include <QMessageBox>
DAOWorking_hours::DAOWorking_hours()
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

DAOWorking_hours::~DAOWorking_hours() {
    db.close();
}

bool DAOWorking_hours::add(int docId, QString day, QTime start, QTime end)
{
    QSqlQuery query;
    QString p;
    p = "INSERT INTO working_hours VALUES ('"+QString::number(docId)+"','";
    p += day + "','" + start.toString() + "','" + end.toString() + "');";
    return query.exec(p);
}

QStringList *DAOWorking_hours::getWorkingDays(QString email)
{
    QSqlQuery query;
    QString request = "SELECT day FROM (SELECT * FROM doctors INNER JOIN working_hours";
    request += " ON doctors.id = working_hours.doctor_id) AS workTable ";
    request += "WHERE workTable.doctor_id = (SELECT id FROM doctors WHERE email = '";
    request += email;
    request += "');";
    query.prepare(request);
    QStringList* list = new QStringList();
    if(query.exec()) {
        while(query.next())
            list->append(query.value(0).toString());
    }
    return list;
}

QList<QTime>* DAOWorking_hours::getWorkingHoursByDay(QString docEmail, QString day)
{
    QSqlQuery query;
    QString p;
    p += "SELECT start, end from working_hours WHERE";
    p += " day = '"+day+"' AND working_hours.doctor_id = ";
    p += "(SELECT id FROM doctors WHERE email = '"+docEmail+"');";
    query.prepare(p);
    if(query.exec()) {
        query.next();
        QList<QTime>* startEnd = new QList<QTime>();
        startEnd->append(query.value(0).toTime());
        startEnd->append(query.value(1).toTime());
        return startEnd;
    }
    return nullptr;
}
