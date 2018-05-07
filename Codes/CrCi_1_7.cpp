// Matrix rotation
// Transpose and row reverse will rotate the square matrix to clockwise,
// Transpose and col reverse will rotate the square matrix to counter-clockwise.
#include <iostream>
#include <cstdlib>
#include <ctime>

void printMatrix(int **matrix, int N);

void helper_transpose(int **matrix, int N) // O(N2)
{
    for(int i=0; i<N; ++i)
    {
        for(int j=i+1; j<N; ++j)
        {
            if(i!=j)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    // printf("Transposed: \n");
    // printMatrix(matrix,N);
}

void helper_row_reverse(int *row, int N)
{
    for(int i=0; i<N/2; ++i)
    {
        std::swap(row[i], row[N-i-1]);
    }
}

void helper_col_reverse(int **matrix, int N)
{
    for(int i=0; i<N/2; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            std::swap(matrix[i][j],matrix[N-i-1][j]);
        }
    }
}

void rotate1(int **matrix, int N)
{
    helper_transpose(matrix, N);
    for(int i=0; i<N; ++i)
    {
        helper_row_reverse(matrix[i],N);
    }
}

void rotate2(int **matrix, int N)
{
    helper_transpose(matrix,N);
    helper_col_reverse(matrix,N);
}

void printMatrix(int **matrix, int N)
{
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    int N = 5;
    // std::cout << "Enter N for NxN matrix:";
    // std::cin >> N;
    int** matrix = new int*[N];
    srand((unsigned)time(0));

    for(int i=0; i<N; ++i)
    {
        matrix[i] = new int[N];
    }

    // Create an NxN square array from 1-10
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {           
            matrix[i][j] = (rand()%10)+1;
        }
    }

    std::cout << "Original Matrix: \n";
    printMatrix(matrix,N);

    std::cout << "Rotated matrix by 90 (clockwise): \n";
    rotate1(matrix,N);
    printMatrix(matrix,N);

    std::cout << "Rotated same matrix by 90 (counterclockwise): \n";
    rotate2(matrix,N);
    printMatrix(matrix,N);

    return 0;
}