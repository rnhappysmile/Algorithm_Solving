//¹®Á¦ URL: https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;
static int ANSWER_COUNT = 0;

void MakeOperator(vector<int> numbers, int count, int target) {
	if (count < numbers.size()) {
		numbers.at(count) *= 1;
		MakeOperator(numbers, count + 1, target);

		numbers.at(count) *= -1;
		MakeOperator(numbers, count + 1, target);
	}
	else {
		int sum = 0;
		for (vector<int>::iterator its = numbers.begin(); its < numbers.end(); *its++) {
			sum += *its;
			cout << *its;
		}
		cout << endl;
		if (sum == target)
			ANSWER_COUNT++;
	}
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	if (2 > numbers.size() > 20)
		return answer;

	if (1 > target > 1000)
		return answer;

	for (vector<int>::iterator its = numbers.begin(); its < numbers.end(); *its++)
		if (1 > *its > 50)
			return answer;

	MakeOperator(numbers, 0, target);
	answer = ANSWER_COUNT;

	return answer;
}

int main() {
	vector<int> test_numbers = { 1, 1, 1, 1, 1 };
	int test_target = 3;
	int answer = 0;

	answer = solution(test_numbers, test_target);
	cout << answer << endl;

	return 0;
}