#include <iostream>
using namespace std;

int convert(int hours, int minutes) {
    int total = hours * 60 + minutes;
    return total;
}

void convert(int total) {
    int hours = total / 60;
    int minutes = total % 60;
    cout << hours << " ch. " << minutes << " min." << endl;
}

int main() {
    int hours, minutes, total;

    cout << "Vvedite chasy i minuty: ";
    cin >> hours >> minutes;
    cout << "V minutah: " << convert(hours, minutes) << endl;

    cout << "Vvedite kolichestvo minut: ";
    cin >> total;
    cout << "Chasy i minuty: ";
    convert(total);

    return 0;
}
