#include <iostream>
#include <vector>

using namespace std;

template <class T>
T squared(T num) {
	return num * num;
}

template<class T>
void print_squared(T num) {
	cout << "[IN]: " << num << endl;
	cout << "[OUT]: " << squared(num) << endl;
}

template<class T>
void print_squared(vector<T> v) {
	cout << "[IN]: ";
	for (int i = 0; i < v.size(); i++) {
		if (i != v.size() - 1) cout << v[i] << ", ";
		else cout << v[i] << endl;
	}
	
	cout << "[OUT]: ";
	for (int i = 0; i < v.size(); i++) {
		if (i != v.size() - 1) cout << squared(v[i]) << ", ";
		else cout << squared(v[i]) << endl;
	}
}

int main() {
	int a = 4;
	vector<int> b = { -1, 4, 8 };
	vector<double> c = { -1.2, 4.3, 8.4 };

	print_squared(a);
	print_squared(b);
	print_squared(c);

	return 0;
}