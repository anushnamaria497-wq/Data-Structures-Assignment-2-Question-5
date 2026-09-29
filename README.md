# Data Structures Assignment 2 - Question 5

## Topic
Organisational Hierarchy and Department Searching

## Description
A company hierarchy is represented as a general tree and traversed level by level. Linear Search and Binary Search are compared for locating department names.).
## Index

| Sl. No. | Contents |
|--------:|----------|
| 1 | Organisational Hierarchy |
| 2 | Tree Construction and Level-Order Traversal |
| 3 | Department Searching |
| 4 | Linear Search |
| 5 | Binary Search |
| 6 | Trace Table |
| 7 | Time and Space Complexity Analysis |
| 8 | Comparison of Linear Search and Binary Search |
| 9 | Conclusion |

## Hierarchy
CEO
- HR
- Finance
- IT
  - Development
    - Frontend
    - Backend
  - Testing

## Files
- `tree_hierarchy.c` - tree construction and level-order traversal
- `searching.c` - Linear Search vs Binary Search (comparison counts)
- `input.txt` - input data
- `output.txt` - program output
- `Trace_table.txt` - intermediate steps
- `Complexity_analysis.txt` - time and space complexity
- `Comparison_table.txt` - search method comparison
- `Conclusion.txt` - final conclusion

## How to run
```
gcc tree_hierarchy.c -o tree && ./tree
gcc searching.c -o search && ./search
```

## Level-order traversal
CEO HR Finance IT Development Testing Frontend Backend

## Search results (comparisons)
## Search Results (Comparisons)

| Key | Linear | Binary |
|---|---:|---:|
| Development | 2 | 2 |
| HR | 5 | 3 |
| Testing | 7 | 3 |

## Conclusion
Binary Search needs sorted data but uses far fewer comparisons as the number of
departments grows (O(log n) vs O(n)).
