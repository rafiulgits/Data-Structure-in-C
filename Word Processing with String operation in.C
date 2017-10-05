#include<stdio.h>

/// string operation
int LENGTH(char source[]);
int INDEX(char data[],char source[]);
int OCCURRENCE(char data[],char source[]);
void SUBSTRING(char subdata[], char data[], int start, int length);
void CONCATENATION(char s[], char s1[], char s2[]);

/// word processing
void INSERT(char source[], int pos, char data[]);
void DELETE(char source[], int pos, int length);
void REPLACE(char source[], char pattern1[], char pattern2[]);

/// main function
int main()
{
    /// ::::::::::: code here :::::::::::::::::://

}
/// ////////////////////////
/// function define area //
/// //////////////////////
void INSERT(char source[], int pos, char data[])
{
	int req_length=LENGTH(source)-pos;
	char temp1[1000]; char temp2[1000];
	SUBSTRING(temp1,source,0,pos);
	SUBSTRING(temp2,source,pos,req_length);
	CONCATENATION(source,temp1,data);
	CONCATENATION(source,source,temp2);
}
void DELETE(char source[], int pos, int length)
{
	char temp1[1000]; char temp2[1000];
	int source_length=LENGTH(source)+1;
	SUBSTRING(temp1,source,0,pos);
	SUBSTRING(temp2,source,(length+pos),source_length);
	CONCATENATION(source,temp1,temp2);
}
void REPLACE(char source[], char pattern1[], char pattern2[])
{
	int indexOfPattern1=INDEX(pattern1,source);
	if(indexOfPattern1!=-1)
	{
		int pattern1_length=LENGTH(pattern1);
		DELETE(source,indexOfPattern1,pattern1_length);
		INSERT(source,indexOfPattern1,pattern2);
	}
}
int LENGTH(char source[])
{
    int i;
	for(i=0;;i++)
		if(*(source+i)=='\0')
			return i;
}
int INDEX(char data[],char source[])
{
    int i,j;
	int source_length=LENGTH(source);
	int data_length=LENGTH(data);
	for(i=0;i<source_length;i++)
	{
		for(j=0;j<data_length;j++)
		{
			if(source[i+j]!=data[j])
				break;
			if(j==data_length-1) return i;
		}
	}
	return -1;
}
void SUBSTRING(char subdata[], char data[], int start, int length)
{
    int i,j;
	for(i=0,j=start;j<(start+length);i++,j++)
		subdata[i]=data[j];
	subdata[length]='\0';
}
void CONCATENATION(char s[], char s1[], char s2[])
{
    int i,j;
	int s1_length=LENGTH(s1);
	int s2_length=LENGTH(s2);
	for(i=0;i<s1_length;i++)
		s[i]=s1[i];
	for(i=0,j=s1_length;i<s2_length;i++,j++)
		s[j]=s2[i];
	int s_length=s1_length+s2_length;
	s[s_length]='\0';
}
int OCCURRENCE(char data[],char source[])
{
    int i,j;
	int Counter=0;
	int source_length=LENGTH(source);
	int data_length=LENGTH(data);
	for(i=0;i<source_length;i++)
	{
		for(j=0;j<data_length;j++)
		{
			if(source[i+j]!=data[j])
				break;
			if(j==data_length-1)
            {
                i+=data_length-1;
				Counter++;
            }
		}
	}
	return Counter;
}
