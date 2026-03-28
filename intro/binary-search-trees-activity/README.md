# Binary Search Tree

## Task

1. Imagine you were to take an empty binary search tree and insert the following sequence of numbers in this order: [1, 5, 9, 2, 4, 10, 6, 3, 8]. Draw a diagram showing what the binary search tree would look like. Remember, the numbers are being inserted in the order presented here.
   - insert 1
     ```mermaid
     graph TD
         A[1]
     ```
   - insert 5

     ```mermaid
     graph TD
         A[1] --> B[null]
         A --> C[5]
     ```

   - insert 9
     ```mermaid
     graph TD
        A[1] --> B[null]
        A --> C[5]
        C --> E[null]
        C --> F[9]
     ```
   - insert 2

     ```mermaid
     graph TD
        A[1] --> B[null]
        A --> C[5]
        C --> E[2]
        C --> F[9]
        F --> G[null]
        F --> H[null]
     ```

   - insert 4

     ```mermaid
     graph TD
        A[1] --> B[null]
        A --> C[5]
        C --> E[2]
        C --> F[9]
        F --> G[null]
        F --> H[null]
        E --> I[null]
        E --> J[4]
     ```

   - insert 10

   ```mermaid
    graph TD

        A[1] --> B[null]
        A --> C[5]
        C --> E[2]
        C --> F[9]
        F --> G[null]
        F --> H[10]
        E --> I[null]
        E --> J[4]
   ```

   - insert 6

   ```mermaid
    graph TD
        A[1] --> B[null]
        A --> C[5]
        C --> E[2]
        C --> F[9]
        F --> G[6]
        F --> H[10]
        E --> I[null]
        E --> J[4]
   ```

   - insert 3

   ```mermaid
   graph TD
       A[1] --> B[null]
       A --> C[5]
       C --> E[2]
       C --> F[9]
       E --> I[null]
       E --> J[4]
       F --> G[6]
       F --> H[10]
       J --> K[3]
       J --> L[null]
   ```

   - insert 8

   ```mermaid
   graph TD
       A[1] --> B[null]
       A --> C[5]
       C --> E[2]
       C --> F[9]
       F --> G[6]
       F --> H[10]
       E --> I[null]
       E --> J[4]
       J --> K[3]
       J --> L[null]
       G --> M[null]
       G --> N[8]
   ```

2. If a well-balanced binary search tree contains 1,000 values, what is the maximum number of steps it would take to search for a value within it?

   $O(log_2(1000))\approx 10$
   - so it would take approximately 10 steps to find the value.

3. Write an algorithm that finds the greatest value within a binary search tree.
   - the right deepest node should always be the largest value in the tree

     ```pseudocode
     function findMax() {
             // start at root node
             tmpNode = tree.rootNode;

             while(tmpNode.right != null) {
                 // traverse the right side of the graph
                 tmpNode = tmpNode.right;
             }

             // return the value
             return tmpNode.value;
     }
     ```

4. Write a code in C++ using the same array mentioned in #1 and implement a binary search tree. Only insertion operation is required.
   - see implementation [Tree](./include/bst/tree.h)
