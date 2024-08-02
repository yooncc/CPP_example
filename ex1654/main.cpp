
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    
    int N,K,a;
    vector<int> v;
    vector<int> s;
    
    // ex) K = 4 , N = 11 입력
    cin>> K >> N;
    
    // vector에 추가
    // ex) 802, 743, 457, 539
    for (int i=0;i<K;i++) {
        cin >> a;
        v.push_back(a);
    }
    // sort {457, 539, 743, 802}
    sort(v.begin(),v.end());
    
    unsigned int mid,start,end,sum=0;
    
    start = 0;
    end = *(v.end()-1);
    
    while(start<=end) {
        sum = 0;
        mid = (start+end)/2;
        for (auto it=v.begin();it != v.end();it++) {
            if (mid == 0) {
                continue;
            }
            sum += (*it)/mid;
        }
        
        if ( sum >= N ) {
            s.push_back((mid));
            start = mid+1;
        }
        else {
            end = mid-1;
        }
        
    }
    
    sort(s.begin(),s.end());
    
    cout<<*(s.end()-1);
    
    return 0;
}


