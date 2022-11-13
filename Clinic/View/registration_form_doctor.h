#ifndef REGISTRATION_FORM_DOCTOR_H
#define REGISTRATION_FORM_DOCTOR_H

#include <QMainWindow>
#include "Handles/handle_doctor_mode.h"
namespace Ui {
class Registration_form_doctor;
}

class Registration_form_doctor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registration_form_doctor(QWidget *parent = nullptr);
    ~Registration_form_doctor();

private slots:
    void on_pushButton_add_clicked();

private:
    Handle_doctor_mode* handleDoc;
    Ui::Registration_form_doctor *ui;
};

#endif // REGISTRATION_FORM_DOCTOR_H
