#include <iostream>
#include <vector>

template<typename F>
class Factorial {
public:
    explicit Factorial() = default;
    F operator()(F num) {
        if(num < cached.size()) return cached[num];
        //std::cout << "cache not enough, calculating" << std::endl;
        for(; cached.size() <= num; cached.push_back(cached.back() * cached.size())) {}
        return cached[num];
    }
private:
    std::vector<F> cached = {1};
};

int main() {
    Factorial<unsigned long long> factorial{};
    std::cout << factorial(5) << std::endl;
    std::cout << factorial(4) << std::endl;
    std::cout << factorial(3) << std::endl;
    std::cout << factorial(2) << std::endl;
    std::cout << factorial(1) << std::endl;
    std::cout << factorial(0) << std::endl;
    std::cout << factorial(20) << std::endl;
    return 0;
}
