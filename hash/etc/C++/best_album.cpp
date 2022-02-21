#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> totalPalys;
	int tempTotalPalys = 0;

	/*
	# 문제 설명
	1.속한 노래가 많이 재생된 장르를 먼저 수록합니다.
	2.장르 내에서 많이 재생된 노래를 먼저 수록합니다.
	3.장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

	# 제한사항
	-	genres[i]는 고유번호가 i인 노래의 장르입니다.
	-	plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
	-	genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
	-	장르 종류는 100개 미만입니다.
	-	장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
	-	모든 장르는 재생된 횟수가 다릅니다.
	*/

	for (unsigned int count = 0; count < genres.size(); count++)
	{	
		if (count == 0)
		{
			tempTotalPalys = plays.at(count);
		} else {
			tempTotalPalys = totalPalys[genres.at(count)] + plays.at(count);
		}
		totalPalys.erase(genres.at(count));
		totalPalys.insert(pair<string, int>(genres.at(count), tempTotalPalys));
	}
	/*
	sort(totalPalys.begin(), totalPalys.end(), [](pair<string, int>elem1, pair<string, int>elem2)
	{
		return elem1.second < elem2.second; 
	});
	*/

	//totalPalys.value_comp();
	map <string, int>::value_compare vc1 = totalPalys.value_comp();

	for (map<string, int>::iterator itr = totalPalys.begin(); itr != totalPalys.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}

	return answer;
}

int main()
{
	vector<int> answer;
	vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
	vector<int> plays = { 500, 600, 150, 800, 2500 };

	answer = solution(genres, plays);

	return 0;
}