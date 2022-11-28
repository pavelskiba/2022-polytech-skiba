#include <iostream>


int** createArr(int m, int n)
{
    int **arr = new int* [m];
    for(int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }
    return arr;
}

void fillArr(int** arr, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        std::cout << i << " row" << std::endl;
        for(int j = 0; j < n; j++)
        {
            std::cin >> arr[i][j];
        }
    }
}

void printArr(int**arr, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteArr(int** arr, int m)
{
    for(int i = 0; i < m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void matmul(int** a, int m_a, int n_a, int** b, int m_b, int n_b, int** c)
{
    for (int i = 0; i < m_a; i++) 
    {
        for (int j = 0; j < n_b; j++) 
        {
            c[i][j] = 0;
            for (int k = 0; k < n_a; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

bool mateq(int** a, int m_a, int n_a, int** b, int m_b, int n_b)
{
    bool f = true;
    if(m_a != m_b || n_a != n_b) 
    {
    return f = false; 
    }
    
    else
    {
        for(int i = 0; i < m_a; i++)
        {
            for(int j =0; j < n_a; j++)
            {
              if(a[i][j] != b[i][j])
              {
                return f = false;
              }
            }
        }
        return f = true;
    }
}