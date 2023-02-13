#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <string>
#include <vector>

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
    std::vector<std::string> functions_table;

    std::vector<Token> str_to_tokens(std::string &input_str);
    std::vector<Token> infix_to_rpn(const std::vector<Token> &input_expression);
    double rpn_to_result(const std::vector<Token> &input_rpn);
    bool is_operator(char input);
    bool is_function(char input);
};

#endif // MODEL_H
