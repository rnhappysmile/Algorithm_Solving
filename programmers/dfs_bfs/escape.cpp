/*
* BFS 알고리즘 문제 escape
* 문제 URL: https://www.acmicpc.net/problem/3055
*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>

#define DIR_MAX 4

using namespace std;

bool Inside(int x, int y, int max_x, int max_y)
{
	return((x >= 0) && (x < max_x) && (y >= 0) && (y < max_y));
}

int BFS(int max_x, int max_y,
	vector<vector<char>>& element,
	vector<vector<int>> visited)
{
	queue<pair<int, int>> q_man;
	queue<pair<int, int>> q_water;
	int cur_x = 0, cur_y = 0;
	int next_x = 0, next_y = 0;
	bool first_BFS_flag = true;
	int q_man_bfs_count = 0;
	int q_water_bfs_count = 0;
	int q_bfs_count = 0;
	int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

	for (int x = 0; x < max_x; x++) {
		for (int y = 0; y < max_y; y++) {
			if (element[x][y] == 'S') {
				cur_x = x;
				cur_y = y;
				q_man.push(pair<int,int>(cur_x, cur_y));
				q_man_bfs_count++;
				break;
			}
			else if (element[x][y] == '*') {
				cur_x = x;
				cur_y = y;
				q_water.push(pair<int, int>(cur_x, cur_y));
				q_water_bfs_count++;
			}
		}
	}

	while ((!q_man.empty()) && (!q_water.empty())) {
		if (first_BFS_flag == true) {
			q_bfs_count = q_man_bfs_count;
			q_man_bfs_count = 0;
		}
		else if (first_BFS_flag == false) {
			q_bfs_count = q_water_bfs_count;
			q_water_bfs_count = 0;
		}
		for (int count = 0; count < q_bfs_count; count++) {
			if (first_BFS_flag == true) {
				cur_x = q_man.front().first;
				cur_y = q_man.front().second;
				q_man.pop();	// how to status if q_man.empty() have to q_man.pop() 
			}
			else if (first_BFS_flag == false) {
				cur_x = q_water.front().first;
				cur_y = q_water.front().second;
				q_water.pop();	// how to status if q_water.empty() have to q_water.pop() 
			}

			for (int i = 0; i < DIR_MAX; i++)
			{
				next_x = cur_x + dir[i][0];
				next_y = cur_y + dir[i][1];

				if(first_BFS_flag == true){
					if ((Inside(next_x, next_y, max_x, max_y)) &&
						(element[next_x][next_y] != '*') &&
						(element[next_x][next_y] != 'X') &&
						(visited[next_x][next_y] != 1) &&
						(visited[next_x][next_y] != -1)) {
						if (element[next_x][next_y] == 'D')
						{
							return visited[cur_x][cur_y] + 1;
						}
						element[next_x][next_y] = 'S';
						visited[next_x][next_y] = visited[cur_x][cur_y] + 1;
						q_man.push(pair<int, int>(next_x, next_y));
						q_man_bfs_count++;
					}
				}
				else if (first_BFS_flag == false) {
					if ((Inside(next_x, next_y, max_x, max_y)) &&
						(element[next_x][next_y] != 'D') &&
						(element[next_x][next_y] != 'X')) {
						element[next_x][next_y] = '*';
						visited[next_x][next_y] = -1;
						q_water.push(pair<int, int>(next_x, next_y));
						q_water_bfs_count++;
					}
				}
			}
		}
		first_BFS_flag = !first_BFS_flag;
	}

	return 0;
}

int main()
{
	FILE* fp;
	int data;
	char char_data;
	int cur_x = 0, cur_y = 0;
	int max_x = 0, max_y = 0;
	int answer = 0;
	vector<vector<char>> element;
	vector<vector<int>> visited;

	fp = fopen("test.txt", "r");

	fscanf(fp, "%1d", &data);
	if((0 < data) && (data <= 50))
	{
		max_x = data;
	} else {
		return 0;
	}

	fscanf(fp, "%1d", &data);
	if ((0 < data) && (data <= 50))
	{
		max_y = data;
	}
	else {
		return 0;
	}

	element.assign(max_x, vector<char>(max_y, ' '));
	visited.assign(max_x, vector<int>(max_y, 0));

	while (fscanf(fp, "%c", &char_data) != EOF) {
		if(char_data != '\n'){
			element[cur_x][cur_y] = char_data;
			cur_y++;
			if(cur_y == max_y)
			{
				cur_x++;
				if (cur_x == max_x)
				{
					break;
				}
				cur_y = 0;
			}
		}
	}

	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++)
		{
			cout << element[i][j];
		}
		cout << endl;
	}

	if ((answer = BFS(max_x, max_y, element, visited)) != 0) {
		cout << answer << endl;
	}
	else {
		cout << "KAKTUS" << endl;
	}

	return 0;
}
