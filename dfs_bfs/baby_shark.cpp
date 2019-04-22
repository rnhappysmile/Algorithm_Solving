/*
* BFS 알고리즘 문제 baby_shark
* 문제 URL: https://www.acmicpc.net/problem/16236
*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

#define DIR_MAX 4

using namespace std;

int Inside(int x, int y, int map_size)
{
	return ((0 <= x) && (x < map_size) &&
		 (0 <= y) &&(y < map_size));
}

int BSD(int map_size, vector<vector<int>> &element)
{
	int cur_x = 0, cur_y = 0;
	int next_x = 0, next_y = 0;
	int q_pish_x = 0, q_pish_y = 0;
	int temp_bsd_count = 0, bsd_count = 0;
	int temp_sec = 0;
	int answer = 0;
	int shark_eat[1][2] = { 0, 2 };
	int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
	queue<pair<int, int>> q;
	queue<pair<int, int>> q_pish;
	vector<pair<int, int>> compare_pish;
	vector<vector<int>> visited;

	visited.assign(map_size, (vector<int>(map_size, 0)));
	compare_pish.assign(1, pair<int, int>(map_size, map_size));

	for (int x = 0; x < map_size; x++) {
		for (int y = 0; y < map_size; y++) {
			if (Inside(x, y, map_size) &&
				(element[x][y] == 9)) {
				cur_x = x;
				cur_y = y;
				element[cur_x][cur_y] = 0;
				q.push(pair<int, int>(x, y));
				bsd_count++;
			}
		}
	}

	while (!q.empty()) {
		int compare_pish_index = 0;

		for(int count = 0; count < bsd_count; count++) {
			cur_x = q.front().first;
			cur_y = q.front().second;
			q.pop();

			for(int i =0; i< DIR_MAX; i++){
				next_x = cur_x + dir[i][0];
				next_y = cur_y + dir[i][1];
				if ((Inside(next_x, next_y, map_size)) &&
					(element[next_x][next_y] <= shark_eat[0][1]) &&
					(visited[next_x][next_y] == 0)){
					visited[next_x][next_y] = visited[cur_x][cur_y] + 1;
					q.push(pair<int, int>(next_x, next_y));
					temp_bsd_count++;
					if ((element[next_x][next_y] < shark_eat[0][1]) &&
						(element[next_x][next_y] != 0)) {
						q_pish.push(pair<int, int>(next_x, next_y));
						temp_sec = visited[next_x][next_y];						
					}
				}
			}
		}
		
		while (!q_pish.empty()) {
			q_pish_x = q_pish.front().first;
			q_pish_y = q_pish.front().second;
			q_pish.pop();

			if((compare_pish[0].first > q_pish_x) ||
				((compare_pish[0].first == q_pish_x) &&
					(compare_pish[0].second > q_pish_y))){
				compare_pish[0].first = q_pish_x;
				compare_pish[0].second = q_pish_y;
			}

			if(q_pish.empty()){
				visited.assign(map_size, (vector<int>(map_size, 0)));
				visited[compare_pish[0].first][compare_pish[0].second] = temp_sec;
				element[compare_pish[0].first][compare_pish[0].second] = 0;
				compare_pish_index++;

				visited[compare_pish[0].first][compare_pish[0].second] = temp_sec;
				shark_eat[0][0]++;
				if (shark_eat[0][0] == shark_eat[0][1]) {
					shark_eat[0][1]++;
					shark_eat[0][0] = 0;
				}
				answer = temp_sec;

				for (int i = 0; i < map_size; i++) {
					for (int j = 0; j < map_size; j++) {
						cout << element[i][j];
					}
					cout << endl;
				}

				cout << endl; 
				cout << endl;
			}
			
			while(!q.empty()){
				q.pop();
			}
			q.push(pair<int, int>(compare_pish[0].first, compare_pish[0].second));
		}
		
		if (compare_pish_index > 0) {
			bsd_count = compare_pish_index;
		}
		else {
			bsd_count = temp_bsd_count;
		}
		compare_pish[0].first = map_size;
		compare_pish[0].second = map_size;
		compare_pish_index = 0;
		temp_bsd_count = 0;
	}

	return answer;
}

int main()
{
	FILE* fp;
	int data = 0;
	int cur_x = 0, cur_y = 0;
	int map_size = 0;
	int receive_fscanf = 0;
	vector<vector<int>> element;

	fp = fopen("test.txt", "r");
	if(fscanf(fp, "%1d", &data)){
		if ((2 <= data) && (data <= 20)){
			map_size = data;
			element.assign(map_size, vector<int>(map_size, 0));
		}
	}
	else {
		return 0;
	}

	while(fscanf(fp, "%1d", &data) != EOF){
		element[cur_x][cur_y] = data;
		cur_y++;
		if (cur_y == map_size) {
			cur_x++;
			cur_y = 0;
			if (cur_x == map_size) {
				break;
			}
		}
	}

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			cout << element[i][j];
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}

	cout << BSD(map_size, element) << endl;;

	return 0;
}