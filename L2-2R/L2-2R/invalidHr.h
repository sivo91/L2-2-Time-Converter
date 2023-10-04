


#pragma once
#include <iostream>
#include <string>

using namespace std;

class invalidHr {
private:
    string message;
public:
    invalidHr() : message("Invalid Hour Input!") {}
    invalidHr(const string& msg) : message(msg) {}
    const string& getErrorMessage() const {
        return message;
    }
};