#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>
#include <QtWidgets/QLineEdit>

#include "../controller.h"

namespace Ui {
class Credit;
}

namespace s21 {
class Credit : public QWidget {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:
  void on_pushButton_calculate_clicked();

 private:
  Ui::Credit *ui;
  Controller controller;
  double total_credit_amount = 0.0;
  int term = 0;
  double interest_rate = 0.0;
  bool flag = false;  // false = annuity / true = differentiated
  double overpay = 0.0;
  double total_payment = 0.0;
  double payment_mouth = 0.0;
};
} // namespace s21
#endif  // CREDIT_H
