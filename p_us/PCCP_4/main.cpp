#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

string first = "", second = "", res = "";
char curSign;
int ndim = 2,mydim = 2, mydim2;

int myfunc(string str, int a) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += pow(a, i) * ((str[str.size() - i - 1])-'0');
    }
    return sum;
}

int myfunc2(int a, int b) {

    int i = 1, sum=0;
    int x = a;

    
    while (x > 0) {
        sum += (x % b) * i;
        x = x / b;       
        i = i * 10;
    }
   
    return sum;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;

    int current = 1;
    for (int i = 0; i < expressions.size(); i++) {

        for (int j = 0; j < expressions[i].size(); j++) {
            if (expressions[i][j] == ' ') {
                continue;
            }
            if (expressions[i][j] == '+' || expressions[i][j] == '-') {
                curSign = expressions[i][j];
                current = 2;
                continue;
            }
            if (expressions[i][j] == '=') {
                current = 3;
                continue;
            }
            if (expressions[i][j] == 'X') {
                break;
            }

            if ((((expressions[i][j])-'0') + 1) > ndim) {
                ndim = (((expressions[i][j])-'0') + 1);

            }

            if (current == 1) {
                first.append(1, expressions[i][j]);
            }
            else if (current == 2) {
                second.append(1, expressions[i][j]);
            }
            else {
                res.append(1, expressions[i][j]);
            }
        }
     

        if (expressions[i][expressions[i].size() - 1] == 'X') {
            answer.push_back(expressions[i]);
            if (ndim > mydim) {
                mydim = ndim;
                mydim2 = ndim;
            }
            current = 1; ndim = 2;
            first = ""; second = ""; res = "";
            continue;
        }

        for (int j = ndim; j < 10; j++) {
            if (curSign == '+') {
                if ((myfunc(first, j) + myfunc(second, j)) == myfunc(res, j)) {
                    mydim = j;
                    break;
                }
            }
            else {
                if ((myfunc(first, j) - myfunc(second, j)) == myfunc(res,j)) {
                    mydim = j;
                    break;
                }
            }
        }

        current = 1; ndim = 2;
        first = ""; second = ""; res = "";
    }


    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            if (answer[i][j] == ' ') {
                continue;
            }
            if (answer[i][j] == '+' || answer[i][j] == '-') {
                curSign = answer[i][j];
                current = 2;
                continue;
            }
            if (answer[i][j] == '=') {
                answer[i].pop_back();
                //answer[i][answer[i].size() - 1] = '\0';
                
                if (curSign == '+') {
                    answer[i].append(to_string(myfunc2( (myfunc(first, mydim)+myfunc(second, mydim)),mydim ) ));
                }
                else {
                    answer[i].append(to_string(myfunc2((myfunc(first, mydim) - myfunc(second, mydim)),mydim)));
                }
                break;
            }
            if ((((answer[i][j]) - '0') + 1) == mydim2) {
              
                answer[i][answer[i].size() - 1] = '?';
                break;
            }

            if ((((answer[i][j])-'0') + 1) > mydim) {
                answer[i][answer[i].size() - 1] = '?';
                break;
            }

            if (current == 1) {
                first.append(1, answer[i][j]);
            }
            else if (current == 2) {
                second.append(1, answer[i][j]);
            }
        }
        current = 1; ndim = 2;
        first = ""; second = ""; res = "";
    }

   /* for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }*/

    return answer;
}

int main()
{

    vector<string> test = { "2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "5 - 5 = X" };
    solution(test);

    return 0;
}