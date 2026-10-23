#include <stdio.h>

#define SIZE 50

struct Student {
    char name[30];
    int rollno;
    int sub[3];
};

int main() {
    int i, j, max, total, n, a[SIZE], ni = 0;
    struct Student st[SIZE];

    printf("Enter how many students: ");
    scanf("%d", &n);

    /* Read names and roll numbers */
    for (i = 0; i < n; i++) {
        printf("\nEnter name and roll number for student %d: ", i);
        scanf("%s", st[i].name);
        scanf("%d", &st[i].rollno);
    }

    /* Read subject marks */
    for (i = 0; i < n; i++) {
        for (j = 0; j <= 2; j++) {
            printf("\nEnter marks of student %d for subject %d: ", i, j);
            scanf("%d", &st[i].sub[j]);
        }
    }

    /* Calculate total marks obtained by each student */
    for (i = 0; i < n; i++) {
        total = 0;
        for (j = 0; j < 3; j++) {
            total = total + st[i].sub[j];
        }
        printf("\nTotal marks obtained by student %s are %d", st[i].name, total);
        a[i] = total;
    }

    /* List out student who secured highest marks in each subject */
    for (j = 0; j < 3; j++) {
        max = -1;
        ni = 0;
        for (i = 0; i < n; i++) {
            if (st[i].sub[j] > max) {
                max = st[i].sub[j];
                ni = i;
            }
        }
        printf("\nStudent %s got maximum marks = %d in Subject: %d", st[ni].name, max, j);
    }

    /* Find student with overall highest total marks */
    max = -1;
    ni = 0;
    for (i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            ni = i;
        }
    }
    printf("\n%s obtained the total highest marks.\n", st[ni].name);

    return 0;
}
