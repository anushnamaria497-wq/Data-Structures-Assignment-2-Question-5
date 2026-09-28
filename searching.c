#include <stdio.h>
#include <string.h>

#define N 8

int linearSearch(char arr[][20], int n, char key[], int *count)
{
    int i;
    *count = 0;
    for (i = 0; i < n; i++)
    {
        (*count)++;
        if (strcmp(arr[i], key) == 0)
            return i;
    }
    return -1;
}

int binarySearch(char arr[][20], int n, char key[], int *count)
{
    int low = 0, high = n - 1, mid;
    *count = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        (*count)++;
        if (strcmp(arr[mid], key) == 0)
            return mid;
        else if (strcmp(key, arr[mid]) < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    /* Original (level-order) list: used for Linear Search */
    char original[N][20] = {"CEO", "HR", "Finance", "IT",
                            "Development", "Testing", "Frontend", "Backend"};
    /* Alphabetically sorted list: required for Binary Search */
    char sorted[N][20] = {"Backend", "CEO", "Development", "Finance",
                          "Frontend", "HR", "IT", "Testing"};
    /* 3 present departments + 1 absent department */
    char keys[4][20] = {"Testing", "Frontend", "HR", "Marketing"};
    int i, lc, bc, li, bi;

    printf("Original list : ");
    for (i = 0; i < N; i++) printf("%s ", original[i]);
    printf("\nSorted list   : ");
    for (i = 0; i < N; i++) printf("%s ", sorted[i]);
    printf("\n\nSearch Results:\n");

    for (i = 0; i < 4; i++)
    {
        li = linearSearch(original, N, keys[i], &lc);
        bi = binarySearch(sorted, N, keys[i], &bc);
        printf("\nDepartment: %s (%s)\n", keys[i], li == -1 ? "not present" : "present");
        printf("Linear Search Comparisons: %d\n", lc);
        printf("Binary Search Comparisons: %d\n", bc);
    }
    return 0;
}
