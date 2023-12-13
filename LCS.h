#include <vector>
#include <string>
#include <algorithm>

std::vector<std::vector<int>> fillMatrix(std::string& s1, std::string& s2)
{
    int m = s1.length(), n = s2.length();
    std::vector<std::vector<int>> dp;
    for (int i = 0; i < m+1; i++)
    {
        std::vector<int> per;
        for (int j = 0; j < n+1; j++)
        {
            per.push_back(0);
        }
        dp.push_back(per);
    }

    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp;
}

std::string lcs(std::string& s1, std::string& s2)
{
    std::vector<std::vector<int>> L = fillMatrix(s1, s2);
    std::string word;
    int x = s1.length()-1, y = s2.length()-1;
    while (x >= 0 && y >= 0)
    {
        if (s1[x] == s2[y])
        {
            word.push_back(s1[x]);
            x--;
            y--;
        }
        else if (L[x-1][y] > L[x][y-1])
            x--;
        else
            y--;
    }
    reverse(word.begin(), word.end());
    return word;
}