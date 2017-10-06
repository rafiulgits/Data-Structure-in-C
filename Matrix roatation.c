#include<stdio.h>

int main()
{
    int i,j,len,newI,newJ;
    scanf("%d",&len);
    int data[len][len];
    int update[len][len];

    /// input area
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
            scanf("%d",&data[i][j]);
    }
    printf("\n");
    /// :::::::::::::::::::::::::::::::::::::::::::::///
    /// ::::::::::::rotation precess area::::::::::::///
    /// :::::::::::::::::::::::::::::::::::::::::::::///

    /// 90 degree right
    /*
    for(i=0; i<len; i++)
    {
        for(j=0, newI=len-1; j<len; j++, newI--)
            update[i][j]=data[newI][i];
    }
    ///********inter-exchange of these two index can rotate the array to left******
    */

    /// 90 degree left
    /*
    for(i=0,newJ=len-1; i<len; i++,newJ--)
    {
        for(j=0;j<len;j++)
            update[i][j]=data[j][newJ];
    }
    ///********inter-exchange of these two index can rotate the array to right *****
    */

    /// 180 degree
    /*
    for(i=0,newI=len-1; i<len; i++,newI--)
    {
        for(j=0, newJ=len-1; j<len; j++, newJ--)
            update[i][j]=data[newI][newJ];
    }
    ///********180 degree rotation is same for right and left
    */

    /// vertical
    /*
    for(i=0;i<len;i++)
    {
        for(j=0, newJ=len-1;j<len;j++,newJ--)
            update[i][j]=data[i][newJ];
    }
    ///********** index inter-exchange has no difference
    */

    /// horizontal (this is like rotate 180 degree)
    /*
    for(i=0,newI=len-1;i<len;i++,newI--)
    {
        for(j=0;j<len;j++)
            update[i][j]=data[newI][j];
    }
    ///********** index inter-exchange has no difference
    */



    ///:::::::::::::::::output of updated array::::::::::::::::///
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
            printf("%d ",update[i][j]);
        printf("\n");
    }

}

