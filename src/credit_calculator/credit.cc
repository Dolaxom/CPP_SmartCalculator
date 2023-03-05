#include "credit.h"
#include "ui_credit.h"

using namespace s21;

Credit::Credit(QWidget *parent) : QWidget(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
}

Credit::~Credit() { delete ui; }

void Credit::on_pushButton_calculate_clicked() {
  // clear
  ui->inputOverpaymentLine->clear();
  ui->inputTotalPaymentLine->clear();
  ui->listViewMountlyPayment->reset();

  // get values
  total_credit_amount =
      ui->inputTotalCreditAMountLine->toPlainText().toDouble();
  term = ui->inputTermLine->toPlainText().toInt();
  interest_rate = ui->inputInterestRateLine->toPlainText().toDouble();
  flag = ui->checkBoxDifferentiated->isChecked();

  // set values
  controller.FindCredit(total_credit_amount, term, interest_rate, flag, overpay,
                        total_payment, payment_mouth,
                        &ui->listViewMountlyPayment);
  ui->inputOverpaymentLine->setText(QString::number(overpay));
  ui->inputTotalPaymentLine->setText(QString::number(total_payment));
}
