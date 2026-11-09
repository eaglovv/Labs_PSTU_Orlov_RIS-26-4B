#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int q[MAX_SIZE];
    int size = 0;
    int choice = 0;
    int val = 0;

    cout << "1 - Dobavit element (Enqueue)" << endl;
    cout << "2 - Udalit element (Dequeue)" << endl;
    cout << "0 - Vyhod" << endl << endl;

    while (true) {
        cout << "Vvedite komandu: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }
        if (choice == 1) {
            if (size < MAX_SIZE) {
                cout << "Vvedite chislo: ";
                cin >> val;
                q[size] = val;
                size++;
            } else {
                cout << "Oshibka: ochered perepolnena!" << endl;
            }
        } else if (choice == 2) {
            if (size > 0) {
                val = q[0];
                for (int i = 0; i < size - 1; i++) {
                    q[i] = q[i + 1];
                }
                size--;
                cout << "Udalen element: " << val << endl;
            } else {
                cout << "Oshibka: ochered pusta!" << endl;
            }
        }

        // Vivod sostoyaniya ocheredi posle operatsii
        cout << "Tekushchaya ochered: ";
        if (size == 0) {
            cout << "[pusto]";
        } else {
            for (int i = 0; i < size; i++) {
                cout << q[i] << " ";
            }
        }
        cout << endl << endl;
    }

    return 0;
}
