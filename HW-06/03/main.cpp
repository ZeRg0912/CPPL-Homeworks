#include <iostream>
#include <exception>

using namespace std;

template<typename T> class MyOwnVector {

	T* arr;
	size_t capacity;
	size_t current;

public:
	MyOwnVector() {
		arr = new T[1];
		capacity = 1;
		current = 0;
	}

	~MyOwnVector() {
		delete[] arr;
	}

	T at(int index) {
		if (index <= current) {
			return arr[index];
		}
		else {
			throw out_of_range("Out of memory range!\n");
		}
	}

	void push_back(T data) {
		if (current == capacity) {
			capacity *= 2;
			T* temp = new T[capacity];
			for (size_t i = 0; i < capacity; i++) temp[i] = arr[i];
			delete[] arr;
			arr = temp;
		}
		arr[current] = data;
		current++;
	}

	void pop_back() {
		if (current > 0) {
			if (current == (capacity / 4)) {
				capacity /= 2;
				T* temp = new T[capacity];
				for (size_t i = 0; i < capacity / 2; i++) temp[i] = arr[i];
				delete[] arr;
				arr = temp;
			}
			current--;
		}
		else {
			throw out_of_range("Vector empty!");
		}
	}

	size_t size() const {
		return current;
	}

	size_t get_capacity() const {
		return capacity;
	}

	void print() {
		for (size_t i = 0; i < current; i++) {
			if (i != current - 1) cout << arr[i] << ", ";
			else cout << arr[i] << endl;
		}
	}


};

int main() {
	MyOwnVector<int> a;

	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}

	cout << a.size() << " " << a.get_capacity() << endl;

	for (int i = 0; i < 8; i++) {
		a.pop_back();
	}

	cout << a.size() << " " << a.get_capacity() << endl;

	cout << a.at(1) << " " << a.at(2) << endl;

	try {
		for (int i = 0; i < 8; i++) {
			a.pop_back();
		}
	} catch (const out_of_range& err) {
		cerr << err.what() << endl;
	}
	try {
		a.at(30);
	} catch (const out_of_range& err) {
		cerr << err.what() << endl;
	}

	return 0;
}