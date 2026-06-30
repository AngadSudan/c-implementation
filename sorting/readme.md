# Comparison of Time complexities

## Bubble Sort

Intiution behind bubble sort is that we pick 2 adjacent elements and check if an element is greater than the one to its right which points out the unsorted pairs for us and then we swap them creating a sorted pair.

We repeat these process over cycle to finally yield the sorted array.

Time Complexity - `O(n^2)`
Space Complexity - `O(1)`
Edge Case - If the array is already sorted and an optimized implementation stops early, best case becomes `O(n)`.

| ArraySize | Time Required |
| --------- | ------------- |
| 10        | 0.000002s     |
| 100       | 0.000034s     |
| 1000      | 0.001721s     |
| 10000     | 0.232385s     |
| 50000     | 6.954275s     |
| 100000    | 27.789869s    |

---

## Selection Sort

Intiution behind selection sort is that we select an element which is minimum and place it at the ith position and in the next cycle we search for the min element from `i+1`th position. Which goes as the name suggest - select and place at the position.

Time Complexity - `O(n^2)`
Space Complexity - `O(1)`

| ArraySize | Time Required |
| --------- | ------------- |
| 10        | 0.000003s     |
| 100       | 0.000019s     |
| 1000      | 0.001152s     |
| 10000     | 0.115242s     |
| 50000     | 2.835653s     |
| 100000    | 10.917344s    |

---

## Insertion Sort

Intiution behind insertion sort is not about swapping but rather its about shifting of elements. You start from the last position and keep on swapping until you reach an index where you element can be placed so that it remains sorted. We place an element where it can be inserted using shifting operation.

Time Complexity - `O(n^2)`
Space Complexity - `O(1)`
Edge Case - If the array is already (or nearly) sorted, insertion sort runs in `O(n)` time.

| ArraySize | Time Required |
| --------- | ------------- |
| 10        | 0.000002s     |
| 100       | 0.000009s     |
| 1000      | 0.000655s     |
| 10000     | 0.065105s     |
| 50000     | 1.578544s     |
| 100000    | 6.185397s     |

---

## Merge Sort

Merge sort works on the principal of divide and conquer using recursion. The key idea is to break down your array until it can no longer be divided (single element array) and then combine those arrays in such a way that they remain sorted.

Time Complexity - `O(n*log(n))`
Space Complexity - `O(n)`

| ArraySize | Time Required |
| --------- | ------------- |
| 10        | 0.000002s     |
| 100       | 0.000015s     |
| 1000      | 0.000153s     |
| 10000     | 0.001557s     |
| 50000     | 0.008802s     |
| 100000    | 0.019083s     |

---

## Comparison of all Sorting Methods

| Sorting Method | Best Case  | Average Case | Worst Case |
| -------------- | ---------- | ------------ | ---------- |
| Selection Sort | O(n²)      | O(n²)        | O(n²)      |
| Insertion Sort | O(n)       | O(n²)        | O(n²)      |
| Bubble Sort    | O(n) \*    | O(n²)        | O(n²)      |
| Merge Sort     | O(n log n) | O(n log n)   | O(n log n) |

- Bubble Sort achieves O(n) in the best case only when optimized with a
  swap flag to detect an already sorted array. Otherwise, its best case
  is also O(n²).
