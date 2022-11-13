#include "registration_form_patient.h"
#include "ui_registration_form_patient.h"
#include "Handles/handle_sign_in.h"
registration_form_patient::registration_form_patient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registration_form_patient)
{
    ui->setupUi(this);

}

registration_form_patient::~registration_form_patient()
{
    delete ui;
}




void registration_form_patient::on_pushButton_2_clicked()
{
    QString firstName = ui->lineEdit_firstName->text();
    QString lastName = ui->lineEdit_lastName->text();
    QString email = ui->lineEdit_email->text();
    int age = ui->spinBox->value();
    char sex;
    if(ui->radioButton_male->isChecked()){
        sex = 'm';
    } else {
        sex = 'f';
    }
    Handle_sign_in* handle = new Handle_sign_in();
    if(handle->signUpPatient(firstName, lastName, email, age, sex))
        this->close();
}

