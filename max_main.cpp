#include <iostream>
#include <vector>
#include "max_code.h"

using namespace std;

int main() {
    // Размеры матриц в цепочке
    vector<int> matrixSizes = {10,100,5,50};

    // Проверяем, достаточно ли данных для умножения матриц
    if (matrixSizes.size() < 2) {
        cerr << "Недостаточно данных для умножения матриц" << endl;
        return 1;
    }

    // Создаем таблицы для хранения промежуточных результатов
    int n = matrixSizes.size() - 1;
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    // Вызываем функцию для расчета оптимального порядка умножения
    matrixChainOrder(matrixSizes, m, s);

    // Выводим минимальное количество умножений
    cout << "Minimum number of multiplications: " << m[1][n] << endl;

    // Выводим оптимальный порядок умножения
    cout << "Optimal multiplication order: ";
    printOptimalOrder(s, 1, n);
    cout << endl; 

    // Расчет и вывод количества умножений для простого метода
    int simpleMultiplications = simpleMatrixChainMultiplication(matrixSizes);
    cout << "Number of multiplications (simple): " << simpleMultiplications << endl;
    
     // Создаем случайные матрицы по размерам вектора p
    vector<vector<vector<int>>> matrices(matrixSizes.size()-1);
    for (size_t i = 0; i < matrixSizes.size(); ++i) {
        matrices[i] = generateRandomMatrix(matrixSizes[i], matrixSizes[i + 1]);
    }

    // Выводим результат перемножения матриц по оптимальному пути
    cout << "Result of multiplication: " << endl;
    optimalMultiplication(matrices[1], s);//, 1, n);

    return 0;
}
