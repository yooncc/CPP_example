#include <iostream>
#define ARR_MAX 200000
#define VALUE_MAX 100000

using namespace std;

int N,K,seqLen,maxLen,cnt,seq[ARR_MAX];

int main() {
    cin.tie(NULL)->ios::sync_with_stdio(false);

    cin >> N >> K;
    for (int i=0;i<N;i++) {
        cin >> seq[i];
    }
    cnt = 0;
    maxLen = 0;
    while (cnt != N) {
        seqLen =0;
        int valueCnt[VALUE_MAX] = {0,};
        for (int i=cnt;i<N;i++) {
            valueCnt[seq[i]]++;
            if (valueCnt[seq[i]] > K) {
                cnt++;
                if (maxLen < seqLen) {
                    maxLen = seqLen;
                }
                break;
            }
            seqLen++;
            if (i == N-1) {
                cnt = N;
            }
        }
    }
    
    cout << maxLen;

}