#pragma once
#include <string>

using namespace std;

class invalidSec {
private:
    string message;
public:
    invalidSec() : message("Invalid Second Input!") {}
    invalidSec(const string& msg) : message(msg) {}
    const string& getErrorMessage() const {
        return message;
    }
};
