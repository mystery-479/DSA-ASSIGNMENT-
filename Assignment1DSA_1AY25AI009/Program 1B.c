#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int roll_no;
    char name[20];
    float marks;
} Student;

int main()
{
    Student *ptr, *temp;
    int n, i, add;
    float sum = 0;
    int max = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    ptr = (Student *)malloc(n * sizeof(Student));

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter roll, name, marks: ");
        scanf("%d %19s %f", &(ptr + i)->roll_no, (ptr + i)->name, &(ptr + i)->marks);
    }

    for (i = 0; i < n; i++)
    {
        sum += (ptr + i)->marks;

        if ((ptr + i)->marks > (ptr + max)->marks)
            max = i;
    }

    printf("Average marks: %.2f\n", sum / n);
    printf("Topper: %s (Roll %d, Marks %.2f)\n", (ptr + max)->name, (ptr + max)->roll_no, (ptr + max)->marks);

    printf("Add 2 more students? (1 = Yes, 0 = No): ");
    scanf("%d", &add);

    if (add == 1)
    {
        temp = (Student *)realloc(ptr, (n + 2) * sizeof(Student));

        if (temp == NULL)
        {
            printf("Memory reallocation failed!\n");
            free(ptr);
            return 1;
        }

        ptr = temp;

        for (i = n; i < n + 2; i++)
        {
            printf("Enter roll, name, marks: ");
            scanf("%d %19s %f",
                &(ptr + i)->roll_no,
                (ptr + i)->name,
                &(ptr + i)->marks);
        }

        n = n + 2;
        sum = 0;

        for (i = 0; i < n; i++)
            sum += (ptr + i)->marks;

        printf("Updated average marks: %.2f\n", sum / n);
    }

    free(ptr);
    return 0;
}
