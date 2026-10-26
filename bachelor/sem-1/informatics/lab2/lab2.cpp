#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double eps = 1e-4;
    int n = 1;
    double fact = 1.0;
    double a_n, sum = 0.0;

    do {
        fact *= n;
        a_n = log10(fact) * exp(-n * sqrt(n));
        sum += a_n;
        cout << "n = " << n << "  a_n = " << a_n << "  sum = " << sum << endl;
        n++;
    } while (a_n >= eps || n == 2);

    cout << "Summa ryada = " << sum << endl;

    return 0;
}
