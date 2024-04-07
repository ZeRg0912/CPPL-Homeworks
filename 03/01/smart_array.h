#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

class smart_array {
private:
	int* data;
	size_t size;
	size_t last_index;
public:
	smart_array(int init_size) : data(new int[init_size] {}), size(init_size), last_index(0) {};

	~smart_array() {
		delete[] data;
	};

	void add_element(int element);
	int get_element(int index);
	void print();
	smart_array& operator=(const smart_array& other);
};