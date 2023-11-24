#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct Expression {
    std::string expression;
    bool isComputed;
    double value;
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void evaluateExpression(std::vector<Expression> &expressions, int index) {
    std::istringstream iss(expressions[index].expression);
    std::string token;
    double result = 0.0;

    while (iss >> token) {
        if (isOperator(token[0])) {
            char oper = token[0];
            iss >> token;
            double operand = std::stod(token);

            switch (oper) {
                case '+':
                    result += operand;
                    break;
                case '-':
                    result -= operand;
                    break;
                case '*':
                    result *= operand;
                    break;
                case '/':
                    if (operand != 0)
                        result /= operand;
                    else {
                        std::cerr << "Error: Division by zero\n";
                        exit(EXIT_FAILURE);
                    }
                    break;
            }
        }
    }

    expressions[index].value = result;
    expressions[index].isComputed = true;
}

int main() {
    std::string input;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, input);

    std::istringstream inputStream(input);
    std::string token;
    std::vector<Expression> expressions;

    while (inputStream >> token) {
        expressions.push_back({token, false, 0.0});
    }

    for (size_t i = 0; i < expressions.size(); ++i) {
        if (!expressions[i].isComputed) {
            evaluateExpression(expressions, i);
        }
    }

    std::cout << "Optimized Expression: ";
    for (const auto &exp : expressions) {
        std::cout << exp.value << " ";
    }
    std::cout << std::endl;

    return 0;
}

