//https://programmers.co.kr/learn/courses/30/lessons/42588

#include <string>
#include <vector>
#include <iostream>

//#define DEBUG_LOG

using namespace std;


vector<int> solution(vector<int> heights) {
    vector<int> answer;
    vector<int> tempHeights = heights;
    
    //높이의 사이즈 만큼 전체를 각각 선택
    for(vector<int>::iterator sendTower = tempHeights.begin(); sendTower != tempHeights.end(); ++sendTower)
    {
        //나보다 높은게 있으면 수신 탑 선택
        for(vector<int>::iterator receiveTower = sendTower; receiveTower != tempHeights.begin() - 1; --receiveTower){
            //배열의 인덱스를 넘김
            
            if(*receiveTower > *sendTower){
                answer.push_back(distance(tempHeights.begin() - 1, receiveTower));
                break;
            } else if ( receiveTower == tempHeights.begin())
            {
#ifdef DEBUG_LOG
                cout << *sendTower << *receiveTower << endl;
#endif
                answer.push_back(0);
            }
        }
    }
      
    return answer;
}

int main()
{
    vector<int> answer = {0,};
    vector<int> heights = {6,9,5,7,4};

    answer = solution(heights);

    for(vector<int>::iterator its=answer.begin(); its< answer.end(); its++)
    {
        cout << *its << endl;
    }

    return 0;
}