// 문제가 개편 되었습니다. 이로 인해 함수 구성이 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getMinSum(vector<int> A, vector<int> B)
{
	int answer = 0;
	int maxCount = 0;

	maxCount = A.size();

	std::sort(A.begin(), A.begin() + A.size());
	std::sort(B.begin(), B.begin() + B.size());

	for (int count = 0; count < maxCount; count++)
	{
		answer += A[count] * B[maxCount - count - 1];
	}

	return answer;
}
int main()
{
	vector<int> tA{ 1,2 }, tB{ 3,4 };

	//아래는 테스트 출력을 위한 코드입니다.
	cout << getMinSum(tA, tB) << endl;

	return 0;
}