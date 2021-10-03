#include<iostream>
#define R 4
#define C 5
using namespace std;

// Node to represent row - list

class value_list
{public:
    int column_index;
    int value;
    value_list *next;
};
class row_list
{public:
    int row_number;
    row_list *link_down;
    value_list *link_right;
};

void create_value_node(int data, int j, row_list **z)
{
     value_list *temp, *d;
    temp = new value_list();
    temp->column_index = j+1;
    temp->value = data;
    temp->next = NULL;
    if ((*z)->link_right==NULL)
        (*z)->link_right = temp;
    else
    {   d = (*z)->link_right;
        while(d->next != NULL)
            d = d->next;
        d->next = temp;
    }
}

void create_row_list(row_list **start, int row,int column, int Sparse_Matrix[R][C])
{
   for (int i = 0; i < row; i++)
    {
         row_list *z, *r;
        z = new row_list;
        z->row_number = i+1;
        z->link_down = NULL;
        z->link_right = NULL;
        if (i==0)
            *start = z;
        else
        {
            r = *start;
            while (r->link_down != NULL)
                r = r->link_down;
            r->link_down = z;
        }
        for (int j = 0; j < 5; j++)
        {
            if (Sparse_Matrix[i][j] != 0)
            {
                create_value_node(Sparse_Matrix[i][j], j, &z);
            }
        }
    }
}

void print_LIL( row_list *start, int size1)
{
    int arr[size1],max1=0,ind,i=0;
    for(int j=0;j<size1;j++)
    {
        arr[j]=0;
    }
     row_list *r;
     value_list *z;
    r = start;
    while (r != NULL)
    {
        if (r->link_right != NULL)
        {
           cout<<"\nrow= "<< r->row_number;
            z = r->link_right;
            while (z != NULL)
            {
               cout<<"\n column= "<< z->column_index<<" value= "<<z->value;
                z = z->next;
                arr[i]++;
                if(max1<arr[i])
                {
                    max1=arr[i];
                    ind=r->row_number;
                }

            }
        }
        i++;
        r = r->link_down;
    }
              



}
int main()
{
    int Sparse_Matrix[R][C] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 1 , 0 , 0 },
        {0 , 2 , 6 , 9 , 10 }
    };
    row_list* start = NULL;
    create_row_list(&start, R, C, Sparse_Matrix);
     print_LIL(start,R);

    return 0;
}
