/*
* BFS �˰��� ���� ���̷���
* ���� URL: https://www.acmicpc.net/problem/2606
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

	//ù° �ٿ��� �Ĥ����� ���� �־�����.
	//��ǻ���� ���� 100���ϰ� �� ��ǻ�Ϳ��� 1�� ���� ���ʴ�� ��ȣ�� �Ű�����.
	//��° �ٿ��� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ�� ������ ���� �־���
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