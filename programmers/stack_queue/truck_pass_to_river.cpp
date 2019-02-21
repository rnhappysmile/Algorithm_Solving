//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int pass_truck = 0;
	int current_weigt = 0;
	int front_weigh = 0;
	int current_truck = 0;
	int bridge_size = 0;
	queue<int> truck_weights_queue;
	queue<int> current_weight_queue;
	queue<int> bridge;

    if((bridge_length > 10000) || (weight > 10000) || (truck_weights.size() < 1) || (truck_weights.size() > 10000))
    {
        return answer;
    }
    
	for (vector<int>::iterator it = truck_weights.begin(); it != truck_weights.end(); it++)
	{
		truck_weights_queue.push(*it);
	}

	bridge.empty();

	while((!bridge.empty()) || (!truck_weights_queue.empty()))
	{
		bridge_size = bridge.size();
		for (int count = 0; count < bridge_size; count++)
		{
			current_truck = bridge.front();
			bridge.pop();
			current_truck--;
			if (current_truck > 0)
			{
				bridge.push(current_truck);
			}
			else {
				current_weigt -= current_weight_queue.front();
				current_weight_queue.pop();
			}
		}

		if (truck_weights_queue.size() > 0)
		{
			if (current_weigt + truck_weights_queue.front() <= weight)
			{
				bridge.push(bridge_length);
				current_weigt += truck_weights_queue.front();
				current_weight_queue.push(truck_weights_queue.front());
				truck_weights_queue.pop();
			}
		}
		answer++;

	}
	return answer;
}

int main()
{
	int answer = 0;
	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = {7, 4, 5, 6};

	answer = solution(bridge_length, weight, truck_weights);

	cout << answer << endl;

	return 0;
}