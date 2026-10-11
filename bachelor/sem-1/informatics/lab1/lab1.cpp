#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // пример с float
    float a_f = 1000.0f;
    float b_f = 0.0001f;
    float res_f = (pow(a_f - b_f, 3) - (pow(a_f, 3) - 3.0f * pow(a_f, 2) * b_f)) / (pow(b_f, 3) - 3.0f * a_f * pow(b_f, 2));

    // пример с double
    double a_d = 1000.0;
    double b_d = 0.0001;
    double res_d = (pow(a_d - b_d, 3) - (pow(a_d, 3) - 3.0 * pow(a_d, 2) * b_d)) / (pow(b_d, 3) - 3.0 * a_d * pow(b_d, 2));

    cout << "float:  " << res_f << endl;
    cout << "double: " << res_d << endl;

    return 0;
}
