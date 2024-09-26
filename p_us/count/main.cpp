#include <string>
#include <vector>

using namespace std;
#define MAX_VALUE 100000
int myTarget, minSum, mySum;

vector<int> solution(int target) {
    vector<int> answer;
    
    answer.push_back(MAX_VALUE);
    answer.push_back(MAX_VALUE);
    
    int cnt = target/50;
    myTarget = target;
    
    for (int i=0;i<=cnt;i++) {
        minSum = 0;
        mySum = 0;
        myTarget = target-(50*i);
        minSum += i;
        mySum += i;

        while(myTarget > 0) {
            if (myTarget >= 60) {
                myTarget -= 60;
                minSum += 1;
            }
            else if (myTarget < 60 && myTarget >= 50) {
                if (myTarget%3 == 0) {
                    myTarget = 0;
                    minSum += 1;
                }
                else {
                    myTarget = 0;
                    minSum += 2;
                    mySum += 2;
                }

            }
            else if (myTarget < 50 && myTarget > 40) {
                if (myTarget%3 == 0) {
                    myTarget = 0;
                    minSum += 1;
                }
                else {
                    myTarget = 0;
                    minSum += 2;
                    mySum += 1;
                }
            }
            else if (myTarget <= 40 && myTarget > 20) {
                if (myTarget%3 == 0 || myTarget%2 == 0) {
                    myTarget = 0;
                    minSum += 1;
                }
                else {
                    myTarget = 0;
                    minSum += 2;
                    mySum += 2;
                }
            }
            else {
                myTarget = 0;
                minSum += 1;
                mySum += 1;
            }
        }
        
        if (answer[0] == minSum) {
            if (answer[1] < mySum) {
                answer[1] = mySum;
            }
        }
        else if (answer[0] > minSum) {
            answer[0] = minSum;
            answer[1] = mySum;
        }
         
    }
    
    
    
    
    return answer;
}