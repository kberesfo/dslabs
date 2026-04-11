# Binary Heaps

## Tasks

1.  Draw what the following heap would look like after we insert the value 11 into it:

<img width="377" alt="image" src="https://user-images.githubusercontent.com/11669149/229943640-2f9f7951-a9c6-4e4a-86f2-ea5dcd4bc64a.png">

## Solution

- Insert 11

  ```mermaid
  graph TD

      A[10] --> B[9]
      A --> C[8]
      B --> D[6]
      B --> E[5]
      D --> F[2]
      D --> G[1]
      E --> H[3]
      E --> I[11]
      C --> J[7]
      C --> K[4]
  ```

- Bubble up 11

  ```mermaid
  graph TD

      A[10] --> B[9]
      A --> C[8]
      B --> D[6]
      B --> E[11]
      D --> F[2]
      D --> G[1]
      E --> H[3]
      E --> I[5]
      C --> J[7]
      C --> K[4]
  ```

- Bubble up 11

  ```mermaid
  graph TD

      A[10] --> B[11]
      A --> C[8]
      B --> D[6]
      B --> E[9]
      D --> F[2]
      D --> G[1]
      E --> H[3]
      E --> I[5]
      C --> J[7]
      C --> K[4]
  ```

- Bubble up 11

  ```mermaid
  graph TD

      A[11] --> B[10]
      A --> C[8]
      B --> D[6]
      B --> E[9]
      D --> F[2]
      D --> G[1]
      E --> H[3]
      E --> I[5]
      C --> J[7]
      C --> K[4]
  ```

2.  Draw what the previous heap would look like after we delete the root node.
    - 11 is now the root node / highest priority item in the queue.
      - pop() -> 11
        - `arr[arr.size()-1]` = 5, so 5 gets moved to root node.

    ```mermaid
      graph TD

        A[5] --> B[10]
        A --> C[8]
        B --> D[6]
        B --> E[9]
        D --> F[2]
        D --> G[1]
        E --> H[3]
        E --> I[null]
        C --> J[7]
        C --> K[4]
    ```

- Bubble down 5

  ```mermaid
    graph TD

      A[10] --> B[5]
      A --> C[8]
      B --> D[6]
      B --> E[9]
      D --> F[2]
      D --> G[1]
      E --> H[3]
      E --> I[null]
      C --> J[7]
      C --> K[4]
  ```

- Bubble down 5

  ```mermaid
    graph TD

      A[10] --> B[9]
      A --> C[8]
      B --> D[6]
      B --> E[5]
      D --> F[2]
      D --> G[1]
      E --> H[3]
      E --> I[null]
      C --> J[7]
      C --> K[4]
  ```

3.  Imagine you've built a brand-new heap by inserting the following numbers into the heap in this particular order: 55, 22, 34, 10, 2, 99, 68. If you then pop them from the heap one at a time and insert the numbers into a new array, in what order would the numbers now appear?

- for this I Implemented [main.cpp](./src/main.cpp)

  ```bash
  --- Task 3: Pop order of 55,22,34,10,2,99,68 ---
  Heap: 99 22 68 10 2 34 55
  Pop order: 99 68 55 34 22 10 2
  ```
