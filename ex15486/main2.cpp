#include <iostream>
#include <vector>
#define SIZE 10000

using namespace std;

int n;
int result = 0;
int t[SIZE];
int p[SIZE];
int dp[SIZE] = { 0 };
vector< pair<int, int> > v;

int main(void) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        t[i] = a;
        p[i] = b;
    }

    for (int i = 1; i <= n; i++) {
        int day = t[i];
        int pay = p[i];
        dp[i + day] = max(dp[i + day], dp[i] + pay);
        dp[i + 1] = max(dp[i], dp[i + 1]);
    }
   
    for (int i = 1; i <= (n + 1); i++) {
        result = max(dp[i], result);
    }

    cout << result;
}