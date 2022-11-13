#include "handle_sign_in.h"

Handle_sign_in::Handle_sign_in()
{
    service_user = new ServiceUser();
    service = new ServicePatient();
}

bool Handle_sign_in::execute(QString email)
{
    try {
    this->email = email;

    User* user = service_user->signIn(this->email);
    if(EntityDoctor* doc = dynamic_cast<EntityDoctor*>(user)) {
        ModelDoctor* modelDoc = new ModelDoctor(doc);
        this->viewdoc = new ViewDoctor(modelDoc);
        this->viewdoc->show();
    } else if(EntityPatient* pat = dynamic_cast<EntityPatient*>(user)){
        this->viewpat = new ViewPatient();
        this->viewpat->show();
        }
    } catch(std::exception* ex) {
        QMessageBox msgBox;
        msgBox.setText(ex->what() + email);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return false;
    }
    return true;
}

void Handle_sign_in::registration()
{
    form = new registration_form_patient();
    this->form->show();
}

bool Handle_sign_in::signUpPatient(QString first, QString last, QString email, int age, char sex)
{
    try {
    service->signUp(first, last, email, age, sex);
    this->viewpat = new ViewPatient();
    this->viewpat->show();
    } catch (std::exception *exc) {
        QMessageBox msgBox;
        msgBox.setText(exc->what() + email);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return false;
    }
    return true;
}
