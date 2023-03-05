#include "calc.h"
#include "./ui_calc.h"

using namespace s21;

Calc::Calc(QWidget *parent) : QWidget(parent), ui(new Ui::Calc) {
  ui->setupUi(this);

  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
}

Calc::~Calc() { delete ui; }

void Calc::on_pushButton_1_clicked() { controller.Concat(ui->inputLine, "1"); }

void Calc::on_pushButton_2_clicked() { controller.Concat(ui->inputLine, "2"); }

void Calc::on_pushButton_3_clicked() { controller.Concat(ui->inputLine, "3"); }

void Calc::on_pushButton_4_clicked() { controller.Concat(ui->inputLine, "4"); }

void Calc::on_pushButton_eq_clicked() {
  double res = controller.Calculate(ui->inputLine->text());
  ui->inputLine->setText(QString::number(res, 'f', -1));
}

void Calc::on_pushButton_cos_clicked() {
  controller.Concat(ui->inputLine, "cos(");
}

void Calc::on_pushButton_pow_clicked() {
  controller.Concat(ui->inputLine, "^");
}

void Calc::on_pushButton_mod_clicked() {
  controller.Concat(ui->inputLine, "%");
}

void Calc::on_pushButton_square_open_clicked() {
  controller.Concat(ui->inputLine, "(");
}

void Calc::on_pushButton_square_close_clicked() {
  controller.Concat(ui->inputLine, ")");
}

void Calc::on_pushButton_sin_clicked() {
  controller.Concat(ui->inputLine, "sin(");
}

void Calc::on_pushButton_div_clicked() {
  controller.Concat(ui->inputLine, "/");
}

void Calc::on_pushButton_tan_clicked() {
  controller.Concat(ui->inputLine, "tan(");
}

void Calc::on_pushButton_5_clicked() { controller.Concat(ui->inputLine, "5"); }

void Calc::on_pushButton_6_clicked() { controller.Concat(ui->inputLine, "6"); }

void Calc::on_pushButton_mult_clicked() {
  controller.Concat(ui->inputLine, "*");
}

void Calc::on_pushButton_ln_clicked() {
  controller.Concat(ui->inputLine, "ln(");
}

void Calc::on_pushButton_7_clicked() { controller.Concat(ui->inputLine, "7"); }

void Calc::on_pushButton_8_clicked() { controller.Concat(ui->inputLine, "8"); }

void Calc::on_pushButton_9_clicked() { controller.Concat(ui->inputLine, "9"); }

void Calc::on_pushButton_minus_clicked() {
  controller.Concat(ui->inputLine, "-");
}

void Calc::on_pushButton_log_clicked() {
  controller.Concat(ui->inputLine, "log(");
}

void Calc::on_pushButton_0_clicked() { controller.Concat(ui->inputLine, "0"); }

void Calc::on_pushButton_dot_clicked() {
  controller.Concat(ui->inputLine, ".");
}

void Calc::on_pushButton_plus_clicked() {
  controller.Concat(ui->inputLine, "+");
}

void Calc::on_pushButton_sqrt_clicked() {
  controller.Concat(ui->inputLine, "sqrt(");
}

void Calc::on_pushButton_acos_clicked() {
  controller.Concat(ui->inputLine, "acos(");
}

void Calc::on_pushButton_asin_clicked() {
  controller.Concat(ui->inputLine, "asin(");
}

void Calc::on_pushButton_atan_clicked() {
  controller.Concat(ui->inputLine, "atan(");
}

void Calc::on_pushButton_C_clicked() { ui->inputLine->clear(); }

void Calc::on_pushButton_x_clicked() { controller.Concat(ui->inputLine, "x"); }

void Calc::on_pushButton_drawGraph_clicked() {
  QString s;
  QVector<double> x, y;

  double dotFrequency = 1.0;
  if (ui->xBeginLine->text().toDouble() <= 1000 &&
      ui->xEndLine->text().toDouble() <= 1000) {
    dotFrequency = 0.1;
  }
  if (ui->xBeginLine->text().toDouble() <= 10 &&
      ui->xEndLine->text().toDouble() <= 10) {
    dotFrequency = 0.01;
  }

  for (double i = ui->xBeginLine->text().toDouble();
       i <= ui->xEndLine->text().toDouble(); i += dotFrequency) {
    x.push_back(i);

    s = controller.ReplaceX(ui->inputLine, i);

    y.push_back(controller.Calculate(s));
  }
  ui->widget->xAxis->setRange(ui->xBeginLine->text().toInt(),
                              ui->xEndLine->text().toInt());
  ui->widget->yAxis->setRange(ui->yBeginLine->text().toInt(),
                              ui->yEndLine->text().toInt());
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(x, y);
  ui->widget->replot();
}

void Calc::on_pushButton_credit_clicked() { credit_form.show(); }
