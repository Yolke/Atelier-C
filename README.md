# Sorting Algorithms Performance Comparison

This project aims to compare the performance of various sorting algorithms on a randomly generated string of 100,000 characters. The algorithms implemented and tested include:

- **Bubble Sort**: Known for its simplicity but inefficient for large datasets.
- **Merge Sort**: More efficient for large datasets with generally better time complexity.
- **Quick Sort**: Commonly used for its ability to handle large amounts of data with good average performance.
- **Insertion Sort**: Effective for small datasets or partially sorted datasets.

## Algorithms Implemented

1. **Bubble Sort**
2. **Merge Sort**
3. **Quick Sort**
4. **Insertion Sort**

## Project Structure

```
.
├── main.c
├── sorting_algorithms.c
├── sorting_algorithms.h
├── Makefile
└── README.md
```

- `main.c`: Contains the main function and performance testing logic.
- `sorting_algorithms.c`: Contains the implementations of the sorting algorithms.
- `sorting_algorithms.h`: Header file with declarations of the sorting functions.
- `Makefile`: Instructions for compiling the project.
- `README.md`: This file.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Make (build automation tool)
- pthreads (POSIX threads library)

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/sorting-algorithms-comparison.git
   cd sorting-algorithms-comparison
   ```

2. Compile the project using the provided Makefile:
   ```sh
   make
   ```

### Usage

Run the compiled executable to test the performance of the sorting algorithms:
```sh
./main
```

### Example Output

```
Testing sorting algorithms with string size of 100000 characters...
Bubble Sort took 16.796875 seconds.
Insertion Sort took 3.859375 seconds.
Quick Sort took 0.062500 seconds.
Merge Sort took 0.000000 seconds.
```

## Description of Algorithms

### Bubble Sort
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted. 

### Merge Sort
Merge Sort is an efficient, stable, comparison-based, divide and conquer sorting algorithm. Most implementations produce a stable sort, meaning that the implementation preserves the input order of equal elements in the sorted output.

### Quick Sort
Quick Sort is an efficient, comparison-based, divide and conquer sorting algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.

### Insertion Sort
Insertion Sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
