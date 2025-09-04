# Sorting Algorithms 

## Different Sorting type

- **Bubble Sort** : Repeatedly swaps adjacent out-of-order elements until the list is sorted.  
- **Merge Sort** : Recursively splits the array in half, then merges sorted halves back together.  
- **Quick Sort** : Partitions the array around a pivot so smaller go left, larger go right, then recurses.  
- **Heap Sort** : Builds a max-heap and repeatedly extracts the root to build the sorted array.  
- **Counting Sort** : Counts occurrences of each value and reconstructs the array in order.  
- **Radix Sort** : Sorts numbers digit by digit (usually with Counting Sort as a subroutine).  


## Speed Comparison

| Algorithm   | Time Avg.   | Time Worst | Space   | 
|-------------|-------------|------------|---------|
| Bubble      | O(n²)       | O(n²)      | O(1)    | 
| Merge       | O(n log n)  | O(n log n) | O(n)    | 
| Quick       | O(n log n)  | O(n²)      | O(log n)| 
| Heap        | O(n log n)  | O(n log n) | O(1)    |
| Radix (LSD) | O(d(n+k))   | O(d(n+k))  | O(n+k)  | 


