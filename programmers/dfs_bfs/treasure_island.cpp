/*
* BFS 알고리즘 문제 보물섬
* 문제 URL: https://www.acmicpc.net/problem/2589
*/

#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

bool Inside(int row, int col, int max_row, int max_col)
{
	return ((row >= 0) && (col >= 0) && (row < max_row) && (col < max_col));
}

int BFS(int max_row, int max_col, vector<vector<char>> element, vector<vector<int>> &visited)
{
	queue<pair<int, int>> q;
	int cur_y = 0, cur_x = 0;
	int next_y = 0, next_x = 0;
	int end_point_y = 0, end_point_x = 0;
	int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
	int answer = 0;
	bool search_flag = false;
	bool answer_flag = false;
	
	for (int i = 0; i < max_row; i++) {
		for (int j = 0; j < max_col; j++) {
			if ((element[i][j] == 'L') && (visited[cur_y][cur_x] == 0)){
				cur_y = i;
				cur_x = j;
				visited[cur_y][cur_x] = 1;
				q.push(pair<int, int>(cur_y, cur_x));
				search_flag = true;
				break;
			}
		}
		if (search_flag == true) {
			search_flag = false;
			break;
		}
	}

	while(!q.empty()) {
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			next_y = cur_y + dir[i][0];
			next_x = cur_x + dir[i][1];

			if ((Inside(next_y, next_x, max_row, max_col)) &&
				(element[next_y][next_x] == 'L') &&
				(visited[next_y][next_x] < 1)) 
			{
				q.push(pair<int, int>(next_y, next_x));
				visited[next_y][next_x] = visited[cur_y][cur_x] + 1;
				if (visited[next_y][next_x] > visited[cur_y][cur_x]) {
					end_point_y = next_y;
					end_point_x = next_x;
					if (answer_flag == true) {
						answer = visited[next_y][next_x];
					}
				}
			}
		}

		if (q.empty() && answer_flag == false) {
			visited.assign(max_row, vector<int>(max_col, 0));
			q.push(pair<int, int>(end_point_y, end_point_x));
			answer_flag = true;
		}
	}

	return answer;
}

int main()
{
	FILE *fp;
	int data = 0;
	char char_data = 0;
	int max_row = 0, max_col = 0;
	int cur_row = 0, cur_col = 0;
	vector<vector<char>> element;
	vector<vector<int>> visited;

	fp = fopen("test.txt", "r");

	fscanf(fp, "%1d", &data);
	max_row = data;

	fscanf(fp, "%1d", &data);
	max_col = data;

	element.assign(max_row, vector<char>(max_col, 0));
	visited.assign(max_row, vector<int>(max_col, 0));
	
	while (fscanf(fp, "%c", &char_data) != EOF) {
		if(char_data != '\n'){
			element[cur_row][cur_col] = char_data;
			cur_col++;
			if (cur_col == max_col) {
				cur_row++;
				if (cur_row == max_row) {
					break;
				}
				cur_col = 0;
			}
		}
	}

	for (cur_row = 0; cur_row < max_row; cur_row++) {
		for (cur_col = 0; cur_col < max_col; cur_col++) {
			cout << element[cur_row][cur_col];
		}
		cout << endl;
	}

	cout << BFS(max_row, max_col, element, visited);
	cout << BFS(max_row, max_col, element, visited);

	return 0;
}