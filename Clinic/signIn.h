#ifndef SIGNIN_H
#define SIGNIN_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "Handles/handle_sign_in.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SignIn; }
QT_END_NAMESPACE

class SignIn : public QMainWindow
{
    Q_OBJECT

public:
    SignIn(QWidget *parent = nullptr);
    ~SignIn();
    Handle_sign_in* handle;
private slots:
    void on_pushButton_signIn_clicked();

    void on_pushButton_signUp_clicked();

private:
    Ui::SignIn *ui;
};
#endif // SIGNIN_H
