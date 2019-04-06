#include <iterator>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/**
* @brief: 정점 출력을 담당하는 함수
* @param: bool visitArr[], int ver
*
* visitArr: 정점에 대해 방문 여부를 나타내는 배열
* ver: 방문할 정점 변수
*/
void VisitVertex(bool visitArr[], int ver) {
	cout << ver << " ";
	visitArr[ver] = true;
}

/**
* @brief: 넓이 우선 탐색
* @param: vector<int> vecArr[], bool visitArr[], int num, int fir
*
* vecArr: 그래프 나타내는 배열(by 인접 리스트)
* visitArr: 카드 섞을 때 중복을 방지하는 기준 배열
* num: 정점의 개수
* fir: 처음 방문할 정점 변수
*/
void BFS(vector<int> element, vector<vector<int>> edge, bool visitArr[]) {
	queue<int> queue;
	int visit = element.at(2);

	for (int i = 0; i <= element.at(0); i++)
		visitArr[i] = false;

	queue.push(visit);
	VisitVertex(visitArr, visit);
	while (!queue.empty()) {
		for (int i = 0; i < element.at(1); i++) {
			if ((visit == edge[i][0]) && (visitArr[edge[i][1]] == false))
			{
				queue.push(edge[i][1]);
				VisitVertex(visitArr, edge[i][1]);
			}
		}
		
		queue.pop();
		if (!queue.empty()) {
			visit = queue.front();
		}
	}
}

/**
* @brief: 깊이 우선 탐색
* @param: vector<int> vecArr[], bool visitArr[], int num, int fir
*
* vecArr: 그래프 나타내는 배열(by 인접 리스트)
* visitArr: 카드 섞을 때 중복을 방지하는 기준 배열
* num: 정점의 개수
* fir: 처음 방문할 정점 변수
*/

void DFS(vector<int> element, vector<vector<int>> edge, bool visitArr[]) {
	stack<int> stack;
	bool visitFlag = false;
	int visit = element.at(2); // 방문 변수 선언

	for (int i = 0; i <= element.at(0); i++) // 방문 여부 전부 false
		visitArr[i] = false;

	stack.push(element.at(2));
	VisitVertex(visitArr, element.at(2));

	while (!stack.empty()) {
		visitFlag = false;
		for(int i = 0; i < element.at(1); i++)
			{
			if (visit == edge[i][0]) {
				if (visitArr[edge[i][1]] == false)
				{
					stack.push(visitArr[edge[i][1]]);
					VisitVertex(visitArr, edge[i][1]);
					visit = edge[i][1];
					visitFlag = true;
					break;
				}
			}
		}

		if (visitFlag == false) {
			stack.pop();
			if (!stack.empty()) {
				visit = stack.top();
			}
		}
	}

}

int main()
{
	vector<int> test_element{ 4, 5, 1 };
	vector<vector<int>> test_edge{ {1,2}, {1,3}, {1,4},{2,4},{3,4} };

	bool * visitArr = (bool *)malloc(sizeof(bool) * (test_element.size() + 1));

	BFS(test_element, test_edge, visitArr);

	//DFS(test_element, test_edge, visitArr);

	return 0;
}