#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include<string.h>
#include "md5.h"
MD5_CTX mdContext; 

int main()
{
	/* 4294967295 = 0xFFFFFFFF */
unsigned int a=4294967295,i;
int infile,n,output,rollingKey,buf,input;
int *temp, result;   
char* plainText;
int char1,char2,char3,char4;
int isProper=0;

for(i=0;i<a;i++)
{
	printf("\r Brute Forcing: %x",i);
	isProper=1;
	infile = open ("text-encr", O_RDONLY);
	if (infile<0) { printf("input open error\n"); exit(0); }
	read(infile, &input, 4);
	rollingKey=i;
	while ((n = read(infile, &buf, 4))> 0) 
	{

		buf = buf ^ rollingKey; 		//doing the reverse of encrypt
		MD5Init(&mdContext);
		MD5Update(&mdContext, &rollingKey, 4);
		MD5Final(&mdContext);
		temp = (int *) &mdContext.digest[12]; 
		result = *temp; 			//result is 32 bits of 			MD5 of key
		rollingKey = rollingKey ^ result; // new key
		plainText=&buf;
		char1= plainText[0];
		char2=plainText[1];
		char3=plainText[2];
		char4=plainText[3];
	
		if(!((char1>=0 && char1<=255) && (char2>=0 && char2<=255) && 			(char3>=0 & char3<=255) && (char4>=0 && char4<=255)))
		//checking the ascii range
		{
		isProper=0;
		break;
		}
	      buf = 0;  // repeat, keep track of output size in size.
	};

	close(infile);
	if(isProper==1)
		{
		printf("Success %x",i);
		break;
		}  
	}

}

