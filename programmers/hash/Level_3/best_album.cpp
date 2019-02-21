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
	# ���� ����
	1.���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
	2.�帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
	3.�帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.

	# ���ѻ���
	-	genres[i]�� ������ȣ�� i�� �뷡�� �帣�Դϴ�.
	-	plays[i]�� ������ȣ�� i�� �뷡�� ����� Ƚ���Դϴ�.
	-	genres�� plays�� ���̴� ������, �̴� 1 �̻� 10,000 �����Դϴ�.
	-	�帣 ������ 100�� �̸��Դϴ�.
	-	�帣�� ���� ���� �ϳ����, �ϳ��� � �����մϴ�.
	-	��� �帣�� ����� Ƚ���� �ٸ��ϴ�.
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