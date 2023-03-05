#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

#include "../controller.h"
#include "../credit_calculator/credit.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Calc;
}
QT_END_NAMESPACE


namespace s21 {
class Calc : public QWidget {
  Q_OBJECT

 public:
  Calc(QWidget *parent = nullptr);
  ~Calc();

 private:
  Ui::Calc *ui;
  Controller controller;
  Credit credit_form;

 private slots:
  void on_pushButton_1_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_eq_clicked();

  void on_pushButton_cos_clicked();

  void on_pushButton_pow_clicked();

  void on_pushButton_mod_clicked();

  void on_pushButton_square_open_clicked();

  void on_pushButton_square_close_clicked();

  void on_pushButton_sin_clicked();

  void on_pushButton_div_clicked();

  void on_pushButton_tan_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_mult_clicked();

  void on_pushButton_ln_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_minus_clicked();

  void on_pushButton_log_clicked();

  void on_pushButton_0_clicked();

  void on_pushButton_dot_clicked();

  void on_pushButton_plus_clicked();

  void on_pushButton_sqrt_clicked();

  void on_pushButton_acos_clicked();

  void on_pushButton_asin_clicked();

  void on_pushButton_atan_clicked();

  void on_pushButton_C_clicked();

  void on_pushButton_x_clicked();

  void on_pushButton_drawGraph_clicked();

  void on_pushButton_credit_clicked();
};
} //namespace s21
#endif  // VIEW_H
