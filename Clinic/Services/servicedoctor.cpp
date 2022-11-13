#include "servicedoctor.h"

ServiceDoctor::ServiceDoctor()
{
    daop = new DAOPatient();
    daod = new DAODoctor();
    daosp = new DAOSpecialities();
    daoapp = new DAOAppointments();
    daowh = new DAOWorking_hours();
}

void ServiceDoctor::printPatientsTable(QTableView *view)
{
    if(view == nullptr)
        throw new std::invalid_argument("Check your data.");
    view->setModel(daop->getAllPatients());
}

void ServiceDoctor::printDoctorsTable(QTableView *view)
{
    if(view == nullptr)
        throw new std::invalid_argument("Check your data.");
    view->setModel(daod->getAllDoctors());
}

QList<ModelSpeciality> *ServiceDoctor::getListOfSpeciality()
{ try {
    return daosp->getAllSpeciality();
  } catch (DBException* e) {
        throw new std::invalid_argument(e->what());
    }
}

void ServiceDoctor::addDoc(QString f, QString l, QString em, int age, int exp, QString spec, QString newSpec)
{
    if(!em.contains("@clinic.com") || exp>age) {
        throw new std::invalid_argument("Illegal argument!");
    }
    try {
    ModelDoctor* newDoc = new ModelDoctor();
    bool isNew = false;
    if(newSpec.isEmpty()!=true) {
        isNew = daosp->addSpec(newSpec);
        isNew = true;
    }
    EntitySpecialities* speciality = new EntitySpecialities();
    newDoc->setFirstName(f);
    newDoc->setLastName(l);
    newDoc->setEmail(em);
    newDoc->setAge(age);
    newDoc->setYearsOfExp(exp);
    if(isNew) {
        newDoc->setSpec(newSpec);
        speciality->setName(newSpec);
    } else {
        newDoc->setSpec(spec);
        speciality->setName(spec);
    }
    speciality->setId(daosp->getSpecId(speciality->getName()));
    daod->addDoctor(newDoc, speciality->getId());
    } catch (DBException* ex) {
        throw new std::invalid_argument(ex->what());
    }
}

void ServiceDoctor::addWorkingHours(QString email, QStringList days, QTime start, QTime end)
{
    if(!email.contains("@clinic.com") ) {
        throw new std::invalid_argument("Illegal argument!");
    }
    try {
    int docId = daod->getByEmail(email)->getId();
    for(auto i = days.begin(); i != days.end(); ++i) {
        daowh->add(docId, *i, start, end);
    }
    } catch (DBException* ex) {
        throw new std::invalid_argument(ex->what());
    }
}

void ServiceDoctor::fillWithFreeHours(QString day, QDate date, QString docEmail, QComboBox *comboBox)
{
    if(!docEmail.contains("@clinic.com") ) {
        throw new std::invalid_argument("Illegal argument!");
    }
    try {
    QStringList* listOfDays = daowh->getWorkingDays(docEmail);
    QList<QTime>* fullTimes = daoapp->getFullSlotsByDateAndDocEmail(date, docEmail);
    if(listOfDays->contains(day)) {
        QList<QTime>* listOfHours = daowh->getWorkingHoursByDay(docEmail, day);
        auto i = listOfHours->begin();
        QTime start = *i;
        ++i;
        QTime end = *i;
        listOfHours->clear();
        QTime tmp = start;
        if(fullTimes!=nullptr){
            while(tmp != end) {
                if(!fullTimes->contains(tmp))
                    listOfHours->append(tmp);
                tmp = tmp.addSecs(this->secsPerHour);
                }
           if(!fullTimes->contains(end))
                listOfHours->append(end);
           for(auto i = listOfHours->begin(); i != listOfHours->end();++i) {
                comboBox->addItem(i->toString());
           }
        } else {
            while(tmp != end) {
                listOfHours->append(tmp);
                tmp = tmp.addSecs(this->secsPerHour);
            }
            listOfHours->append(end);
            for(auto i = listOfHours->begin(); i != listOfHours->end();++i) {
                 comboBox->addItem(i->toString());
            }
        }
    } else {
        throw new std::invalid_argument("Doc doesn't work on this day");
    }
    } catch (DBException* ex) {
        throw new std::invalid_argument(ex->what());
    }
}

void ServiceDoctor::addAppointment(QString docEm, QString patEm, QDate date, QTime time)
{
    try {
    if(!docEm.contains("@clinic.com") ) {
        throw new std::invalid_argument("Illegal argument!");
    }
    if(!patEm.contains("@")) {
        throw new std::invalid_argument("Illegal argument!");
    }
    daoapp->addAppointment(patEm, docEm, date, time);
    } catch (DBException* ex) {
        throw new std::invalid_argument(ex->what());
    }
}

void ServiceDoctor::getAppointments(QTableView *view, QString email)
{
    if(view == nullptr || !email.contains("@"))
        throw new std::invalid_argument("Illegal argument!");
    try {
    view->setModel(daoapp->getDocAppointments(email));
    } catch (DBException* ex) {
        throw new std::invalid_argument(ex->what());
    }
}

void ServiceDoctor::makeDone(QDateTime datetime, QString email)
{
    if(!email.contains("@"))
        throw new std::invalid_argument("Illegal argument");
    try {
    QString timeSlot = datetime.toString("yyyy-MM-dd hh:mm:ss");
    daoapp->makeAppDone(email, timeSlot);
    } catch (DBException* ex) {
        throw new std::invalid_argument(ex->what());
    }
}

void ServiceDoctor::getRangeAppointments(QTableView *view, QString email, QDate date1, QDate date2)
{
    if(!email.contains("@"))
        throw new std::invalid_argument("Illegal argument");
    try {
    QString firstDate = date1.toString("yyyy-MM-dd");
    QString secondDate = date2.toString("yyyy-MM-dd");
    view->setModel(daoapp->getRangeApp(email, firstDate, secondDate));
    } catch (DBException* ex) {
        throw new std::invalid_argument(ex->what());
    }
}

int ServiceDoctor::getCompletedTask(QString docEmail)
{
    if(!docEmail.contains("@clinic.com") ) {
        throw new std::invalid_argument("Illegal argument!");
    } try {
    return daoapp->getCompletedTask(docEmail);
    } catch (DBException* ex) {
        throw new std::invalid_argument(ex->what());
    }
}

int ServiceDoctor::getMissedTask(QString docEmail)
{
    if(!docEmail.contains("@clinic.com") ) {
        throw new std::invalid_argument("Illegal argument!");
    } try {
    return daoapp->getMissedTask(docEmail);
    } catch (DBException* ex) {
        throw new std::invalid_argument(ex->what());
    }
}




