#include "controller.h"

Controller::Controller()
{

}

void Controller::Concat(QLineEdit *lineEdit, const QString &src)
{
    lineEdit->setText(lineEdit->text() + src);
}

QString Controller::ReplaceX(QLineEdit *lineEdit, double x)
{
    std::string str = (lineEdit->text()).toStdString();

    size_t pos = 0;
    while ((pos = str.find("x")) != std::string::npos) {
        str.replace(pos, 1, std::to_string(x));
    }

    return QString::fromStdString(str);;
}
