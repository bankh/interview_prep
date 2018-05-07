#include <iostream>
#include <ctime>
#include <cstdlib>

struct Node
{
    int data;
    Node* next;
    Node(int d) : data{ d }, next{nullptr}{}
};

void insert( Node *&head, int data)
{
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void deleteList(Node *&head)
{
    Node* nextNode;
    while(head)
    {
        nextNode = head->next;
        delete(head);
        head = nextNode;
    }
}

void printList(Node *head)
{
    while(head)
    {
        std::cout << head->data << "-->";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

// [Recursive Approach]
// @param head  - head of the list
// @param k     - the k value for finding kth element from last of the list
// @param i     - an index maintained to keep track of current node
// @return
Node* kthToLastHelper(Node* head, int k, int& i)
{
    if(head==nullptr)
    {
        return nullptr;
    }
    printf("See recur\n"); // Always finish the function first then keep the value in the memory...
    Node* node = kthToLastHelper(head->next, k, i);
    printf("i: %d\n", i);
    i = i + 1;
    if(i==k)
    {
        return head;
    }
    return node;
}

Node* kthToLastRecursive(Node* head, int k)
{
    int i=0; // This is necessary for recursive 
    return kthToLastHelper(head, k, i);
}

// [Iterative Approach]
Node* kthToLastIterative(Node* head, int k)
{
    if(head==nullptr)
        return head;

    Node* ptr1 = head;
    Node* ptr2 = head;

    int i =0;
    while(i<k && ptr1)
    {
        ptr1 = ptr1->next;
        ++i;
    }

    // Out of bounds
    if(i<k)
    {
        return nullptr;
    }

    while(ptr1 != nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr2;
}

int main()
{
    Node* head = nullptr;
    srand(time(0));

    for(int i=10; i>0; i--)
    {
        insert(head, (rand()%10));
    }

    std::cout << "List: ";
    printList(head);

    int kth = 2;

    std::cout << "4th node from last (recursive): ";
    Node* node4 = kthToLastRecursive(head,kth);
    if(node4 != nullptr)
    {
        std::cout << node4->data << std::endl;
    }else{
        std::cout << "NULL NODE\n";
    }

    std::cout << "4th node from last (iterative): ";
    node4= kthToLastIterative(head, kth);
    if(node4 != nullptr)
    {
        std::cout << node4->data << std::endl;
    }else{
        std::cout << "NULL NODE\n";
    }
    deleteList(head);

    return 0;
}
