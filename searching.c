#include <stdio.h>
#include <string.h>

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
    int low = 0;
    int high = n - 1;
    int mid;

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
    char departments[7][20] =
    {
        "Backend",
        "Development",
        "Finance",
        "Frontend",
        "HR",
        "IT",
        "Testing"
    };

    char search[3][20] =
    {
        "Development",
        "HR",
        "Testing"
    };

    int i;
    int linearCount;
    int binaryCount;

    printf("Sorted Department List:\n");

    for (i = 0; i < 7; i++)
        printf("%s ", departments[i]);

    printf("\n\nSearch Results:\n");

    for (i = 0; i < 3; i++)
    {
        linearSearch(departments, 7, search[i], &linearCount);
        binarySearch(departments, 7, search[i], &binaryCount);

        printf("\nDepartment: %s\n", search[i]);
        printf("Linear Search Comparisons: %d\n", linearCount);
        printf("Binary Search Comparisons: %d\n", binaryCount);
    }

    return 0;
}
