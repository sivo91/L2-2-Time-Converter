#pragma once
#include <string>

using namespace std;

class invalidMin {
private:
    string message;
public:
    invalidMin() : message("Invalid Minute Input!") {}
    invalidMin(const string& msg) : message(msg) {}
    const string& getErrorMessage() const {
        return message;
    }
};
