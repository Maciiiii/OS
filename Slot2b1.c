
//scan

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tc, ip, n;
    int ch;
    int j = 0;
    int k = 0;
    int total=0;

    printf("\nEnter the total number of cylinders in HDD:\n");
    scanf("%d", &tc);
    if (tc <= 0) {
        printf("Total cylinders must be greater than 0");
        exit(1);
    }

    printf("\nEnter the number of cylinders to enter in the Request queue:\n");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of cylinders must be greater than 0");
        exit(1);
    }

    int req[n];
    int a[n];
    int b[n];

    printf("\nEnter the cylinders no. in Request queue :\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("\nEnter the initial Position of RW head: ");
    scanf("%d", &ip);

    printf("\nEnter direction (1 --> for Large Value or 0 --> for Smaller value): ");
    scanf("%d",&ch); // Note the space before %c to consume any leading whitespace

    for ( int i = 0; i < n; i++) {
        if (req[i] > ip) {
            a[j] = req[i];
            j++;
        } else if (req[i] < ip) {
            b[k] = req[i];
            k++;
        }
    }

    //sort a  array
    int m = j;
    int y=k;

    for (int  i = 0; i<m-1; i++) {
        for (int j = 0; j < m - i-1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    //sort b array
    for (int  i= 0; i < y - 1; i++) {
        for (int j = 0; j < y - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    //sort b array


    //int m = j; // Number of elements in array 'a'
   /* printf("Size of array a: %d\n", m);

    printf("Elements of array a: ");
    for (int i = 0; i < m; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Elements of array b: ");
    for (int i = 0; i < y; i++)
        printf("%d ", b[i]);
    printf("\n");*/

    if(ch==1)
    {

        for (int i = 0; i < m; i++)
        {
            total=total + abs(ip-a[i]);
            ip=a[i];
        }
        total+=abs(a[m-1]-(tc-1));
        ip=(tc-1);

        for (int i=y-1; i>=0; i--)
        {
            total+=abs(ip-b[i]);
            ip=b[i];

        }

        //printf("hiii");


    }
    else
    {

        for (int i=y-1; i>=0; i--)
        {
            total=total+abs(ip-b[i]);
            ip=b[i];
        }

        total+=abs(0-b[y-y]);
        ip=0;

        for (int i=0; i<m; i++)
        {
            //printf("\n%d",ip);
            total=total+abs(ip-a[i]);
            ip=a[i];
            // printf("\n%d",ip);
        }

    }
    printf("\n Total Movement: %d",total);
    // printf("%d",ip);
    //printf("%d",a[m-1]);

    return 0;
}
