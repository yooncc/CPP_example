#include <iostream>

using namespace std;

int N, K, savePoint=0,sLength,dup[200001] = { 0, },An[100001] = {0,},maxSum=0;


int main()
{

    cin.tie(NULL)->ios::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
       int x;
       cin >> x;
       An[i] = x;
       dup[x]++;
 
       if (dup[x] > K) {     
            for (int j=0;j<100000;j++) {
                if (An[j] == x) {
                    An[j] = 0;
                    if (savePoint <= j) {
                        savePoint = j+1;
                    }
                    break;
                }
            }
            dup[x]--;
            
            if (sLength > maxSum) {
                maxSum = sLength;
            }
            sLength = i - savePoint+1;
        }
        else {
            sLength++;
        }
    }

    if (sLength > maxSum) {
        maxSum = sLength;
    }

    cout << maxSum << endl;


    return 0;
}
