#include <iostream>
#include <vector>
#include <map>

#include <algorithm>
#include <functional>

using namespace std;

class base {
public:
	virtual void some_func(int val) {};
};

class derived : public base {
public:
	void some_func(int val) override {};
};

// C++ 14
template<typename T>
auto sum(T a, T b) {
	return a + b;
}

// C++ 20
auto sum1(auto a, auto b) {
	return a + b;
}

map<string, vector<int>> some_func();

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	system("chcp 1251");
	system("cls");

	// AUTO	
	/*

	auto a = sum(3.2, 5.7);
	cout << "a = " << a << " (type - " << typeid(a).name() << ")" << endl;

	auto b = sum1(3, 5);
	cout << "b = " << b << " (type - " << typeid(b).name() << ")" << endl;

	auto result = some_func();*/

	// RANGE BASED FOR
	
	/*double arr[]{1,2,3,4,2,1,3};
	vector<int> vi{ 1,2,3,4,5 };

	for (int i = 0; i < vi.size(); i++) {
		cout << vi[i] << "\t";
	}
	cout << endl;
	for (const auto & i : vi) {
		cout << i << "\t";
	}
	cout << endl;
	for (const auto & i : arr) {
		cout << i << "\t";
	}
	cout << endl;
	vector<int> vec = { 1,2,3,4,5 };
	for (auto it = vec.begin(); it != vec.end(); it++) {
		cout << *it << "\t";
	}
	cout << endl;
	// Ñ ÄÈÍÀÌÈ×ÅÑÊÈÌ ÌÀÑÑÈÂÎÌ ÍÅ ÏÎËÓ×ÈÒÑß
	int* arr_d = new int[5] {0};
	for (int i : arr_d) {
		cout << i << "\t";
	}
	*/

	auto sum = [](auto a, auto b) {return a + b; };

	cout << sum(19, 20.5);

	return 0;
}