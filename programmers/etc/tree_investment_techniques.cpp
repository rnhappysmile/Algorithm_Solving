/*
* 문제 : 나무 재테크
* 링크 : https://www.acmicpc.net/problem/16235
*
* N x N 땅이 있다
* 가장 처음에 양분은 모든 칸에 5만큼 들어간다.
*
* 봄, 나무가 자신의 나이만큼 양분ㄴ을 먹고, 나이가 1 증가한다.
*   나이가 어린 나무부터 양분을 먹는다.
*   땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 즉사
*
* 여름, 봄에 죽은 나무가 양분으로 변하게 된다.
*   각각의 죽은 나무마다 나이를 2로 나눈 값이 그 자리에 양분으로 추가된다.
*  (소수점 아래는 버린다.)
*
* 가을, 나무가 번식한다.
*   번식하는 나무는 나이가 5의 배수일 때, 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
*   땅을 벗어나는 칸에는 나무가 생기지 않는다.
*
* 겨울, 땅을 돌아다니면서 따엥 양분을 추가한다.
*   각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.
*
* 결과, K년이 지난 후 상도의 땅에 살아있는 나무의 개수를 구하는 프로그램
*
* 입력, 첫째 줄에 N, M, K가 주어진다
* 둘째 줄부터 N개의 줄에 A배열의 값이 주어진다.
* 다음 M개의 줄에는 사옫가 심은 나무의 정보를 나타내는 세 정수 x, y, z가 주어진다
* 처음 두 개의 정수는 나무의 위치, 마지막 정수는 그 나무의 나이를 의미한다
*
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define DIR_MAX 8

struct tree_info {
	int x;
	int y;
	int age;
};

bool cmp(const tree_info &a, const tree_info &b) {
	if (a.x == b.x && a.y == b.y) {
		return a.age < b.age;
	}
	else {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		else {
			return a.x < b.x;
		}
	}
}

bool Inside(int x, int y, int map_size) {
	return ((x >= 1) && (x < map_size) && (y >= 1) && (y < map_size));
}

int main()
{
	FILE *fp;
	vector<vector<int>> map;
	vector<vector<int>> basic_map;
	vector<tree_info> trees;
	int death_trees_flag = 0;
	int fall_flag = 0;
	int data = 0;
	int cur_x = 1, cur_y = 1, cur_age = 0;
	int map_size = 0;
	int end_years = 0;
	int trees_count = 0;
	int dir[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

	fp = fopen("test.txt", "r");
	fscanf(fp, "%1d", &data);
	if ((1 <= data) && (data <= 10)) {
		map_size = data + 1;
	}
	else {
		return 0;
	}

	fscanf(fp, "%1d", &data);
	if ((1 <= data) && (data <= (map_size * map_size))) {
		trees_count = data;
	}
	else {
		return 0;
	}

	fscanf(fp, "%1d", &data);
	if ((1 <= data) && (data <= 1000)) {
		end_years = data;
	}
	else {
		return 0;
	}

	basic_map.assign(map_size, vector<int>(map_size, 0));
	map.assign(map_size, vector<int>(map_size, 0));
	
	for (int i = 1; i < map_size; i++) {
		for (int j = 1; j < map_size; j++) {
			fscanf(fp, "%1d", &data);
			basic_map[i][j] = data;
			map[i][j] = 5;
		}
	}

	for (int i = 0; i < trees_count; i++) {
		fscanf(fp, "%d %d %d", &cur_x, &cur_y, &cur_age);

		trees.push_back({ cur_x, cur_y, cur_age });
	}

	while (end_years--) {
		vector<tree_info> alive;
		vector<tree_info> dead;
		vector<tree_info> five;
		vector<tree_info> birth;

		sort(trees.begin(), trees.end(), cmp);
		//º½
		for (unsigned int i = 0; i < trees.size(); i++) {
			int x = trees[i].x;
			int y = trees[i].y;
			int age = trees[i].age;

			if (map[x][y] < age) {
				dead.push_back({ x, y, age });
			}
			else {
				map[x][y] -= age;
				trees[i].age++;
				alive.push_back({ x, y, trees[i].age });
				if (trees[i].age % 5 == 0) {
					five.push_back({ x, y, trees[i].age });
				}
			}
		}

		//¿©¸§
		for (unsigned int i = 0; i < dead.size(); i++) {
			int x = dead[i].x;
			int y = dead[i].y;
			int age = dead[i].age;

			map[x][y] += age / 2;
		}

		//°¡À»
		for (unsigned int i = 0; i < five.size(); i++) {
			int x = five[i].x;
			int y = five[i].y;

			for (int i = 0; i < DIR_MAX; i++)
			{
				int next_x = dir[i][0] + x;
				int next_y = dir[i][1] + y;

				if (Inside(next_x, next_y, map_size)) {
					birth.push_back({ next_x, next_y, 1 });
				}
			}
		}

		//°Ü¿ï
		for (int x = 1; x < map_size; x++) {
			for (int y = 1; y < map_size; y++) {
				map[x][y] += basic_map[x][y];
			}
		}

		trees.clear();
		for (unsigned int i = 0; i < alive.size(); i++) {
			int x = alive[i].x;
			int y = alive[i].y;
			int age = alive[i].age;
			trees.push_back({ x, y, age });
		}

		for (unsigned int i = 0; i < birth.size(); i++) {
			int x = birth[i].x;
			int y = birth[i].y;
			int age = birth[i].age;
			trees.push_back({ x, y, age });
		}

		alive.clear();
		birth.clear();
		dead.clear();
		five.clear();

		trees_count = trees.size();
	}

	cout << trees_count << endl;

	return 0;
}

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define DIR_MAX 8

struct tree_info {
	int x;
	int y;
	int age;
};

bool cmp(const tree_info &a, const tree_info &b) {
	if (a.x == b.x && a.y == b.y) {
		return a.age < b.age;
	}
	else {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		else {
			return a.x < b.x;
		}
	}
}

bool Inside(int x, int y, int map_size) {
	return ((x >= 1) && (x < map_size) && (y >= 1) && (y < map_size));
}

int main()
{
	FILE *fp;
	vector<vector<int>> map;
	vector<vector<int>> basic_map;
	vector<tree_info> trees;
	int death_trees_flag = 0;
	int fall_flag = 0;
	int data = 0;
	int cur_x = 1, cur_y = 1, cur_age = 0;
	int map_size = 0;
	int end_years = 0;
	int trees_count = 0;
	int dir[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

	fp = fopen("test.txt", "r");
	fscanf(fp, "%1d", &data);
	if ((1 <= data) && (data <= 10)) {
		map_size = data + 1;
	}
	else {
		return 0;
	}

	fscanf(fp, "%1d", &data);
	if ((1 <= data) && (data <= (map_size * map_size))) {
		trees_count = data;
	}
	else {
		return 0;
	}

	fscanf(fp, "%1d", &data);
	if ((1 <= data) && (data <= 1000)) {
		end_years = data;
	}
	else {
		return 0;
	}

	basic_map.assign(map_size, vector<int>(map_size, 0));
	map.assign(map_size, vector<int>(map_size, 0));
	
	for (int i = 1; i < map_size; i++) {
		for (int j = 1; j < map_size; j++) {
			fscanf(fp, "%1d", &data);
			basic_map[i][j] = data;
			map[i][j] = 5;
		}
	}

	for (int i = 0; i < trees_count; i++) {
		fscanf(fp, "%d %d %d", &cur_x, &cur_y, &cur_age);

		trees.push_back({ cur_x, cur_y, cur_age });
	}

	while (end_years--) {
		vector<tree_info> alive;
		vector<tree_info> dead;
		vector<tree_info> five;
		vector<tree_info> birth;

		sort(trees.begin(), trees.end(), cmp);
		//º½
		for (unsigned int i = 0; i < trees.size(); i++) {
			int x = trees[i].x;
			int y = trees[i].y;
			int age = trees[i].age;

			if (map[x][y] < age) {
				dead.push_back({ x, y, age });
			}
			else {
				map[x][y] -= age;
				trees[i].age++;
				alive.push_back({ x, y, trees[i].age });
				if (trees[i].age % 5 == 0) {
					five.push_back({ x, y, trees[i].age });
				}
			}
		}

		//¿©¸§
		for (unsigned int i = 0; i < dead.size(); i++) {
			int x = dead[i].x;
			int y = dead[i].y;
			int age = dead[i].age;

			map[x][y] += age / 2;
		}

		//°¡À»
		for (unsigned int i = 0; i < five.size(); i++) {
			int x = five[i].x;
			int y = five[i].y;

			for (int i = 0; i < DIR_MAX; i++)
			{
				int next_x = dir[i][0] + x;
				int next_y = dir[i][1] + y;

				if (Inside(next_x, next_y, map_size)) {
					birth.push_back({ next_x, next_y, 1 });
				}
			}
		}

		//°Ü¿ï
		for (int x = 1; x < map_size; x++) {
			for (int y = 1; y < map_size; y++) {
				map[x][y] += basic_map[x][y];
			}
		}

		trees.clear();
		for (unsigned int i = 0; i < alive.size(); i++) {
			int x = alive[i].x;
			int y = alive[i].y;
			int age = alive[i].age;
			trees.push_back({ x, y, age });
		}

		for (unsigned int i = 0; i < birth.size(); i++) {
			int x = birth[i].x;
			int y = birth[i].y;
			int age = birth[i].age;
			trees.push_back({ x, y, age });
		}

		alive.clear();
		birth.clear();
		dead.clear();
		five.clear();

		trees_count = trees.size();
	}

	cout << trees_count << endl;

	return 0;
}