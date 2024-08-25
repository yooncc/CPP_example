#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> height;
int sum=0;

int main()
{

    for (int i=0;i<9;i++) {
        int x;
        cin >> x; 
        height.push_back(x);
        sum += x;
    }

    sort(height.begin(),height.end());

    int a,b;
    for (int i=0;i<9;i++) {
        a = i+1;
        for (int j=a;j<9;j++) {
            if ( sum - (height[i]+height[j]) == 100 ) {
                a=i; b=j;
                break;
            }
        }
    }


    for (int i=0;i<9;i++) {
        if (i == a || i == b) {
            continue;
        }
        cout << height[i] << endl;
    }
    

    return 0;
}