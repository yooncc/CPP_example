#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N,work[1500001][2],arr[1500001] = {0,};
stack<int> s;
// vector< pair<int,int> > start;
vector<int> start;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> work[i][0] >> work[i][1];
        if (i + work[i][0] < N) {
            start.push_back(i);
        }
    }


    for (int i = 0; i < start.size(); i++) {
        cout << "start " << i <<endl;
        s.push(i);
        // int sum = work[i][1];
        // if ( sum > arr[i] ) {
        //     arr[i] = sum;
        // }
        int sum = 0;

        while (!s.empty()) {
            int index = s.top();
            cout << "top : " << index << endl;
            s.pop();
 
            sum += work[index][1];
 
            if ( sum > arr[index] ) {
                arr[index] = sum;
            }

            bool isLast = true;
            for (int j = index+work[index][0]; j < N;j++ ) {
                if ( j+work[j][0] <= N ) {
                    isLast = false;
                    s.push(j); 
                }
            }
            if ( isLast ) {
                sum = work[i][1];
            }
        }
    }

    int result = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > result) {
            result = arr[i];
        }
    }
   
    cout << result;
    return 0;
}