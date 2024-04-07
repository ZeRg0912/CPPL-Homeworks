#include <iostream>
#include <exception>
#include "catch_amalgamated.hpp"

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
	MyVector(const MyVector& other) : size(other.size), capacity(other.capacity) {
		data = new T[capacity];
		for (size_t i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
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

	void erase(size_t index) {
		if (index >= size) {
			throw std::out_of_range("Index out of range");
		}
		for (size_t i = index; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size--;
	}

	void clear() {
		delete[] data;
		data = nullptr;
		size = 0;
		capacity = 0;
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
		if (this != &other) {
			delete[] data;
			size = other.size;
			capacity = other.capacity;
			data = new T[capacity];
			std::copy(other.data, other.data + size, data);
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

TEST_CASE("Task #1:", "[Vector]") {
	MyVector<int> a;
	MyVector<int> c = { 5, 6, 7, 8 };
	std::cout << "\nVector a:\n";
	a.print();

	std::cout << "\nVector a after push_back:\n";
	a.push_back(5);
	a.print();
	REQUIRE(a[a.get_size() - 1] == 5);

	std::cout << "\nVector a after clear:\n";
	a.clear();
	a.print();

	std::cout << "\nVector a after push_back cycle:\n";
	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}
	a.print();	
	for (size_t i = a.get_size() - 1; i > 1; i--) {
		REQUIRE(a[i] == i);
	}

	std::cout << "\nVector a after pop_back:\n";
	for (int i = 0; i < 10; i++) {
		a.pop_back();
	}
	REQUIRE(a.get_size() == 0);
	a.print();

	std::cout << "\nVector a after fit:\n";
	a.shrink_to_fit();
	a.print();
	REQUIRE(a.get_capacity() == 0);

	std::cout << "\nVector a after a[0] = 2\n";
	a.push_back(5);
	a[0] = 2;
	a.print();
	REQUIRE(a[0] == 2);

	std::cout << "\nVector a after .at():\n";
	std::cout << a.at(0) << std::endl;
	REQUIRE(a.at(0) == 2);

	std::cout << "\nVector a try catch after .at() with index out of range:\n";
	CHECK(a.at(5));

	std::cout << "\nVector b :\n";
	MyVector<double> b = { 0.2, 1.22, 3.25 };
	b.print();

	std::cout << "\nVector a after (a = c)\n";
	a = c;
	a.print();
	for (size_t i = 0; i < c.get_size(); i++) {
		REQUIRE(a[i] == c[i]);
	}

	MyVector<int> c1 = { 5,6,7,8 };
	MyVector<int> c2 = c1;
	for (size_t i = 0; i < c1.get_size(); i++) {
		REQUIRE(c1[i] == c2[i]);
	}
	std::cout << "\nVector c1:\n";
	c1.print();
	std::cout << "Vector c2:\n";
	c2.print();

	MyVector<int> c3 = { 8,7,6,5,4,3,2 };
	MyVector<int> c4(c3); 
	for (size_t i = 0; i < c3.get_size(); i++) {
		REQUIRE(c3[i] == c4[i]);
	}
	std::cout << "\nVector c3:\n";
	c3.print();
	std::cout << "Vector c4:\n";
	c4.print();
}

int main() {
	return Catch::Session().run();
}