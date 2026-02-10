# Linear and binary search

## Tasks

1. How many steps would it take to perform a linear search for the number 8 in the ordered array, [2, 4, 6, 8, 10, 12, 13]?
   - it would be found in 4 steps. Because the target is located in the 4th element, 3rd index, in the array.
1. How many steps would binary search take for the previous example?
   - it is found in the first step because `arr[mid]=8`
1. What is the maximum number of steps it would take to perform a binary search on an array of size 100,000?
   - Binary search would take approximately 17 steps assuming the data is sorted and that the target isn't in the array.
   - `log(100_000)/Log(2) ~= 17`
   - `O(log(N))` Time complexity
1. Write a C++ program that implements both linear search and binary search algorithms using an array of 100,000 elements. The program should record and report the number of steps (comparisons) performed during each search operation. In addition, analyze and justify the observed behavior by providing a theoretical explanation using Big-O notation, demonstrating why linear search exhibits $O(N)$ complexity and binary search exhibits $O(\log N)$ complexity.
   - [Linear Search](./package/linear_search.h)
     - Iterates over the array until the target is found. `O(N)`
   - [Binary Search](./package/binary_search.h)
     - **Requires array to be sorted.**
     - Half the remaining elements every iteration `O(log2(N))`
1. Random Search
   1. Write pseudocode for a randomized search algorithm that searches for a given key by randomly selecting indices **without repetition**. Use a dataset of 100,000 distinct elements, stored in a vector. Each element may be examined **at most** once during the search. Analyze and state the best-case, average-case, and worst-case time complexities of this algorithm using Big-O notation.
      - **Best Case**: Finding the target element in the first randomized index `O(1)` (unlikely)
      - **Avg Case**: Search half of the elements before finding the target, `arr.len/2`, resulting in `O(N)/2 = O(N)` time complexity
      - **Worst Case**: Search the entire array resulting in `O(N)` time complexity

      ```pseudocode
      def random_search(arr, target):
         n = length(arr)

         // build index list 0..n-1
         idx = new array of length n
         for i from 0 to n-1:
            idx[i] = i

         // shuffle idx using Fisher–Yates
         for i from n-1 to 1:
            j = random int in [0, i]
            swap(idx[i], idx[j])

         // NOTE: idx is now the shuffled indexes for arr

         // search using randomized indexes
         for random_index in idx:
            if arr[random_index] == target:
                  return random_index
      ```

      ### References
      - Lorenzo Battilocchi et al., “Fisher–Yates Shuffling Algorithm in C,” _Stack Overflow_,  
        https://stackoverflow.com/questions/42321370/fisher-yates-shuffling-algorithm-in-c

   1. Then, implement the algorithm in C++, using only the following standard headers: `<vector>` for data storage, `<random>` for random index generation, and `<iostream>` for input and output. The implementation should track and report the number of comparisons performed during the search.
      - [Random Search](./package/random_search.h)

   1. Finally, compare and contrast the randomized search algorithm with linear search and binary search in terms of time complexity, data requirements (such as ordering), and practical efficiency. Discuss scenarios in which each approach may be preferred, highlighting the advantages and limitations of randomized search relative to linear and binary search.
      - Random and Linear both have the same time complexity. Despite the fact that in the random search implementation we iterate over the length of the array twice. Because it would be 2n we drop the constant and consider it O(N) time complexity.
      - Linear search iterates over early elements more frequently than elements at the end of the array. If that isn't desired behavior random search offers an alternative.

   ## Video

   [Canvas Video](https://sdccd.us-west-2.instructuremedia.com/embed/3b84de61-ddb5-4eb7-8387-0639ad7784d5)
