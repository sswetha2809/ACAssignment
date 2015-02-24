#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include<string.h>
#include "md5.h"

MD5_CTX mdContext; 

int main()
{
	unsigned int a=4294967295,i;
	int infile,n,output,input1, input2,input3,rollingKey;
	int *temp, result;   
	char* plainText;
	infile = open ("output", O_RDONLY);
	if (infile<0) { printf("input open error\n"); exit(0); }
  
	read(infile, &input1, 4);
	read(infile, &input2, 4);
	read(infile, &input3, 4);
  
	 for(i=0;i>=a;i++)
	 {
		rollingKey=i;
		printf("\r Brute Forcing: %x",i);
		output = input2 ^ rollingKey; // doing the reverse of encrypt
		plainText=&output;;
	
		if(plainText[0]=='%' && (plainText[1])=='P' && (plainText[2])=='D' &&	(plainText[3])=='F' ) 	      // common tag for all pdf files 
 	
		// if(plainText[0]=='/211' && (plainText[1])=='P' && (plainText[2])=='N' && (plainText[3])=='G' ) 	      // common tag for all png files 

		{
		printf("\nSuccess!!! Key Found-------> %x",i);
		break;
		}

	 }

 }
