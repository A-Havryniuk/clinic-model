#include "handle_doctor_mode.h"

Handle_doctor_mode::Handle_doctor_mode()
{
    servDoc = new ServiceDoctor();
    servPat = new ServicePatient();
}

void Handle_doctor_mode::getAllPatients(QTableView *view)
{
    servDoc->printPatientsTable(view);
}

void Handle_doctor_mode::getAllDoctors(QTableView *view)
{
    servDoc->printDoctorsTable(view);
}

void Handle_doctor_mode::fillFilterBySpeciality(QComboBox *combo)
{
    QList<ModelSpeciality>* list = servDoc->getListOfSpeciality();
    for(auto i = list->begin(); i != list->end(); ++i) {
        combo->addItem(i->getName());
    }
}

void Handle_doctor_mode::addDoc(QString first, QString last, QString email, int age, int exp, QString spec, QString newSpec, QStringList days, QTime start, QTime end)
{
    servDoc->addDoc(first, last, email, age, exp, spec, newSpec);
    servDoc->addWorkingHours(email, days,start, end);
}

void Handle_doctor_mode::setMsgAboutWorkingDays(QString docEmail, QLabel *label)
{
    QStringList* workingDays = servPat->getWorkingDays(docEmail);
    QString msg = "This doctor works on: ";
    for(auto i = workingDays->begin(); i != workingDays->end(); ++i) {
        msg += *i + " ";
    }
    label->setText(msg);
}

void Handle_doctor_mode::fillFreeHours(QString docEmail, QDate date, QComboBox *comboBox)
{
    int num = date.dayOfWeek();
    QString day;
    switch(num) {
    case 1:
        day = "Monday";
        break;
    case 2:
        day = "Tuesday";
        break;
    case 3:
        day = "Wednesday";
        break;
    case 4:
        day = "Thursday";
        break;
    case 5:
        day = "Friday";
        break;
    case 6:
        day = "Saturday";
        break;
    case 7:
        day = "Sunday";
        break;
    default:
        break;
    }
    servDoc->fillWithFreeHours(day, date, docEmail, comboBox);

}

void Handle_doctor_mode::addAppointment(QString docEmail, QString patEmail, QDate date, QTime time)
{
    servDoc->addAppointment(docEmail, patEmail, date, time);
}

void Handle_doctor_mode::getAllAppointments(QString email, QTableView *view)
{
    servDoc->getAppointments(view, email);
}

void Handle_doctor_mode::makeDone(QTableView *view, int row, QString docEmail)
{
    QStringList headers;
    for(int i = 0; i < view->model()->columnCount(); ++i) {
        headers.append(view->model()->headerData(i, Qt::Horizontal).toString());
    }
    int indxColSlot = headers.indexOf("timeslot");
    QDateTime slot = view->model()->index(row, indxColSlot).data().toDateTime();
    servDoc->makeDone(slot, docEmail);
}

void Handle_doctor_mode::getAppOnWeek(QString email, QTableView *view)
{
    servDoc->getRangeAppointments(view, email, QDate::currentDate(), QDate::currentDate().addDays(7));
}

int Handle_doctor_mode::getCompletedTask(QString email)
{
    return servDoc->getCompletedTask(email);
}

int Handle_doctor_mode::getMissedTask(QString email)
{
    return servDoc->getMissedTask(email);
}
