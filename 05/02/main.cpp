#include <iostream>

using namespace std;

template <class T>
class Table {
private:
	size_t rows = NULL;
	size_t cols = NULL;
	T** table = nullptr;

public:
	Table(size_t rows_, size_t cols_) : rows(rows_), cols(cols_) {
		table = new T*[rows];
		for (size_t i = 0; i < rows; i++) {
			table[i] = new T[cols];
		}
	}

	~Table() {
		for (size_t i = 0; i < rows; i++) {
			delete[] table[i];
		}
		delete[] table;
	}

	const T* operator[](size_t index) const {
		return table[index];
	}

	T* operator[](size_t index) {
		return table[index];
	}

	size_t size() const {
		return rows * cols;
	}

};

int main() {
	auto test = Table<int>(2, 3);

	test[0][0] = 4;

	cout << test[0][0] << endl;
	cout << test.size() << endl;

	return 0;
}