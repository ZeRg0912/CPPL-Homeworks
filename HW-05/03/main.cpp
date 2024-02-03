#include <iostream>
#include <vector>

using namespace std;

class print {
public:
	void operator()(const vector<int>& v) {
		cout << "[IN]: ";
		for (int i = 0; i < v.size(); i++) {
			if (i != v.size() - 1) cout << v[i] << ", ";
			else cout << v[i] << endl;
		}
	}
};

class get_count {
public:
	get_count() = default;
	int operator()(const vector<int>& v) {
		int count = 0;
		for (auto& element : v) {
			if (element % 3 == 0) {
				count++;
			}
		}
		cout << "[OUT]: get_count() = " << count << endl;
		return count;
	}
};

class get_sum {
public:
	get_sum() = default;
	int operator()(const vector<int>& v) {
		int sum = 0;
		for (auto& element : v) {
			if (element % 3 == 0) {
				sum += element;
			}
		}
		cout << "[OUT]: get_sum() = " << sum << endl;
		return sum;
	}
};

int main() {
	print print;
	get_sum get_sum;
	get_count get_cout;
	vector<int> vec = { 4,1,3,6,25,54 };
	vector<int> vec2 = { 12,18,2,5,85 };

	print(vec);
	get_sum(vec);
	get_cout(vec);

	print(vec2);
	get_sum(vec2);
	get_cout(vec2);


	return 0;
}