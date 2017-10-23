#include<stdio.h>
void operations();
int main()
{
    printf("Enter your Queue length : ");
    int length; scanf("%d",&length);
    int data[length+2];
    int temp_length=0; bool running=true;
    while(running)
    {
        operations();
        printf("Enter your operation : ");
        int chooser; scanf("%d",&chooser);
        switch(chooser)
        {
        case 1:
            {
                if(temp_length==length)
                    puts("Sorry, Overflow !");
                else
                {
                    printf("Enter your new element : ");
                    int newValue; scanf("%d",&newValue);
                    data[temp_length]=newValue;
                    temp_length++;
                }

            } break;
        case 2:
            {
                if(temp_length==0)
                    puts("Sorry, Underflow !");
                else
                {
                    int i,j;
                    {
                        for(i=0,j=i+1;i<temp_length;i++,j++)
                            data[i]=data[j];
                        temp_length--;
                        puts("Successfully pop !");
                    }
                }
            } break;
        case 3:
            {
                if(temp_length==0)
                    puts("Sorry, your Queue is empty !");
                else
                    printf("Your Front value is : %d\n",data[0]);
            } break;
        case 4:
            {
                if(temp_length==0)
                    puts("Sorry, your Queue is empty !");
                else
                {
                    printf("Your Queue is : ");
                    int i;
                    for(i=0;i<temp_length;i++)
                        printf("%d ",data[i]);
                    puts("");
                }
            } break;
        case 5:
            {
                running=false;
            } break;
        }
    }
}
void operations()
{
    puts("\nSelect your operation :");
    puts("1. Push");
    puts("2. Pop");
    puts("3. Front");
    puts("4. Queue data");
    puts("5. Exit");
}
