#include <ctime>
#include <iostream>

void task1027()
{
    std::cout << "\n\nЗадание 1027\n"
        "Дан Двумерный массив. В каждой его строке найти:\n"
        "а) максимальный элемент;\n"
        "б) минимальный элемент;\n"
        "в) координаты максимального элемента (если элементов с максимальным значением в строке"
        "несколько, то должны быть найдены координаты самого левого из них);\n"
        "г) координаты минимального элемента (если элементов с минимальным значением в строке"
        "несколько, то должны быть найдены координаты самого правого из них).\n";
    int const N = 3;
    int array[N][N], cmin, cmax, rmin, rmax, min = 51, max = -1;
    std::cout << "Все элементы последовательности:\n";
    for (int raw = 0; raw < N; raw++)
    {
        for (int column = 0; column < N; column++)
        {
            array[raw][column] = rand() % 50;
            if (array[raw][column] < min)
            {
                min = array[raw][column];
                cmin = column;
                rmin = raw;
            }
            if (array[raw][column] >= max)
            {
                max = array[raw][column];
                cmax = column;
                rmax = raw;
            }
            std::cout << array[raw][column] << "\t";
        }
        std::cout << "\n\n";
    }

    std::cout << "a) максимальный элемент: " << array[rmax][cmax] << "\nб) минимальный элемент: " << array[rmin][cmin];
    std::cout << "\nв) координаты максимального элемента: " << rmax + 1 << " " << cmax + 1;
    std::cout << "\nг) координаты минимального элемента: " << rmin + 1 << " " << cmin + 1;
}
void task1047()
{
    std::cout << "\n\nЗадание 1047\n Дан Двумерный массив. Поменять местами;\n"
        "а) первый и предпоследний столбцы;\n"
        "б) вторую и последнюю строки;\n";

    int const N = 3;
    int array[N][N], save;

    std::cout << "Исходный вид: \n";
    for (int raw = 0; raw < N; raw++)
    {
        for (int column = 0; column < N; column++)
        {
            array[raw][column] = rand() % 10;
            std::cout << array[raw][column] << "\t";
        }
        std::cout << "\n\n";
    }

    for (int raw = 0; raw < N; raw++)
    {
        save = array[raw][0];
        array[raw][0] = array[raw][N - 2];
        array[raw][N - 2] = save;
    }

    std::cout << "а) поменяли первый и предпоследний столбцы: \n";
    for (int raw = 0; raw < N; raw++)
    {
        for (int column = 0; column < N; column++)
            std::cout << array[raw][column] << "\t";
        std::cout << "\n\n";
    }

    for (int column = 0; column < N; column++)
    {
        save = array[1][column];
        array[1][column] = array[N - 1][column];
        array[N - 1][column] = save;
    }

    std::cout << "б) поменяли вторую и последнюю строки: \n";
    for (int raw = 0; raw < N; raw++)
    {
        for (int column = 0; column < N; column++)
            std::cout << array[raw][column] << "\t";
        std::cout << "\n\n";
    }
}
void task1067()
{
    std::cout << "\n\nЗадание 1027\n Дан Двумерный массив целых чисел. Удалить из него:\n"
        "а) все строки, количество нечётных элементов которых равно заданному числу n;\n"
        "б) все столбцы, сумма элементов которых больше заданного числа n.\n";
    int const N = 3;
    int array[N][N], savear[N][N];

    std::cout << "Начальный массив:\n ";
    for (int raw = 0; raw < N; raw++)
    {
        for (int column = 0; column < N; column++)
        {
            array[raw][column] = rand() % 10 + 1;
            std::cout << array[raw][column] << "\t";
            savear[raw][column] = array[raw][column];
        }
        std::cout << "\n\n";
    }

    int n, sum = 0, colvdel = 0, save;
    std::cout << "Введите число n: ";
    std::cin >> n;

    for (int raw = 0; raw < N; raw++)
    {
        sum = 0;
        for (int column = 0; column < N; column++)
            if (array[raw][column] % 2 != 0)
                sum++;

        if (sum == n)
            for (int column = 0; column < N; column++)
                array[raw][column] = 0;
    }

    std::cout << "\nа) Массив где убрали все строки, количество нечётных элементов которых равно заданному числу n:\n\n";
    for (int raw = 0; raw < N; raw++)
    {
        for (int column = 0; column < N; column++)
            if (array[raw][column] != 0)
                std::cout << array[raw][column] << "\t";
        if (array[raw][1] != 0)
            std::cout << "\n\n";
    }

    std::cout << "Введите число n: ";
    std::cin >> n;

    for (int column = 0; column < N; column++)
    {
        sum = 0;
        for (int raw = 0; raw < N; raw++)
            sum += savear[raw][column];

        if (sum > n)
            for (int raw = 0; raw < N; raw++)
                savear[raw][column] = 0;
    }

    std::cout << "\nб) Массив где убрали все столбцы, сумма элементов которых больше заданного числа n: \n\n";
    for (int raw = 0; raw < N; raw++)
    {
        for (int column = 0; column < N; column++)
            if (savear[raw][column] != 0)
                std::cout << savear[raw][column] << "\t";
        if (savear[raw][1] != 0)
            std::cout << "\n\n";
    }
}

int main()
{
    srand(time(NULL));
    //task1027();
    //task1047();
    task1067();
    return 0;
}