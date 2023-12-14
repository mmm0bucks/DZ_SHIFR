
#include <iostream>
using namespace std; 


int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack_classic(int W, int wt[], int val[], int n) 
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
int knapSack_reduce_memory(int W, int wt[], int val[], int n) 
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
int knapSack_naive(int W, int wt[], int val[], int n) 
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

int test_cases() 
{ 
	int profit[] = { 60, 100, 120 }; 
	int weight[] = { 10, 20, 30 }; 
	int W = 50; 
    int n = sizeof(profit) / sizeof(profit[0]); 
    cout<<"maximum capacity: "<<endl;
	cout << "Classic way with O(N*W) memory: "<<knapSack_classic(W, weight, profit, n)<<endl; 
    cout << "O(W) memory approach: "<<knapSack_reduce_memory(W, weight, profit, n)<<endl; 
    cout << "Naive approach: "<<knapSack_naive(W, weight, profit, n)<<endl; 
    int weight1[] = {2, 3, 4, 5};
    int profit1[] = {3, 4, 5, 6};
    int W1 = 5;
	int n1 = sizeof(profit1) / sizeof(profit1[0]);
    cout<<"maximum capacity: "<<endl;
	cout << "Classic way with O(N*W) memory: "<<knapSack_classic(W1, weight1, profit1, n1)<<endl; 
    cout << "O(W) memory approach: "<<knapSack_reduce_memory(W1, weight1, profit1, n1)<<endl; 
    cout << "Naive approach: "<<knapSack_naive(W1, weight1, profit1, n1)<<endl; 
    int weight2[] = {1, 2, 3, 4, 5};
    int profit2[] = {10, 40, 30, 50, 60};
    int W2 = 8;
	int n2 = sizeof(profit2) / sizeof(profit2[0]); 
    cout<<"maximum capacity: "<<endl;
	cout << "Classic way with O(N*W) memory: "<<knapSack_classic(W2, weight2, profit2, n2)<<endl; 
    cout << "O(W) memory approach: "<<knapSack_reduce_memory(W2, weight2, profit2, n2)<<endl; 
    cout << "Naive approach: "<<knapSack_naive(W2, weight2, profit2, n2)<<endl; 
    int weight3[] = {1};
    int profit3[] = {5};
    int W3 = 8;
	int n3 = sizeof(profit3) / sizeof(profit3[0]); 
    cout<<"maximum capacity: "<<endl;
	cout << "Classic way with O(N*W) memory: "<<knapSack_classic(W3, weight3, profit3, n3)<<endl; 
    cout << "O(W) memory approach: "<<knapSack_reduce_memory(W3, weight3, profit3, n3)<<endl; 
    cout << "Naive approach: "<<knapSack_naive(W3, weight3, profit3, n3)<<endl; 
    int weight4[] = {3,4};
    int profit4[] = {1,2};
    int W4 = 8;
	int n4 = sizeof(profit4) / sizeof(profit4[0]); 
    cout<<"maximum capacity: "<<endl;
	cout << "Classic way with O(N*W) memory: "<<knapSack_classic(W4, weight4, profit4, n4)<<endl; 
    cout << "O(W) memory approach: "<<knapSack_reduce_memory(W4, weight4, profit4, n4)<<endl; 
    cout << "Naive approach: "<<knapSack_naive(W4, weight4, profit4, n4)<<endl; 

	return 0; 
} 



