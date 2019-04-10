/*
* BFS 알고리즘 문제 토마토(응용: 3차원)
* 문제 URL: https://www.acmicpc.net/problem/7569
*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int Inside(int cur_x, int cur_y, int cur_z, 
	int max_x, int max_y, int max_z)
{
	return ((cur_x >= 0 && cur_x < max_x) && 
		(cur_y >= 0 && cur_y < max_y) &&
		(cur_z >= 0 && cur_z < max_z));
}

int BFS(int max_x, int max_y, int max_z,
	vector<vector<vector<int>>> &element, vector<vector<vector<int>>> &visited) {
	queue< pair<pair<int, int>, int>> q;

	int dir[6][3] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
	
	int cur_x = 0, cur_y, cur_z = 0;
	int next_x = 0, next_y, next_z = 0;
	
	for (int z = 0; z < max_z; z++) {
		for (int x = 0; x < max_x; x++) {
			for (int y = 0; y < max_y; y++) {
				if (element[x][y][z] == 1) {
					cur_x = x;
					cur_y = y;
					cur_z = z;
					q.push(make_pair(make_pair(cur_x, cur_y), cur_z));
				}
			}
		}
	}

	while(!q.empty()){
		cur_x = q.front().first.first;
		cur_y = q.front().first.second;
		cur_z = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			next_x = cur_x + dir[i][0];
			next_y = cur_y + dir[i][1];
			next_z = cur_z + dir[i][2];
			if (Inside(next_x, next_y, next_z, max_x, max_y, max_z) &&
				(element[next_x][next_y][next_z] == 0)) {
				element[next_x][next_y][next_z] = element[cur_x][cur_y][cur_z] + 1;
				q.push(make_pair(make_pair(next_x, next_y), next_z));
			}
		}
	}

	return (element[cur_x][cur_y][cur_z] - 1);
}

bool last_check(int max_x, int max_y, int max_z,
	vector<vector<vector<int>>> element)
{
	for (int cur_z = 0; cur_z < max_z; cur_z++) {
		for (int cur_x = 0; cur_x < max_x; cur_x++) {
			for (int cur_y = 0; cur_y < max_y; cur_y++) {
				if (element[cur_x][cur_y][cur_z] == 0) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() 
{
	FILE* fp;
	int data;
	int max_y = 0, max_x = 0, max_z = 0;
	int cur_y = 0, cur_x = 0, cur_z = 0;
	int answer = 0;
	vector<vector<vector<int>>> element, visited;

	fp = fopen("test.txt", "r");
	fscanf(fp, "%1d", &data);

	//코드 함수화 가능한 부분
	if(2 <= data <= 100){
		max_y = data;
	} else {
		return 0;
	}
	fscanf(fp, "%1d", &data);
	if (2 <= data <= 100) {
		max_x = data;
	} else {
		return 0;
	}
	fscanf(fp, "%1d", &data);
	if (2 <= data <= 100) {
		max_z = data;
	} else {
		return 0;
	}

	element.assign(max_x, vector<vector<int>>(max_y, vector<int>(max_z, 0)));
	visited.assign(max_x, vector<vector<int>>(max_y, vector<int>(max_z, 0)));

	while (fscanf(fp, "%2d", &data) != EOF) {
		element[cur_x][cur_y][cur_z] = data;
		cur_y++;
		if (cur_y == max_y) {
			cur_x++;
			if (cur_x == max_x) {
				cur_z++;
				if (cur_z == max_z) {
					break;
				}
				cur_x = 0;
			}
			cur_y = 0;
		}
	}

	for (cur_z = 0; cur_z < max_z; cur_z++) {
		for (cur_x = 0; cur_x < max_x; cur_x++) {
			for (cur_y = 0; cur_y < max_y; cur_y++) {
				cout << element[cur_x][cur_y][cur_z];
			}
			cout << endl;
		}
		cout << endl;
	}
	
	answer = BFS(max_x, max_y, max_z, element, visited);
	if (last_check(max_x, max_y, max_z, element) != false) {
		cout << answer << endl;
	}
	else {
		cout << "-1" << endl;
	}
	

	return 0;
}