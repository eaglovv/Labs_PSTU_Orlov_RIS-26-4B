#include<iostream>

using namespace std;

int main()
{
    int n, z; 
    bool f = false;
    cin >> n >> z;

    while (n > 0 && !f) 
    {
        if (z == n % 10) 
        {
            f = true;
        }

    n /= 10;
    }

    if (f) {
        cout << "Цифра " << z << " есть в n.";
    }
    else {
        cout << "Цифры " << z <<  " нет в числе n.";
    }
    return 0;
}
