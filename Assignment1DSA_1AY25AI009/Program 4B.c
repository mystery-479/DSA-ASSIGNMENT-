#include <stdio.h>
#define MAX 100

typedef struct
{
    int row, col, value;
} term;

void fast_transpose(term a[], term b[]){
    
    int row_terms[MAX] = {0};
    int starting_pos[MAX];
    int i, j, cols = a[0].col, n = a[0].value;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    for (i = 1; i <= n; i++)
        row_terms[a[i].col]++;

    starting_pos[0] = 1;

    for (i = 1; i < cols; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

    printf("\nRow terms: ");
    for (i = 0; i < cols; i++)
        printf("%d ", row_terms[i]);

    printf("\nStarting positions: ");
    for (i = 0; i < cols; i++)
        printf("%d ", starting_pos[i]);

    for (i = 1; i <= n; i++)
    {
        j = starting_pos[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}

void display(term a[]){

    int i;

    printf("Row Col Value\n");
    for (i = 0; i <= a[0].value; i++)
        printf("%3d %3d %5d\n",
                a[i].row, a[i].col, a[i].value);
}

int main(){

    term a[MAX], b[MAX];
    int matrix[MAX][MAX];
    int rows, cols, i, j, k = 1;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0 ||
        rows >= MAX || cols >= MAX)
    {
        printf("Invalid matrix size!\n");
        return 1;
    }

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    a[0].row = rows;
    a[0].col = cols;
    a[0].value = 0;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                a[k].row = i;
                a[k].col = j;
                a[k].value = matrix[i][j];
                k++;
            }
        }
    }

    a[0].value = k - 1;

    printf("\nOriginal triples:\n");
    display(a);

    fast_transpose(a, b);

    printf("\n\nTransposed triples:\n");
    display(b);

    printf("\nTriples are in row-major order.\n");

    return 0;
}
