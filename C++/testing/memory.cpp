#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> memory_hog;
    
    try {
        while (true) {
            // Allocate a large chunk of memory
            std::vector<int> block(1e10, 0);
            memory_hog.push_back(block);
        }
    } catch (std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }

    return 0;
}
