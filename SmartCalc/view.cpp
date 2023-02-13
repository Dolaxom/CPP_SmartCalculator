#include "view.h"
#include "./ui_view.h"

View::View(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
}

void View::on_pushButton_1_clicked()
{
    Controller::Concat(ui->inputLine, "1");
}


void View::on_pushButton_2_clicked()
{
    Controller::Concat(ui->inputLine, "2");
}


void View::on_pushButton_3_clicked()
{
    Controller::Concat(ui->inputLine, "3");
}


void View::on_pushButton_4_clicked()
{
    Controller::Concat(ui->inputLine, "4");
}


void View::on_pushButton_eq_clicked()
{
    double res = model.calculate(ui->inputLine->text().toStdString());
    ui->inputLine->setText(QString::number(res, 'f', -1));
}

void View::on_pushButton_cos_clicked()
{
    Controller::Concat(ui->inputLine, "cos(");
}


void View::on_pushButton_pow_clicked()
{
    Controller::Concat(ui->inputLine, "^");
}


void View::on_pushButton_mod_clicked()
{
    Controller::Concat(ui->inputLine, "%");
}


void View::on_pushButton_square_open_clicked()
{
    Controller::Concat(ui->inputLine, "(");
}


void View::on_pushButton_square_close_clicked()
{
    Controller::Concat(ui->inputLine, ")");
}


void View::on_pushButton_sin_clicked()
{
    Controller::Concat(ui->inputLine, "sin(");
}


void View::on_pushButton_div_clicked()
{
    Controller::Concat(ui->inputLine, "/");
}


void View::on_pushButton_tan_clicked()
{
    Controller::Concat(ui->inputLine, "tan(");
}


void View::on_pushButton_5_clicked()
{
    Controller::Concat(ui->inputLine, "5");
}


void View::on_pushButton_6_clicked()
{
    Controller::Concat(ui->inputLine, "6");
}


void View::on_pushButton_mult_clicked()
{
    Controller::Concat(ui->inputLine, "*");
}


void View::on_pushButton_ln_clicked()
{
    Controller::Concat(ui->inputLine, "ln(");
}


void View::on_pushButton_7_clicked()
{
    Controller::Concat(ui->inputLine, "7");
}


void View::on_pushButton_8_clicked()
{
    Controller::Concat(ui->inputLine, "8");
}


void View::on_pushButton_9_clicked()
{
    Controller::Concat(ui->inputLine, "9");
}


void View::on_pushButton_minus_clicked()
{
    Controller::Concat(ui->inputLine, "-");
}


void View::on_pushButton_log_clicked()
{
    Controller::Concat(ui->inputLine, "log(");
}


void View::on_pushButton_0_clicked()
{
    Controller::Concat(ui->inputLine, "0");
}


void View::on_pushButton_dot_clicked()
{
    Controller::Concat(ui->inputLine, ".");
}


void View::on_pushButton_plus_clicked()
{
    Controller::Concat(ui->inputLine, "+");
}


void View::on_pushButton_sqrt_clicked()
{
    Controller::Concat(ui->inputLine, "sqrt(");
}


void View::on_pushButton_acos_clicked()
{
    Controller::Concat(ui->inputLine, "acos(");
}


void View::on_pushButton_asin_clicked()
{
    Controller::Concat(ui->inputLine, "asin(");
}


void View::on_pushButton_atan_clicked()
{
    Controller::Concat(ui->inputLine, "atan(");
}


void View::on_pushButton_C_clicked()
{
    ui->inputLine->clear();
}



void View::on_pushButton_x_clicked()
{
    Controller::Concat(ui->inputLine, "x");
}
