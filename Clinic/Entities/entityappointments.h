#ifndef ENTITYAPPOINTMENTS_H
#define ENTITYAPPOINTMENTS_H
#include <QTime>

class EntityAppointments
{
    int doctorId;
    int patientId;
    bool isDone;
    QDate dateSlot;
    QTime timeSlot;
public:
    EntityAppointments();
};

#endif // ENTITYAPPOINTMENTS_H
