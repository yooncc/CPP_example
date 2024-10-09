#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char orient[4] = {'d','u','r','l'};
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1} ;
int nn, mm, rr, cc, kk;
vector<string> myvector;

void bfs(int curX, int curY,  string curStr) 
{
    if (curStr.size()==kk) {
        if (curX==rr-1 && curY==cc-1) {
            myvector.push_back(curStr);
        }
        return;
    }
    // x,y 1,2   n,m 3,4 
    for (int i=0;i<4;i++) {
        if (curX+dx[i]<0 || curX+dx[i] >= nn) 
            continue;
        if (curY+dy[i]<0 || curY+dy[i] >= mm)
            continue;
        
        string mystring = curStr;
        mystring.append(1,orient[i]);
        bfs(curX+dx[i],curY+dy[i],mystring);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    nn = n; mm = m; rr = r; cc = c; kk = k;
    
    bfs(x-1,y-1,"");
    
    if (myvector.size()==0) {
        answer = "impossible";
    }
    else {
        sort(myvector.begin(),myvector.end());
        answer = myvector[0];
    }
    
    return answer;
}