#ifndef VIEWPATIENT_H
#define VIEWPATIENT_H

#include <QMainWindow>
#include <QTableView>
#include "Handles/handle_patient_mode.h"
namespace Ui {
class ViewPatient;
}

class ViewPatient : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewPatient(QWidget *parent = nullptr);
    ~ViewPatient();

private slots:

    void on_tabWidget_currentChanged(int index);


    void on_pushButton_find_clicked();

    void on_pushButton_getPop_clicked();

    void on_pushButton_selectDoc_clicked();

    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_getinfo_clicked();

    void on_pushButton_info_clicked();

    void on_comboBox_activated(int index);

private:
    Handle_patient_mode* handlePat;
    QTableView* view;
    Ui::ViewPatient *ui;
};

#endif // VIEWPATIENT_H
