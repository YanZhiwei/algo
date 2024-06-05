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
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = 0;
    node->next = node;
    return node;
}

void headInsert(Node* L, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = L->next;
    L->next = node;
    L->data++;
}

void tailInsert(Node* L, int data) {
    Node* lastNode = L;
    while (lastNode->next != L)
    {
        lastNode = lastNode->next;
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = L;
    lastNode->next = node;
    L->data++;
}

int delete(Node* L, int data) {
    Node* node = L->next;
    Node* preNode = L;

    while (node != L)
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
    while (node != L)
    {
        printf("%d\n", node->data);
        node = node->next;
    }
}

int main() {
    Node* L = initList();
    headInsert(L, 1);
    headInsert(L, 2);
    headInsert(L, 3);
    headInsert(L, 4);
    headInsert(L, 5);
    tailInsert(L, 6);
    tailInsert(L, 7);
    delete(L, 6);
    delete(L, 7);
    printList(L);
    return 0;
}