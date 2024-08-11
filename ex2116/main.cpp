#include <iostream>
#include <vector>
#define MAX_DICE 20000

using namespace std;

int N,topPoint,bottomPoint,sum[6]={0,0,0,0,0,0};
int dice[MAX_DICE][6];

int getOppositeNum(int);
int getMaxNum(int,int);

int main()
{
    cin.tie(NULL)->ios::sync_with_stdio(false);
    cin >> N;
    
    for (int j=0;j<N;j++) {
        for (int i=0;i<6;i++) {
            cin >> dice[j][i];
        }
    }

    for (int j=0;j<6;j++) {
        topPoint = dice[0][j];
        bottomPoint = dice[0][getOppositeNum(j)]; 
        sum[j] += getMaxNum(topPoint,bottomPoint);
        for (int k=1;k<N;k++) {
            bottomPoint= topPoint;
            for (int i=0;i<6;i++) {
                if (dice[k][i] == bottomPoint) {
                    topPoint = dice[k][getOppositeNum(i)];
                    break;
                }
            }
            sum[j] += getMaxNum(topPoint,bottomPoint);
        }
    }
    
    int max = sum[0];
    for (int i =1;i<6;i++) {
        if (max < sum[i]) {
            max = sum[i];
        }
    }
    cout << max;

    return 0;
}

int getMaxNum(int top,int bottom) {
    if (bottom+top == 11) {
        return 4;
    }
    else if (bottom==6 || top == 6) {
        return 5;
    }
    else {
        return 6;
    }
}

int getOppositeNum(int current) {
    switch(current) {
        case 0 :
        return 5;
        break;
        case 1 :
        return 3;
        break;
        case 2 :
        return 4;
        break;
        case 3 :
        return 1;
        break;
        case 4 :
        return 2;
        break;
        case 5 :
        return 0;
        break;
    }
}