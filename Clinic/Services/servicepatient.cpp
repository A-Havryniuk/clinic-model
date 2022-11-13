#include "servicepatient.h"

ServicePatient::ServicePatient()
{
    daop = new DAOPatient();
    daod = new DAODoctor();
    daosp = new DAOSpecialities();
    daoapp = new DAOAppointments();
    daowh = new DAOWorking_hours();
}

void ServicePatient::signUp(QString firstName, QString lastName, QString email, int age, char sex)
{
    if(!email.contains("@")) {
        throw new std::invalid_argument("Illegal argument!\n You entered:");
    }
    try {
    ModelPatient* patient = new ModelPatient(firstName, lastName, email, age, sex);
    daop->addPatient(patient);
    } catch (DBException* ex) {
        throw new std::invalid_argument(ex->what());
    }
}

void ServicePatient::printDoctorsTable(QTableView* view)
{
    view->setModel(daod->getAllDoctors());
}

void ServicePatient::printDoctorsByFilterParam(QTableView *view, int from, int to, QString speciality)
{
    view->setModel(daod->getDoctorsByFilterParam(from, to, speciality));
}

QList<ModelSpeciality> *ServicePatient::getListOfSpeciality()
{
    return daosp->getAllSpeciality();
}

void ServicePatient::printMostPopularDoctor(QTableView *view)
{
    view->setModel(daoapp->getMostPopularDoc());
}

ModelDoctor *ServicePatient::getDocByEmail(QString email)
{
    EntityDoctor* docEntity = daod->getByEmail(email);
    ModelDoctor* docModel = new ModelDoctor();
    docModel->setEmail(docEntity->getEmail());
    docModel->setAge(docEntity->getAge());
    docModel->setFirstName(docEntity->getFirstName());
    docModel->setLastName(docEntity->getLastName());
    docModel->setYearsOfExp(docEntity->getYearsOfExperience());
    QString spec = daosp->getSpecById(docEntity->getSpecId())->getName();
    docModel->setSpec(spec);
    return docModel;
}

QStringList *ServicePatient::getWorkingDays(QString email)
{
    return daowh->getWorkingDays(email);
}

void ServicePatient::getAppointments(QString email, QTableView *view)
{
    view->setModel(daoapp->getPatientAppointments(email));
}

void ServicePatient::deleteAppointment(QString DocEmail, QDateTime datetime)
{
    QString slot = datetime.toString("yyyy-MM-dd hh:mm:ss");
    daoapp->deleteAppointment(DocEmail, slot);
}

void ServicePatient::getAppByDay(QTableView *view, QDate date, QString email)
{
    QString slot = date.toString("yyyy-MM-dd");
    view->setModel(daoapp->getPatAppByDay(email, slot));
}


