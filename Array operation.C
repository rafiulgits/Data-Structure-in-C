#include<stdio.h>

void INSERT(int data[], int length, int pos, int value);
void DELETE(int data[], int length, int pos);
int LENGTH(int source[]);

int main()
{
	int source[1000]={'\0'}; /// predefine array with null value

    /// Insert
    /*
    int len,i,index,Value; /// define variables
    scanf("%d",&len); /// input length of array;
    for(i=0;i<len;i++)
        scanf("%d",&source[i]); /// input array's elements
    scanf("%d %d",&index,&Value); /// input position and value
    INSERT(source,len,index,Value); /// call Insert function
    len=LENGTH(source); /// new length of array
    for(i=0;i<len;i++)
        printf("%d ",source[i]); /// print new modify array
    */

    /// Delete
    /*
    int len,i,index; /// define variables
    scanf("%d",&len); ///  input length of array;
    for(i=0;i<len;i++)
        scanf("%d",&source[i]); /// input array's elements
    scanf("%d",&index); /// input position
    DELETE(source,len,index); /// call Delete function
    len=LENGTH(source); /// new length of array
    for(i=0;i<len;i++)
        printf("%d ",source[i]); /// print new modify array
    */
}

/// function define area
void INSERT(int data[], int length, int pos, int value)
{
    int i,j;
    for(i=length+1,j=length;i>=pos;i--,j--)
        *(data+i)=*(data+j);
    *(data+pos-1)=value;
    *(data+length+1)='\0';
}
void DELETE(int data[], int length, int pos)
{
    int i,j;
    for(i=pos,j=pos-1;i<=length;i++,j++)
        *(data+j)=*(data+i);
    *(data+length-1)='\0';
}
int LENGTH(int source[])
{
    int i;
    for(i=0;;i++)
        if(*(source+i)=='\0')
            return i;
}
