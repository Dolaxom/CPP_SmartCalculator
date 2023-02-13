#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "QtWidgets/qlineedit.h"
#include "model.h"

class Controller
{
public:
    Controller();

    static void Concat(QLineEdit *lineEdit, const QString &src);
};

#endif // CONTROLLER_H
