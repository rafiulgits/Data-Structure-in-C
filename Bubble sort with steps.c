#include <stdio.h>
void BubbleSort(int source[], int length);
int main()
{
	int length,i;
	scanf("%d",&length); /// scan length
	int data[length]; /// define array
	for(i=0;i<length;i++)
		scanf("%d",&data[i]);
	BubbleSort(data,length); /// call for sort

	/// output area
	printf("\nSorted array : ");
	/// print values
	for(i=0;i<length;i++)
		printf("%d ",data[i]);

    printf("\n");


}
void BubbleSort(int source[], int length)
{
	int Change_count=1;
	int Check_count=0;
	int i,j,k;
	for(i=0;i<length-1;i++)
	{
		for(j=i;j<length;j++)
		{
		    Check_count++;
			if(source[i]>source[j]) /// make ascending order
			{
				int temp=source[i];
				source[i]=source[j];
				source[j]=temp;
				/// after change print new array
				printf("Step %d : ", Change_count);
				for(k=0;k<length;k++)
					printf("%d ",source[k]);
				printf("\n");
				Change_count++; // increase value for next
			}
		}
	}
	printf("Total Check : %d\n",Check_count);
}
