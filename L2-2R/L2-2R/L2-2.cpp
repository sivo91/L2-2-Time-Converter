


#include <iostream>
#include <string>
#include "invalidHr.h"
#include "invalidMin.h"
#include "invalidSec.h"

using namespace std;

// prototype
void validateAndConvertTo24Hr(string time);

int main() {

    string timeInput;
    cout << "Enter time in 12-hour format (hh:mm:ssAM/PM): ";
    getline(cin, timeInput); 

    try {
        validateAndConvertTo24Hr(timeInput);
    }
    catch (const invalidHr& e) {
        cout << e.getErrorMessage() << endl;
    }
    catch (const invalidMin& e) {
        cout << e.getErrorMessage() << endl;
    }
    catch (const invalidSec& e) {
        cout << e.getErrorMessage() << endl;
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}



void validateAndConvertTo24Hr(string time) {

    if (time.length() != 10 && time.length() != 11) {
        throw invalid_argument("Invalid time format!");
    }

    int hr = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3, 2));
    int sec = stoi(time.substr(6, 2));
    string meridiem = time.substr(time.length() - 2, 2); 
    // this ensures that we always get the last two characters

    if (hr < 1 || hr > 12) {
        throw invalidHr("Invalid hour value");
    }

    if (min < 0 || min > 59) {
        throw invalidMin("Invalid minute value");
    }

    if (sec < 0 || sec > 59) {
        throw invalidSec("Invalid second value");
    }

    if (meridiem == "AM" || meridiem == "am") {
        hr = (hr == 12) ? 0 : hr;
    }
    else if ((meridiem == "PM" || meridiem == "pm") && hr != 12) {
        hr += 12;
    }

    cout << " Time in 24-hour format: " 
         << (hr < 10 ? "0" : "") << hr << ":"
         << (min < 10 ? "0" : "") << min << ":"
         << (sec < 10 ? "0" : "") << sec << endl;
}

