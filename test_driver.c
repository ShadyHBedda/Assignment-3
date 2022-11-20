#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


int length = 100;
int count;

int count1s (int *arrayInput)
{
    int i;
    count = 0;

    for (i=0; i<length; i++)
    {
        if (arrayInput[i] == 1)
        {
            count++;
        }
    }

    return count;
}


int race_count(int *arrayInput, int numberOfThreads) {
    int T[numberOfThreads];
    for (int i = 0; i < numberOfThreads; i++) {
        T[i] = 0;
    }
    omp_set_num_threads(numberOfThreads);
    int parallel_count = 0;
    #pragma omp parallel
    {
        int i;
        #pragma omp for
        for (i=0; i<length; i++)
        {
            if (arrayInput[i] == 1)
            {
                parallel_count++;
                T[omp_get_thread_num()]++;
            }
        }
    }

    for (int i = 0; i < numberOfThreads; i++) {
        printf("\nNumber of 1's found by Thread %d is %d", i, T[i]);
    }
    return parallel_count;
};



int main(void)
{
    srand(time(0));
    int randArray[length],i;
    for(i=0;i<length;i++)
        randArray[i]=rand()%6;   //Generate number between 0 and 5
    /*
    printf("\nElements of the array::");
    for(i=0;i<length;i++)
    {
        printf("\nElement number %d::%d",i+1,randArray[i]);
    }
    */

    int *array = &randArray;
    printf("\nNumber of 1's is %d", count1s(array));
    printf("\nNumber of 1's found by race_count is %d", race_count(array, 10));

}




