#ifndef ENTITYWORKING_HOURS_H
#define ENTITYWORKING_HOURS_H
#include <QString>
#include <QTime>
class EntityWorking_hours
{
    int doctorId;
    QString* workingDays;
    QTime* startDay;
    QTime* endDay;
public:
    EntityWorking_hours();
};

#endif // ENTITYWORKING_HOURS_H
