#include <iostream>

int main() {
    const unsigned long long int SIZE = 1ULL << 30; // 1 GB (2^30 bytes)

    try {
        // Allocate a large block of memory
        int* bigArray = new int[SIZE];
        std::cout << "Allocated " << SIZE << " bytes of memory." << std::endl;

        // Access the allocated memory to prevent the compiler from optimizing it out
        for (unsigned long long int i = 0; i < SIZE; ++i) {
            bigArray[i] = i;
        }

        // Clean up the allocated memory
        delete[] bigArray;
    } catch (std::bad_alloc& e) {
        std::cout << "Failed to allocate memory: " << e.what() << std::endl;
    }

    return 0;
}
