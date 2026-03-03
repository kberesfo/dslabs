// hash_table.h
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <list>
#include <string>
#include <utility>
#include <ostream>

class HashTable
{
private:
    std::vector<std::list<std::pair<std::string, int>>> table;
    std::ostream *debugOut = nullptr;
    int currentSize;
    int capacity;
    int collisionCount;

    int hashFunction(const std::string &key, int mod) const;
    int hashFunction(const std::string &key) const;
    void rehash();

public:
    /// @brief constructor for the HashTable
    /// @param size defaults to 11
    HashTable(int size = 11);
    /// @brief Inserts a key-value pair into the hash table.
    /// If the key already exists, its value is updated.
    /// Rehashes automatically if load factor exceeds threshold.
    /// @param key The string key to insert.
    /// @param value The associated integer value.
    void insert(const std::string &key, int value);
    /// @brief Removes a key from the table.
    /// @param key The key to remove.
    /// @return True if removed, false if key not found.
    bool remove(const std::string &key);
    /// @brief Searches for a key in the table.
    /// @param key The key to search for.
    /// @return The associated value if found, otherwise -1.
    int search(const std::string &key) const;
    /// @brief Returns the current load factor (n / m).
    /// @return the current load factor 0.0 if empty n/m otherwise
    double loadFactor() const;
    /// @brief get the size of the HashTable
    /// @return size of the HashTable
    int size() const;
    /// @brief retruns true if the HashTable is empty
    /// @return boolean if the HashTable is empty
    bool isEmpty() const;
    /// @brief this is replaces the printTable method
    /// @param os outstream
    /// @param ht an instance of our hashtable
    /// @return the ostream
    friend std::ostream &operator<<(std::ostream &os, const HashTable &ht);

    void setDebugStream(std::ostream &os) { debugOut = &os; }
    void clearDebugStream() { debugOut = nullptr; }
};

#endif