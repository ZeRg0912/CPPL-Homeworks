#include <iostream>
#include <vector>
#include <algorithm>

template<typename T> 
void print(const std::vector<T>& vec) {
	auto it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << '\n';
}

template<typename T>
void uniq(std::vector<T>& vec) {
	std::sort(vec.begin(), vec.end());
	auto last = std::unique(vec.begin(), vec.end());
	vec.erase(last, vec.end());
}

template<typename T>
void solution(std::vector<T>& vec) {
	std::cout << "[IN]: ";
	print(vec);
	uniq(vec);
	std::cout << "[OUT]: ";
	print(vec);
	std::cout << std::string(30, '=') << '\n';
}

int main() {
	std::vector<int> vec1 = { 1,2,3,4,2,3,1,5 };
	solution(vec1);
	std::vector<int> vec2 = { 1,1,2,5,6,1,2,4 };
	solution(vec2);
	std::vector<double> vec3 = { 2.21,3.45,14.2,2.21,14.2,5.64,3.45 };
	solution(vec3);
	std::vector<std::string> vec4 = {"goose", "dog", "cat", "cow", "bull", "cat", "bull", "dog"};
	solution(vec4);

	return 0;
}