template <typename T>
shared_ptr<node_t<T>> even_odd_merge(const shared_ptr<node_t<T>> &L)
{
    shared_ptr<node_t<T>> odd = L ? L->next : nullptr;
    shared_ptr<node_t<T>> odd_curr = odd;
    shared_ptr<node_t<T>> pre_even_curr = nullptr, even_curr = L;
    
    while(even_curr & odd_curr)
    {
        
        even_curr -> next = odd_curr -> next;
        pre_even_curr = even_curr;
        even_curr = even_curr->next;

        if(even_curr)
        {
            odd_curr -> next = even_curr->next;
            odd_curr = odd_curr->next;
        }
    }

    if(even_curr)
    {
        pre_even_curr = even_curr;
    }

    if(pre_even_curr)
    {
        pre_even_curr->next = odd;
    }
    
    return L;
}