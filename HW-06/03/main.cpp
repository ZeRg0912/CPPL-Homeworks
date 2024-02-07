#include <iostream>
#include <exception>

template<typename T>
class MyVector {
private:
	T* data;
	size_t size;
	size_t capacity;
public:
	MyVector() : data(nullptr), size(0), capacity(0) {}
	explicit MyVector(size_t init_capacity) : data(new T[init_capacity]), size(0), capacity(init_capacity) {}
	MyVector(std::initializer_list<T> init_list) : size(init_list.size()), capacity(init_list.size()) {
		data = new T[capacity];
		std::copy(init_list.begin(), init_list.end(), data);
	}

	~MyVector() {
		delete[] data;
	}

	void push_back(const T& value) {
		if (size >= capacity) {
			if (capacity == 0) capacity = 1;
			else capacity *= 2;
			T* temp_data = new T[capacity];
			for (size_t i = 0; i < size; i++) {
				temp_data[i] = data[i];
			}
			delete[] data;
			data = temp_data;
		}
		data[size++] = value;
	}

	void pop_back() {
		if (size > 0) size--;
		else throw std::out_of_range("Nothing to pop, vector is empty");
	}

	void shrink_to_fit() {
		if (size < (capacity / 4)) {
			capacity = size;
			T* temp_data = new T[capacity];
			for (size_t i = 0; i < size; i++) {
				temp_data[i] = data[i];
			}
			delete[] data;
			data = temp_data;
		}
	}

	T& at(size_t index) {
		if (index < size) return data[index];
		else throw std::out_of_range("Index out of range");
	}

	size_t get_size() const{
		return size;
	}

	size_t get_capacity() const {
		return capacity;
	}

	T& operator[](size_t index) {
		if (index < size) return data[index];
		else throw std::out_of_range("Index out of range");
	}

	const T& operator[](size_t index) const{
		if (index < size) return data[index];
		else throw std::out_of_range("Index out of range");
	}

	MyVector& operator=(const MyVector& other) {
		if (this != other) {
			delete[] data;
			size = other.size;
			capacity = other.capacity;
			data = new T[capacity];
			for (size_t i = 0; i < size; i++) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	void print() {
		std::cout << "Size: " << get_size() << " Capacity: " << get_capacity() << std::endl;
		for (size_t i = 0; i < size; i++) {
			if (i != size -1) std::cout << data[i] << ", ";
			else std::cout << data[i] << std::endl;
		}
	}
};

int main() {
	MyVector<int> a;
	MyVector<double> b = { 0.2, 1.22, 3.25 };
	a.print();
	a.push_back(5);
	a.print();
	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}
	a.print();
	for (int i = 0; i < 10; i++) {
		a.pop_back();
	}
	a.shrink_to_fit();
	a.print();

	a[0] = 2;
	a.print();

	std::cout << a.at(0) << std::endl;
	try {
		std::cout << a.at(5) << std::endl;
	}
	catch (const std::out_of_range& err) {
		std::cerr << "Exception caught: " << err.what() << std::endl;
	}

	return 0;
}