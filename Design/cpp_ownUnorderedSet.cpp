#include <iostream>
#include <vector>
#include <list>
#include <functional> // For std::hash

template<typename T>
class SimpleUnorderedSet {
public:
    using BucketType = std::list<T>;
    using BucketIterator = typename BucketType::iterator;

private:
    std::vector<BucketType> buckets; // Hash table: vector of lists
    size_t numBuckets;

    size_t hashFunction(const T& value) const {
        // A simple hash function using std::hash
        return std::hash<T>{}(value) % numBuckets;
    }

public:
    explicit SimpleUnorderedSet(size_t numBuckets = 101) : numBuckets(numBuckets), buckets(numBuckets) {}

    bool insert(const T& value) {
        auto& bucket = buckets[hashFunction(value)];

        // Check if the value already exists
        if (find(value) != bucket.end()) {
            return false; // Value already exists
        }

        // Insert the new value
        bucket.push_back(value);
        return true;
    }

    BucketIterator find(const T& value) {
        auto& bucket = buckets[hashFunction(value)];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == value) {
                return it; // Found the value, return the iterator
            }
        }
        return bucket.end(); // Value not found, return end iterator of the bucket
    }

    bool contains(const T& value) const {
        const auto& bucket = buckets[hashFunction(value)];
        return std::find(bucket.begin(), bucket.end(), value) != bucket.end();
    }

    bool erase(const T& value) {
        auto& bucket = buckets[hashFunction(value)];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == value) {
                bucket.erase(it);
                return true; // Successfully erased
            }
        }
        return false; // Value not found to erase
    }

    // An end() method to provide a universal end iterator
    BucketIterator end() {
        static BucketType dummyBucket;
        return dummyBucket.end();
    }
};

int main() {
    SimpleUnorderedSet<int> mySet;

    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);

    auto it = mySet.find(20);
    if (it != mySet.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    // Erase by iterator
    if (it != mySet.end()) {
        mySet.erase(*it);
    }

    it = mySet.find(20);
    std::cout << "After erase, found 20: " << (it != mySet.end() ? "yes" : "no") << std::endl;

    return 0;
}
