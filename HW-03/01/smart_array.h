#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

class smart_array {
private:
	int* data;
	int size;
	int last_index;
public:
	smart_array(int init_size);
	~smart_array();
	void add_element(int element);
	int get_element(int index);
	void print();
	smart_array& operator=(const smart_array& other);
};