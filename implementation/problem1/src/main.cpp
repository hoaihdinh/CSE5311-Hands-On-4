#include <iostream>
#include <vector>
#include <string>
#include <climits>

using std::vector;
using std::string;

void print_vector(string label, vector<int> v) {
    std::cout << label << "{";
    for(int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ((i == v.size()-1) ? "}" : ", ");
    }
    std::cout << std::endl;
}

vector<int> merge_sorted_vectors(vector<vector<int>>& vectors) {
    int total_size = 0;
    for(vector<int>& v : vectors) {
        total_size += v.size();
    }

    vector<int> result(total_size, 0);
    vector<int> indexes(vectors.size(), 0);

    int i, j;
    for(i = 0; i < total_size; i++) {
        int smallest = INT_MAX;
        int idx = 0;
        
        for(j = 0; j < indexes.size(); j++) {
            if(indexes[j] < vectors[j].size() && vectors[j][indexes[j]] < smallest) {
                smallest = vectors[j][indexes[j]];
                idx = j;
            }
        }

        indexes[idx]++;
        result[i] = smallest;
    }

    return result;
}

int main() {

    vector<vector<int>> input1 = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };

    vector<int> result1 = merge_sorted_vectors(input1);

    std::cout << "Input1: {\n";
    for(vector<int>& v : input1) {
        std::cout << "    ";
        print_vector("", v);
    }
    std::cout << "}" << std::endl;
    print_vector("Result1: ", result1);

    std::cout << std::endl;

    vector<vector<int>> input2 = {
        {1, 3, 7},
        {2, 4, 8},
        {9, 10, 11}
    };
    vector<int> result2 = merge_sorted_vectors(input2);

    std::cout << "Input2: {\n";
    for(vector<int>& v : input2) {
        std::cout << "    ";
        print_vector("", v);
    }
    std::cout << "}" << std::endl;
    print_vector("Result2: ", result2);

    std::cout << std::endl;

    vector<vector<int>> input3 = {
        {8, 19, 25, 36, 42, 45, 56, 69, 71, 95},
        {23, 30, 36, 43, 47, 57, 66, 98, 98, 100},
        {3, 24, 27, 27, 31, 57, 58, 69, 83, 93},
        {9, 27, 27, 35, 45, 52, 57, 58, 62, 65},
        {3, 21, 34, 35, 52, 52, 66, 75, 81, 89}
    };
    vector<int> result3 = merge_sorted_vectors(input3);

    std::cout << "Input3: {\n";
    for(vector<int>& v : input3) {
        std::cout << "    ";
        print_vector("", v);
    }
    std::cout << "}" << std::endl;
    print_vector("Result3: ", result3);

    return 0;
}