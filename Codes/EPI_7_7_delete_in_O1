template <typename T>
void deletion_from_list(const shared_ptr<node_t<T>> &v)
{
    v->data = v->next->data;
    v->next = v->next->next;
}