// run_experiment.h
#ifndef RUN_EXPERIMENT_H
#define RUN_EXPERIMENT_H

#include "hashing/hash_table.h"

#include <algorithm>
#include <ostream>
#include <string>
#include <vector>

/// @brief Runs an experiment
/// @param os outstream
/// @param label the name of the experiment to run
/// @param keys a pointer to the keys
inline void runExperiment(
    std::ostream &os,
    const std::string &label,
    const std::vector<std::string> &keys)
{
    os << "\n==============================\n";
    os << label << "\n";
    os << "==============================\n";

    HashTable ht; // default capacity = 11
    // debug bad hash
    // ht.setDebugStream(os);
    // Insert at least N keys
    for (int i = 0; i < static_cast<int>(keys.size()); ++i)
    {
        ht.insert(keys[i], i);
    }

    // Print table + stats
    os << ht << "\n";

    // existing + missing
    const std::string existingKey = keys.empty() ? "" : keys[keys.size() / 2];
    const std::string missingKey = "missing_key";

    if (!keys.empty())
    {
        int existingVal = ht.search(existingKey);
        os << "Search existing key \"" << existingKey << "\" -> " << existingVal << "\n";
    }
    else
    {
        os << "Search existing key skipped (no keys).\n";
    }

    int missingVal = ht.search(missingKey);
    os << "Search for missing key (Expect Empty): ";
    if (missingVal == -1)
        os << "returned empty\n";
    else
        os << "FOUND value=" << missingVal << " (unexpected)\n";

    // Remove some keys and verify correctness
    int toRemove = 10;
    int removed = 0;

    for (int i = 0; i < toRemove; ++i)
    {
        if (ht.remove(keys[i]))
            ++removed;
    }

    os << "Attempted to remove " << toRemove << " keys, removed " << removed << ".\n";
    os << "Size after removals: " << ht.size() << "\n";

    int stillFound = 0;
    for (int i = 0; i < toRemove; ++i)
    {
        if (ht.search(keys[i]) != -1)
            ++stillFound;
    }

    os << "Removed keys still found (should be 0): " << stillFound << "\n";
}

#endif