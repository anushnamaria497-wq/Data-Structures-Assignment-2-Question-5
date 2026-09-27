#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[20];
    struct Node *child1;
    struct Node *child2;
    struct Node *child3;
};

struct Node* createNode(char name[])
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);

    newNode->child1 = NULL;
    newNode->child2 = NULL;
    newNode->child3 = NULL;

    return newNode;
}

void levelOrder(struct Node *root)
{
    struct Node *queue[20];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        struct Node *temp = queue[front++];

        printf("%s ", temp->name);

        if (temp->child1 != NULL)
            queue[rear++] = temp->child1;

        if (temp->child2 != NULL)
            queue[rear++] = temp->child2;

        if (temp->child3 != NULL)
            queue[rear++] = temp->child3;
    }
}

int main()
{
    struct Node *CEO;
    struct Node *HR;
    struct Node *Finance;
    struct Node *IT;
    struct Node *Development;
    struct Node *Testing;
    struct Node *Frontend;
    struct Node *Backend;

    CEO = createNode("CEO");
    HR = createNode("HR");
    Finance = createNode("Finance");
    IT = createNode("IT");
    Development = createNode("Development");
    Testing = createNode("Testing");
    Frontend = createNode("Frontend");
    Backend = createNode("Backend");

    CEO->child1 = HR;
    CEO->child2 = Finance;
    CEO->child3 = IT;

    IT->child1 = Development;
    IT->child2 = Testing;

    Development->child1 = Frontend;
    Development->child2 = Backend;

    printf("Organisational Hierarchy:\n");
    printf("CEO\n");
    printf("|-- HR\n");
    printf("|-- Finance\n");
    printf("|-- IT\n");
    printf("    |-- Development\n");
    printf("        |-- Frontend\n");
    printf("        |-- Backend\n");
    printf("    |-- Testing\n");

    printf("\nLevel Order Traversal:\n");
    levelOrder(CEO);

    return 0;
}
