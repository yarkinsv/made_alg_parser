#include <iostream>
#include <cstdlib>
#include "parser.h"
#include <iostream>
#include <fstream>


std::string read_test_case(int num) {
    std::ifstream myReadFile;
    myReadFile.open("tests/test_" + std::to_string(num));
    std::string output;
    std::string result;
    if (myReadFile.is_open()) {
        for( std::string line; getline( myReadFile, line ); ) {
            result += line;
            result += '\n';
        }
    }
    myReadFile.close();
    return result;
}

int main(int argc, const char* argv[]) {
    for (int testCase = 0; testCase < 7; testCase++) {
        std::cout << "Test case " << testCase << ":\n\n";
        std::string s = read_test_case(testCase);
        std::cout << s << '\n' ;
        std::cout << "Results:\n\n";
        try {
            eval(s);
        } catch(const std::invalid_argument& e) {
            printf("Got error: %s\n", e.what());
        }
        std::cout << "\n----------\n\n";
    }
    return 0;
}
