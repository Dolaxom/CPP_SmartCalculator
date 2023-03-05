#include "controller.h"

using namespace s21;

double Controller::Calculate(QString str) {
  return model.Calculate(str.toStdString());
}

void Controller::Concat(QLineEdit *lineEdit, const QString &src) {
  model.Concat(lineEdit, src);
}

QString Controller::ReplaceX(QLineEdit *lineEdit, double x) {
  return model.ReplaceX(lineEdit, x);
}

void Controller::FindCredit(const double &total_credit, const int &term,
                            const double &rate, const bool flag,
                            double &overpay, double &total_payment,
                            double &payment_mouth, QListView **lv) {
  int days_in_month = 30;
  model.FindCredit(total_credit, term, rate, flag, overpay, total_payment,
                   payment_mouth, lv, days_in_month);
}
