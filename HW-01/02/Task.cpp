#include <iostream>
#include <vector>
#include <variant>

using namespace std;

variant<int, string, vector<int>> get_variant() {
    srand(time(nullptr));
    int random_variable = rand() % 3;

    variant<int, string, vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}

void print_variant(variant<int, string, vector<int>> in) {
    in = get_variant();

    if (holds_alternative<int>(in)) cout << "Int: " << (get<int>(in) * 2) << endl;
    else if (holds_alternative<string>(in)) cout << "String: " << get<string>(in) << endl;
    else if (holds_alternative<vector<int>>(in)) {
        vector<int> tmp = get<vector<int>>(in);
        int lastIndex = 0;
        cout << "Vector: ";
        for (auto i : tmp) {
            if (lastIndex != tmp.size() - 1) cout << i << ", ";
            else cout << i;
            lastIndex++;
        }
        cout << endl;
    }
}

int main()
{
    print_variant(get_variant());

    return 0;
}
