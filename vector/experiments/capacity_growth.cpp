#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int count = 0;
    for (int i = 0; i < 1000000; ++i) {
        std::size_t capacity_before = vec.capacity();
        vec.push_back(i);
        if (vec.capacity() != capacity_before) {
            std::cout << "Capacity changed from " << capacity_before << " to " << vec.capacity()
                      << " after inserting element " << i << std::endl;
            std::cout << "Current size: " << vec.size() << std::endl;
            count++;
            std::cout << "Number of capacity changes so far: " << count << std::endl;
        }
    }
    return 0;
}
