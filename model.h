#ifndef SMARCCALC_MODEL_H
#define SMARCCALC_MODEL_H

#include <string>
#include <map>

namespace s21 {
    class Model {
    public:
        Model();
        double calculate(std::string input_str);

    private:
        struct Token {
            std::string token;
            int priority;
        };

        std::map<char, int> priority_table;

        std::vector<Token> str_to_tokens(const std::string &input_str);
        std::vector<Token> infix_to_rpn(const std::vector<Token> &input_expression);
        double rpn_to_result(const std::vector<Token> &input_rpn);
        bool is_operator(char input);
    };
}


#endif //SMARCCALC_MODEL_H
