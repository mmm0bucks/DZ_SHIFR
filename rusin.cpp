
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;


int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack_classic(int W, const vector<int> &wt, const vector<int> &val, int n) 
{ 
	int i, w; 
	vector<vector<int> > K(n + 1, vector<int>(W + 1)); 

	for (i = 0; i <= n; i++) { 
		for (w = 0; w <= W; w++) { 
			if (i == 0 || w == 0) 
				K[i][w] = 0; 
			else if (wt[i - 1] <= w) 
				K[i][w] = max(val[i - 1] 
								+ K[i - 1][w - wt[i - 1]], 
							K[i - 1][w]); 
			else
				K[i][w] = K[i - 1][w]; 
		} 
	} 
	return K[n][W]; 
} 
int knapSack_reduce_memory(int W, const vector<int> &wt, const vector<int> &val, int n) 
{ 
	int dp[W + 1]; 
	memset(dp, 0, sizeof(dp)); 

	for (int i = 1; i < n + 1; i++) { 
		for (int w = W; w >= 0; w--) { 

			if (wt[i - 1] <= w) 
				
				dp[w] = max(dp[w], 
							dp[w - wt[i - 1]] + val[i - 1]); 
		} 
	} 
	return dp[W]; 
}
int knapSack_naive(int W, const vector<int> &wt, const vector<int> &val, int n) 
{ 
  
    // Base Case 
    if (n == 0 || W == 0) 
        return 0; 
  
    if (wt[n - 1] > W) 
        return knapSack_naive(W, wt, val, n - 1); 

    else
        return max( 
            val[n - 1] 
                + knapSack_naive(W - wt[n - 1], wt, val, n - 1), 
            knapSack_naive(W, wt, val, n - 1)); 
} 


int main() {
    ifstream f("knapsack_tests.txt");
    if (!f) {
        cerr << "Ошибка открытия файла на загрузку " << endl;
        return 1;
    }

    string line1,line2;
    int n;
    int W;
    while (f>>n) {
        f>>ws;
        vector<int> profit;
        vector<int> weight;
        getline(f, line1);
        istringstream isss(line1);
        int num;
        while (isss >> num) {
            weight.push_back(num);
        }
        getline(f, line2);
        istringstream iss(line2);
        
        while (iss >> num) {
            profit.push_back(num);
        }
        f>>W;
        f>>ws;
        cout<<endl;
        cout<<"weights: "<<line1<<endl;
        cout<<"values:  "<<line2<<endl;
        cout<<"max_weight:"<<W<<endl;
        cout<<"Backpack max value:"<<knapSack_reduce_memory(W, weight, profit, n)<<endl;
    }

    return 0;
}



