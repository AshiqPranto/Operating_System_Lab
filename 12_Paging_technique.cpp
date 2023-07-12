Certainly! Here's an example C++ program that demonstrates a simple paging technique for memory management:

```cpp
#include <iostream>
#include <vector>

const int PAGE_SIZE = 4;
const int MEMORY_SIZE = 16;
const int NUM_PAGES = MEMORY_SIZE / PAGE_SIZE;

std::vector<int> memory(MEMORY_SIZE, -1); // Represents the physical memory
std::vector<int> pageTable(NUM_PAGES, -1); // Represents the page table

void displayMemory() {
    std::cout << "Physical Memory: ";
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        if (memory[i] != -1) {
            std::cout << memory[i] << " ";
        } else {
            std::cout << "- ";
        }
    }
    std::cout << std::endl;
}

void displayPageTable() {
    std::cout << "Page Table: ";
    for (int i = 0; i < NUM_PAGES; ++i) {
        if (pageTable[i] != -1) {
            std::cout << pageTable[i] << " ";
        } else {
            std::cout << "- ";
        }
    }
    std::cout << std::endl;
}

void handlePageFault(int pageNumber) {
    // Simulating page fault handling by replacing the first available page in memory
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        if (memory[i] == -1) {
            memory[i] = pageNumber;
            pageTable[pageNumber] = i;
            break;
        }
    }
}

void accessMemory(int logicalAddress) {
    int pageNumber = logicalAddress / PAGE_SIZE;
    int offset = logicalAddress % PAGE_SIZE;

    if (pageTable[pageNumber] == -1) {
        std::cout << "Page Fault for Logical Address " << logicalAddress << std::endl;
        handlePageFault(pageNumber);
    }

    int physicalAddress = pageTable[pageNumber] * PAGE_SIZE + offset;
    std::cout << "Accessing Logical Address " << logicalAddress << " (Physical Address: " << physicalAddress << ")" << std::endl;
}

int main() {
    // Simulating memory accesses
    accessMemory(2);
    accessMemory(8);
    accessMemory(10);
    accessMemory(3);
    accessMemory(5);

    displayMemory();
    displayPageTable();

    return 0;
}
```

Explanation of the program:

1. `PAGE_SIZE` represents the size of each page in the memory.
2. `MEMORY_SIZE` represents the total size of the physical memory.
3. `NUM_PAGES` represents the total number of pages in the memory.
4. `memory` is a vector that represents the physical memory, initialized with -1 to indicate empty frames.
5. `pageTable` is a vector that represents the page table, initialized with -1 to indicate empty page table entries.
6. `displayMemory()` function displays the contents of the physical memory.
7. `displayPageTable()` function displays the contents of the page table.
8. `handlePageFault()` function is called when a page fault occurs (page is not found in memory). It replaces the first available page in memory with the required page.
9. `accessMemory()` function simulates accessing memory based on a given logical address. It calculates the page number and offset from the logical address. If the page is not present in memory (indicated by -1 in the page table), it triggers a page fault and calls `handlePageFault()` to bring the required page into memory. It then calculates the physical address and displays the access details.
10. In the `main()` function, memory accesses are simulated by calling `accessMemory()` with different logical addresses.
11. After the memory accesses, the program displays the current state of the physical memory and the page table.

Note: This program demonstrates a basic implementation of a paging technique, where page faults are handled by replacing the first available page in memory. In a real operating system, more sophisticated algorithms like LRU (Least Recently Used) or FIFO (First-In-First-Out) would be used for page replacement.