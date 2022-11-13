#include "report.h"
#include "ui_report.h"

Report::Report(ModelDoctor* doc, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
    this->setWindowTitle("Report");
    this->doctor = doc;
    ui->label_fName->setText(doctor->getFirstName());
    ui->label_lName->setText(doctor->getLastName());
    ui->label_email->setText(doctor->getEmail());
    docMode = new Handle_doctor_mode();
    ui->label_compl->setText("Completed: "+QString::number(docMode->getCompletedTask(doc->getEmail())));
    ui->label_missed->setText("Missed: " + QString::number(docMode->getMissedTask(doc->getEmail())));
}

Report::~Report()
{
    delete ui;
}
