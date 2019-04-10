/*
* BFS 알고리즘 문제 토마토
* 문제 URL: https://www.acmicpc.net/problem/7576
*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int Inside(int row, int col, int max_row, int max_col)
{
	return ((row >= 0 && row < max_row) && (col >= 0 && col < max_col));
}

int BFS(int max_row, int max_col,
	vector<vector<int>> element, vector<vector<int>> visited) {
	queue<pair<int, int>>q;
	int dir[4][2] = { {1,0}, {-1,0},{0,1},{0,-1} };
	
	int cur_row = 0, cur_col = 0;
	int next_row = 0, next_col = 0;
	
	for (int i = 0; i < max_row; i++) {
		for (int j = 0; j < max_col; j++) {
			if (element[i][j] == 1) {
				cur_row = i;
				cur_col = j;
				q.push(pair<int, int>(cur_row, cur_col));
			}
		}
	}

	while(!q.empty()){
		cur_row = q.front().first;
		cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dir[i][0];
			next_col = cur_col + dir[i][1];
			if (Inside(next_row, next_col, max_row, max_col) &&
				(element[next_row][next_col] == 0)) {
				element[next_row][next_col] = element[cur_row][cur_col] + 1;
				q.push(pair<int, int>(next_row, next_col));
			}
		}
	}

	return (element[cur_row][cur_col] - 1);
}

int main() 
{
	FILE *fp;
	int data;
	int max_row = 0, max_col = 0;
	int cur_row = 0, cur_col = 0;
	vector<vector<int>> element, visited;

	fp = fopen("test.txt", "r");
	fscanf(fp, "%1d", &data);
	max_col = data;
	fscanf(fp, "%1d", &data);
	max_row = data;

	element.assign(max_row, vector<int>(max_col, 0));
	visited.assign(max_row, vector<int>(max_col, 0));

	while (fscanf(fp, "%2d", &data) != EOF) {
		element[cur_row][cur_col] = data;
		cur_col++;
		if (cur_col == max_col) {
			cur_row++;
			if (cur_row == max_row) {
				break;
			}
			cur_col = 0;
		}
	}

	for (cur_row = 0; cur_row < max_row; cur_row++) {
		for (cur_col = 0; cur_col < max_col; cur_col++) {
			cout << element[cur_row][cur_col];
		}
		cout << endl;
	}

	cout << BFS(max_row, max_col, element, visited) << endl;

	return 0;
}