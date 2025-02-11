#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

void print_vector(string label, vector<int> v) {
    std::cout << label << "{";
    for(int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ((i == v.size()-1) ? "}" : ", ");
    }
    std::cout << std::endl;
}

vector<int> remove_duplicates(vector<int> array) {
    vector<int> result = {};

    int i = 0;
    for(i = 0; i < array.size(); i++) {
        if(result.empty() || result.back() != array[i]) {
            result.push_back(array[i]);
        }
    }

    return result;
}

int main() {
    vector<int> input1 = {2, 2, 2, 2, 2};
    vector<int> result1 = remove_duplicates(input1);
    print_vector("Input1: ", input1);
    print_vector("Result1: ", result1);

    std::cout << std::endl;

    vector<int> input2 = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    vector<int> result2 = remove_duplicates(input2);
    print_vector("Input2: ", input2);
    print_vector("Result2: ", result2);

    std::cout << std::endl;

    vector<int> input3 = {1, 2, 3, 4, 7, 7, 10, 15, 15, 15, 15, 15, 20};
    vector<int> result3 = remove_duplicates(input3);
    print_vector("Input3: ", input3);
    print_vector("Result3: ", result3);

    return 0;
}