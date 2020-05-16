#include <iostream>

class Lexer {
public:
    Lexer(const std::string& s) : input(s), idx(0) { };

    void skip_new_line();
    void skip_spaces();
    bool eof(bool is_skip_new_line);
    char get_variable();
    void get_equals();
    char current();
    bool is_variable();
    float get_number();
    void next();

private:
    const std::string& input;
    int idx;
};
