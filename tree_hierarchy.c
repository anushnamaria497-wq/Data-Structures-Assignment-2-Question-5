/* ============================================================
   Q5(a): Organisational Hierarchy represented as a General Tree
   Construction + Level Order (BFS) Traversal
   ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 10
#define MAX_NAME 30

typedef struct Node {
    char name[MAX_NAME];
    struct Node* children[MAX_CHILDREN];
    int childCount;
} Node;

Node* createNode(const char* name) {
    Node* n = (Node*)malloc(sizeof(Node));
    strcpy(n->name, name);
    n->childCount = 0;
    return n;
}

void addChild(Node* parent, Node* child) {
    parent->children[parent->childCount++] = child;
}

/* Simple array based queue for BFS */
typedef struct {
    Node* items[100];
    int front, rear;
} Queue;

void initQueue(Queue* q) { q->front = 0; q->rear = 0; }
int isEmpty(Queue* q) { return q->front == q->rear; }
void enqueue(Queue* q, Node* n) { q->items[q->rear++] = n; }
Node* dequeue(Queue* q) { return q->items[q->front++]; }

void levelOrderTraversal(Node* root) {
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    int level = 0;

    printf("\n--- Level Order (BFS) Traversal ---\n");
    while (!isEmpty(&q)) {
        int levelSize = q.rear - q.front;   /* nodes at current level */
        printf("Level %d: ", level);
        for (int i = 0; i < levelSize; i++) {
            Node* cur = dequeue(&q);
            printf("%s ", cur->name);
            for (int j = 0; j < cur->childCount; j++)
                enqueue(&q, cur->children[j]);
        }
        printf("\n");
        level++;
    }
}

int treeHeight(Node* root) {
    if (root == NULL || root->childCount == 0) return 0;
    int maxH = 0;
    for (int i = 0; i < root->childCount; i++) {
        int h = treeHeight(root->children[i]);
        if (h > maxH) maxH = h;
    }
    return maxH + 1;
}

int countNodes(Node* root) {
    int count = 1;
    for (int i = 0; i < root->childCount; i++)
        count += countNodes(root->children[i]);
    return count;
}

int main() {
    /* Build hierarchy:
       CEO -> HR, Finance, IT
       IT -> Development, Testing
       Development -> Frontend, Backend
    */
    Node* CEO = createNode("CEO");
    Node* HR = createNode("HR");
    Node* Finance = createNode("Finance");
    Node* IT = createNode("IT");
    Node* Development = createNode("Development");
    Node* Testing = createNode("Testing");
    Node* Frontend = createNode("Frontend");
    Node* Backend = createNode("Backend");

    addChild(CEO, HR);
    addChild(CEO, Finance);
    addChild(CEO, IT);
    addChild(IT, Development);
    addChild(IT, Testing);
    addChild(Development, Frontend);
    addChild(Development, Backend);

    printf("Organisational Hierarchy Tree constructed.\n");
    printf("Total departments (nodes): %d\n", countNodes(CEO));
    printf("Tree height (root = level 0): %d\n", treeHeight(CEO));

    levelOrderTraversal(CEO);

    return 0;
}
