# Intro Arrays

## Explain how to create an array of 100 elements. You can choose any data type of your choice.

There are few different ways to instantiate arrays.

```
// Allocates contiguous memory for 100 integers on the stack.
int arr[100];
```

- this creates an array of 100 ints. This allocates space for 100 integers. arr points to the start of the sequence.

```
// Allocates contiguous memory for 100 integers on the heap.
int* arr = new int[100];
```

## What will be the size of each element of an array?

The size of each element depends on the type of element, however, we can determine the size of any element using the `sizeof` method.
ex:

```
std::cout << sizeof(arr[0]);
```

## For an array containing 100 elements, provide the number of steps the following operations would take

---

### Reading

Reading is a single step operation and therefor constant time complexity operation O(1). We simply need to go to the memory location and load the variable in.

### Searching

There are several types of search algorithm, however the two referenced in the text are:

- Linear
  - requires 100 steps because we need to search the entire array.
  - This is an O(n) operation where n is the size of the array. (Assuming worst case)
  - Iterates over elements of the array sequentially until the element is found.
  - Does not require sorted data.
- Binary
  - Log(100)/Log(2) ~= 7, so it would take seven steps.
  - This algorithm is a O(log(n)) time complexity
  - Requires data to be sorted.
  - defines the middle of the array. we half the array looking to see if the desired element is larger smaller than the center of the remaining elements. we continue to half the number of elements in the array until the desired element is found.

### Insertion at the beginning of the array

This would take 1 creation step + 100 steps, 101 steps, to shift every element and be considered an O(n) operation because we need to shift every element in the array by 1. (If space exists)

### Insertion at the end of the array

This takes a single step assuming space exists and is an O(1) time complexity operation. Simply add the new element to the end of the array. If space does not exist it becomes an O(n) operation.

### Deletion at the beginning of the array

This takes 1 deletion step + 99 steps, 100 steps, and would be an O(n) operation because all elements must be shifted left by one index.

### Deletion at the end of the array

This takes a single step and would be an O(1) time complexity because the element at the end of the array is simply deleted.

---

## How many steps would it take to find all instances of an element? Give your answer in terms of N.

If we assume a linear search algorithm this would N steps where N is the number of elements in the array. It would be O(n) time complexity.
The idea would be to iterate over every element of the array counting or preforming operations on the target elements.

## Research how to find the memory address of an array. You can use any programming language of your choice.

I chose cpp for this. the results can be seen here: [main.cpp](./main.cpp).

As mentioned above the first element in the array and the address of the array variable are the same. thats why when iterating over a cpp array one of the patterns is to use the the sizeof(arr)/sizeof(arr[0]). This formula calculates the total memory size of the array divided by the memory size of each element to get the number of elements in an array.


## Video
[Canvas Video](https://sdccd.us-west-2.instructuremedia.com/embed/571a06e1-c18d-475d-85ef-c0c8c9378272)