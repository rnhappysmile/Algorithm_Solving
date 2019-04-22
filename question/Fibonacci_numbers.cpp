// 문제가 개편 되었습니다. 이로 인해 함수 구성이 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include<iostream>
using namespace std;

long long fibonacci(int n)
{
  if(n == 0 || n == 1){
    return n;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main()
{
	int testCase = 4;
	long long testAnswer = fibonacci(testCase);

	cout<<testAnswer;
}