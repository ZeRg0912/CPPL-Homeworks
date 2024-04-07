#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class simple_functor {
public:
	// print vector
	template<class T>
	void print(vector<T>& v) {
		cout << "[IN]: ";
		for (int i = 0; i < v.size(); i++) {
			if (i != v.size() - 1) cout << v[i] << ", ";
			else cout << v[i] << endl;
		}
	}

	// get_sum variable for int
	template<class T>
	T get_sum(vector<T>& v) {
		T sum = 0;
		for (auto& element : v) {
			if (element % 3 == 0) {
				sum += element;
			}
		}
		cout << "[OUT]: get_sum() = " << sum << endl;
		return sum;
	}

	// get_sum variable for double
	template<>
	double get_sum(vector<double>& v) {
		double sum = 0;
		for (auto& element : v) {
			if (!fmod(element, 3)) {
				sum += element;
			}
		}
		cout << "[OUT]: get_sum() = " << sum << endl;
		return sum;
	}

	// get_count variable for int
	template<class T>
	T get_count(vector<T>& v) {
		T count = 0;
		for (auto& element : v) {
			if (!fmod(element, 3)) {
				count++;
			}
		}
		cout << "[OUT]: get_count() = " << count << endl;
		return count;
	}

	// get_count variable for double
	template<>
	double get_count(vector<double>& v) {
		double count = 0;
		for (auto& element : v) {
			if (!fmod(element, 3)) {
				count++;
			}
		}
		cout << "[OUT]: get_count() = " << count << endl;
		return count;
	}

	// functor 
	template<class T>
	void operator()(vector<T>& v) {
		print(v);
		get_sum(v);
		get_count(v);
	}
};

int main() {
	simple_functor fc;

	vector<int> vec = { 4, 1, 3, 6, 25, 54 };
	vector<double> vec2 = { 12.00, 15.45, 2.51, 5.55, 85.25 }; 

	fc(vec);
	fc(vec2);
	return 0;
}