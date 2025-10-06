#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    int a[n][n];
    int i, j, dop;
    //Заповнюємо матрицю
    cout << "Введіть елементи матриці 5x5:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    // Створюємо масив головної діагоналі
    int diag[n];
    for (i = 0; i < n; i++) {
        diag[i] = a[i][i];
    }

    // Метод екстремальних елементів для знаходження мінімального числа
    for (i = 0; i < n - 1; i++) {
        int minim = i;
        for (j = i + 1; j < n; j++) {
            if (diag[j] < diag[minim])
                minim = j;
        }
        dop = diag[i];
        diag[i] = diag[minim];
        diag[minim] = dop;
    }

    cout << "Мінімальний елемент головної діагоналі = " << diag[0] << endl;

    return 0;
}