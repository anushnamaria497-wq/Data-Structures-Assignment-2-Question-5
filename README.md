# Data Structures Assignment 2 - Question 5

## Topic

Organisational Hierarchy and Department Searching

## Description

This project represents a company organisational hierarchy
using a general tree and compares Linear Search and Binary
Search for locating department names.

## Organisational Hierarchy

CEO
- HR
- Finance
- IT
  - Development
    - Frontend
    - Backend
  - Testing

## Contents

- `tree_hierarchy.c` - Tree construction and level-order traversal
- `searching.c` - Linear Search and Binary Search
- `Input.txt` - Input data
- `Output.txt` - Program output
- `Trace_table.txt` - Important intermediate steps
- `Complexity_analysis.txt` - Time and space complexity
- `Comparison_table.txt` - Search method comparison
- `Conclusion.txt` - Final conclusion

## Level Order Traversal

CEO HR Finance IT Development Testing Frontend Backend

## Search Methods

The project compares:

1. Linear Search
2. Binary Search

The department names are arranged in sorted order for
Binary Search.

## Complexity

### Linear Search

Worst-case time complexity: O(n)

### Binary Search

Worst-case time complexity: O(log n)

### Level-order Traversal

Time complexity: O(n)

## Conclusion

The tree structure is suitable for representing the
organisational hierarchy.

Binary Search requires sorted data but can reduce the
number of comparisons compared with Linear Search for
larger datasets.
