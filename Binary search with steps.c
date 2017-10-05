#include <stdio.h>

int BinarySearch(int source[], int start, int stop, int value);

///  this binary search is for ascending sorted array

int main()
{
    /// input area
	int length,i,value; /// define variables
	scanf("%d",&length); /// input array length
	int data[length]; /// define array
	for(i=0;i<length;i++) /// input elements of array
		scanf("%d",&data[i]);
	scanf("%d",&value); /// input search data

	/// function call area
	int index=BinarySearch(data,0,length,value); /// get index of value

	/// output area
	if(index!=-1) /// check whether found or not
		printf("Found at %d (index start from 0)\n", index); /// for found
	else
		printf("Not Found\n"); /// for not found
}

int BinarySearch(int source[], int start, int stop, int value)
{
	int steps=1,i; /// define variables
	while(start<=stop) /// condition for search
	{
		int mid=start+(stop-start)/2; /// define mid point

		printf("Step %d : ",steps);  /// print array's portion or shrink array
		for(i=start;i<stop;i++)
            printf("%d ", source[i]);
        printf("\n");

		if(source[mid]==value) /// for found the value at mid point
			return mid; /// return
		else if(source[mid]<value)
			start=mid+1,steps++; /// for descending order {stop=mid-1,steps++};
		else
			stop=mid-1,steps++; /// for descending order {start=mid+1,steps++;}
        /// just swap these two conditions for descending order
	}
	return-1; /// return -1 for not found
}
