#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <string>
#include <vector>

#ifdef QT_MACRO
#include "QtWidgets/qlineedit.h"
#include "qlistview.h"
#include "qstandarditemmodel.h"
#endif

namespace s21 {

class Model {
 public:
  Model();
  double Calculate(std::string input_str);

#ifdef QT_MACRO
  void Concat(QLineEdit *lineEdit, const QString &src);
  QString ReplaceX(QLineEdit *lineEdit, double x);

  void FindCredit(const double &total_credit, const int &term,
                  const double &rate, const bool flag, double &overpay,
                  double &total_payment, double &payment_mouth, QListView **lv,
                  int &days_in_month);
#endif
 private:
  struct Token {
    std::string token;
    int priority;
  };

  std::map<char, int> priority_table;
  std::vector<std::string> functions_table;

  std::vector<Token> StrToTokens(std::string &input_str);
  std::vector<Token> InfixToRpn(const std::vector<Token> &input_expression);
  double RpnToResult(const std::vector<Token> &input_rpn);
  bool IsOperator(char input);
  bool IsFunction(char input);
};
} // namespace s21
#endif  // MODEL_H
