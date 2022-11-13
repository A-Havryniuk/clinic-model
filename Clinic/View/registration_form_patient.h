#ifndef REGISTRATION_FORM_PATIENT_H
#define REGISTRATION_FORM_PATIENT_H
#include "View/viewdoctor.h"
#include <QMainWindow>

namespace Ui {
class registration_form_patient;
}

class registration_form_patient : public QMainWindow
{
    Q_OBJECT

public:
    explicit registration_form_patient(QWidget *parent = nullptr);
    ~registration_form_patient();

private slots:


    void on_pushButton_2_clicked();

private:
    Ui::registration_form_patient *ui;
};

#endif // REGISTRATION_FORM_PATIENT_H
