/*
*	URL: https://www.hackerrank.com/challenges/2d-array/problem
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

bool Inside(int x, int y)
{
	return ((x >= 0) || (y >= 0) || (x < 6) || (y < 6));
}

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
	vector<vector<int>> visited;	
	int dir[8][2] = { {0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 0}, {2, 1}, {2, 2} };
	int answer[36] = { 0, };

	for (int i = 0; i < 6; i++) {
		int answer_count = 0;
		for (int j = 0; j < 6; j++) {
			for (int count = 0; count < 7; count++) {
				if(Inside(i+dir[count][0], j+dir[count][1])){
					answer[answer_count] += arr[i + dir[count][0]][j + dir[count][1]];
				}
				else {
					break;
				}
			}
			answer_count++;
		}
	}
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	vector<vector<int>> arr(6);
	for (int i = 0; i < 6; i++) {
		arr[i].resize(6);

		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int result = hourglassSum(arr);

	fout << result << "\n";

	fout.close();

	return 0;
}
