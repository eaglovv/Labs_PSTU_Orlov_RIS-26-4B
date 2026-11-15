#include <iostream>
#include <cstdarg>
#include <cstdio>
using namespace std;

int dateNumber(const char date[]) {
    int day, month, year;
    sscanf(date, "%d.%d.%d", &day, &month, &year);
    year = year + 2000;

    int monthDays[12] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};
    if (year % 4 == 0) {
        monthDays[1] = 29;
    }

    int result = day;
    for (int y = 2000; y < year; y++) {
        result = result + 365;
        if (y % 4 == 0) {
            result++;
        }
    }
    for (int m = 0; m < month - 1; m++) {
        result = result + monthDays[m];
    }
    return result;
}

void days(int n, ...) {
    va_list dates;
    va_start(dates, n);
    const char* previous = va_arg(dates, const char*);

    for (int i = 1; i < n; i++) {
        const char* current = va_arg(dates, const char*);
        int difference = dateNumber(current) - dateNumber(previous);
        if (difference < 0) {
            difference = -difference;
        }
        cout << previous << " - " << current << ": "
             << difference << " dn." << endl;
        previous = current;
    }
    va_end(dates);
}

int main() {
    cout << "3 daty:" << endl;
    days(3, "01.01.24", "10.01.24", "01.02.24");

    cout << "\n5 dat:" << endl;
    days(5, "27.02.24", "28.02.24", "29.02.24",
            "01.03.24", "02.03.24");

    cout << "\n8 dat:" << endl;
    days(8, "28.12.23", "31.12.23", "01.01.24", "15.01.24",
            "01.02.24", "28.02.24", "29.02.24", "01.03.24");
    return 0;
}
