# Project activity

## Task 1

You’re working on software that analyzes sports players. Following are two arrays of players of different sports:

```
basketball_players = [
      {first_name: "Jill", last_name: "Huang", team: "Gators"},
      {first_name: "Janko", last_name: "Barton", team: "Sharks"},
      {first_name: "Wanda", last_name: "Vakulskas", team: "Sharks"},
      {first_name: "Jill", last_name: "Moloney", team: "Gators"},
      {first_name: "Luuk", last_name: "Watkins", team: "Gators"}
]

football_players = [
      {first_name: "Hanzla", last_name: "Radosti", team: "32ers"},
      {first_name: "Tina", last_name: "Watkins", team: "Barleycorns"},
      {first_name: "Alex", last_name: "Patel", team: "32ers"},
      {first_name: "Jill", last_name: "Huang", team: "Barleycorns"},
      {first_name: "Wanda", last_name: "Vakulskas", team: "Barleycorns"}
]
```

If you look carefully, you’ll see that some players participate in more than one sport. Jill Huang and Wanda Vakulskas play both basketball _and_ football.

You are to write a function that accepts two arrays of players and returns an array of the players who play in _both_ sports. In this case, that would be:

`["Jill Huang", "Wanda Vakulskas"]`

While there are players who share first names and players who share last names, we can assume there’s only one person who has a particular _full_ name (meaning first _and_ last name).

We can use a nested-loops approach, comparing each player from one array against each player from the other array, but this would have a runtime of $O(N * M)$.

**Your job is to optimize the function so that it can run just $O(N + M)$.**

### [Implementation](./src/task1/task1.cpp)

### Explanation

This i used an unordered set to achieve the desired $O(N+M)$ time complexity. I iterated over the first array of players adding each player to the set. Then i iterated over the second array of players and checked for membership in the player_set, if the player existed in the given set then I added that player to the returned string array. Each array was only iterated over a single time ensuring the desired $O(N+M)$ time complexity.

## Task 2

You’re writing a function that accepts an array of distinct integers from 0, 1, 2, 3...up to N. However, the array will be missing one integer, and your function is to _return the missing one._

For example, this array has all the integers from 0 to 6, but is missing the 4:

```
[2, 3, 0, 6, 1, 5]
```

Therefore, the function should return 4.

The next example has all the integers from 0 to 9, but is missing the 1:

```
[8, 2, 3, 9, 4, 7, 5, 0, 6]
```

In this case, the function should return the 1.

Using a nested-loops approach would take up to $O(N^2)$.

**Your job is to optimize the code so that it has a runtime of $O(N)$.**

### [Implementation](./src/task2/task2.cpp)

### Explanation

For this I used the size of the array to determine what the "theoretical sum" of the array should be, then i subtracted the actual sum of the array to determine the missing element. **NOTE** this makes the assumption that the series starts with 0. This solution would not be appropriate if the series started at a non-zero number. Because the array is only iterated over a single time it has a $O(N)$ time complexity

## Task 3

You’re working on some more stock-prediction software. The function you’re writing accepts an array of predicted prices for a particular stock over the course of time.

For example, this array of seven prices:

```
[10, 7, 5, 8, 11, 2, 6]
```

predicts that a given stock will have these prices over the next seven days. (On Day 1, the stock will close at \$10; on Day 2, the stock will close at $7; and so on.)

Your function should calculate the greatest profit that could be made from a single “buy” transaction followed by a single “sell” transaction.

In the previous example, the most money could be made if we bought the stock when it was worth \$5 and sold it when it was worth \$11. This yields a profit of $6 per share.

Note that we could make even more money if we buy and sell multiple times, but for now, this function focuses on the most profit that could be made from just _one_ purchase followed by _one_ sale.

Now, we could use nested loops to find the profit of every possible buy and sell combination. However, this would be $O(N^2)$ and too slow for our hotshot trading platform.

**Your job is to optimize the code so that the function clocks in at just $O(N)$.**

### [Implementation](./src/task3/task3.cpp)

### Explanation

For this solution we use a current_low variable to track the lowest price we have seen so far and only update it if the "profit" we could make would be larger than our current max profit. this ensures that we don't run into the issue of selling before we purchase. This solution achieves the $O(N)$ desired time complexity because we only iterate over the array a single time.

## Task 4

You’re writing a function that accepts an array of numbers and computes the highest product of any two numbers in the array. At first glance, this is easy, as we can just find the two greatest numbers and multiply them. However, our array can contain negative numbers and look like this:

```
[5, -10, -6, 9, 4]
```

We could use nested loops to multiply every possible pair of numbers, but this would take $O(N^2)$ time. **Your job is to optimize the function so that it’s a speedy $O(N)$.**

### [Implementation](./src/task4/task4.cpp)

### Explanation

For this i used four variables to track the largest, second largest, smallest and second smallest values. I then iterated over the array updating the those variables giving priority to the largest and smallest then the second largest and smallest. at then end i multiplied both the values together ensuring the largest possible value was returned as the answer. This solution achieves the desired $O(N)$ time complexity because we only iterate over the array a single time.

## Task 5

You’re creating software that analyzes the data of body temperature readings taken from hundreds of human patients. These readings are taken from healthy people and range from 97.0 degrees Fahrenheit to 99.0 degrees Fahrenheit. An important point: within this application, _the decimal point never goes beyond the tenth place._

Here’s a sample array of temperature readings:

```
[98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1]
```

You are to write a function that sorts these readings from lowest to highest.

Using a classic sorting algorithm such as Quicksort would take $O(N log N)$. However, in this case, writing a faster sorting algorithm is possible.

Yes, that’s right. Even though you’ve learned that the fastest sorts are $O(N log N)$, this case is different. Why? In this case, there are limited possibilities for the readings. In such a case, we can sort these values in $O(N)$. It may be $N$ multiplied by a constant, but that’s still considered $O(N)$.

### [Implementation](./src/task5/task5.cpp)

### Explanation

For this task I used a "bin" approach to achieve the linear $O(N)$ time complexity. First we instantiate a vector that spans the delta between the min and max values, in this case 97.0 and 99.0 then we multiplied them by 10 to get whole numbers leaving us with 20 bins. Then we use the formula $(n * 10) - (min * 10)$ to get the index of each bin and increment it for each occurrence. We can then iterate over the original array updating each subsequent index using the frequency of each bin.

## Task 6

You’re writing a function that accepts an array of unsorted integers and returns the length of the _longest consecutive sequence_ among them. The sequence is formed by integers that increase by 1. For example, in the array:

```
[10, 5, 12, 3, 55, 30, 4, 11, 2]
```

the longest consecutive sequence is 2-3-4-5. These four integers form an increasing sequence because each integer is one greater than the previous one. While there’s also a sequence of 10-11-12, it’s only a sequence of three integers. In this case, the function should return 4, since that’s the length of the _longest_ consecutive sequence that can be formed from this array.

One more example:

```
[19, 13, 15, 12, 18, 14, 17, 11]
```

This array’s longest sequence is 11-12-13-14-15, so the function would return 5.

**Your job is to optimize the function so that it takes $O(N)$ time.**

### [Implementation](./src/task6/task6.cpp)

### Explanation

For this task I chose to use a set data structure to achieve the $O(1)$ time complexity requirement. This data structure gives us $O(1)$ access to each element and ensures that each number only exists once. We then iterate over each int in the set, if n-1 exists in the set then it is not the "head" of the longest sequence and we move on. If n-1 dne in the set then we continue iterating over the sequence, incrementing a counter, until we reach the end of the sequence. This allows us to check each sequence and compare the longest continuous sequence.
