template <typename T>
void dutch_flag_partition(vector<T> &A, const int &pivot_index)
{
    T pivot = A[pivot_index];
    int smaller =0, equal = 0, larger = A.size() -1;

    while(equal <= larger)
    {
        if(A[equal] < pivot)
        {
            swap(A[smaller++], A[equal++]);
        }else if(A[equal] == pivot)
        {
           ++equal;
        }else{
            swap(A[equal],A[larger--]);
        }      
    }
}