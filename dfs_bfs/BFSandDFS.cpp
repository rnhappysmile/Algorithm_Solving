#include <iterator>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/**
* @brief: ���� ����� ����ϴ� �Լ�
* @param: bool visitArr[], int ver
*
* visitArr: ������ ���� �湮 ���θ� ��Ÿ���� �迭
* ver: �湮�� ���� ����
*/
void VisitVertex(bool visitArr[], int ver) {
	cout << ver << " ";
	visitArr[ver] = true;
}

/**
* @brief: ���� �켱 Ž��
* @param: vector<int> vecArr[], bool visitArr[], int num, int fir
*
* vecArr: �׷��� ��Ÿ���� �迭(by ���� ����Ʈ)
* visitArr: ī�� ���� �� �ߺ��� �����ϴ� ���� �迭
* num: ������ ����
* fir: ó�� �湮�� ���� ����
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
* @brief: ���� �켱 Ž��
* @param: vector<int> vecArr[], bool visitArr[], int num, int fir
*
* vecArr: �׷��� ��Ÿ���� �迭(by ���� ����Ʈ)
* visitArr: ī�� ���� �� �ߺ��� �����ϴ� ���� �迭
* num: ������ ����
* fir: ó�� �湮�� ���� ����
*/

void DFS(vector<int> element, vector<vector<int>> edge, bool visitArr[]) {
	stack<int> stack;
	bool visitFlag = false;
	int visit = element.at(2); // �湮 ���� ����

	for (int i = 0; i <= element.at(0); i++) // �湮 ���� ���� false
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