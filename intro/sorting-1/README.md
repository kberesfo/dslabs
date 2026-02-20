# Sorting algorithms

## Task

1. Use Big O Notation to describe the time complexity of an algorithm that takes $4N + 16 steps.$
   - This algorithm would be consider a linear complexity $O(N)$.
   - $4N$ is a linear function, so we drop the constants 4 and 16, to say the algo is $O(N)$
1. Use Big O Notation to describe the time complexity of an algorithm that takes $2N^2$.
   - This algorithm would be $O(N^2)$
   - $N^2$ drives the behavior so we drop the constant 2

1. Use Big O Notation to describe the time complexity of the following function, which returns the sum of all numbers of an array after the numbers have been doubled:

   ```
   def double_then_sum(array)
       doubled_array = []

       array.each do |number|
           doubled_array << number *= 2
       end

       sum = 0

       doubled_array.each do |number|
           sum += number
       end
       return sum
   end

   ```

   - There are two for loops in this method so it would be $N+N$ steps.
   - The time complexity would be $O(N)$

1. Use Big O Notation to describe the time complexity of the following function, which accepts an array of strings and prints each string in multiple cases:

   ```
   def multiple_cases(array)
       array.each do |string|
           puts string.upcase
           puts string.downcase
           puts string.capitalize
       end
   end
   ```

   - There is a single for loop in this method so there are N steps
   - The time complexity would be $O(N)$

1. The next function iterates over an array of numbers, and for each number whose index is even, it prints the sum of that number plus every number in the array. What is this function’s efficiency in terms of Big O Notation?

   ```
   def every_other(array)
       array.each_with_index do |number, index|
           if index.even?
               array.each do |other_number|
                   puts number + other_number
               end
           end
       end
   end
   ```

   - There are **nested** for loops so there are $N * N/2$ steps.
   - The Time Complexity for this would be $O(N^2)$

## Video

[Canvas Video](https://sdccd.us-west-2.instructuremedia.com/embed/aa2e58ee-7ed3-46dc-a831-774453c2fb7c)
