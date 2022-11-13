#ifndef HANDLE_PATIENT_MODE_H
#define HANDLE_PATIENT_MODE_H
#include <QTableView>
#include <QComboBox>
#include <QList>
#include <QLabel>
#include "Services/servicepatient.h"
#include "Models/modelspeciality.h"
#include "Handles/handle_mode.h"
#include "Models/modeldoctor.h"
#include "View/appointmentcreator.h"
class Handle_patient_mode : public Handle_mode
{
    ServicePatient* servPat;
    QTableView* popDocView;
    AppointmentCreator* creator;
public:
    Handle_patient_mode();
    void getAllDoctors(QTableView *view);
    void getDoctorByFilterParam(QTableView *view, int from, int to, QString speciality);
    void fillFilterBySpeciality(QComboBox* combo);
    void getMostPopularDoctor();
    void getDoctorBySelectedItem(int rowIndx, QTableView* view);
    void getPatientAppointments(QString email, QTableView* view);
    void deleteApp(int rowIndx, QTableView* view);
    void getAppointmentsByDay(QTableView* view, QDate date, QString email);
};

#endif // HANDLE_PATIENT_MODE_H
