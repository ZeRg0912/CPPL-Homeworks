#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>

//Вывод контейнеров:
#if 1
// Прямой порядок
#if 1
// Вывод контейнера
template<typename T>
void print_container(const T& cont) {
    for (auto it = cont.begin(); it != cont.end(); it++) {
        if (it != std::prev(cont.end(), 1)) std::cout << *it << ", ";
        else std::cout << *it << '\n';
    }
    std::cout << std::string(30, '-') << '\n';
}

// Вывод ассоциативного контейнера (map и unordered_map)
template<typename Key, typename Value>
void print_container(const std::map<Key, Value>& cont) {
    for (auto it = cont.begin(); it != cont.end(); it++) {
        if (it != std::prev(cont.end(), 1)) std::cout << "{" << it->first << ": " << it->second << "}, ";
        else std::cout << "{" << it->first << ": " << it->second << "}\n";
    }
    std::cout << std::string(30, '-') << '\n';
}

template<typename Key, typename Value>
void print_container(const std::unordered_map<Key, Value>& cont) {
    for (auto it = cont.begin(); it != cont.end(); it++) {
        if (it != std::prev(cont.end(), 1)) std::cout << "{" << it->first << ": " << it->second << "}, ";
        else std::cout << "{" << it->first << ": " << it->second << "}\n";
    }
    std::cout << std::string(30, '-') << '\n';
}

// Вывод стека
template<typename T>
void print_container(const std::stack<T>& cont) {
    std::stack<T> temp = cont;
    while (!temp.empty()) {
        if (temp.size() != 1) std::cout << temp.top() << ", ";
        else std::cout << temp.top() << '\n';
        temp.pop();
    }
    std::cout << std::string(30, '-') << '\n';
}

// Вывод очереди
template<typename T>
void print_container(const std::queue<T>& cont) {
    std::queue<T> temp = cont;
    while (!temp.empty()) {
        if (temp.size() != 1) std::cout << temp.front() << ", ";
        else std::cout << temp.front() << '\n';
        temp.pop();
    }
    std::cout << std::string(30, '-') << '\n';
}

// Вывод двусторонней очереди
template<typename T>
void print_container(const std::deque<T>& cont) {
    for (auto it = cont.begin(); it != cont.end(); it++) {
        if (it != std::prev(cont.end(), 1)) std::cout << *it << ", ";
        else std::cout << *it << '\n';
    }
    std::cout << std::string(30, '-') << '\n';
}
#endif

// Обратный порядок
#if 1
// Вывод контейнера в обратном порядке
template<typename T>
void reverse_print_container(const T& cont) {
    for (auto it = cont.rbegin(); it != cont.rend(); it++) {
        if (it != std::prev(cont.rend(), 1)) std::cout << *it << ", ";
        else std::cout << *it << '\n';
    }
    std::cout << std::string(30, '-') << '\n';
}

// Вывод ассоциативного контейнера (map и unordered_map)
template<typename Key, typename Value>
void reverse_print_container(const std::map<Key, Value>& cont) {
    for (auto it = cont.rbegin(); it != cont.rend(); it++) {
        if (it != std::prev(cont.rend(), 1)) std::cout << "{" << it->first << ": " << it->second << "}, ";
        else std::cout << "{" << it->first << ": " << it->second << "}\n";
    }
    std::cout << std::string(30, '-') << '\n';
}

template<typename Key, typename Value>
void reverse_print_container(const std::unordered_map<Key, Value>& cont) {
    std::vector<std::pair<Key, Value>> temp;
    temp.reserve(cont.size());
    for (const auto& pair : cont) {
        temp.emplace_back(pair);
    }
    for (auto it = temp.rbegin(); it != temp.rend(); it++) {
        if (it != std::prev(temp.rend(), 1)) std::cout << "{" << it->first << ": " << it->second << "}, ";
        else std::cout << "{" << it->first << ": " << it->second << "}\n";
    }
    std::cout << std::string(30, '-') << '\n';
}

// Вывод стека
template<typename T>
void reverse_print_container(const std::stack<T>& cont) {
    std::vector<T> temp;
    temp.reserve(cont.size());
    std::stack<T> temp_stack = cont;

    while (!temp_stack.empty()) {
        temp.push_back(temp_stack.top());
        temp_stack.pop();
    }

    for (auto it = temp.rbegin(); it != temp.rend(); it++) {
        if (it != std::prev(temp.rend(), 1)) std::cout << *it << ", ";
        else std::cout << *it << '\n';
    }
    std::cout << std::string(30, '-') << '\n';
}

// Вывод очереди
template<typename T>
void reverse_print_container(const std::queue<T>& cont) {
    std::vector<T> temp;
    temp.reserve(cont.size());
    std::queue<T> temp_queue = cont;

    while (!temp_queue.empty()) {
        temp.push_back(temp_queue.front());
        temp_queue.pop();
    }


    for (auto it = temp.rbegin(); it != temp.rend(); it++) {
        if (it != std::prev(temp.rend(), 1)) std::cout << *it << ", ";
        else std::cout << *it << '\n';
    }
    std::cout << std::string(30, '-') << '\n';
}

// Вывод двусторонней очереди
template<typename T>
void reverse_print_container(const std::deque<T>& cont) {
    for (auto it = cont.rbegin(); it != cont.rend(); it++) {
        if (it != std::prev(cont.rend(), 1)) std::cout << *it << ", ";
        else std::cout << *it << '\n';
    }
    std::cout << std::string(30, '-') << '\n';
}
#endif
#endif

int main() {
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	std::list<std::string> test_list = { "one", "two", "three", "four" };
	std::vector<std::string> test_vector = { "one", "two", "three", "four" }; 
    std::map<int, std::string> test_map = { {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"} };
    std::unordered_map<int, std::string> test_unordered_map = { {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"} };
    std::stack<int> test_stack;
    std::queue<int> test_queue;
    std::deque<int> test_deque = { 1, 2, 3, 4 };

    test_stack.push(1);
    test_stack.push(2);
    test_stack.push(3);
    test_stack.push(4);

    test_queue.push(1);
    test_queue.push(2);
    test_queue.push(3);
    test_queue.push(4);


    std::cout << "PRINT:" << '\n'; 

    std::cout << "Set:" << std::endl;
    print_container(test_set);
    std::cout << "List:" << std::endl;
    print_container(test_list);
    std::cout << "Vector:" << std::endl;
    print_container(test_vector);
    std::cout << "Map:" << std::endl;
    print_container(test_map);
    std::cout << "Unordered map:" << std::endl;
    print_container(test_unordered_map);
    std::cout << "Stack:" << std::endl;
    print_container(test_stack);
    std::cout << "Queue:" << std::endl;
    print_container(test_queue);
    std::cout << "Deque:" << std::endl;
    print_container(test_deque);

	
    std::cout << "\nREVERSE PRINT:\n";

    std::cout << "Set:" << std::endl;
    reverse_print_container(test_set);
    std::cout << "List:" << std::endl;
    reverse_print_container(test_list);
    std::cout << "Vector:" << std::endl;
    reverse_print_container(test_vector);
    std::cout << "Map:" << std::endl;
    reverse_print_container(test_map);
    std::cout << "Unordered map:" << std::endl;
    reverse_print_container(test_unordered_map);
    std::cout << "Stack:" << std::endl;
    reverse_print_container(test_stack);
    std::cout << "Queue:" << std::endl;
    reverse_print_container(test_queue);
    std::cout << "Deque:" << std::endl;
    reverse_print_container(test_deque);

	return 0;
}