#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int emp_id;
    enum { FULL_TIME, CONTRACT } type;

    union
    {
        float salary;
        struct
        {
            float hourly_rate;
            int hours_worked;
        } contract_info;
    } pay;

} Employee;

int main()
{
    Employee *e;
    int n, i;
    float total = 0, pay;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    e = malloc(n * sizeof(Employee));

    if (e == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter employee name and ID: ");
        scanf("%s %d", (e + i)->name, &(e + i)->emp_id);

        printf("1. Full-time  2. Contract\n");
        printf("Enter employee type: ");
        scanf("%d", &((e + i)->type));

        if ((e + i)->type == FULL_TIME || (e + i)->type == 1)
        {
            (e + i)->type = FULL_TIME;
            printf("Enter monthly salary: ");
            scanf("%f", &(e + i)->pay.salary);
        }
        else if ((e + i)->type == 2)
        {
            (e + i)->type = CONTRACT;
            printf("Enter hourly rate and hours worked: ");
            scanf("%f %d", &(e + i)->pay.contract_info.hourly_rate, &(e + i)->pay.contract_info.hours_worked);
        }
        else
        {
            printf("Invalid employee type!\n");
            free(e);
            return 1;
        }
    }

    printf("\n--- Employee Payslips ---\n");

    for (i = 0; i < n; i++)
    {
        if ((e + i)->type == FULL_TIME)
            pay = (e + i)->pay.salary;
        else
            pay = (e + i)->pay.contract_info.hourly_rate *
                (e + i)->pay.contract_info.hours_worked;

        printf("\nName: %s\n", (e + i)->name);
        printf("Employee ID: %d\n", (e + i)->emp_id);
        printf("Total Pay: %.2f\n", pay);

        total += pay;
    }

    printf("\nTotal salary bill: %.2f\n", total);

    free(e);
    return 0;
}
