# Space constraints

## Tasks

The following exercises provide you with the opportunity to practice with space constraints.

1. Following is the 'Word Builder' algorithm. Describe its space complexity in terms of Big O.

```
function wordBuilder(array) {
		let collection = [];
		for(let i = 0; i < array.length; i++) {
				for(let j = 0; j < array.length; j++) {
						if (i !== j) {
								collection.push(array[i] + array[j]);
						}
				}
		}
		return collection;
}
```

**Answer**: This would be an $O(n^2)$ space complexity, because for each index of j we call collection.push creating a new index in the collection, so the outer loop is n iteration the inner loop is n iterations leading to an $O(n^2)$ space complexity.

2. Following is a function that reverses an array. Describe its _space_ complexity in terms of Big O:

```
function reverse(array) {
		let newArray = [];
		for (let i = array.length - 1; i >= 0; i--) {
				newArray.push(array[i]);
		}
		return newArray;
}
```

**Answer**: This would be a $O(n)$ space complexity, the reverse indexing is irrelevant to the space complexity. Space doesn't care about traversal direction, only about the number of new array indices being created $n$.

3. Create a new function to reverse an array that takes up just $O(1)$ extra space.

```
function reverse(array) {
		temp = 0;

		for (let i = 0; i < Math.floor(array.length/2); ++i) {
            let temp = array[i];
            array[i] = array[array.length-i-1];
            array[array.length-i-1] = temp;
		}

		return array;
}
```

**Answer**: This method uses a single temporary variable to swap elements in-place, working from either end toward the center. Because only one extra variable (temp) is allocated regardless of input size, the space complexity is O(1). See example [here](./src/main.cpp).

4. Following are three different implementations of a function that accepts an array of numbers and returns an array containing those numbers multiplied by 2. For example, if the input is [5, 4, 3, 2, 1], the output will be [10, 8, 6, 4, 2].

```
function doubleArray1(array) {
	let newArray = [];

	for(let i = 0; i < array.length; i++) {
		newArray.push(array[i] * 2);
	}
	return newArray;
}


function doubleArray2(array) {
	for(let i = 0; i < array.length; i++) {
  	    array[i] *= 2;
    }
	return array;
}


function doubleArray3(array, index=0) {
	if (index >= array.length) { return; }
    array[index] *= 2;
    doubleArray3(array, index + 1);
	return array;
}
```

Fill in the table that follows to describe the efficiency of these three versions in terms of both time and space:

| Version    | Time complexity | Space complexity |
| ---------- | --------------- | ---------------- |
| Version #1 | $O(n)$          | $O(n)$           |
| Version #2 | $O(n)$          | $O(1)$           |
| Version #3 | $O(n)$          | $O(n)$           |
