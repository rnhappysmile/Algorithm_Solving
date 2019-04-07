/*
* BFS 알고리즘 문제 미로 탐색
* 문제 URL: https://www.acmicpc.net/problem/2178
*/

#include <stdio.h>
#include <vector>
#include <iterator>
#include <iostream>
#include <queue>

using namespace std;

//check [y, x] is in or not
bool isInside(int a, int b, int row, int col) {
	return (a >= 0 && a < row) && (b >= 0 && b < col);
}

int bfs(int row, int col, vector<vector<int>> element) {
	int cur_y = 0, cur_x = 0;
	queue<pair<int, int>> q;
	vector<vector<int>> visited;

	visited.assign(row, vector<int>(col, 0));
	visited[cur_y][cur_x] = 1;
	int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

	q.push(pair<int, int>(cur_y, cur_x));

	while(!q.empty())
	{
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dir[i][0];
			int next_x = cur_x + dir[i][1];

			if (isInside(next_y, next_x, row, col) && visited[next_y][next_x]==0 && element[next_y][next_x] == 1) {
				visited[next_y][next_x] = visited[cur_y][cur_x] + 1;
				q.push(pair<int, int>(next_y, next_x));
			}
		}
	}

	return visited[row - 1][col - 1];
}


int main()
{
	FILE *fp;
	int data;
	int row = 0, col = 0;
	int vector_row = 0, vector_col = 0;
	vector<vector<int>> element;

	fp = fopen("test.txt", "r");


	fscanf(fp, "%d", &data);
	row = data;
	fscanf(fp, "%d", &data);
	col = data;

	element.assign(row, vector<int>(col,0));

	while (fscanf(fp, "%1d", &data) != EOF) {
		element[vector_row][vector_col] = data;
		vector_col++;
		if (vector_col == col) {
			vector_row++;
			if (vector_row == row) {
				break;
			}
			vector_col = 0;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << element[i][j];
		}
		cout << endl;
	}

	cout << bfs(row, col, element) << endl;

	fclose(fp);
	return 0;
}
