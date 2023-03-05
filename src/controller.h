#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>

#include "model.h"
#include "qlistview.h"

namespace s21 {

class Controller {
 public:
  double Calculate(QString str);

  void Concat(QLineEdit *lineEdit, const QString &src);
  QString ReplaceX(QLineEdit *lineEdit, double x);

  void FindCredit(const double &total_credit, const int &term,
                  const double &rate, const bool flag, double &overpay,
                  double &total_payment, double &payment_mouth, QListView **lv);

 private:
  Model model;
};
} // namespace s21
#endif  // CONTROLLER_H
