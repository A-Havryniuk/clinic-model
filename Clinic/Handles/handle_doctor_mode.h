#ifndef HANDLE_DOCTOR_MODE_H
#define HANDLE_DOCTOR_MODE_H
#include <QTableView>
#include <QTime>
#include <QLabel>
#include "Services/servicedoctor.h"
#include "Services/servicepatient.h"
#include "Handles/handle_mode.h"
#include "Models/modelspeciality.h"

class Handle_doctor_mode : public Handle_mode
{
    ServiceDoctor* servDoc;
    ServicePatient* servPat;
public:
    Handle_doctor_mode();
    void getAllPatients(QTableView *view);
    void getAllDoctors(QTableView* view);
    void fillFilterBySpeciality(QComboBox* combo);
    void addDoc(QString first, QString last, QString email, int age, int exp, QString spec, QString newSpec,
                QStringList days, QTime start, QTime end);
    void setMsgAboutWorkingDays(QString docEmail, QLabel* label);
    void fillFreeHours(QString docEmail, QDate date, QComboBox* comboBox);
    void addAppointment(QString docEmail, QString patEmail, QDate date, QTime time);
    void getAllAppointments(QString email, QTableView* view);
    void makeDone(QTableView* view, int row, QString docEmail);
    void getAppOnWeek(QString email, QTableView* view);
    int getCompletedTask(QString email);
    int getMissedTask(QString email);
};
#endif // HANDLE_DOCTOR_MODE_H
