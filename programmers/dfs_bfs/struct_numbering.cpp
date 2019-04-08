/*
* BFS 알고리즘 문제 단지번호붙이기
* 문제 URL: https://www.acmicpc.net/problem/2667
*/

#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

bool Inside(int y, int x, int map_size)
{
	return ((y >= 0 && y < map_size) && (x >= 0 && x < map_size));
}

vector<int> BFS(int map_size, vector<vector<int>> element)
{
	int cur_y = 0, cur_x = 0;
	queue<pair<int, int>> q;
	vector<vector<int>> visited;
	bool search_flag = false;
	vector<int> answer;
	int answer_index = 0;
	int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

	answer.push_back(1);
	visited.assign(map_size, vector<int>(map_size, 0));

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			if ((element[i][j] == 1) && (visited[cur_y][cur_x] == 0))
			{
				cur_y = i;
				cur_x = j;
				visited[cur_y][cur_x] = 1;
				q.push(pair<int, int>(cur_y, cur_x));
				break;
			}
		}
	}

	while (!q.empty())
	{
		// 1. cur_y, cur_x 를 찾는 기능이 필요하다
		// 2. 1.기능 후 다른 그룹을 찾는 기능도 필요하다 (1을 검색해서 찾으면 될 듯)
		//    2.번 기능은 따로 함수로 관리해야한다.
		// 3. 해당 그룹의 순서를 정렬하는 기능이 필요하다 ( 이건 main에서 구현 되어야 함)
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dir[i][0];
			int next_x = cur_x + dir[i][1];

			if(Inside(next_y, next_x, map_size) && 
				(visited[next_y][next_x] < 1) &&
				(element[next_y][next_x] != 0))
			{
				q.push(pair<int, int>(next_y, next_x));
				visited[next_y][next_x] = visited[cur_y][cur_x] + 1;
				answer[answer_index]++;
			}
		}

		if(q.empty()){
			for (int i = 0; i < map_size; i++) {
				for (int j = 0; j < map_size; j++) {
					if ((element[i][j] == 1) && (visited[i][j] == 0))
					{
						cur_y = i;
						cur_x = j;
						visited[cur_y][cur_x] = 1;
						q.push(pair<int, int>(cur_y, cur_x));
						search_flag = true;
						answer.push_back(1);
						answer_index++;
						break;
					}
				}
				if (search_flag == true) {
					search_flag = false;
					break;
				}
			} 
		}
	}

	return answer;
}

int main()
{
	FILE *fp;
	int data = 0;
	int map_size = 0;
	int row = 0, col = 0;
	vector<vector<int>> element;
	vector<int> answer;

	//첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5<=N<=25)
	//그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

	fp = fopen("test.txt", "r");

	fscanf(fp, "%1d", &data);
	map_size = data;

	element.assign(map_size, vector<int>(map_size, 0));

	while (fscanf(fp, "%1d", &data) != EOF) {
		element[row][col] = data;
		col++;
		if (col == map_size) {
			row++;
			if (row == map_size) {
				break;
			}
			col = 0;
		}
	}

	for (row = 0; row < map_size; row++) {
		for (col = 0; col < map_size; col++) {
			cout << element[row][col];
		}
		cout << endl;
	}

	answer = BFS(map_size, element);
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (vector<int>::iterator its = answer.begin(); its < answer.end(); its++)
	{
		cout << *its << endl;
	}

	return 0;
}