#include "registration_form_doctor.h"
#include "ui_registration_form_doctor.h"

Registration_form_doctor::Registration_form_doctor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registration_form_doctor)
{
    ui->setupUi(this);
    this->setWindowTitle("Registration form");
    handleDoc = new Handle_doctor_mode();
    handleDoc->fillFilterBySpeciality(ui->comboBox_speciality);
}

Registration_form_doctor::~Registration_form_doctor()
{
    delete ui;
}

void Registration_form_doctor::on_pushButton_add_clicked()
{
    QString firstName = ui->lineEdit_doctorFirstName->text();
    QString lastName = ui->lineEdit_doctorLastName->text();
    QString email = ui->lineEdit_doctorEmail->text();
    int age = ui->spinBox_doctorAge->value();
    int experience = ui->spinBox_doctorExp->value();
    QString spec = ui->comboBox_speciality->currentText();
    QString newSpec = ui->lineEdit_newSpec->text();

    QStringList days;
    if(ui->checkbox_Monday->isChecked())
        days.append("Monday");
    if(ui->checkbox_Tuesday->isChecked())
        days.append("Tuesday");
    if(ui->checkbox_Wednesday->isChecked())
        days.append("Wednesday");
    if(ui->checkbox_Thursday->isChecked())
        days.append("Thursday");
    if(ui->checkbox_Friday->isChecked())
        days.append("Friday");
    if(ui->checkbox_Saturday->isChecked())
        days.append("Saturday");
    if(ui->checkbox_Sunday->isChecked())
        days.append("Sunday");
    QTime start = ui->timeEdit_start->time();
    QTime end = ui->timeEdit_end->time();
    handleDoc->addDoc(firstName, lastName, email, age, experience, spec, newSpec, days, start, end);
    this->close();
}

