//https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <iterator>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> progresses_queue;
    queue<int> speeds_queue;
    queue<int> answer_queue;
    unsigned int temp_progresses = 0;
    unsigned int temp_speeds = 0;
    unsigned int day = 0;
    unsigned int temo_pregoresses_size = 0;
    unsigned int first_progresse = 0;
    
    if(progresses.size() > 100)
    {
        return answer;
    }
    
    for(int i = 0; i < progresses.size(); i++)
    {
        if((progresses.at(i) >= 100) || (speeds.at(i) > 100))
        {
            return answer;
        }
        progresses_queue.push(progresses.at(i));
        speeds_queue.push(speeds.at(i));
    }
    
    temo_pregoresses_size = progresses_queue.size();
    
    while(!progresses_queue.empty())
    {
        for(int count = 0; count < temo_pregoresses_size; count++)
        {
            temp_progresses = progresses_queue.front();
            temp_speeds = speeds_queue.front();
            progresses_queue.pop();
            speeds_queue.pop();
            
            temp_progresses += temp_speeds;
            
            if((temp_progresses >= 100) && (count == day))
            {
                day++;
            } else {
                progresses_queue.push(temp_progresses);
                speeds_queue.push(temp_speeds);                        }
        }
        if(temo_pregoresses_size != progresses_queue.size())
        {
            temo_pregoresses_size = progresses_queue.size();
            answer.push_back(day);
            day=0;
        }
    }
 
    return answer;
}

int main()
{
    vector<int> answer = {};
    vector<int> progresses = {93,30,55};
    vector<int> speeds = {1,30,5};

    answer = solution(progresses, speeds);

    for(vector<int>::iterator its = answer.begin(); its < answer.end(); its++)
    {
        cout << *its << endl;
    }

    return 0;
}