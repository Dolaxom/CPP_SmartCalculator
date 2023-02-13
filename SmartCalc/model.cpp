#include <stack>
#include <cmath>
#include "model.h"
#include <iostream>


Model::Model() : functions_table({"cos", "sin", "tan", "tg", "tan", "acos",
                                  "asin", "atan", "sqrt", "ln", "log"}) {
    // functions is -1 priority
    // num is 0 priority
    priority_table['('] = 1;
    priority_table[')'] = 1;
    priority_table['+'] = 2;
    priority_table['-'] = 2;
    priority_table['*'] = 3;
    priority_table['/'] = 3;
    priority_table['%'] = 3;
    priority_table['^'] = 4;
    priority_table['u'] = 5; // унарный минус
}

double Model::calculate(std::string input_str) {
    std::vector<Token> tokens;
    try {
        tokens = str_to_tokens(input_str);
    } catch (...) {
        return INFINITY;
    }
    std::vector<Token> rpn = infix_to_rpn(tokens);

    std::cout << "\n\n" << "Обычная запись:\n" << input_str << "\n\nПольская нотация\n";

    for (auto & i : rpn) {
        std::cout<< i.token << " ";
    }

    double res = 0.0f;
    try {
        res = rpn_to_result(rpn);
    } catch (...) {
        res = INFINITY;
    }

    std::cout << std::fixed <<"\n\nОтвет: " << res;

    return res;
}

std::vector<Model::Token> Model::str_to_tokens(std::string &input_str) {
    std::vector<Token> result;
    std::string current_token_str;
    Token current_token;
    std::size_t i = 0;
    while (i < input_str.length()) {
        // Убираем пробелы
        if (input_str[i] == ' ') {
            i++;
            continue;
        }

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
            // Проверка на унарные операторы
            if ((is_operator(input_str[i - 1]) || !i) && input_str[i - 1] != ')') {
                if (input_str[i] == '+') {
                    i++;
                    continue;
                }
                if (input_str[i] == '-') input_str[i] = 'u';
            }
            current_token.priority = priority_table.at(input_str[i]);
            current_token_str.push_back(input_str[i]);
            i++;
        // Нашли функцию
        } else if (is_function(input_str[i])) {
            current_token.priority = -1;
            current_token_str.push_back(input_str[i]);
            i++;

            // Если число составное
            while (i < input_str.length() && input_str[i] != '(') {
                current_token_str.push_back(input_str[i]);
                i++;
            }
        } else {
            throw std::runtime_error("Пример говно");
        }

        current_token.token = current_token_str;
        result.push_back(current_token);
        current_token_str.clear();
    }

    return result;
}

std::vector<Model::Token> Model::infix_to_rpn(const std::vector<Token> &input_expression) {
    std::vector<Token> result;
    std::stack<Token> operators_stack;

    for (const Token &current_token : input_expression) {
        if (!current_token.priority) {                                              // Если число
            result.push_back(current_token);
        } else if (current_token.priority > 1) {                                    // Если оператор, кроме скобок
            if (operators_stack.empty()) {
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
                // Проверка на функцию
                if (!operators_stack.empty()) {
                    if (operators_stack.top().priority == -1) {
                        result.push_back(operators_stack.top());
                        operators_stack.pop();
                    }
                }
            }
        } else if (current_token.priority == -1) {                                  // Если функция
            operators_stack.push(current_token);
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
        } else if (current_token.priority > 1 && current_token.priority < 5 ) {
            if (num_stack.empty()) {
                throw std::runtime_error("Пример говно");
            }
            b = std::stod(num_stack.top().token);
            num_stack.pop();
            if (num_stack.empty()) {
                throw std::runtime_error("Пример говно");
            }
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
        } else if (current_token.priority == -1) {
            if (num_stack.empty()) {
                throw std::runtime_error("Пример говно");
            }
            a = std::stod(num_stack.top().token);
            num_stack.pop();
            if (current_token.token == "cos") {
                res = cos(a);
            } else if (current_token.token == "sin") {
                res = sin(a);
            } else if (current_token.token == "tan" || current_token.token == "tg") {
                res = tan(a);
            } else if (current_token.token == "acos") {
                res = acos(a);
            } else if (current_token.token == "asin") {
                res = asin(a);
            } else if (current_token.token == "atan") {
                res = atan(a);
            } else if (current_token.token == "sqrt") {
                if (a < 0) {
                    throw std::out_of_range("sqrt value must be >= 0");
                }
                res = sqrt(a);
            } else if (current_token.token == "ln") {
                res = log(a);
            } else if (current_token.token == "log") {
                res = log10(a);
            }

            tmp.token = std::to_string(res);
            num_stack.push(tmp);
        } else if (current_token.priority == 5) {
            if (num_stack.empty()) {
                throw std::runtime_error("Пример говно");
            }
            a = std::stod(num_stack.top().token);
            num_stack.pop();
            res  = -a;
            tmp.token = std::to_string(res);
            num_stack.push(tmp);
        }
    }

    if (num_stack.size() > 1) {
        throw std::runtime_error("Стек чисел не был пустым!");
    }
    return std::stod(num_stack.top().token);
}

bool Model::is_operator(char input) {
    return priority_table.find(input) != priority_table.end();
}

// Функция не производит полную проверку!
bool Model::is_function(char input) {
    auto it = std::find_if(functions_table.begin(), functions_table.end(),
                           [input](const std::string &s) { return s[0] == input; });

    return it != functions_table.end() ? true : false;
}
