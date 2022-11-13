#ifndef REPORT_H
#define REPORT_H

#include <QWidget>
#include "Models/modeldoctor.h"
#include "Handles/handle_doctor_mode.h"

namespace Ui {
class Report;
}

class Report : public QWidget
{
    Q_OBJECT

public:
    explicit Report(ModelDoctor* doc, QWidget *parent = nullptr);
    ~Report();

private:
    Handle_doctor_mode* docMode;
    Ui::Report *ui;
    ModelDoctor* doctor;
};

#endif // REPORT_H
