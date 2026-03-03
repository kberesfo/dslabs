
#include "hashing/hash_table.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size)
    : capacity(size),
      currentSize(0),
      collisionCount(0),
      table(size),
      debugOut(nullptr)
{
}

int HashTable::hashFunction(const string &key, int mod) const
{
    const int prime = 31;
    long long hash = 0;

    for (char c : key)
    {
        hash = hash * prime + c;
    }
    int r = static_cast<int>(hash % mod);
    int idx = static_cast<int>((hash % mod + mod) % mod);
    // looking for bad keys
    if (debugOut && r < 0)
    {
        (*debugOut) << "NEG remainder key=" << key
                    << " hash=" << hash
                    << " mod=" << mod
                    << " r=" << r
                    << " fixedIdx=" << idx << "\n";
    }
    return idx;
}

int HashTable::hashFunction(const string &key) const
{
    // overload for simplicity
    return hashFunction(key, capacity);
}

void HashTable::insert(const string &key, int value)
{

    if (loadFactor() > 0.75)
    {
        rehash();
    }

    // get the new key
    int idx = hashFunction(key);
    // if table has a list then possible collision or update
    if (!table[idx].empty())
    {
        // if table is not empty iterate over kv pair
        for (auto &kv : table[idx])
        {
            // if found update the value
            if (kv.first == key)
            {
                kv.second = value;
                // return prevents updating collision if we just update value
                return;
            }
        }
        // increment collisions
        ++collisionCount;
    }

    // update the table
    table[idx].push_back({key, value});
    // increment size
    ++currentSize;
    return;
}

bool HashTable::remove(const string &key)
{
    int idx = hashFunction(key);
    // iterate through the linked list
    for (auto it = table[idx].begin(); it != table[idx].end(); ++it)
    {
        // if the first == key
        if (it->first == key)
        {
            // erase the node, updating the node to the left and right
            table[idx].erase(it);
            // decrease current size
            --currentSize;
            // found
            return true;
        }
    }
    // not found
    return false;
}

int HashTable::search(const string &key) const
{
    // get the table idx
    int idx = hashFunction(key);
    // iterate over the kv pairs
    for (const auto &kv : table[idx])
    {
        // if found return value
        if (kv.first == key)
            return kv.second;
    }
    // return -1 if not found
    return -1;
}

double HashTable::loadFactor() const
{
    // prevent weirdness
    if (isEmpty())
        return 0.0;

    // calc load factor n/m
    return static_cast<double>(currentSize) /
           static_cast<double>(capacity);
}

int HashTable::size() const
{
    // getter of current size
    return currentSize;
}

bool HashTable::isEmpty() const
{
    // check if the current size is empty
    return currentSize == 0;
}

void HashTable::rehash()
{
    int newCapacity = capacity * 2;
    int newCollisionCount = 0;
    // new bucket vector
    std::vector<std::list<std::pair<std::string, int>>> tmpTable(newCapacity);

    for (const auto &bucket : table)
    {
        for (const auto &kv : bucket)
        {
            // compute hash with newCapacity
            const std::string &key = kv.first;
            int value = kv.second;

            // get the new key
            int idx = hashFunction(key, newCapacity);
            if (!tmpTable[idx].empty())
                ++newCollisionCount;

            // update the tmp table
            tmpTable[idx].push_back({key, value});
        }
    }

    // prevent copy
    table = std::move(tmpTable);
    // update cap
    capacity = newCapacity;
    // update collision count
    collisionCount = newCollisionCount;
}

std::ostream &operator<<(std::ostream &os, const HashTable &ht)
{
    int maxBucket = 0;
    int nonEmptyBuckets = 0;

    for (int i = 0; i < ht.capacity; ++i)
    {
        os << "[" << i << "] ";

        int bucketSize = 0;
        for (const auto &kv : ht.table[i])
        {
            os << "(" << kv.first << ", " << kv.second << ") ";
            ++bucketSize;
        }

        if (bucketSize > 0)
        {
            ++nonEmptyBuckets;
            if (bucketSize > maxBucket)
                maxBucket = bucketSize;
        }

        os << "\n";
    }

    double loadFactor = ht.loadFactor(); // n/m
    double avgAllBuckets = loadFactor;   // same thing
    double avgNonEmpty = (nonEmptyBuckets == 0)
                             ? 0.0
                             : static_cast<double>(ht.currentSize) /
                                   static_cast<double>(nonEmptyBuckets);

    os << "Size: " << ht.currentSize << "\n";
    os << "Capacity: " << ht.capacity << "\n";
    os << "Load Factor (n/m): " << loadFactor << "\n";
    os << "Collisions: " << ht.collisionCount << "\n";
    os << "Max Bucket Size: " << maxBucket << "\n";
    os << "Avg Bucket Length (all buckets): " << avgAllBuckets << "\n";
    os << "Avg Bucket Length (non-empty): " << avgNonEmpty << "\n";

    return os;
}