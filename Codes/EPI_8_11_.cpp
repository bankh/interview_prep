class Queue {
    private:
        unsigned val, size;

    public:
        Queue() : val(0), size(0) {}

        void enqueue(const unsigned &x)
        {
            val = val * 10 + x;
            ++size;
        }

        unsigned dequeue(void)
        {
            if(size){
                unsigned ret = 0, d = floor(log10(val));
                if(d + 1 == size)
                {
                    ret = val / pow(10.0, d);
                    val -= pow(10.0, d) * ret;
                }
                --size;
                return ret;
            }
            throw length_error("empty queue");
        }
};