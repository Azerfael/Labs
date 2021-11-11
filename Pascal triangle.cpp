#include <iostream>

void output(int* matrix, const int colv, int n)
{
    int p = 0;
    matrix = new int [colv + 1]{ 0 };
    matrix[0] = 1;
    std::cout << "\n";
    for (int j = 1; j <= n; j++)
        for (int i = j; i >= 1; i--)
            matrix[i] += matrix[i - 1];
    while (colv - n > p)
    {
        std::cout << " ";
        p++;
    }
    for (int i = 0; i <= n; i++)
    {
        if (matrix[i] % 2 == 0)
            std::cout << "  ";
        else
            std::cout << "0 ";
    }
    if (n >= 0)
    {
        n--;
        output(matrix, colv, n);
    }
}



int main()
{
    int const colv = rand() % 55 + 1;
    int* matrix;
    int n = colv;
    matrix = new int[colv];
    output(matrix, colv, n);
    return 0;
}