#include "viewdoctor.h"
#include "ui_viewdoctor.h"

ViewDoctor::ViewDoctor(ModelDoctor* doc, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewDoctor)
{
    ui->setupUi(this);
    this->setWindowTitle("Doctor mode");
    view = ui->tableView_patients;
    viewDoc = new QTableView();
    handleDocMode = new Handle_doctor_mode();
    docForm = new Registration_form_doctor();
    this->doc = doc;
    report = new Report(this->doc);
}

ViewDoctor::~ViewDoctor()
{
    delete ui;
}

void ViewDoctor::on_pushButton_signout_clicked()
{
    this->close();

}


void ViewDoctor::on_tabWidget_currentChanged(int index)
{
    switch(index) {
    case 0:
         break;
    case 1:
        handleDocMode->getAllPatients(view);
        view->show();
        break;
    case 2:
        handleDocMode->getAllAppointments(doc->getEmail(), ui->tableView_appointments);
        break;
    default:
        break;
    }
}


void ViewDoctor::on_pushButton_clicked()
{
    handleDocMode->getAllDoctors(viewDoc);
    viewDoc->show();
}


void ViewDoctor::on_pushButton_2_clicked()
{
    docForm->show();
}


void ViewDoctor::on_pushButton_makeDone_clicked()
{
    QModelIndex indx = ui->tableView_appointments->currentIndex();
    if(indx.isValid()) {
        int rowIndx = indx.row();
        handleDocMode->makeDone(ui->tableView_appointments, rowIndx, this->doc->getEmail());
        handleDocMode->getAllAppointments(doc->getEmail(), ui->tableView_appointments);
    } else {
        QMessageBox msg;
        msg.setText("Chose the patient");
        msg.exec();
    }
}


void ViewDoctor::on_pushButton_weekJob_clicked()
{
    handleDocMode->getAppOnWeek(this->doc->getEmail(), ui->tableView_appointments);
}


void ViewDoctor::on_pushButton_3_clicked()
{
    report->show();
}

