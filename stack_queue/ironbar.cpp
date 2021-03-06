//https://programmers.co.kr/learn/courses/30/lessons/42585

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    unsigned int current_iron_bar = 0;
    char currnet_bracket = ' ';
    char previous_bracket = ' ';
    
    if(arrangement.size() > 100000){
        return answer;
    }
    
    for(string::iterator it = arrangement.begin()+1; it != arrangement.end(); it++)
    {
        currnet_bracket = *it;
        previous_bracket = *(it-1);
        if((previous_bracket == '(') && (currnet_bracket == ')')){
            answer += current_iron_bar;
        } else if ((previous_bracket == '(') && (currnet_bracket == '(')){
            current_iron_bar++;
        } else if ((previous_bracket == ')') && (currnet_bracket == ')')){
            if(current_iron_bar != 0){
                current_iron_bar--;
            }
            answer++;
        }
    //    cout << previous_bracket << currnet_bracket << endl;
    //    cout << answer << endl;
    }
    
    if(current_iron_bar != 0){
        return 0;
    }
    // arrangement 문자열의 문자를 하나씩 확인
    // ()가 함께 나오면 레이저
          // () 나오기 전의 선 카운트를 answer에 중첩한다.
    
    // (( 동시에 나오면 선 카운트 +1
    // )) 동시에 나오면 선 카운트 -1
          // )) 나오면 answer에 +1을 한다.
    
    return answer;
}

int main()
{
    int answer = 0;
    string arrangement = "()(((()())(())()))(())";

    answer = solution(arrangement);

    cout << answer << endl;

    return 0;
}