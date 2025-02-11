# CSE5311-Hands-On-4
## Fibonacci Implementation
### To Compile:
```
cd implementation/fibonacci
make
```
### To Run:
```
./fib
```
### Output:
```
fib(5) = 5
```
### Callstack:
```
fib(5)                 // 1
    fib(4)             // 2
        fib(3)         // 3
            fib(2)     // 4
                fib(1) // 5
                fib(0) // 6
            fib(1)     // 7
        fib(2)         // 8
            fib(1)     // 9
            fib(0)     // 10
    fib(3)             // 11
        fib(2)         // 12
            fib(1)     // 13
            fib(0)     // 14
        fib(1)         // 15
```
## Problem 1
### Code:
```cpp
using std::vector;

// K = number of arrays, N = size of each array
vector<int> merge_sorted_vectors(vector<vector<int>>& vectors) {
    int total_size = 0;                                // c
    for(vector<int>& v : vectors) {                    // Theta(K)
        total_size += v.size();                        // Theta(K) * c = Theta(K)
    }

    vector<int> result(total_size, 0);                 // Theta(N*K)
    vector<int> indexes(vectors.size(), 0);            // Theta(K)

    int i, j;                                          // c
    for(i = 0; i < total_size; i++) {                  // Theta(N*K)
        int smallest = INT_MAX;                        // Theta(N*K) * c = Theta(N*K)
        int idx = 0;                                   // Theta(N*K) * c = Theta(N*K)
        
        for(j = 0; j < indexes.size(); j++) {          // Theta(N*K) * K = Theta(N*K^2)
            if(indexes[j] < vectors[j].size() && vectors[j][indexes[j]] < smallest) { // Theta(N*K^2) * c = Theta(N*K^2)
                smallest = vectors[j][indexes[j]];     // Theta(N*K^2) * c = Theta(N*K^2)
                idx = j;                               // Theta(N*K^2) * c = Theta(N*K^2)
            }
        }

        indexes[idx]++;                                // Theta(N*K) * c = Theta(N*K)
        result[i] = smallest;                          // Theta(N*K) * c = Theta(N*K)
    }

    return result;   // c
}
```
### Time Complexity
```math
T(N, K) = c_1 + K + K + N*K + K + c_2 + N*K + N*K + N*K + N*K^2 + N*K^2 + N*K^2 + N*K^2 + N*K + N*K + c_3
```
```math
T(N, K) = c_1 + c_2 + c_3 + 3K + 6N*K + 4N*K^2
```
```math
T(N, K) = K + N*K + N*K^2
```
```math
T(N, K) = N*K^2
```
```math
T(N, K) = \Theta(N*K^2)
```
### Space Complexity
N*K for the result

K for the indexes

$\Theta(N*K + K) = \Theta(N*K)$

### Possible Improvements
Rather than always checking every vector for their smallest element, I can cut the loop short once there is only one vector with elements. The time complexity will not change, but will be an overall improvement. This will be more noticable when there is one vector with a significant amount of large elements compared to others.

Utilizing a min-heap would be a noticable improvement to the time complexity. Reducing to $O(N*KlogK)$. Keeping the tree with only K elements (1 element from each array) ensures that all heap operations have a time complexity of $O(logK)$.

### To Compile:
```
cd implementation/problem1
make
```
### To Run:
```
./merge_arrays
```
### Output:
```
Input1: {
    {1, 3, 5, 7}
    {2, 4, 6, 8}
    {0, 9, 10, 11}
}
Result1: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}

Input2: {
    {1, 3, 7}
    {2, 4, 8}
    {9, 10, 11}
}
Result2: {1, 2, 3, 4, 7, 8, 9, 10, 11}

Input3: {
    {8, 19, 25, 36, 42, 45, 56, 69, 71, 95}
    {23, 30, 36, 43, 47, 57, 66, 98, 98, 100}
    {3, 24, 27, 27, 31, 57, 58, 69, 83, 93}
    {9, 27, 27, 35, 45, 52, 57, 58, 62, 65}
    {3, 21, 34, 35, 52, 52, 66, 75, 81, 89}
}
Result3: {3, 3, 8, 9, 19, 21, 23, 24, 25, 27, 27, 27, 27, 30, 31, 34, 35, 35, 36, 36, 42, 43, 45, 45, 47, 52, 52, 52, 56, 57, 57, 57, 58, 58, 62, 65, 66, 66, 69, 69, 71, 75, 81, 83, 89, 93, 95, 98, 98, 100}
```

## Problem 2
### Code:
```cpp
// N = size of the array
vector<int> remove_duplicates(vector<int> array) {
    vector<int> result = {};                              // c

    int i = 0;                                            // c
    for(i = 0; i < array.size(); i++) {                   // Theta(N)
        if(result.empty() || result.back() != array[i]) { // Theta(N) * c = Theta(N)
            result.push_back(array[i]);                   // Theta(N) * c = Theta(N)
        }
    }

    return result;                                        // c
}
```
### Time Complexity
```math
T(N) = c_1 + c_2 + N + N + N + c_3
```
```math
T(N) = c_1 + c_2 + c_3 + 3N
```
```math
T(N) = N
```
```math
T(N) = \Theta(N)
```
### Space Complexity
N for the result

$\Theta(N)$

### Possible Improvments
There is likely a way to solve this problem in constant space. This would involve shuffling elements around in the array, which could increase the time complexity of the algorithm.

### To Compile:
```
cd implementation/problem2
make
```
### To Run:
```
./remove_dups
```
### Output:
```
Input1: {2, 2, 2, 2, 2}
Result1: {2}

Input2: {1, 2, 2, 3, 4, 4, 4, 5, 5}
Result2: {1, 2, 3, 4, 5}

Input3: {1, 2, 3, 4, 7, 7, 10, 15, 15, 15, 15, 15, 20}
Result3: {1, 2, 3, 4, 7, 10, 15, 20}
```