#include <iostream>
#include <vector>
#include <chrono>
#include "LCS.h"

using namespace std;

int main()
{
    string s1 = "HABRAHABR";
    string s2 = "HARBOUR";
    cout << lcs(s1, s2);
}