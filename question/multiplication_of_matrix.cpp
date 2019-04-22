// 문제가 개편 되었습니다. 이로 인해 함수 구성이 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> >productMatrix(vector<vector<int> >A, vector<vector<int> >B)
{
	vector<vector<int> >answer;
	
	cout << "Hello productMatrix" << endl;

	for (int count = 0; count < A.size(); count++) {
		answer.push_back({ 0,0 });
	}

	//그리고 행렬의 곱을 리턴
	for (int row = 0; row < A.size(); row++) {
		for (int col = 0; col < A.size(); col++) {
			for (int inner = 0; inner < A.size(); inner++) {
				answer[row][col] += A[row][inner] * B[inner][col];
			}
		}
	}
	return answer;
}

int main()
{
	vector<vector<int> >A{ { 1,4 },{ 3,2 }, {4,1} };
	vector<vector<int> >B{ { 3,3 },{ 3,3 } };
	vector<vector<int> > testAnswer = productMatrix(A, B);

	for (int i = 0; i<testAnswer.size(); i++)
	{
		for (int j = 0; j<testAnswer[i].size(); j++)
			cout << testAnswer[i][j] << " ";
		cout << "\n";
	}
}