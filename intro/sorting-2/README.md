# Sorting algorithms

## Objective

Understand the working of insertion sort algorithm algorithms and evaluate the algorithm's efficiency.

## Task

1. Proof that, under the average-case scenario, insertion sort has time complexity $O(N^2)$.

   **Average-case time complexity of insertion sort** (Note: these are assuming just comparisons)

   **Best Case**:

   $$
   \sum_{i=1}^{N-1} 1 = N-1
   $$

   **Worst Case**:

   $$
   \sum_{i=1}^{N-1} i = \frac{(N-1)N}{2}
   $$

   **Avg Case**:

   $$
   \frac12\sum_{i=1}^{N-1} i
   $$

   $$
   \frac12\sum_{i=1}^{N-1} i = \frac12\frac{(N-1)N}{2} = \frac{(N-1)N}{4}
   $$

   $$
   \frac{N^2-N}{4}
   $$

   Since $\frac{N^2-N}{4}$ is dominated by $N^2$, insertion sort runs in:

   $$
   T(N) \in O(N^2).
   $$

1. At the start of the insertion sort, the index of the inspected value is set to 1. Change the index of the inspected value and verify that the total number of operations equals 20. Consider the worst-case scenario. Use N=5, where N is the number of elements. (Note: Comparisons and Insertions so a factor of 2 is added)

   $$
   2\sum_{i=0}^{N-1} i, N=5
   $$

   $$
   2\sum_{i=0}^{4} i = 2(0+1+2+3+4)=20
   $$

1. The following function returns whether or not a capital “X” is present within a string.

```ts
function containsX(string) {
  foundX = false;
  for (let i = 0; i < string.length; i++) {
    if (string[i] === "X") {
      foundX = true;
    }
  }
  return foundX;
}
```

a. What is this function’s time complexity regarding Big O Notation?

- The function has a time complexity of $O(N)$ because in the worst case it must iterate through all N characters of the string.

b. Then, modify the code to improve the algorithm’s efficiency for best- and average-case scenarios.

```ts
function containsX(string: string): boolean {
  for (let i = 0; i < string.length; i++) {
    if (string[i] === "X") {
      return true;
    }
  }
  return false;
}
```

Above improves efficiency because it exits the loop as soon as `X` is found preventing the loop from iterating over the entire string.

- **Best Case**: 1 step or constant time, `X` is the first letter in the string
- **Avg Case**: $N/2$ steps linear time, `X` is near the middle of the string and we iterate through ~ N/2 elements before finding `X`.
- **Worst Case**: $N$ steps linear time, `X` is not present in the string string and we iterate through all elements before returning `false`.

## Video

[Canvas Video](https://sdccd.us-west-2.instructuremedia.com/embed/b6f764c7-ce2f-4905-9e84-ea52b0361feb)
