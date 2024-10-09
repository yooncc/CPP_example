#include <string>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    int condition=0;
    char c_1='0',c_2='0';
    string myword="";
    string dup;
    // 1번 글자 사이마다 같은 기호, 2번 단어 앞뒤 특정단어, 3번 공백제거  
    
    for (int i=0;i<sentence.size();i++) {
        if (sentence[i] - 'a' < 0) {    // 대문자
            myword.append(sentence[i],1);
            
            if (c_1 != '0') {
                if (i+1==sentence.size()) {
                    answer="invalid";
                    return answer;
                }
                
                if (sentence[i+1] == c_1) {
                    if (answer=="") {
                        answer.append(myword);
                    }
                    else {
                        answer.append(" ");
                        answer.append(myword);
                    }
                }
                continue;
            }
            if (c_2 != '0') {
                if (i+1==sentence.size()) {
                    if (answer=="") {
                        answer.append(myword);
                    }
                    else {
                        answer.append(" ");
                        answer.append(myword);
                    }
                    return answer;
                }
                if (sentence[i+1] != c_2) {
                    if (answer=="") {
                        answer.append(myword);
                    }
                    else {
                        answer.append(" ");
                        answer.append(myword);
                    }
                }
            }
        }
        else {  // 소문자
            if (myword=="") {
                c_1 = sentence[i];
                continue;
            }
            if (c_2 != '0') {
                continue;
            }
            c_2 = sentence[i];
        }
    }
    
    return answer;
}