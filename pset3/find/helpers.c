/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n<0)
    return false;
    int start=0;
    int end=n-1;
    while(end>=start)
    {
        int mid=(start+end)/2;
        if(values[mid]==value)
        return true;
        else if(values[mid]>value)
        end=mid-1;
        else
        start=mid+1;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int pos,t;
    // TODO: implement a sorting algorithm
    for(int i=0;i<n-1;i++)
    {
        pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(values[j]<values[pos])
            pos=j;
        }
        t=values[i];
        values[i]=values[pos];
        values[pos]=t;
        
    }
    return;
}
