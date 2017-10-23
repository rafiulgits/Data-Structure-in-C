#include<stdio.h>
void operations();
int main()
{
    printf("Enter your Stack size : ");
    int length; scanf("%d",&length);
    int data[length+1]={-1};
    int temp_length=0; bool running=true;
    while(running)
    {
        operations();
        printf("Choose your operation : ");
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
                    int newElement; scanf("%d",&newElement);
                    data[temp_length]=newElement;
                    temp_length++;
                    puts("Successfully pushed !");
                }
            } break;
        case 2:
            {
                if(temp_length==0)
                    puts("Sorry, Underflow !");
                else
                {
                    temp_length--;
                    puts("Successfully pop !");
                }
            } break;
        case 3:
            {
                if(temp_length==0)
                    puts("Your Stack is Empty");
                else
                    printf("Your Top element is %d\n",data[temp_length-1]);
            } break;
        case 4:
            {
                if(temp_length==0)
                    puts("Your Stack is Empty");
                else
                {
                    printf("Your Stack : ");
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
    puts("3. Top");
    puts("4. Stack data");
    puts("5. Exit");
}
