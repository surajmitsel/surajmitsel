#include <iostream>
#include <vector>
#include <utility> // for std::pair

class myMalloc {
private:
    static const size_t MEMORY_BLOCK_SIZE = 2048; // 2KB
    // vec(pair: ptr(block), vec(free/occupy))
    std::vector<std::pair<void*, std::vector<bool>>> memoryBlocks; 

public:
    myMalloc() {
        // Initialize with one memory block during object creation
        allocateMemoryBlock();
    }

    ~myMalloc() {
        // Deallocate all memory blocks during object destruction
        for (auto& block : memoryBlocks) {
            operator delete(block.first);
        }
    }

    // Function similar to malloc
    void* myMalloc(size_t size) {
        // Find a suitable block for allocation
        for (auto& block : memoryBlocks) {
            size_t startIndex = findFreeBlock(block.second, size);
            if (startIndex != SIZE_MAX) {
                markAsAllocated(block.second, startIndex, size);
                return static_cast<char*>(block.first) + startIndex;
            }
        }

        // If no suitable block found, allocate a new block
        allocateMemoryBlock();
        return myMalloc(size);
    }

private:
    // Allocate a new memory block
    void allocateMemoryBlock() {
        void* newBlock = operator new(MEMORY_BLOCK_SIZE);
        if (newBlock == nullptr) {
            std::cerr << "Memory allocation failed." << std::endl;
            return;
        }
        memoryBlocks.emplace_back(newBlock, std::vector<bool>(MEMORY_BLOCK_SIZE, false));
    }

    // Find a free block in memory map
    size_t findFreeBlock(std::vector<bool>& memoryMap, size_t size) {
        size_t contiguousFree = 0;

        for (size_t i = 0; i < MEMORY_BLOCK_SIZE; ++i) {
            if (!memoryMap[i]) {
                if (contiguousFree == 0) {
                    // Start of a potential free block
                    contiguousFree++;
                } else {
                    // Continuing a potential free block
                    contiguousFree++;
                    if (contiguousFree >= size) {
                        // Enough space found
                        return i - contiguousFree + 1;
                    }
                }
            } else {
                // Reset contiguous free count
                contiguousFree = 0;
            }
        }

        return SIZE_MAX; // No free block found
    }

    // Mark a block in memory map as allocated
    void markAsAllocated(std::vector<bool>& memoryMap, size_t startIndex, size_t size) {
        for (size_t i = startIndex; i < startIndex + size; ++i) {
            memoryMap[i] = true;
        }
    }
};

int main() {
    myMalloc customMalloc;

    // Usage example
    int* ptr1 = static_cast<int*>(customMalloc.myMalloc(sizeof(int)));
    if (ptr1 != nullptr) {
        *ptr1 = 42;
        std::cout << "Allocated memory value: " << *ptr1 << std::endl;
    }

    // Clean up (not implemented in this simplified example)

    return 0;
}
