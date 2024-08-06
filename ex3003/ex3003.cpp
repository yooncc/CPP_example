#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    //킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개
    int a,b[]={1,1,2,2,2,8};
    vector<int> v;
    for (int i=0;i<6;i++) {
        cin>>a;
        v.push_back(a);
    }
    
    for (int i=0;i<6;i++) {
        cout << b[i]-v[i] <<" ";
    } 

    return 0;
}