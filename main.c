#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Rus");
    {
        int i,j,n,m, **mas;

        printf("Введите размерность массива m*n:\n");
        scanf("%d %d", &m, &n);

        mas = (int**) malloc(m*sizeof(int*));

        for (i = 0; i < m; i++)
        {
            mas[i] = (int*) malloc(n*sizeof(int));
        }

        printf("Введите элементы массива\n");

        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
                scanf("%d",&mas[i][j]);

        printf("Исходный двумерный массив\n");
        for (i=0; i<m; i++, printf("\n"))
            for (j=0; j<n; j++)
                printf("%d ", mas[i][j]);

        int mas_2[m*n];


        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
            {
                mas_2[i*n+j]=mas[i][j];

            }


        printf("Новый одномерный массив:\n");

        for (i=0; i<m*n; i++)
            printf("%d ",mas_2[i]);

        printf("\n");

        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
                mas[i][j]=0;
        printf("Запись элементов обратно в двумерный массив:\n");

        for (i=0; i<m*n; i++)

        {
            mas[i/n][i%n]=mas_2[i];

        }

        for (i=0; i<m; i++, printf("\n"))
            for (j=0; j<n; j++)
                printf("%d ", mas[i][j]);

    }

    return 0;
}
