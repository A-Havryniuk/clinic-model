#include "View/viewpatient.h"
#include "ui_viewpatient.h"

ViewPatient::ViewPatient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewPatient)
{
    ui->setupUi(this);
    this->setWindowTitle("Patient mode");
    handlePat = new Handle_patient_mode();
    view = ui->tableView_doctors;
    ui->calendarWidget_certainDate->setMinimumDate(QDate::currentDate());
    ui->calendarWidget_certainDate->setMaximumDate(QDate::currentDate().addDays(30));
}

ViewPatient::~ViewPatient()
{
    delete ui;
}



void ViewPatient::on_tabWidget_currentChanged(int index)
{
    switch(index) {
    case 0:

         break;
    case 1:
        ui->comboBox->clear();
        handlePat->getAllDoctors(view);
        handlePat->fillFilterBySpeciality(ui->comboBox);
        view->show();
        break;
    case 2:
        ui->frame->close();
        ui->frame_calendar->close();
    default:
        break;
    }
}





void ViewPatient::on_pushButton_find_clicked()
{
    int from = ui->comboBox_from->currentText().toInt();
    int to = ui->comboBox_to->currentText().toInt();
    QString spec = ui->comboBox->currentText();
    if(spec.isEmpty())
        spec = "therapist";
    handlePat->getDoctorByFilterParam(ui->tableView_doctors, from, to, spec);

}


void ViewPatient::on_pushButton_getPop_clicked()
{
    handlePat->getMostPopularDoctor();
}


void ViewPatient::on_pushButton_selectDoc_clicked()
{
    QModelIndex indx = ui->tableView_doctors->currentIndex();
    int row = indx.row();
    handlePat->getDoctorBySelectedItem(row, ui->tableView_doctors);
    handlePat->getAllDoctors(view);
}


void ViewPatient::on_pushButton_ok_clicked()
{
    handlePat->getPatientAppointments(ui->lineEdit->text(), ui->tableView_patAppointments);
    ui->frame->show();
}


void ViewPatient::on_pushButton_cancel_clicked()
{
    QModelIndex indx = ui->tableView_patAppointments->currentIndex();
    int row = indx.row();
    handlePat->deleteApp(row, ui->tableView_patAppointments);
    handlePat->getPatientAppointments(ui->lineEdit->text(), ui->tableView_patAppointments);
}


void ViewPatient::on_pushButton_getinfo_clicked()
{
    QString patEmail = ui->lineEdit->text();
    QDate date = ui->calendarWidget_certainDate->selectedDate();
    handlePat->getAppointmentsByDay(ui->tableView_patAppointments, date, patEmail);
}


void ViewPatient::on_pushButton_info_clicked()
{
    ui->frame_calendar->show();
}


void ViewPatient::on_comboBox_activated(int index)
{

}

