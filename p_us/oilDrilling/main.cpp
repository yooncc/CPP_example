#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// bool visited[501][501] = {0,};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int sum[501] = {0,};
int maxSum=0;
queue< pair<int,int> > q;

int solution(vector< vector<int> > &land);
void bfs(int x,int y,vector< vector<int> > &land);

int main()
{
    vector< vector<int> > land;
    // vector<int> v1;
    // v1.push_back(0);
    // v1.push_back(0);
    // v1.push_back(0);
    // v1.push_back(1);
    // v1.push_back(1);
    // v1.push_back(1);
    // v1.push_back(0);
    // v1.push_back(0);
    // vector<int> v2;
    // v2.push_back(0);
    // v2.push_back(0);
    // v2.push_back(0);
    // v2.push_back(0);
    // v2.push_back(1);
    // v2.push_back(1);
    // v2.push_back(0);
    // v2.push_back(0);
    // vector<int> v3;
    // v3.push_back(1);
    // v3.push_back(1);
    // v3.push_back(0);
    // v3.push_back(0);
    // v3.push_back(0);
    // v3.push_back(1);
    // v3.push_back(1);
    // v3.push_back(0);
    // vector<int> v4;
    // v4.push_back(1);
    // v4.push_back(1);
    // v4.push_back(1);
    // v4.push_back(0);
    // v4.push_back(0);
    // v4.push_back(0);
    // v4.push_back(0);
    // v4.push_back(0);
    // vector<int> v5;
    // v5.push_back(1);
    // v5.push_back(1);
    // v5.push_back(1);
    // v5.push_back(0);
    // v5.push_back(0);
    // v5.push_back(0);
    // v5.push_back(1);
    // v5.push_back(1);
    // land.push_back(v1);
    // land.push_back(v2);
    // land.push_back(v3);
    // land.push_back(v4);
    // land.push_back(v5);
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(0);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(0);
    vector<int> v3;
    v3.push_back(0);
    v3.push_back(0);
    v3.push_back(0);
    v3.push_back(1);
    v3.push_back(1);
    v3.push_back(1);
    vector<int> v4;
    v4.push_back(0);
    v4.push_back(0);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(0);
    v4.push_back(0);
    land.push_back(v1);
    land.push_back(v2);
    land.push_back(v3);
    land.push_back(v4);

    solution(land);
    
    return 0;
}

void bfs(int x,int y,vector< vector<int> > &land) {
     int oilCount =0;
     int minY;
     int maxY;
    
     q.push(make_pair(x,y));

     land[x][y] = 2;
     oilCount++;
     minY=y,maxY=y;

     while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k=0;k<4;k++) {
            int nx = i+dy[k]; 
            int ny = j+dx[k];
            if (nx < 0 || ny < 0 || nx >= land.size() || ny >= land[0].size() ) {
                continue;
            }
            if (land[nx][ny] == 0 || land[nx][ny] == 2) {
                continue;
            }

            if (ny > maxY) {
                maxY = ny;
            }
            if (ny < minY) {
                minY = ny;
            }

            land[nx][ny] = 2;
            q.push(make_pair(nx,ny));

            oilCount++;
        }
     }

    for (int i=minY;i<=maxY;i++) {
        sum[i] += oilCount;
        if (sum[i] > maxSum) {
            maxSum = sum[i];
        }
    }

     cout << minY << " " << maxY << " "<< oilCount << endl;
}

int solution(vector< vector<int> > &land) {
    int answer = 0;
    
    for (int i=0;i<land.size();i++) {
        for (int j=0;j<land[i].size();j++) {
            if (land[i][j] == 1) {
                bfs(i,j,land);
            }
            // if (land[i][j] != 0 && visited[i][j] == false) {
            //     bfs(i,j,land);
            // }
        }
    }

    

    cout << maxSum;
    return answer;
}