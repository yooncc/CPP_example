#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K,result,maxHeight;
vector< pair<int,int> > v;

int main() 
{

    cin >> K;

    maxHeight = 0;
    for (int i=0; i<K ; i++) {
        int l,h;
        cin >> l >> h;
        if (h >= maxHeight) {
            maxHeight = h;
        }
        v.push_back(make_pair(l,h));
    }

    sort(v.begin(),v.end());


    int currentL=v[0].first,currentH=v[0].second,currentI;
    result = 0;

    if ( currentH != maxHeight ) {
        for (int i=1;i<v.size();i++) {
            if (v[i].second > currentH) {
                result += (v[i].first - currentL)*currentH;
                currentL = v[i].first;
                currentH = v[i].second;
            }
            if ( currentH == maxHeight ) {
                currentI = i;
                break;
            }
        }
    }
    else {
        currentI = 0;
    }
    
    int bottom = 1;
    for (int i=currentI+1;i<v.size();i++) {
        if ( v[i].second != maxHeight ) {
            result += (maxHeight*bottom);
            break;
        }

        bottom += v[i].first - currentL;
        currentL = v[i].first;
        currentI = i;
    }


    currentL = v[v.size()-1].first;
    currentH = v[v.size()-1].second;
    for (int i=1;i<v.size()-currentI;i++) {
        if (v[v.size()-1-i].second > currentH) {
            result += (currentL - v[v.size()-1-i].first)*currentH;
            currentL = v[v.size()-1-i].first;
            currentH = v[v.size()-1-i].second;
        }
    }

    cout << result;

    return 0;
}