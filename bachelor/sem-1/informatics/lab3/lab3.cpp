#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double pi = acos(-1.0);
    double a = pi / 5.0, b = pi;
    double h = (b - a) / 10.0;
    double eps = 1e-4;
    int n = 40;

    for (double x = a; x <= b; x += h) {
        double sn = 0.0;
        for (int i = 1; i <= n; i++) {
            double term = cos((2 * i - 1) * x) / pow(2 * i - 1, 2);
            sn += term;
        }

        double se = 0.0;
        int i = 1;
        double term2;
        do {
            term2 = cos((2 * i - 1) * x) / pow(2 * i - 1, 2);
            se += term2;
            i++;
        } while (fabs(term2) >= eps);

        double y = (pi * pi) / 8.0 - (pi / 4.0) * fabs(x);

        cout << "X=" << x << "    SN=" << sn << "    SE=" << se << "    Y=" << y << endl;
    }
}
