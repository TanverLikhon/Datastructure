///the task
/* Name: Tanver Ahmed
    ID:1702028
    Dept. of CSE*/

#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
void sclean(void);
void show(int *,int *);
void menu(void);
void location(int *, int *);


void location(int *p,int *n)
{
    int loc,k, x,lower_bound=1;

    printf("Enter index no:\n");
    scanf("%d",&k);
    if(k>*n)
    {
        printf("The index doesn't exists :( \n ");

    }
    x=sizeof(int);
    loc=(int)p+x*(k-lower_bound);
    printf("The address of the desired index is %d\n\a",loc);
    sclean();
}
void bubblesort1(int *n,int *p)
{
    int j, i,temp,n1;
    n1=*n;
    for (i = 0; i < n1; i++)
    {
        for (j = i + 1; j < n1; j++)
        {
            if (*(p+i)> *(p+j))
            {
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    }
}
void bubblesort2(int *n,int *p)
{
    int j, i,temp,n1;
    n1=*n;
    for (i = 0; i < n1; i++)
    {
        for (j = i + 1; j < n1; j++)
        {
            if (*(p+i)< *(p+j))
            {
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    }
    show(n,p);
}
void rem(int *n,int *array)
{
    int ck=0, i,position,c,element;
    printf("Enter the element you wish to delete element\n");
    scanf("%d",&element);
    for (i = 0; i <*n; i++)
    {
        if (*(array+i) == element)
        {
            ck=1;
            position = i;
            break;
        }

    }



    if(ck==1)
    {
        for (c = position; c < *n; c++)
            *(array+c) = *(array+c+1);
        *n=*n-1;
        printf("\n%d found and deletion successful\n resultant array ",element);
        show(n,array);

    }
    else
    {
        printf("Element not found :(\nArray remains the same.");
        show(n,array);
    }

}
void binary(int *n,int *array)
{

    bubblesort1(n,array);
    int search,first,last,middle;
    printf("Enter value to find\n");
    scanf("%d", &search);

    first = 0;
    last = *n - 1;
    middle = (first+last)/2;

    while (first <= last)
    {
        if (*(array+middle) < search)
            first = middle + 1;
        else if (*(array+middle) == search)
        {
            printf("%d found at location %d.\n", search, middle+1);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last)/2;
    }
    if (first > last)
        printf("Not found! %d isn't present in the list.\n", search);
    sclean();
}
void insert(int *n, int *array)
{
    int position,value;
    int c;
    printf("Enter the location where you wish to insert an element\n");
    scanf("%d", &position);

    printf("Enter the value to insert\n");
    scanf("%d", &value);

    for (c = *n - 1; c >= position - 1; c--)
        *(array+c+1)= *(array+c);

    *(array+position-1) = value;

    *n=*n+1;

    show(n,array);
}
void sclean(void)
{
    printf("Enter any key to clean the screen and to go to MENU\n");
    getch();
    system("cls");
    menu();
}
void show(int *n,int *p)
{
    printf("Array elements are :");
    int i=0;
    for( i=0; i<*n; i++)
    {
        printf("%d ",*(p+i));
    }
    printf("\n");
    sclean();
}
void intro (void)
{
    printf("======Welcome======\n");
    printf("Press any key to start ......\n");
    getch();

}
void menu(void)
{
    printf("\n=====Main menu======\n");
    printf("# 0....Exit\n");
    printf("# 1....View all elements\n");
    printf("# 2....Insert new element\n");
    printf("# 3....Search an element\n");
    printf("# 4....Delete an element\n");
    printf("# 5....Sort elements in ascending order\n");
    printf("# 6....Sort elements in descending order\n");
    printf("# 7....Find memory location of an element\n");
    printf("##Enter your Choice.......\n");
}
int main()
{
    intro();
    int loc, search,select,i,*ptr,*p,n;

    printf("\n\nEnter the size of the array:");
    scanf("%d",&n);
    ptr=(int*) malloc(n*sizeof(int ));
    if(ptr==NULL)
    {
        printf("There is not enough space :(\n");
        exit(0);
    }
    p=ptr;
    printf("Enter the %d elements of the array: \n",n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",ptr);
        ptr++;
    }
    printf("\nElements are successfully stored :)\a\n");

    sclean();
    while(scanf("%d",&select))
    {


        switch(select)
        {
        case 0:
            system("cls");
            printf("The program is closed :(\n\a ");
            return 0;
            break;
        case 1:
            show(&n,p);
            break;

        case 2:
            insert(&n,p);
            break;

        case 3:
            binary(&n,p);
            break;

        case 4:
            rem(&n,p);
            break;

        case 5:
            bubblesort1(&n,p);
            printf("After sorting Ascending order:");
            show(&n,p);
            break;

        case 6:
            bubblesort2(&n,p);
            break;

        case 7:
            location(p,&n);
            break;

        default:
            ///it is for if any number except 0-7 is entered
            //system("cls");
            printf("You have entered an invalid character :(\n ");
            sclean();
            break;
        }


    }
free(ptr);

    return 0;
}
