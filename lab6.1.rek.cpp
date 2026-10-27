#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція-предикат для перевірки критерію (від'ємне парне число)
bool predict(int value) {
    return (value < 0 && value % 2 == 0);
}

// Рекурсивна функція формування масиву
void F(int* p, const int size, const int Low, const int High, int i = 0) {
    if (i >= size) return;
    p[i] = Low + rand() % (High - Low + 1);
    F(p, size, Low, High, i + 1);
}

// Рекурсивна функція виведення масиву
void out(const int* p, const int size, int i = 0) {
    if (i >= size) {
        cout << endl;
        return;
    }
    cout << setw(5) << p[i];
    out(p, size, i + 1);
}

// Рекурсивна функція обчислення кількості елементів
int countElements(const int* p, const int size, int i = 0) {
    if (i >= size) return 0;
    return (predict(p[i]) ? 1 : 0) + countElements(p, size, i + 1);
}

// Рекурсивна функція обчислення суми елементів
int sumElements(const int* p, const int size, int i = 0) {
    if (i >= size) return 0;
    return (predict(p[i]) ? p[i] : 0) + sumElements(p, size, i + 1);
}

// Рекурсивна функція заміни елементів нулями
void replaceElements(int* p, const int size, int i = 0) {
    if (i >= size) return;
    if (predict(p[i])) {
        p[i] = 0;
    }
    replaceElements(p, size, i + 1);
}

int main() {
    srand((unsigned)time(0));

    const int SIZE = 20;
    const int LOW = -20;
    const int HIGH = 34;

    int p[SIZE];

    // 1. Формування масиву (рекурсивно)
    F(p, SIZE, LOW, HIGH);

    // 2. Виведення початкового масиву (рекурсивно)
    cout << "start massive:" << endl;
    out(p, SIZE);

    // 3. Обчислення кількості та суми (рекурсивно)
    int count = countElements(p, SIZE);
    int sum = sumElements(p, SIZE);

    // 4. Виведення результатів
    cout << endl;
    cout << "count elements: " << count << endl;
    cout << "sum:      " << sum << endl;

    // 5. Заміна елементів нулями (рекурсивно)
    replaceElements(p, SIZE);

    // 6. Виведення модифікованого масиву (рекурсивно)
    cout << endl;
    cout << "mod massive:" << endl;
    out(p, SIZE);

    return 0;
}