#include "View/signIn.h"
#include "ui_signIn.h"

SignIn::SignIn(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign in");
    handle = new Handle_sign_in();
}

SignIn::~SignIn()
{
    delete ui;
}


void SignIn::on_pushButton_signIn_clicked()
{
    QString email = ui->lineEdit->text();
    if(handle->execute(email)) {
        this->close();
    }
}



void SignIn::on_pushButton_signUp_clicked()
{
    handle->registration();
    this->close();
}

