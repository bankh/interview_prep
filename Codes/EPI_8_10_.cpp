/* 
Implement a circular queue
*/

template <typename T>
class Queue{
    private:
        size_t head, tail, count;
        vector<T> data;

    public:
        Queue(const size_t &cap = 8) : head(0), tail(0), count(0), data({cap}){}

        void enqueue(const T &x)
        {
            if(count==data.size()){
                data.resize(data.size() << 1);
            }
            data[tail] = x;
            tail = (tail + 1) % data.size(), ++ count;
        }

        T dequeue(void)
        {
            if(count)
            {
                --count;
                T ret = data[head];
                head = (head+1)%data.size();
                return ret;
            }
            throw length_error("empty queue");
        }

        const size_t &size(void) const{
            return count;
        }
};
