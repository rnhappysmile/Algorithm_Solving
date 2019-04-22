//https://programmers.co.kr/learn/courses/30/lessons/12899

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(int n) {
        string answer = "";
        int rmd;

        while(n>0){
            rmd = n%3;
            n = n/3;

            if(rmd == 0){
                n -= 1;
                rmd = 4;
            }

            answer = to_string(rmd) + answer;
        }

        return answer;
}

int main()
{
    int test = 10;
    string answer = "";

    answer = solution(test);

    cout << answer << endl;

    return 0;
}