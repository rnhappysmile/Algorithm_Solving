//https://programmers.co.kr/learn/courses/30/lessons/42746#

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool  bin_number_compare(const string& a, const string& b)
{
	if (a == b)
		return false;

	string ab = a + b;
	string ba = b + a;

	if (ab > ba)
		return true;
	else
		return false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> string_numbers;
	int zero_count = 0;

	if(numbers.size() > 1000000)
		return answer;

	for (vector<int>::iterator its = numbers.begin(); its < numbers.end(); its++)
	{
		if (*its <= 1000)
			string_numbers.push_back(to_string(*its));
		else
			return answer;

		if (*its == 0)
			zero_count++;
	}

	if (zero_count == numbers.size())
		return "0";

	sort(string_numbers.begin(), string_numbers.end(), bin_number_compare);

	for (vector<string>::iterator its = string_numbers.begin(); its < string_numbers.end(); its++)
	{
		answer.append(*its);
	}


	return answer;
}

int main()
{
	string answer = "";
	vector<int> numbers = {6, 10, 2};
	answer = solution(numbers);

	cout << answer << endl;

	return 0;
}