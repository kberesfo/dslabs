# Stacks and queues

## Objective

Implement stacks and queues data structures

## Pre-requisite

Review "Stacks and Queues" from the book [Data Structures in C++](https://d-khan.github.io/ds)

## Task

1. Using Figure 17 as a model, in the book [Data Structures in C++](https://d-khan.github.io/ds), illustrate the result of each operation in the sequence PUSH(S,4), PUSH(S,1), PUSH(S,3), POP(S), PUSH(S,8), and POP(S) on an initially empty stack $S$ stored in array $S[1..6]$.

   ### Note: ( \* = top )
   1. PUSH(S,4)

      ```mermaid
      block
          columns 6
          S1["4*"] S2[" "] S3[" "] S4[" "] S5[" "] S6[" "]

      ```

   1. PUSH(S,1)

      ```mermaid
      block
          columns 6
          S1["4"] S2["1*"] S3[" "] S4[" "] S5[" "] S6[" "]
      ```

   1. PUSH(S,3)
      ```mermaid
      block
          columns 6
          S1["4"] S2["1"] S3["3*"] S4[" "] S5[" "] S6[" "]
      ```
   1. POP(S) -> 3
      ```mermaid
      block
          columns 6
          S1["4"] S2["1*"] S3["3"] S4[" "] S5[" "] S6[" "]
      ```
   1. PUSH(S,8)
      ```mermaid
      block
          columns 6
          S1["4"] S2["1"] S3["8*"] S4[" "] S5[" "] S6[" "]
      ```
   1. POP(S) -> 8

      ```mermaid
      block
          columns 6
          S1["4"] S2["1*"] S3["8"] S4[" "] S5[" "] S6[" "]
      ```

2. Using Figure 18 as a model, in the book [Data Structures in C++](https://d-khan.github.io/ds), illustrate the result of each operation in the sequence ENQUEUE(Q,4), ENQUEUE(Q,1), ENQUEUE(Q,3), DEQUEUE(Q), ENQUEUE(Q,8), and DEQUEUE(Q) on an initially empty queue $Q$ stored in array $Q[1..6]$.

   ### Note: ( \* = head, ^ = tail )
   1. ENQUEUE(Q,4)

      ```mermaid
      block
          columns 6
          S1["4*"] S2["^"] S3[" "] S4[" "] S5[" "] S6[" "]

      ```

   1. ENQUEUE(Q,1)

      ```mermaid
      block
          columns 6
          S1["4*"] S2["1"] S3["^"] S4[" "] S5[" "] S6[" "]
      ```

   1. ENQUEUE(Q,3)
      ```mermaid
      block
          columns 6
          S1["4*"] S2["1"] S3["3"] S4["^"] S5[" "] S6[" "]
      ```
   1. DEQUEUE(Q) -> 4
      ```mermaid
      block
          columns 6
          S1["4"] S2["1*"] S3["3"] S4["^"] S5[" "] S6[" "]
      ```
   1. ENQUEUE(Q,8)
      ```mermaid
      block
          columns 6
          S1["4"] S2["1*"] S3["3"] S4["8"] S5["^"] S6[" "]
      ```
   1. DEQUEUE(Q) -> 1

      ```mermaid
      block
          columns 6
          S1["4"] S2["1"] S3["3*"] S4["8"] S5["^"] S6[" "]
      ```

3. Rewrite ENQUEUE and DEQUEUE to detect **_underflow_** and **_overflow_** of a queue. (see Listings 4 & 5 in the book).

   ```pseudocode
   function dequeue(): int {
       if (self.tail == self.head):
           throw new ValueError("Underflow")

       x = self.arr[self.head]
       self.head = (self.head + 1) % self.length
       return x
   }

   function enqueue(value: int): void {
       if ((self.tail + 1) % self.length == self.head):
           throw new ValueError("Overflow")

       self.arr[self.tail] = value
       self.tail = (self.tail + 1) % self.length
   }
   ```

4. A stack allows insertion and deletion of elements at only end, and a queue allows insertion at one end and deletion at the other end, a **deque** (double-ended queue) allows insertion and deletion at both ends. Write four $O(1)$-time procedures to insert elements into and delete elements from both ends of a deque implemented by an array.

   ```pseudocode
   function enqueueHead(value: int): void {
       if ((self.head - 1) % self.length == self.tail):
           throw new ValueError("Overflow")

       self.arr[self.head] = value
       self.head = (self.head - 1) % self.length
   }

   function enqueueTail(value: int): void {
       if ((self.tail + 1) % self.length == self.head):
           throw new ValueError("Overflow")

       self.arr[self.tail] = value
       self.tail = (self.tail + 1) % self.length
   }

   function dequeueHead(): int {
       if (self.head == self.tail):
           throw new ValueError("Underflow")

       x = self.arr[self.head]
       self.head = (self.head + 1) % self.length
       return x
   }

   function dequeueTail(): int {
       if (self.head == self.tail):
           throw new ValueError("Underflow")

       self.tail = (self.tail - 1) % self.length
       x = self.arr[self.tail]
       return x
   }
   ```

## What/how to submit?

- Write your responses in a markdown file along with the code, upload the file to GitHub, and submit the GitHub link in Canvas. Use **appropriate headings to differentiate tasks**. Please review the guide “[Submitting Your Assignment Using GitHub](https://sdccd-edu.zoom.us/rec/play/SVjSkOJp16n_7ii-oRt1-9auud9NZ0NrhuXrnJYf-bcQP5ipZbGONd6Jxt7h1jns5OJKIq9lgjAuBw.Tc2b6f-qrSDM8aye?eagerLoadZvaPages=sidemenu.billing.plan_management&accessLevel=meeting&canPlayFromShare=true&from=share_recording_detail&startTime=1725121532000&componentName=rec-play&originRequestUrl=https%3A%2F%2Fsdccd-edu.zoom.us%2Frec%2Fshare%2FSVvlngcEn-7CaNI8FvwEVJ5ulLp4sxpqN9hnCYvXeHHcls2e0TBlU47uATNklUf-.yX4fsJjsU2nuLGeX%3FstartTime%3D1725121532000)” before submission.

## Deadline

The deadlines are posted on the Syllabus as well as on Canvas.

## Rubric

- Your response describes the solution in detail. (10 marks)
- The questions are partially answered. (Marks awarded based on the work submitted)
- The answers were not submitted, or the code contains errors. (0 marks)
