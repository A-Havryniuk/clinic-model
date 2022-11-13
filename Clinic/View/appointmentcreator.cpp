#include "View/appointmentcreator.h"
#include "ui_appointmentcreator.h"

AppointmentCreator::AppointmentCreator(ModelDoctor* doc, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AppointmentCreator)
{
    this->doc = doc;
    ui->setupUi(this);
    this->setWindowTitle("New appointment");

    handleDoc = new Handle_doctor_mode();
   // ui->dateEdit->setDate(QDate::currentDate());
    QDate cur = QDate::currentDate();
    cur = cur.addDays(30);
    ui->calendarWidget->setMinimumDate(QDate::currentDate());
    ui->calendarWidget->setMaximumDate(cur);
    handleDoc->setMsgAboutWorkingDays(this->doc->getEmail(), ui->label_working_days);
    ui->frame->close();


}

AppointmentCreator::~AppointmentCreator()
{
    delete ui;
}

void AppointmentCreator::on_pushButton_date_clicked()
{
    ui->comboBox->clear();
    handleDoc->fillFreeHours(this->doc->getEmail(), ui->calendarWidget->selectedDate(), ui->comboBox);
    ui->frame->show();
}


void AppointmentCreator::on_pushButton_clicked()
{
    QString patEmail = ui->lineEdit->text();
    QDate chosenDate = ui->calendarWidget->selectedDate();
    QTime time;
    time = time.fromString(ui->comboBox->currentText());
    handleDoc->addAppointment(this->doc->getEmail(), patEmail, chosenDate, time);
    this->close();
}

