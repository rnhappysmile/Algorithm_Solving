/*
* BFS 알고리즘 문제 바이러스
* 문제 URL: https://www.acmicpc.net/problem/2606
*/

#include <stdio.h>
#include <vector>
#include <iterator>
#include <iostream>
#include <queue>

#define MAX_INDEX 2
#define SIZE_DEFINE 1
#define CUR_INDEX 0
#define NEXT_INDEX 1
using namespace std;

int BFS(int computers, int connect, vector<vector<int>> element)
{
	int answer = 0;
	int visit = 1;
	vector<bool> visited;
	queue<int> q;

	visited.assign(computers + SIZE_DEFINE, false);
	q.push(visit);

	while (!q.empty()) {
		for (int i = 0; i < connect; i++) {
			if ((visited[element[i][NEXT_INDEX]] == false) && (element[i][CUR_INDEX] == visit)) {
				q.push(element[i][NEXT_INDEX]);
				answer++;
				visited[element[i][NEXT_INDEX]] = true;
			}
		}

		q.pop();

		if (!q.empty()) {
			visit = q.front();
		}
	}

	return answer;
}

int main()
{
	FILE *fp;
	int data;
	int computers = 0, connect = 0;
	int cur_connect = 0, index = 0;
	vector<vector<int>> element;

	//첫째 줄에는 컴ㅍ터의 수가 주어진다.
	//컴퓨터의 수는 100이하고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다.
	//둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 싸으이 수가 주어짐
	fp = fopen("test.txt", "r");

	fscanf(fp, "%1d", &data);
	computers = data;
	fscanf(fp, "%1d", &data);
	connect = data;

	element.assign(connect, vector<int>(2, 0));
	
	while (fscanf(fp, "%1d", &data) != EOF) {
		element[cur_connect][index] = data;
		index++;
		if (index == MAX_INDEX) {
			cur_connect++;
			if (cur_connect == connect) {
				break;
			}
			index = 0;
		}
	}

	for (int i = 0; i < connect; i++) {
		cout << element[i][0] << element[i][1] << endl;
	}

	cout << BFS(computers, connect, element) << endl;

	return 0;
}