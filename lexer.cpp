#include "lexer.h"


void Lexer::next() {
    if (input[idx] != '\0') {
        idx++;
    }
}

void Lexer::skip_spaces() {
    while (input[idx] == ' ') {
        idx++;
    }
}

void Lexer::skip_new_line() {
    while (input[idx] == '\n') {
        idx++;
    }
}

bool Lexer::eof(bool is_skip_new_line) {
    skip_spaces();
    if (is_skip_new_line) {
        skip_new_line();
        skip_spaces();
    }
    return input[idx] == '\0';
}

bool Lexer::is_variable() {
    return (input[idx] >= 'a' && input[idx] <= 'z');
};

char Lexer::get_variable() {
    if (!is_variable()) {
        throw std::invalid_argument(std::string{ "Expected variable, got " } + input[idx] + std::string{ ", at index " } + std::to_string(idx));
    }
    return input[idx++];
}

void Lexer::get_equals() {
    skip_spaces();
    if (input[idx++] != '=') {
        throw std::invalid_argument(std::string{ "Expected '=', got " } + input[idx - 1] + std::string{ ", at index " } + std::to_string(idx));
    }
    skip_spaces();
}

char Lexer::current() {
    return input[idx];
}


float Lexer::get_number() {
    skip_spaces();
    int start = idx;
    while (input[idx] >= '0' & input[idx] <= '9') {
        idx++;
    }
    if (start == idx) {
        throw std::invalid_argument(std::string{ "Expected number, got " } + input[idx] + std::string{ ", at index " } + std::to_string(idx));
    }
    int end = idx++;
    skip_spaces();
    return stof(input.substr(start, end - start));
}
