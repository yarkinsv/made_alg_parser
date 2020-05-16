#include "lexer.h"
#include <iostream>
#include <map>

using namespace std;


static float parse_value(Lexer& lexer, map<char, float>& result) {
    lexer.skip_spaces();
    if (lexer.current() == '-') {
        lexer.next();
        return -parse_value(lexer, result);
    }
    if (lexer.is_variable()) {
        char variable = lexer.get_variable();
        lexer.skip_spaces();
        if (!result.count(variable)) {
            throw invalid_argument("Got unknown variable");
        }
        return result[variable];
    } else {
        return lexer.get_number();
    }
}


static float parse_term(Lexer& lexer, map<char, float>& result) {
    float termValue = parse_value(lexer, result);

    while (lexer.current() == '/') {
        lexer.next();
        float divisor = parse_value(lexer, result);
        if (divisor == 0) {
            throw invalid_argument("Division by zero");
        }
        termValue /= divisor;
    }

    if (lexer.current() == '*') {
        lexer.next();
        return termValue * parse_term(lexer, result);
    }

    return termValue;
}

static float parse_expression(Lexer& lexer, map<char, float>& result) {
    float termValue = parse_term(lexer, result);
    if (lexer.current() == '+') {
        lexer.next();
        return termValue + parse_expression(lexer, result);
    } else if (lexer.current() == '-') {
        return termValue + parse_expression(lexer, result);
    }
    return termValue;
}


static void parse_assignment(Lexer& lexer, map<char, float>& result) {
    if (lexer.eof(false)) {
        return;
    }
    char variable = lexer.get_variable();
    lexer.get_equals();
    result[variable] = parse_expression(lexer, result);
}


static map<char, float> parse_script(const string& input) {
    map<char, float> result;
    Lexer lexer (input);
    while (!lexer.eof(true)) {
        parse_assignment(lexer, result);
    }
    for (auto& a : result) {
        std::cout << a.first << " = " << a.second << '\n';
    }
    return result;
}


void eval(const string& input) {
    if (input.length() == 0) {
        throw invalid_argument("Empty string");
    }
    parse_script(input);
}
