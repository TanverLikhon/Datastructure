///the task
/* Name:Tanver Ahmed
    ID:1702028
    Dept. of CSE*/

#include <iostream>
using namespace std;
#include<conio.h>
#include<bits/stdc++.h>
#include <cstdlib>
void sclean(void);
void show(int *,int *);
void menu(void);
void location(int *, int *);


void location(int *p,int *n)
{
    int loc,k, x,lower_bound=1;

cout<<"Enter index no:\n";
   cin>>k;
    if(k>*n)
    {
   cout<<"The index doesn't exists \n ";

    }
    x=sizeof(int);
    loc=int (p)+x*(k-lower_bound);
    cout<<"The address of the desired index is \a"<<loc<<endl;
    //printf("The address of the desired index is %d\n\a",loc);
    sclean();
}
void bubblesort1(int *n,int *p)
{
    int j, i,n1;
    n1=*n;
    for (i = 0; i < n1; i++)
    {
        for (j = i + 1; j < n1; j++)
        {
            if (*(p+i)> *(p+j))
            {
swap(*(p+i),*(p+j));
            }
        }
    }
}
void bubblesort2(int *n,int *p)
{
    int j, i,n1;
    n1=*n;
    for (i = 0; i < n1; i++)
    {
        for (j = i + 1; j < n1; j++)
        {
            if (*(p+i)< *(p+j))
            {
swap(*(p+i),*(p+j));
            }
        }
    }
    show(n,p);
}
void rem(int *n,int *array)
{
    int ck=0, i,position,c,element;
cout<<"Enter the element you wish to delete element\n";
    cin>>element;
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
        cout<<element<<" Found and deletion is successful "<<endl;
       // printf("\n%d found and deletion successful\n resultant array ",element);
        show(n,array);

    }
    else
    {
      cout<<"Element not found :(\nArray remains the same.";
        show(n,array);
    }

}
void binary(int *n,int *array)
{

    bubblesort1(n,array);
    int search,first,last,middle;
    cout<<"Enter value to find\n";
    cin>>search;

    first = 0;
    last = *n - 1;
    middle = (first+last)/2;

    while (first <= last)
    {
        if (*(array+middle) < search)
            first = middle + 1;
        else if (*(array+middle) == search)
        {
            cout<<search<<" is found at index "<<middle+1<<endl;
           /// printf("%d found at location %d.\n", search, middle+1);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last)/2;
    }
    if (first > last)
        cout<<"Not found!!! "<<search<<" is not present in the list"<<endl;
       /// printf("Not found! %d isn't present in the list.\n", search);
    sclean();
}
void insert(int *n, int *array)
{
    int position,value;
    int c;
    cout<<"Enter the location where you wish to insert an element\n";
    cin>>position;

 cout<<"Enter the value to insert\n"<<endl;
   cin>>value;
    for (c = *n - 1; c >= position - 1; c--)
        *(array+c+1)= *(array+c);

    *(array+position-1) = value;

    *n=*n+1;

    show(n,array);
}
void sclean(void)
{
   cout<<"Enter any key to clean the screen and to go to MENU\n";
    getch();
    system("cls");
    menu();
}
void show(int *n,int *p)
{
 cout<<"Array elements are :";
    int i=0;
    for( i=0; i<*n; i++)
    {
        cout<<*(p+i)<<" ";
        //printf("%d ",*(p+i));
    }
    cout<<endl;
    sclean();
}
void intro (void)
{
    cout<<"=====WELCOME=====\n"<<endl;
    printf("Press any key to proceed ......\a");
    getch();

}
void menu(void)
{
cout<<"\n=====Main menu======\n\a";
cout<<"# 0....Exit\n";
    cout<<"# 1....View all elements\n";
    cout<<"# 2....Insert new element\n";
    cout<<"# 3....Search an element\n";
    cout<<"# 4....Delete an element\n";
     cout<<"# 5....Sort elements in ascending order\n";
     cout<<"# 6....Sort elements in descending order\n";
    cout<<"# 7....Find memory location of an element\n";
     cout<<"\n##Enter your Choice.......\n";
}
int main()
{
    intro();
    int loc, search,select,i,*ptr,*p,n;

    cout<<"\n\nEnter the size of the array:";
cin>>n;
ptr=new int [n];
    //ptr=(int*) malloc(n*sizeof(int ));
    if(ptr==NULL)
    {
       cout<<"There is not enough space :(\n";
        exit(0);
    }
    p=ptr;
   cout<<"Enter the "<<n<<" elements of the array: \n";
    for(i=0; i<n; i++)
    {
        cin>>ptr[i];
        //scanf("%d",ptr);
      //  ptr++;
    }
    cout<<"\nElements are successfully stored :)\a\n";

    sclean();
    while(cin>>select)
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
            cout<<"After sorting Ascending order:";
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
         cout<<"You have entered an invalid character :( \n ";
            sclean();
            break;
        }


    }
delete[]ptr;

    return 0;
}

