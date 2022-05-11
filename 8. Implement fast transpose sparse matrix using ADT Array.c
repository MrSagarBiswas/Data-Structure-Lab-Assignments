#include<stdio.h>

int frequency(int index, int matrix[][3], int non_zero)
{
    int count = 0;
    for(int i=1; i<non_zero; i++)
    {
        if(matrix[i][1] == index)
            count++;
    }

    return count;
}

int main()
{
    int rows, cols, non_zero;
    printf("Enter number of rows in sparse matrix\n");
    scanf("%d", &rows);
    printf("Enter number of cols in sparse matrix\n");
    scanf("%d",&cols);
    printf("Enter the number of non-zero values in sparse matrix\n");
    scanf("%d",&non_zero);

    int triplet[non_zero+1][3];
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = non_zero;

    printf("Enter the triplet form of sparse matrix as |row|col|value| \n");
    for(int i=1; i<5; i++)
    {
        for(int j=0; j<3; j++)
        {
            scanf("%d", &triplet[i][j]);
        }
    }

    int total[cols];
    int index[cols+1];

    for(int i = 0; i < cols; i++)
    {
        total[i] = frequency(i, triplet, non_zero);
    }

    index[0] = 1;
    for(int i=1; i<cols+1; i++)
        index[i] = index[i-1] + total[i-1];

    int transpose_triplet[non_zero+1][3];
    for(int i=1; i<non_zero+1; i++)
    {
        int col_no = triplet[i][1];
        int loc = index[col_no];

        transpose_triplet[loc][0] = triplet[i][1];
        transpose_triplet[loc][1] = triplet[i][0];
        transpose_triplet[loc][2] = triplet[i][2];

        index[col_no]++;
    }

    printf("triplet of Transpose sparse matrix is \n");
    for(int i=1; i<non_zero+1; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ", transpose_triplet[i][j]);
        }
        printf("\n");
    }
}