#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

struct Page {
    int pageNumber;
    bool referenceBit;
    bool modifiedBit;

    Page(int page, bool modified = false) : pageNumber(page), referenceBit(false), modifiedBit(modified) {}
};

void enhancedSecondChanceAlgorithm(const std::vector<int>& pageReferences, const std::vector<bool>& modifiedBits, int numFrames) {
    std::queue<Page> pageQueue; // Queue to hold the pages
    std::unordered_set<int> pageSet; // Set to keep track of page presence in memory

    int pageFaults = 0;

    for (unsigned int i = 0; i < pageReferences.size(); ++i) {
        int page = pageReferences[i];
        bool modified = modifiedBits[i];

        // Check if page is present in memory
        if (pageSet.find(page) != pageSet.end()) {
            // Page hit, set its reference bit and modified bit accordingly
            for (auto& pg : pageQueue) {
                if (pg.pageNumber == page) {
                    pg.referenceBit = true;
                    pg.modifiedBit = modified;
                    break;
                }
            }
        } else {
            // Page fault, need to replace a page
            ++pageFaults;

            while (true) {
                Page oldestPage = pageQueue.front(); // Get the oldest page from the queue

                if (oldestPage.referenceBit == false && oldestPage.modifiedBit == false) {
                    // Reference bit and modified bit are both 0, replace the page
                    int replacedPage = oldestPage.pageNumber;
                    pageSet.erase(replacedPage);
                    pageQueue.pop();
                    break;
                } else if (oldestPage.referenceBit == false && oldestPage.modifiedBit == true) {
                    // Reference bit is 0, modified bit is 1, give the page a second chance
                    oldestPage.referenceBit = true;
                    pageQueue.pop();
                    pageQueue.push(oldestPage);
                } else {
                    // Reference bit is 1, give the page a second chance by setting reference bit to 0
                    oldestPage.referenceBit = false;
                    pageQueue.pop();
                    pageQueue.push(oldestPage);
                }
            }

            // Add the new page to memory
            Page newPage(page, modified);
            newPage.referenceBit = true;
            pageQueue.push(newPage);
            pageSet.insert(page);
        }
    }

    std::cout << "Page Faults: " << pageFaults << std::endl;
}

int main() {
    std::vector<int> pageReferences = {2, 3, 1, 4, 2, 5, 1, 6, 2, 7, 3, 1, 5, 4, 6};
    std::vector<bool> modifiedBits = {true, false, true, true, false, false, true, true, true, false, true, false, true, false, false};
    int numFrames = 3;

    enhancedSecondChanceAlgorithm(pageReferences, modifiedBits, numFrames);

    return 0;
}
