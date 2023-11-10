#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int countWaysRecursive(int N) {
    if (N < 0) return 0;
    if (N == 0) return 1;
    return countWaysRecursive(N - 1) + countWaysRecursive(N - 2) + countWaysRecursive(N - 3);
}

int countWays(int N) {
    if (N == 0) return 1;
    if (N == 1) return 1;
    if (N == 2) return 2;

    vector<int> dp(N + 1);
    dp[0] = 1; // 1 способ добраться до начала лестницы
    dp[1] = 1; // 1 способ добраться до первой ступеньки
    dp[2] = 2; // 2 способа добраться до второй ступеньки

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[N];
}

int main() {
    int N = 30; // Можно установить другое значение для N

    auto start_rec = chrono::high_resolution_clock::now();
    cout << "Рекурсивно: " << countWaysRecursive(N) << endl;
    auto end_rec = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec = end_rec - start_rec;
    cout << "Время выполнения рекурсией: " << elapsed_rec.count() << " мс" << endl;

    auto start_dp = chrono::high_resolution_clock::now();
    cout << "С использованием ДП: " << countWays(N) << endl;
    auto end_dp = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_dp = end_dp - start_dp;
    cout << "Время выполнения с использованием ДП: " << elapsed_dp.count() << " мс" << endl;

    return 0;
}

