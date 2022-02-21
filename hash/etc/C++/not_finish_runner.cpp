#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> temp_string;
    
    int temp_size = participant.size();
    
    for(int count=0; count<temp_size; count++){
        temp_string[participant[count]]++;
    }
    
    temp_size = completion.size();
    for(int count=0; count<temp_size; count++){
        temp_string[completion[count]]++;
    }
    
    map<string, int>::iterator it;
    for(it = temp_string.begin(); it != temp_string.end(); it++){
        int num = it->second;
        if (num % 2 == 1) {
            answer = it->first;
            break;
        }
    }
    
    cout << answer << endl;
    return answer;
}

int main()
{
    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};
    string answer = "";

    answer = solution(participant, completion);

    cout << answer << endl;

    return 0;
}