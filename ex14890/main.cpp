#include <iostream>

using namespace std;

int N,L,loadMap[101][101],res=0;


int main()
{
    cin >> N >> L;

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> loadMap[i][j];
        }
    } 

    int cmpNum;
    // for (int i=0;i<N;i++) {
    //     cmpNum = loadMap[i][0];
    //     int enable=-1;
    //     for (int j=0;j<N;j++) {
    //         int currentNum = loadMap[i][j];
            
    //         if (cmpNum != currentNum ) {
    //             if ( abs(cmpNum-currentNum) == 1 && j-L >= 0) {
    //                 for (int k=j-L;k<j;k++) {
    //                     enable = 1;
    //                     if (loadMap[i][k] != cmpNum) {
    //                         enable = -1;
    //                         break;
    //                     }
    //                 }
    //                 if (enable == -1) {
    //                     break;
    //                 }
    //                 cmpNum = currentNum;
    //             }
    //             else {
    //                 enable = -1;
    //                 break;
    //             }
    //         }
    //         else {
    //             enable = 1;
    //         }
    //     }
    //     if (enable == 1) {
    //         cout<<i<< " ";
    //         res++;
    //     }
    // }

    for (int i=0;i<N;i++) {
        cmpNum = loadMap[0][i];
        int enable=-1;
        for (int j=0;j<N;j++) {
            int currentNum = loadMap[j][i];
            
            if (cmpNum != currentNum ) {
                if ( abs(cmpNum-currentNum) == 1 && j-L >= 0) {
                    for (int k=j-L;k<j;k++) {
                        enable = 1;
                        if (loadMap[k][i] != cmpNum) {
                            enable = -1;
                            break;
                        }
                    }
                    if (enable == -1) {
                        break;
                    }
                    cmpNum = currentNum;
                }
                else {
                    enable = -1;
                    break;
                }
            }
            else {
                enable = 1;
            }
        }
        if (enable == 1) {
            cout<<i<< " ";
            res++;
        }
    }

    cout <<"\n"<< res; 


    return 0;
}