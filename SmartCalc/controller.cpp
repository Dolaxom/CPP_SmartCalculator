#include "controller.h"

Controller::Controller()
{

}

void Controller::Concat(QLineEdit *lineEdit, const QString &src)
{
    lineEdit->setText(lineEdit->text() + src);
}
