#include <stdio.h>
#include <stdlib.h>

int *array;
int length = 1000;
int count;

int count1s ()
{
    int i;
    count = 0;

    for (i=0; i<length; i++)
    {
        if (array[i] == 1)
        {
            count++;
        }
    }

    return count;
}

int main(void)
{

    int randArray[length],i;
    for(i=0;i<length;i++)
        randArray[i]=rand()%6;   //Generate number between 0 to 99
    printf("\nElements of the array::");
    for(i=0;i<length;i++)
    {
        printf("\nElement number %d::%d",i+1,randArray[i]);
    }

    array = &randArray;
    printf("\nNumber of 1's is %d", count1s());
}



