#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* initList() {
    Node* L = (Node*)malloc(sizeof(Node));
    L->data = 0;
    L->next = NULL;
    return L;
}

void headerInsert(Node* L, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = L->next;
    L->next = node;
    L->data++;
}

void tailInsert(Node* L, int data) {
    Node* lastNode = L;
    for (int i = 0; i < L->data; i++)
    {
        lastNode = lastNode->next;
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    lastNode->next = node;
    L->data++;
}

int delete(Node* L, int data) {
    Node* preNode = L;
    Node* node = L->next;
    while (node)
    {
        if (node->data == data) {
            preNode->next = node->next;
            free(node);
            L->data--;
            return TRUE;
        }
        preNode = node;
        node = node->next;
    }
    return FALSE;
}

void printList(Node* L) {
    Node* node = L->next;
    while (node)
    {
        printf("node=%d\n", node->data);
        node = node->next;
    }

}

int main() {

    Node* L = initList();
    headerInsert(L, 1);
    headerInsert(L, 2);
    headerInsert(L, 3);
    headerInsert(L, 4);
    headerInsert(L, 5);
    tailInsert(L, 6);
    tailInsert(L, 7);
    printList(L);

    if (delete(L, 3)) {
        printf("success delete\n");
    }
    else {
        printf("fail delete\n");
    }
    printList(L);
    return 0;
}