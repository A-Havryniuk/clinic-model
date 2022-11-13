#ifndef VIEWDOCTOR_H
#define VIEWDOCTOR_H

#include <QMainWindow>
#include <QTableView>
#include "Handles/handle_doctor_mode.h"
#include "View/registration_form_doctor.h"
#include "Models/modeldoctor.h"
#include "View/report.h"
namespace Ui {
class ViewDoctor;
}

class ViewDoctor : public QMainWindow
{

    Q_OBJECT

public:
    explicit ViewDoctor(ModelDoctor* doc, QWidget *parent = nullptr);
    ~ViewDoctor();

private slots:
    void on_pushButton_signout_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_makeDone_clicked();

    void on_pushButton_weekJob_clicked();

    void on_pushButton_3_clicked();

private:
    ModelDoctor* doc;
    Handle_doctor_mode* handleDocMode;
    QTableView* view;
    QTableView* viewDoc;
    Registration_form_doctor* docForm;
    Report* report;
    Ui::ViewDoctor *ui;
};

#endif // VIEWDOCTOR_H
