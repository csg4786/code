#include <bits/stdc++.h>
using namespace std;
#define MAX 100

typedef struct Node
{
    int val;
    char key;
    struct Node *left, *right;
} node;

typedef struct Heap
{
    int size;
    int capacity;
    node **array;
} heap;

node *newNode(char key, int val)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->left = temp->right = NULL;
    temp->key = key;
    temp->val = val;

    return temp;
}

heap *buildMinHeap(int capacity)
{
    heap *minHeap = (heap *)malloc(sizeof(heap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (node **)malloc(minHeap->capacity * sizeof(node *));
    return minHeap;
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i];

    cout << "\n";
}

void swapNode(node **a, node **b)
{
    node *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(heap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->val < minHeap->array[smallest]->val)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->val < minHeap->array[smallest]->val)
        smallest = right;

    if (smallest != idx)
    {
        swapNode(&minHeap->array[smallest],
                 &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int oneSize(heap *minHeap)
{
    return (minHeap->size == 1);
}

node *extractMin(heap *minHeap)
{
    node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(heap *minHeap, node *minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->val < minHeap->array[(i - 1) / 2]->val)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(heap *minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(node *root)
{
    return !(root->left) && !(root->right);
}

heap *createAndBuildMinHeap(char key[], int val[], int size)
{
    heap *minHeap = buildMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(key[i], val[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

node *buildHfTree(char key[], int val[], int size)
{
    node *left, *right, *top;
    heap *minHeap = createAndBuildMinHeap(key, val, size);

    while (!oneSize(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->val + right->val);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
void printHCodes(node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printHCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printHCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root))
    {
        cout << root->key << " ";
        printArray(arr, top);
    }
}

void HuffmanCodes(char key[], int val[], int size)
{
    node *root = buildHfTree(key, val, size);

    int arr[MAX], top = 0;
    printHCodes(root, arr, top);
}

int main()
{
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    cout << "\n";

    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, val, size);
    cout << "\nTime complexity of the code is: n*logn\n";
}
