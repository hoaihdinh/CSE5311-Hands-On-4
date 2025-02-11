#include <iostream>

int fib(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    int x = 5;
    int fib_result = fib(x);

    std::cout << "fib(" << x << ") = " << fib_result << std::endl;

    return 0;
}