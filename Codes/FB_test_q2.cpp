
// C++ code to demonstrate 2D vector
#include <iostream>
#include <vector> // for 2D vector
using namespace std;

vector<vector<int> > performOps(vector<vector<int> > &A) {
    vector<vector<int> > B;
    B.resize(A.size());
    printf("Size A: %zu %\n", A.size());
    for (int i = 0; i < A.size(); i++) {
        B[i].resize(A[i].size());
        printf("Size A: %zu %\n", A[i].size());
        for (int j = 0; j < A[i].size(); j++) {
            B[i][A[i].size() - 1 - j] = A[i][j];
        }
    }
    return B;
}

int main()
{   
    vector<vector<int> > A{ { 1, 2, 3, 4 },
                               { 5, 6, 7, 8 },
                               { 9, 10, 11, 12 } };
   // vector<vector <int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}
    vector<vector<int> > B = performOps(A);
    for (int i = 0; i < B.size(); i++) {
        for (int j = 0; j < B[i].size(); j++)
        {
            printf("i: %d",i); printf(" j: %d\n",j);
            cout<<B[i][j]<<" ";
            printf("\n");
        }
    }
}