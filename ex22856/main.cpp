#include <iostream>

using namespace std;

int node[100001][4];

int N,a,b,c,moveCnt=0,lastNode=1;

int main()
{

    cin.tie(NULL)->ios::sync_with_stdio(false);

    cin >> N;

    for (int i=0;i<N;i++) {
        cin >> a >> b >> c;
        
        node[a][0] = b;
        node[a][1] = c;
        if (b != -1) {
            node[b][2] = a;
        }
        if (c != -1) {
            node[c][2] = a;
            if (a == 1 || node[node[c][2]][3] == 1) {
                node[c][3] = 1;
                lastNode = c;
            }
            
        }
    }
   
    int nextNode = 1;
    for (;;) {
        moveCnt++;
        // cout << nextNode << " ";
        
        if (node[nextNode][0] != -1) {
            nextNode = node[nextNode][0];
            continue;
        }
        else if (node[nextNode][1] != -1) {
            nextNode = node[nextNode][1];
            continue;
        }
        else {
            if (nextNode == lastNode) {
                cout << moveCnt-1;
                // cout<<"\n"<<moveCnt-1;
                break;
            }
            int isLeft;
            if (node[node[nextNode][2]][0] == nextNode) {
                isLeft = 1;
            }
            else {
                isLeft = 0;
            }
            nextNode = node[nextNode][2];
            
            if (isLeft == 1) {
                node[nextNode][0] = -1;
            }
            else {
                node[nextNode][1] = -1;
            }
            continue;
        }
    }

    return 0;
}