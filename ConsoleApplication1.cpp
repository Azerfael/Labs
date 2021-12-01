#include <ctime>
#include <iostream>

void task7()
{
    std::cout << "Задание 7\nУдалить из массива, в котором все элементы различны, максимальный и минимальный"
        "элементы.\n\nМассив имеет вид: \n";
    int const N = 10;
    int min = 101, max = -1, numbmin = 0, numbmax = 0;
    int array[N];

    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 100;
        if (i > 0)
            for (int j = i; j >= 0; j--)
                if (array[i] == array[j])
                    array[i] = rand() % 100;
        std::cout << array[i] << "\t";

        if (array[i] < min)
        {
            min = array[i];
            numbmin = i;
        }
    }
    for (int i = numbmin; i <= N; i++)
        array[i] = array[i + 1];

    for (int i = 0; i < N - 1; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            numbmax = i;
        }
    }
    for (int i = numbmax; i <= N - 1; i++)
        array[i] = array[i + 1];

    std::cout << "\nМассив после того как убрали максимальный и минимальный элементы:\n";
    for (int i = 0; i < N - 2; i++)
        std::cout << array[i] << "\t";
}
void task9()
{
    std::cout << "\n\nЗадание 9\nУдалить из массива:\n"
        "а) все отрицательные элементы;\n"
        "б) все элементы, большие данного числа n;\n"
        "в) все элементы, начиная с n1-го по n2-й (n1 ≤ n2).\n";

    int const N = 12; 
    int N1 = N;
    bool stop = false;
    int array[N], save[N];
    //А
    std::cout << "\nНачальный массив: \n";
    for (int i = 0; i < N1; i++)
    {
        array[i] = -20 + rand() % 100;
        std::cout << array[i] << "\t";
        save[i] = array[i];
    }

    for (int i = 0; i < N1; i++)
    {
        stop = false;
        do {
            if (array[i] < 0)
            {
                for (int j = i; j < N1; j++)
                    array[j] = array[j + 1];
                N1--;
            }
            else if (array[i] >= 0)
                stop = true;
        } while (stop == false);
    }

    std::cout << std::endl << "А) Убрали все числа меньше ноля: \n";
    for (int i = 0; i < N1; i++)
        std::cout << array[i] << "\t";
    //Б
    N1 = N;
    for (int i = 0; i < N; i++)
        array[i] = save[i];

    int n = 20;
    for (int k = 0; k < N1; k++)
    {
        for (int i = 0; i < N1; i++)
        {
            if (array[i] > n)
            {
                for (int j = i; j < N1; j++)
                    array[j] = array[j + 1];
                N1--;
            }
        }
    }

    std::cout << std::endl << "Б) Убрали все числа больше n: n=" << n << "\n";
    for (int i = 0; i < N; i++)
        std::cout << array[i] << "\t";
    //В
    N1 = N;
    int n1 = 10, n2 = 50;
    for (int i = 0; i < N1; i++)
        array[i] = save[i];
    for (int k = 0; k < N1; k++)
    {
        for (int i = 0; i < N1; i++)
        {
            if (array[i] > n1&& array[i] < n2)
            {
                for (int j = i; j < N1; j++)
                    array[j] = array[j + 1];
                N1--;
            }
        }
    }
    std::cout << std::endl << "В) Убрали все числа больше n1 и меньше n2: n1=10, n2=50\n";
    for (int i = 0; i < N; i++)
        std::cout << array[i] << "\t";

}
void task11()
{
    int const N = 10;
    int N1 = N;
    int array[N];

    std::cout << "\n\nЗадание 11\nУдалить из массива все повторяющиеся элементы,"
        "оставив их первые вхождения, то есть в массиве должны остаться только разные элементы.\nНеизменённый массив: \n";

    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 10;
        std::cout << array[i] << "\t";
    }

    for (int reset = 0; reset < N; reset++)
    {
        for (int i = 0; i < N1; i++)
            for (int k = i + 1; k < N; k++)
                if (array[i] == array[k])
                    for (int j = k; j < N - 1; j++)
                    {
                        array[j] = array[j + 1];
                        N1--;
                    }
    }

    std::cout << "\nМассив после того как убрали все повторяющиеся значения: \n";
    for (int i = 0; i < N; i++)
        std::cout << array[i] << "\t";

}
int main()
{
    srand(time(NULL));
    //task7();
    //task9();
    task11();
    return 0;
}