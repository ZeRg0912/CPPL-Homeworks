#include <iostream>

template<typename T>
class MyUniquePtr {
private:
	T* ptr;
public:
	MyUniquePtr(T* p = nullptr) : ptr(p) {};
	~MyUniquePtr() {
		std::cout << "Destructor called!\n";
		if (ptr != nullptr) delete ptr;
	}

	T& operator*() const { return *ptr; }

	MyUniquePtr(const MyUniquePtr&) = delete;
	MyUniquePtr& operator= (const MyUniquePtr&) = delete;

	T* release() {
		T* temp = ptr;
		ptr = nullptr;
		return temp;
	}
};

int main() {
	MyUniquePtr<int> p(new int(10));
	std::cout << *p << '\n';

	int* raw_ptr = p.release();
	std::cout << *raw_ptr << '\n';

	delete raw_ptr;
	std::cout << "raw_ptr destructor called!\n";

	return 0;
}