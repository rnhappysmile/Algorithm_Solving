#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	int clothes_count = 0;

	vector<vector<string>> temp = { {"",""} };

	for (int count = 0; count < clothes.size(); count++)
	{
		cout << "hello world!" << endl;
		for (int answer_count = 0; answer_count < temp.size(); answer_count++)
		{
			if (temp[answer_count][1] == clothes[count][1])
			{
				temp[count][0] = +1;
			}
			else if (answer_count == (temp.size() - 1))
			{
				vector<string> row;
        		temp.push_back(row);
				temp[clothes_count][1] = (clothes[count][1]);
				temp[clothes_count][0] = +1;
				cout << "end world!" << endl;
				clothes_count++;
			}
		}
	}

	cout << "hello world!" << endl;

	cout << temp[0][0] << "," << temp[0][1] << endl;
	cout << temp[1][0] << "," << temp[1][1] << endl;
	cout << temp[2][0] << "," << temp[2][1] << endl;

	return answer;
}

int main()
{
	int answer = 0;
	vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };

	answer = solution(clothes);

	return 0;
}