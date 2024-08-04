#include <iostream>
using namespace std;

int main() {

    int cvalue,x,y;
    cin >> x >> y ;
    cvalue = 1;

    int arr[] = {0,0};
    int count =0 ;

    while(1) {
        if (arr[0]==x && arr[1]==y) {
            cout << cvalue;
            return 0;
        }
        
        count++;
        
        arr[1] +=1;
        cvalue ++;
        if (arr[0]==x && arr[1]==y) {
            cout << cvalue;
            return 0;
        }

        if (count-1 > 0) {
            for (int i=0;i<count-1;i++) {
                arr[0] -= 1;
                arr[1] += 1;
                cvalue ++;
                if (arr[0]==x && arr[1]==y) {
                    cout << cvalue;
                    return 0;
                }  
            }
        }

        if (count-1 > 0) {
            for (int i=0;i<count-1;i++) {
                arr[0] -= 1;
                cvalue ++;
                if (arr[0]==x && arr[1]==y) {
                    cout << cvalue;
                    return 0;
                }  
            }
        }

        for (int i=0;i<count+1;i++) {
            if (i==0) {
                arr[0] -= 1;
                cvalue++;
                if (arr[0]==x && arr[1]==y) {
                    cout << cvalue;
                    return 0;
                }
                    
            }
            else {
                arr[1] -= 1;
                cvalue++;
                if (arr[0]==x && arr[1]==y) {
                    cout << cvalue;
                    return 0;
                }
                    
            }
        }

        if (count-1 > 0) {
            for (int i=0;i<count-1;i++) {
                arr[0] += 1;
                arr[1] -= 1;
                cvalue ++;
                if (arr[0]==x && arr[1]==y) {
                    cout << cvalue;
                    return 0;
                }
            }
        }

        arr[0] += 1;
        arr[1] -= 1;
        cvalue ++;
        if (arr[0]==x && arr[1]==y) {
            cout << cvalue;
            return 0;
        }
            
        if (count-1 > 0) {
            for (int i=0;i<count-1;i++) {
                arr[0] += 1;
                cvalue ++;
                if (arr[0]==x && arr[1]==y) {
                    cout << cvalue;
                    return 0;
                }
                    
            }
        }



        for (int i=0;i<count+1;i++) {
            if (i==0) {
                arr[0] += 1;
                cvalue++;
                if (arr[0]==x && arr[1]==y) {
                    cout << cvalue;
                    return 0;
                }
                    
            }
            else {
                arr[1] += 1;
                cvalue++;
                if (arr[0]==x && arr[1]==y) {
                    cout << cvalue;
                    return 0;
                }
            }
        }
    }

    return 0;
}