#pragma once
#include <iostream>
#include <vector>
#include <climits>
#include <random>

using namespace std;

//Функция для умножения цепочки матриц
void matrixChainOrder(const vector<int>& p, vector<vector<int>>& m, vector<vector<int>>& s) {
    int n = p.size() - 1; //Количество матриц в цепочке

    //Заполняем таблицы m и s
    for (int i = 1; i <= n; ++i) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

//Перемножение двух матриц
/* vector<vector<int>> optimalMultiplication(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2){
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
} */

// Перемножение двух матриц
vector<vector<int>> optimalMultiplication(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            int sum = 0;
            for (int k = 0; k < cols1; ++k) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }

    return result;
}

// Функция для создания матрицы с случайными значениями
vector<vector<int>> generateRandomMatrix(int rows, int cols) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 10);

    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = dis(gen);
        }
    }

    return matrix;
}

//Функция для печати оптимального порядка умножения
void printOptimalOrder(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalOrder(s, i, s[i][j]);
        printOptimalOrder(s, s[i][j] + 1, j);
        cout << ")";
    }
} 

int simpleMatrixChainMultiplication(const vector<int>& p) {
    int n = p.size() - 1;

    int count = 0; // Начальное количество умножений
    int rows = p[0], cols = p[1];

    for (int i = 2; i <= n; ++i) {
        count += rows * cols * p[i]; // Умножение на следующую матрицу
        cols = p[i]; // Обновляем количество столбцов для следующего умножения
    }

    return count;
}
