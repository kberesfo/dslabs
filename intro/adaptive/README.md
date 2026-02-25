# Adaptive Sorting Strategy

## Objective

The objective of this assignment is to analyze how input order affects sorting algorithm performance and to apply that analysis to make an adaptive algorithmic decision.

---

The following are the O(N) notations of the following sorting algorithms.

|                | Best case | Average case | Worst case |
| -------------- | --------- | ------------ | ---------- |
| Selection sort | $N^2$     | $N^2$        | $N^2$      |
| Insertion sort | N         | $N^2$        | $N^2$      |

## Part A: Adaptive Sorting Selection

1. Create an array of **50 integers**. [Main.cpp](./main.cpp)
1. Implement both sorting algorithms:
   - **[Selection Sort](./include/sorting/selection_sort.h)**
   - **[Insertion Sort](./include/sorting/insertion_sort.h)**

1. Your program must analyze the initial ordering of the array and determine which scenario it represents (best, average, or worst) based on a **clearly defined threshold** that you assume. [classifySortCase](./include/classifiers/classify_sort_case.h)

1. Based on your analysis, your program should automatically choose the more appropriate sorting algorithm. [main.cpp](./main.cpp)

### Example:

- If the array is **already sorted in ascending order** (or nearly sorted based on your defined threshold), your program should choose **Insertion Sort**, since Insertion Sort runs in linear time `O(n)` in the best case, whereas Selection Sort still performs $O(n^2)$ comparisons regardless of input order.

- If the array is in **strictly descending order** and the goal is to sort in ascending order, your program may decide to use **Selection Sort**, assuming under your defined threshold that it performs more consistently than Insertion Sort in this scenario.

Your decision logic must be clearly implemented in your code.

---

## Part B: Case Classification Without Sorting

Using the same threshold defined in Part A:

1. The user will input 50 integers.
2. Without actually sorting the array, your program must analyze the order of elements.
3. The program should classify the input as:
   - **Average Case**
   - **Worst Case**

The program must then display the classification result.

> No sorting should be performed in this part; only classification is required.

---

## Part C: Documentation

Provide a written explanation that includes:

- The **threshold definition** you used to differentiate between best, average, and worst cases.
- The reasoning behind your assumption.
- Why your program selects one sorting algorithm over the other in specific scenarios.
- A brief discussion of how input order affects the time complexity of Selection Sort and Insertion Sort.

Your explanation should demonstrate a clear understanding of algorithmic behavior and time complexity analysis.

**[classifySortCase](./include/classifiers/classify_sort_case.h)** uses a relatively naive approach by simply counting the number of adjacent pairs where `vec[i]` > `vec[i+1]`. This provides a rough estimate as to how many elements are out of order. It counts adjacent out-of-order pairs and divides by `(n−1)` to get a percentage. If `10%` or less are out of order it classifies the array as "Best case", if `65%` or more are out of order then it classifies it as worst, otherwise it classifies it as average.

- If the algorithm detects `10%` or less adjacent pairs out of order then it uses [Insertion Sort](./include/sorting/insertion_sort.h) because insertion sort runs at near linear time when the array is sorted or nearly sorted. Only a small number of shifts are required.
- If more than `10%` of adjacent pairs are out of order, the array is considered average or worst case. In this situation, [Selection Sort](./include/sorting/selection_sort.h) is chosen. Although both Selection Sort and Insertion Sort have $O(n^2)$ time complexity in average and worst cases, Selection Sort performs a consistent number of comparisons regardless of input order, whereas Insertion Sort may perform many shifts when the data is highly unsorted.
