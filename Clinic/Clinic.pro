QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    DAO/dao.cpp \
    DAO/daoappointments.cpp \
    DAO/daodoctor.cpp \
    DAO/daopatient.cpp \
    DAO/daospecialities.cpp \
    DAO/daoworking_hours.cpp \
    Entities/entityappointments.cpp \
    Entities/entitydoctor.cpp \
    Entities/entitypatient.cpp \
    Entities/entityspecialities.cpp \
    Entities/entityworking_hours.cpp \
    Entities/user.cpp \
    Handles/handle_doctor_mode.cpp \
    Handles/handle_mode.cpp \
    Handles/handle_patient_mode.cpp \
    Models/modelpatient.cpp \
    Handles/handle_sign_in.cpp \
    Services/servicedoctor.cpp \
    Services/servicepatient.cpp \
    View/appointmentcreator.cpp \
    Exceptions/dbexception.cpp \
    View/report.cpp \
    main.cpp \
    Models/modeldoctor.cpp \
    Models/modelspeciality.cpp \
    Services/serviceuser.cpp \
    View/registration_form_doctor.cpp \
    View/registration_form_patient.cpp \
    View/signIn.cpp \
    View/viewdoctor.cpp \
    View/viewpatient.cpp

HEADERS += \
    DAO/dao.h \
    DAO/daoappointments.h \
    DAO/daodoctor.h \
    DAO/daopatient.h \
    DAO/daospecialities.h \
    DAO/daoworking_hours.h \
    Entities/entityappointments.h \
    Entities/entitydoctor.h \
    Entities/entitypatient.h \
    Entities/entityspecialities.h \
    Entities/entityworking_hours.h \
    Entities/user.h \
    Handles/handle_doctor_mode.h \
    Handles/handle_mode.h \
    Handles/handle_patient_mode.h \
    Models/modelpatient.h \
    Handles/handle_sign_in.h \
    Models/modeldoctor.h \
    Models/modelspeciality.h \
    Services/servicedoctor.h \
    Services/servicepatient.h \
    Services/serviceuser.h \
    View/appointmentcreator.h \
    Exceptions/dbexception.h \
    View/registration_form_doctor.h \
    View/registration_form_patient.h \
    View/report.h \
    View/signIn.h \
    View/viewdoctor.h \
    View/viewpatient.h

FORMS += \
    View/appointmentcreator.ui \
    View/registration_form_doctor.ui \
    View/registration_form_patient.ui \
    View/report.ui \
    View/signIn.ui \
    View/viewdoctor.ui \
    View/viewpatient.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
