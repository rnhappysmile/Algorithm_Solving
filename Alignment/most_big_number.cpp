#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool  bin_number_compare(const string& a, const string& b)
{
	if (a == b)
		return false;

	if (a + b > b + a)
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
	vector<int> numbers = { 6, 11, 2 };
	int zero_count = 0;
	string answer = "";

	answer = solution(numbers);
	cout << answer << endl;

	return 0;
}