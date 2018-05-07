template <typename T>
shared_ptr<node_t<T>> has_cycle(const shared_ptr<node_t<T>> & head)
{
    shared_ptr<node_t<T>> fast = head, slow = head;

    while (slow && slow->next && fast && fast -> next && fast -> next -> next)
    {
        slow = slow -> next;
        fast = fast -> next;

        if (slow == fast)
        {
            int cycle_len = 0;
            do{
                ++cycle_len;
                fast = fast ->next;
            }while(slow != fast);

            slow = head, fast = head;

            while(cycle_len--)
            {
                fast = fast -> next;
            }

            while(slow != fast)
            {
                slow = slow -> next, fast = fast -> next;
            }

            return slow;
        }
    }
    return nullptr; // no cycle
}
template <typename T>
int count_len(shared_ptr<node_t<T>> L)
{
    int len = 0;
    while(L)
    {
        ++len, L = L -> next;
    }
    return len;
}

template <typename T>
void advance_list_by_k(shared_ptr<node_t<T>> &L, int k)
{
    while(k--)
    {
        L=L->next;
    }
}

template <typename T>
shared_ptr <node_t<T>> overlapping_no_cycle_lists(shared_ptr<node_t<T>> L1,
                                                  shared_ptd<node_t<T>> L2)
{
    int L1_len = count_len<T>(L1), L2_len = count_len<T>(L2);
    advance_list_by_k(L1_len > L2_len ? L1 : L2, abs(L1_len - L2_len));

    while(L1 && L2 && L1 != L2)
    {
        L1 = L1->next, L2 = L2->next;
    }
    return L1;
}

template <typename T>
shared_ptr<node_t<T>> overlapping_lists(shared_ptr<node_t<T>> L1, 
                                        shared_ptr<node_n<T>> L2)
{
    shared_ptr<node_t<T>> s1 = has_cycle<T>(L1), s2 = has_cycle<T>(L2);
    
    if(!s1 && !s2)
    {
        return overlapping_no_cycle_lists(L1, L2);
    }else if(s1 && s2)
    {
        do{
            temp = temp->next;
        }while(temp!=s1 && temp != s2);
        return temp == s1 ? s1 : nullptr;
    }
    return nullptr; // One list has cycle and the other doesnt
}