template <typename T>
shared_ptr<node_t<T>> reverse_linked_list(const shared_ptr<node_t<T>> &head)
{
    if(!head || !head->next)
    {
        return head;
    }

    shared_ptr<node_t<T>> new_head = reverse_linked_list(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

template <typename T>
shared_ptr<node_t<T>> reverse_linked_list(const shared_ptr<node_t<T>> &head)
{
    shared_ptr<node_t<T>> prev = nullptr, curr = head;
    
    while(curr)
    {
        shared_ptr<node_t<T>> temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev
}