#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node* next;
};

Node *newNode(int data)
{
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* partition(struct Node *head, int x)
{
    struct Node* smallerHead = NULL, *smallerLast = NULL;
    struct Node* biggerLast = NULL, *biggerHead = NULL;
    struct Node* equalHead = NULL, *equalLast = NULL;

    while(head!=NULL)
    {
        if(head->data == x)
        {
            if(equalHead == NULL)
                equalHead = equalLast = head;
            else{
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }else if(head->data < x)
        {
            if(smallerHead == NULL)
                smallerLast = smallerHead = head;
            else{
                smallerLast->next = head;
                smallerLast = head;
            }
        }else{
            if(biggerHead == NULL)
                biggerHead = biggerLast = head;
            else{
                biggerLast->next = head;
                biggerLast = head;
            }
        }

        head = head->next;
    }

    // Fix end of greated linked list to NULL if this list has some nodes
    if(biggerLast!=NULL)
    {
        biggerLast->next = NULL;
    }

    if(smallerHead == NULL)
    {
        if(equalHead == NULL)
            return biggerHead;
        equalLast->next = biggerHead;
        return equalHead;
    }

    if(equalHead == NULL)
    {
        smallerLast->next=biggerHead;
        return smallerHead;
    }
    smallerLast->next = equalHead;
    equalLast->next = biggerHead;
    return smallerHead;
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
    struct Node* head = newNode(10);
    head->next=newNode(4);
    head->next->next=newNode(5);
    head->next->next->next=newNode(30);
    head->next->next->next->next=newNode(2);
    head->next->next->next->next->next=newNode(50);

    printList(head);
    int x = 3;
    head = partition(head, x);
    printList(head);
    return 0;
}