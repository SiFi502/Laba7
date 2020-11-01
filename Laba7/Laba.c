#include <stdio.h>
#include <stdbool.h>


int main(void)
{
    // Ввод количества строк матрицы
    int size;
    printf_s("Enter square matrix size\n>>> ");
    while(!scanf("%d", &size) || size <= 0)
    {
        printf_s("Please, enter correct size \n>>> ");
        fflush(stdin);
    }


    // Выделение памяти под матрицу
    int **matrix;
    printf_s("Enter matrix with size %d\n>>> ", size);
    matrix = (int **)malloc(sizeof(int *) * size);
    for(int i = 0; i < size; i++)
        matrix[i] = (int *)calloc(size, sizeof(int));

    // Ввод матрицы
    for(int i = 0; i < size; i++)
    {

        for(int j = 0; j < size; j++)
        {
            while(!scanf_s("%d", &matrix[i][j]))
            {
                printf_s("Enter numbers\n Enter [%d] line\n>>> ", i + 1);
                fflush(stdin);
            }
        }
        printf_s(">>> ");
    }


    // Проверка матрицы на Латинский квадрат
    // Начальное задание переменной result класса bool отрицательного значения
    bool result = false;
    // Перебор матрицы по строкам и столбцам
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            int score = 0;
            // Сверяем матрицу по строкам
            for (int n = 0; n < size; n++)
                if (matrix[n][j] == matrix[i][j] && n != i)
                    score++;

            if (score > 0)
                result = true;

            score = 0;
            // Сверяем матрицу по столбцам
            for (int k = 0; k < size; k++)
                if (matrix[i][k] == matrix[i][j] && k != j)
                    score++;

            if (score > 0) result = true;
        }

        // Вывод результата, если...
        if (result == false)
            printf_s("Matrix is Latin square.\n");
        else
            printf_s("Matrix is not Latin square.\n");

    // Освобождение памяти
    for (int i = 0; i < size; i++)
    free(*(matrix + i));
    free(matrix);

    getch();
    return 0;
}
