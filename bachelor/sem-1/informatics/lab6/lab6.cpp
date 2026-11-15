#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[256], words[128][256];
    int n = 0, k = 0;

    cout << "Vvedite stroku s tochkoy v kontse:\n";
    cin.getline(s, 256);

    for (int i = 0; s[i] != '.' && s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            words[n][k] = s[i];
            k++;
        } else if (k > 0) {
            words[n][k] = '\0';
            n++;
            k = 0;
        }
    }
    if (k > 0) {
        words[n][k] = '\0';
        n++;
    }

    int best = 0, maxCount = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            best = i;
        }
    }

    if (n > 0) {
        cout << "Samoe chastoe slovo: " << words[best] << endl;
        cout << "Kolichestvo povtoreniy: " << maxCount << endl;
    } else {
        cout << "V stroke net slov." << endl;
    }
    return 0;
}
