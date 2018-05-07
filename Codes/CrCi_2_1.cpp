// See other methods
// https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
//
#include <iostream>
#include <unordered_map> // For hashtables
#include <unordered_set>
#include <random>
#include <cstdlib>
#include <ctime>

struct Node
{
    int data;
    //struct Node* Node;
    Node* next = nullptr;
};

// Utility functions

// Insert a node at the beginning of the
// linked list pointing to the head.
void insert(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Printing the elements of linked-list
void printList (Node* head)
{
    while(head)
    {
        std::cout<< head->data << "-->";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Space complexity : O(1) and Time complexity O(n2)
void removeDuplicates(Node* head)
{
    if(head == nullptr || (head && (head->next == nullptr)))
    {
        return;
    }

    Node* curr = head;
    while(curr)
    {
        Node* runner = curr;
        while(runner->next != nullptr)
        {
            if(runner->next->data == curr->data)
            {
                runner->next = runner->next->next;
            }else{
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

// Space complexity : O(n) and Time complexity O(n)
// Use hashtables
void removeDuplicates1(Node* head)
{
    if(head == nullptr || (head && (head->next == nullptr))) 
    {
        return;
    }

    std::unordered_map<int, int> node_map;
    Node* prev = head;
    Node* curr = head->next;
    node_map[head->data] = 1;

    while(curr!= nullptr)
    {
        while(curr && node_map.find(curr->data) != node_map.end())
        {
            curr=curr->next;
        }
        prev->next = curr;
        prev=curr;
        if(curr)
        {
            node_map[curr->data]=1;
            curr = curr->next;
        }
    }
}

//// My fav
void removeDuplicates2(struct Node* start)
{
    int i=0;
    std::unordered_set<int> seen;
    struct Node *curr = start;
    struct Node *prev = NULL;
    while(curr!=NULL)
    {
        if(seen.find(curr->data) != seen.end())
        {
            printf("In seen.find repeated %d\n",curr->data); 
            prev->next = curr->next;
            delete(curr);
        }else
        {
            printf("Here %d times\n",i++);
            seen.insert(curr->data);
            prev = curr;
        }
        printf("In while only %d\n",curr->data);
        curr = prev->next;
    }
}

int main()
{
    std::cout << "Method1 :\n";
    srand((unsigned)time(0));

    Node* head = nullptr;
    for(int i=0; i< 10; ++i)
    {
        insert(head, (rand()%10));
    }
    //Print generated linked list;
    printList(head);
    removeDuplicates(head);
    printList(head);

    std::cout << "Method 2: \n";
    Node* head1 = nullptr;
    for(int i=0; i<10; ++i)
    {
        insert(head1, (rand()%10));
    }
    printList(head1);
    removeDuplicates1(head1);
    printList(head1);

    std::cout << "Method 3: \n";
    Node* head2 = nullptr;
    for(int i=0; i<10; ++i)
    {
        insert(head2, (rand()%10));
    }
    printList(head2);
    removeDuplicates2(head2);
    printList(head2);
}