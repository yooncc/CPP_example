#include <iostream>
#include <vector>
using namespace std;

int main() {

    int number[] = {-3, -2, -1, 0, 1, 2, 3};
    

    int answer = 0,b=0,c=0;
    int size = 7;
    
    for (int i =0;i<size-2;i++) {
        b = i+1;
        for (int j=b;j<size-1;j++) {
            c = j+1;
            for (int l=c;l<size;l++) {
                cout << "(" <<i << " ,"<<j<<" ,"<<l<<")"<<endl;
                if (number[i]+number[j]+number[l]==0) {
                    answer++;
                }
            }
        }
    }

    return 0;
}