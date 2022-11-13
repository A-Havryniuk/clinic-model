#ifndef DBEXCEPTION_H
#define DBEXCEPTION_H
#include <QException>

class DBException : public QException
{
    QString message;
public:
    DBException(QString const &text = " ") noexcept
        :message(text) {}
    DBException(const DBException &ex) {this->message = ex.message;};
    ~DBException() override {}

    DBException* clone() const override {return new DBException(*this);}
    const char *what() const noexcept override {return this->message.toStdString().c_str();}
};

#endif // DBEXCEPTION_H
