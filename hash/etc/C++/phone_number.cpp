#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	int phone_book_compare_index = 0;

	/*
		# 제한 사항
		phone_book의 길이는 1 이상 1,000,000 이하입니다.
		각 전화번호의 길이는 1 이상 20 이하입니다.
	*/

	if (phone_book.size() > 1000000)
	{
		return answer;
	}

	sort(phone_book.begin(), phone_book.end());

	for (int count = 1; count < phone_book.size(); count++)
	{
		for (int phone_book_count = 0; phone_book_count < phone_book[count].size(); phone_book_count++)
		{
			if ((phone_book[count].size() < 1) || (phone_book[count].size() > 20))
			{
				return answer;
			}
		
			if (phone_book[0][phone_book_compare_index] == phone_book[count][phone_book_count])
			{
				phone_book_compare_index++;
				if (phone_book_compare_index == phone_book[0].size())
				{
					answer = false;
					return answer;
				}
			}
			else if (phone_book[0][0] == phone_book[count][phone_book_count])
			{
				phone_book_compare_index = 1;
			}
			else
			{
				phone_book_compare_index = 0;
			}
		}
	}

	return answer;
}

int main()
{
	bool answer;
	//vector<string> phone_book = {"119", "97674223", "1195524421"};
	vector<string> phone_book = {"123", "456", "789"};
	answer = solution(phone_book);

	cout << answer << endl;

	return 0;
}