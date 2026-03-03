// hash_table.h
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <list>
#include <string>
#include <utility>

class HashTable
{
private:
    std::vector<std::list<std::pair<std::string, int>>> table;
    int currentSize;
    int capacity;
    int collisionCount;

    int hashFunction(const std::string &key, int mod) const;
    int hashFunction(const std::string &key) const;
    void rehash();

public:
    /// @brief
    /// @param size
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
    /// @return
    double loadFactor() const;
    /// @brief
    /// @return
    int size() const;
    /// @brief
    /// @return
    bool isEmpty() const;
    /// @brief
    void printTable() const;
};

#endif