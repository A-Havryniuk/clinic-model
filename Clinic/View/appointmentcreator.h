#ifndef APPOINTMENTCREATOR_H
#define APPOINTMENTCREATOR_H
#include "Models/modeldoctor.h"
#include <QMainWindow>
#include "Handles/handle_doctor_mode.h"

namespace Ui {
class AppointmentCreator;
}

class AppointmentCreator : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppointmentCreator(ModelDoctor* doc, QWidget *parent = nullptr);
    ~AppointmentCreator();

private slots:
    void on_pushButton_date_clicked();

    void on_pushButton_clicked();

private:
    Handle_doctor_mode* handleDoc;
    ModelDoctor* doc;
    Ui::AppointmentCreator *ui;
};

#endif // APPOINTMENTCREATOR_H
