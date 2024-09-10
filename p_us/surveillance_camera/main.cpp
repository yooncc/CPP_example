#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<pair<int,int>> bounds;
    
    sort(routes.begin(), routes.end());
    
    for (int i=0;i<routes.size();i++) {
            
        int boundsCheck=0;
        for (int j=0;j<bounds.size();j++) {
            if (routes[i][0] < bounds[j].first) {
                if (routes[i][1] >= bounds[j].first && routes[i][1] <= bounds[j].second) {
                    bounds[j].second = routes[i][1]; 
                    boundsCheck =1;
                    break;
                }
            }
            else if (routes[i][0] >= bounds[j].first && routes[i][0] <= bounds[j].second) {
                if (routes[i][1] <= bounds[j].second) {
                    bounds[j].first = routes[i][0];
                    bounds[j].second = routes[i][1];
                }
                else {
                    bounds[j].first = routes[i][0];
                }
                boundsCheck =1;
                break;
            } 
        }
        if (boundsCheck == 0) {
            bounds.push_back(make_pair(routes[i][0],routes[i][1]));
        }
        
    }
    
    answer = bounds.size();
    
    return answer;
}