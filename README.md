# Data Structures Assignment 2 - Question 5

## Topic
Organisational Hierarchy and Department Searching

## Description
A company hierarchy is represented as a general tree and traversed level by level.
Linear Search and Binary Search are compared for locating department names (n = 8,
including CEO).

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
| Key | Linear | Binary |
|---|---|---|
| Testing | 6 | 4 |
| Frontend | 7 | 3 |
| HR | 2 | 2 |
| Marketing (absent) | 8 | 4 |

## Conclusion
Binary Search needs sorted data but uses far fewer comparisons as the number of
departments grows (O(log n) vs O(n)).
