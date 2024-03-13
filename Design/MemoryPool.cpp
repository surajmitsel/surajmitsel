#include <iostream>
using namespace std;
/*
A memory pool is a pre-allocated block of memory used for dynamic memory allocation, 
typically to reduce memory fragmentation and overhead associated 
with frequent memory allocations and deallocations.

Here's a basic approach to designing a memory pool:

1) Define the Memory Pool Structure: Decide on the structure of your memory pool. It typically includes the following:
    - Size: Total size of the memory pool.
    - Pointer: Pointer to the start of the memory pool.
    - Allocation Table: Data structure to keep track of allocated and free memory blocks.

2) Initialize the Memory Pool: Allocate a large block of memory and 
initialize the memory pool structure. 
This involves setting the pointer to the start of the allocated 
memory block and initializing the allocation table.

3) Implement Memory Allocation and Deallocation Functions:

    - Allocate Function: Implement a function to allocate memory from the memory pool. 
        This function should search for a free memory block in the allocation table, 
        mark it as allocated, and return a pointer to the allocated memory.
    - Deallocate Function: Implement a function to deallocate memory and return it to the memory pool. 
        This function should mark the memory block as free in the allocation table.
4) Handle Fragmentation: Fragmentation can occur in a memory pool if memory blocks of different sizes 
        are allocated and deallocated. You may need to implement strategies to handle fragmentation, 
        such as memory compaction or using different memory pools for different sizes of memory blocks.

5) Optimize for Performance: Depending on the specific requirements of your application, 
you may need to optimize the memory pool implementation for performance. 
This may involve using efficient data structures for the allocation table, 
minimizing memory overhead, and reducing fragmentation.

6) Testing and Validation: Test the memory pool implementation thoroughly to ensure 
correctness and performance. Validate it against different usage scenarios and workloads 
to identify any potential issues or bottlenecks.


*/
class MemoryPool {
private:
    char* pool; // Pointer to the start of the memory pool
    size_t size; // Size of the memory pool
    bool* allocationTable; // Allocation table to track allocated/free memory blocks

public:
    MemoryPool(size_t poolSize) : size(poolSize) {
        pool = new char[size];
        allocationTable = new bool[size];
        // Initialize allocation table
        for (size_t i = 0; i < size; ++i) {
            allocationTable[i] = false; // All memory blocks initially free
        }
    }

    ~MemoryPool() {
        delete[] pool;
        delete[] allocationTable;
    }

    void* allocate(size_t blockSize) {
        // Find a free block of memory in allocation table
        for (size_t i = 0; i <= size - blockSize; ++i) {
            bool isFree = true;
            for (size_t j = i; j < i + blockSize; ++j) {
                if (allocationTable[j]) {
                    isFree = false;
                    break;
                }
            }
            if (isFree) {
                // Mark memory block as allocated
                for (size_t j = i; j < i + blockSize; ++j) {
                    allocationTable[j] = true;
                }
                return &pool[i];
            }
        }
        return nullptr; // No free memory block found
    }

    void deallocate(void* ptr, size_t blockSize) {
        char* p = static_cast<char*>(ptr);
        size_t index = p - pool;
        // Mark memory block as free
        for (size_t i = index; i < index + blockSize; ++i) {
            allocationTable[i] = false;
        }
    }
};

int main() {
    MemoryPool pool(1024); // Create a memory pool of size 1024 bytes
    void* ptr1 = pool.allocate(64); // Allocate 64 bytes
    void* ptr2 = pool.allocate(128); // Allocate 128 bytes
    pool.deallocate(ptr1, 64); // Deallocate memory
    pool.deallocate(ptr2, 128); // Deallocate memory
    return 0;
}
