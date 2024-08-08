#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> participant[2001];
int min,cnt,N,M,visited[2001];

void dfs(int s) {
    cnt++;
    if (cnt == 5) {
        cout << "1";
        exit(0);
    }
    visited[s] = true;
    cout << s << ' ';
    for (int i =0;i<N;i++) {
        int y = participant[s][i];
        if (!visited[y]) {
            dfs(y);
            // visited[] = false;
        }
    }
}

int main()
{
    cin.tie(NULL)->ios::sync_with_stdio(false);
    
    cin >> N >> M;
    
    for (int i=0;i<M;i++) {
        int x,y;
        cin >> x >> y;
        
        participant[y].push_back(x);
        participant[x].push_back(y);
    }

    stack<int> q;

    dfs(0);
    cout << "0";
    return 0;

}

