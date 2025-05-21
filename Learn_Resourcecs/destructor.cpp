
// There are few points about the same as follows:
// 1. This is a special member function with same name as class with ~ at front.
// 2. Used to destruct the memory of object which was constructed by constructor.
// 3. Destructors get called automatically (implicit call), as constructor was.
// 4. We can call destructors explicitly but that is not good practice.
// 5. The only place where you will call destructors explicitly is after placement new (this is little advanced topic).

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Base {
private:
    int x_;
public:
    Base() {
        auto startTime = high_resolution_clock::now();

        cout << "Default Constructor\n";

        auto stopTime = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stopTime - startTime);
        cout << "Constructor Time (microseconds): " << duration.count() << "\n";
    }

    Base(int x) : x_{x} {
        cout << "Param Constructor\n";
    }

    ~Base() {
        auto startTime = high_resolution_clock::now();

        cout << "Destructor\n";

        auto stopTime = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stopTime - startTime);
        cout << "Destructor Time (microseconds): " << duration.count() << "\n";
    }
};

int main() {
    Base b;
    return 0;
}
