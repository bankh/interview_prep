#include <stack>
// What is required for queue
using namespace std;

template <typename T>
class Queue{
    private:
        stack<T> A, B;

    public:
        void enqueue(const T &x)
        {
            A.emplace(x);
        }

        T dequeue(void)
        {
            if(B.empty())
            {
                while(!A.empty())
                {
                    B.emplace(A.top());
                    A.pop();
                }
            }
            if(B.empty() == false)
            {
                T ret = B.top();
                B.pop();
                return ret;
            }
            throw length_error("Empty queue");
        }
};