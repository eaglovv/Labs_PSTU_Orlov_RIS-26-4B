#include <iostream>

using namespace std;

const int N = 4;

void printMatrix(int a[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

bool checkAndSwap(int a[N][N])
{
    int pickedRow[N];
    int prev = -1000000;

    for (int i = 0; i < N; i++) {
        int col = N - 1 - i;
        int bestRow = -1;

        for (int r = 0; r < N; r++) {
            if (i == 0 || a[r][col] > prev) {
                if (bestRow == -1 || a[r][col] < a[bestRow][col]) {
                    bestRow = r;
                }
            }
        }

        if (bestRow == -1) return false;
        pickedRow[i] = bestRow;
        prev = a[bestRow][col];
    }

    for (int i = 0; i < N; i++) {
        int col = N - 1 - i;
        int r = pickedRow[i];
        int temp = a[i][col];
        a[i][col] = a[r][col];
        a[r][col] = temp;
    }
    return true;
}

int main()
{
    int a[N][N] = {
        { 12,  8, 15,  9 },
        {  5, 14,  3,  2 },
        {  9,  4, 11,  7 },
        { 10,  6,  8,  4 }
    };

    cout << "Ishodnaya matrica:" << endl;
    printMatrix(a);

    if (checkAndSwap(a)) {
        cout << "\nMozhno! Matrica posle perestanovok:" << endl;
        printMatrix(a);
        cout << "Pobochnaya diagonal: ";
        for (int i = 0; i < N; i++)
            cout << a[i][N - 1 - i] << " ";
        cout << endl;
    } else {
        cout << "\nNelzya raspolozhit po vozrastaniyu." << endl;
    }

    return 0;
}
