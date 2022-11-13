#include "handle_patient_mode.h"

Handle_patient_mode::Handle_patient_mode()
{
    servPat = new ServicePatient();
    popDocView = new QTableView();
}

void Handle_patient_mode::getAllDoctors(QTableView *view)
{
    servPat->printDoctorsTable(view);
}

void Handle_patient_mode::getDoctorByFilterParam(QTableView *view, int from, int to, QString speciality)
{
    servPat->printDoctorsByFilterParam(view, from, to, speciality);
}

void Handle_patient_mode::fillFilterBySpeciality(QComboBox *combo)
{
    QList<ModelSpeciality>* list = servPat->getListOfSpeciality();
    for(auto i = list->begin()+1; i != list->end(); ++i) {
        combo->addItem(i->getName());
    }
}

void Handle_patient_mode::getMostPopularDoctor()
{
    servPat->printMostPopularDoctor(popDocView);
    popDocView->show();
}

void Handle_patient_mode::getDoctorBySelectedItem(int rowIndx, QTableView* view)
{
    QStringList headers;
    for(int i = 0; i < view->model()->columnCount(); ++i) {
        headers.append(view->model()->headerData(i, Qt::Horizontal).toString());
    }
    int colIndx = headers.indexOf("email");
    QString email = view->model()->index(rowIndx, colIndx).data().toString();
    ModelDoctor* doc = servPat->getDocByEmail(email);
    creator = new AppointmentCreator(doc);
    creator->show();
}

void Handle_patient_mode::getPatientAppointments(QString email, QTableView *view)
{
    servPat->getAppointments(email, view);
}

void Handle_patient_mode::deleteApp(int rowIndx, QTableView *view)
{
    QStringList headers;
    for(int i = 0; i < view->model()->columnCount(); ++i) {
        headers.append(view->model()->headerData(i, Qt::Horizontal).toString());
    }
    int colIndx = headers.indexOf("email");
    int indxColSlot = headers.indexOf("timeslot");
    QString email = view->model()->index(rowIndx, colIndx).data().toString();
    QDateTime slot = view->model()->index(rowIndx, indxColSlot).data().toDateTime();
    servPat->deleteAppointment(email, slot);
}

void Handle_patient_mode::getAppointmentsByDay(QTableView *view, QDate date, QString email)
{
    servPat->getAppByDay(view, date, email);
}







