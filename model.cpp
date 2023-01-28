#include <vector>
#include <stack>
#include <cmath>
#include "model.h"
#include <iostream>


namespace s21 {

    Model::Model() {
        // num is 0 priority
        priority_table['('] = 1;
        priority_table[')'] = 1;
        priority_table['+'] = 2;
        priority_table['-'] = 2;
        priority_table['*'] = 3;
        priority_table['/'] = 3;
        priority_table['%'] = 3;
        priority_table['^'] = 4;
        priority_table['u'] = 5;
    }

    double Model::calculate(std::string input_str) {
        std::vector<Token> tokens = str_to_tokens(input_str);
        std::vector<Token> rpn = infix_to_rpn(tokens);

        std::cout << "Выражение: " << input_str << "\n";

        for (int i = 0; i < rpn.size(); i++) {
            std::cout << i << ". лексема: " << rpn[i].token << ", приоритет: " << rpn[i].priority << "\n";
        }



        std::cout << "\n\n" << "Обычная запись:\n" << input_str << "\n\nПольская нотация\n";


        for (int i = 0; i < rpn.size(); i++) {
            std::cout<< rpn[i].token << " ";
        }

        double res = rpn_to_result(rpn);
        std::cout << "\n\nОтвет: " << res;

        return res;
    }

    std::vector<Model::Token> Model::str_to_tokens(const std::string &input_str) {
        std::vector<Token> result;
        std::string current_token_str;
        Token current_token;
        std::size_t i = 0;
        while (i < input_str.length()) {
            // Нашли число
            if (std::isdigit(input_str[i])) {
                current_token.priority = 0;
                current_token_str.push_back(input_str[i]);
                i++;

                // Если число составное
                while (i < input_str.length() && (std::isdigit(input_str.at(i)) || input_str.at(i) == '.')) {
                    current_token_str.push_back(input_str[i]);
                    i++;
                }
            // Нашли оператор
            } else if (is_operator(input_str[i])) {
                current_token.priority = priority_table.at(input_str[i]);
                current_token_str.push_back(input_str[i]);
                i++;
            }

            current_token.token = current_token_str;
            result.push_back(current_token);
            current_token_str.clear();
        }

        return result;
    }

    // 5 + 2 * 5 / 10 + (5 - 2^2)
    // 5 2 5 * 10 / + 5 2 2 ^ - +
    std::vector<Model::Token> Model::infix_to_rpn(const std::vector<Token> &input_expression) {
        std::vector<Token> result;
        std::stack<Token> operators_stack;

        for (const Token &current_token : input_expression) {
            if (!current_token.priority) {                                              // Если число
                result.push_back(current_token);
            } else if (current_token.priority > 1) {                                    // Если оператор, кроме скобок
                if (!operators_stack.size()) {
                    operators_stack.push(current_token);
                } else if (operators_stack.top().priority >= current_token.priority) {
                    while (!operators_stack.empty()) {
                        result.push_back(operators_stack.top());
                        operators_stack.pop();
                        if (!operators_stack.empty()) {
                            if (operators_stack.top().priority < current_token.priority) {
                                break;
                            }
                        }
                    }
                    operators_stack.push(current_token);
                } else {
                    operators_stack.push(current_token);
                }
            } else if (current_token.priority == 1) {                                   // Если скобки
                if (current_token.token == "(") {
                    operators_stack.push(current_token);
                } else if (current_token.token == ")") {
                    while (operators_stack.top().token != "(") {
                        result.push_back(operators_stack.top());
                        operators_stack.pop();
                    }
                    operators_stack.pop(); // Удаляем '('
                }
            }
        }

        if (!operators_stack.empty()) {                                                 // В конце пихаем всё из стека в строку
            for (std::size_t i = 0; i < operators_stack.size(); i++) {
                result.push_back(operators_stack.top());
                operators_stack.pop();
            }
            if (!operators_stack.empty()) {
                result.push_back(operators_stack.top());
            }
        }

        return result;
    }

    double Model::rpn_to_result(const std::vector<Token> &input_rpn) {
        std::stack<Token> num_stack;
        double a = 0.0;
        double b = 0.0;
        double res = 0.0;
        Token tmp;

        for (const Token &current_token : input_rpn) {
            // Если число
            if (!current_token.priority) {
                num_stack.push(current_token);
            } else if (current_token.priority) {
                b = std::stod(num_stack.top().token);
                num_stack.pop();
                a = std::stod(num_stack.top().token);
                num_stack.pop();
                if (current_token.token == "+") {
                    res = a + b;
                } else if (current_token.token == "-") {
                    res = a - b;
                } else if (current_token.token == "*") {
                    res = a * b;
                } else if (current_token.token == "/") {
                    res = a / b;
                } else if (current_token.token == "%") {
                    res = std::fmod(a, b);
                } else if (current_token.token == "^") {
                    res = std::pow(a, b);
                }
                tmp.token = std::to_string(res);
                num_stack.push(tmp);
            }
        }

        return std::stod(num_stack.top().token);
    }

//    priority_table['+'] = 2;
//    priority_table['-'] = 2;
//    priority_table['*'] = 3;
//    priority_table['/'] = 3;
//    priority_table['%'] = 3;
//    priority_table['^'] = 4;


    bool Model::is_operator(char input) {
        auto pr = priority_table.find(input);
        return pr->second;
    }
}
