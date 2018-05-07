#include <bits/stdc++.h>

struct Node
{
    int data;
    Node* node;
};

Node* newNode(int data)
{
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* sumLists(struct Node* head1, struct Node* head2)
{

}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    // Randomly generate two different linked list for summation of these
    // the lists don't have to be in the same length
}