#include "hashing/hash_table.h"
#include "util/util.h"
#include <iostream>

using namespace std;

int main()
{
    const int N = 100;

    // generate key vecs
    auto randomKeys = makeRandomKeys(N, 42);
    auto studentKeys = makeStudentKeys(N);
    auto dataKeys = makeDataKeys(N);

    runExperiment(cout, "Experiment 1: Random strings", randomKeys);
    runExperiment(cout, "Experiment 2: Student keys (student1..studentN)", studentKeys);
    runExperiment(cout, "Experiment 3: Data keys (data_0001..data_N)", dataKeys);

    return 0;
}