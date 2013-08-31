/* Program to Encrypt and Decrypt the contents of a file*/

/*Wipro Technologies*/

#include <stdio.h>

#define ENCRYPTION_FORMULA(Byte)  (int) Byte + 35
#define DECRYPTION_FORMULA(Byte)  (int) Byte - 35

int Encrypt(char*  FILENAME, char* NEW_FILENAME)
{
	FILE *inFile;
	FILE *outFile;

	char Byte=1;
	char newByte=1;



	inFile = fopen(FILENAME,"rb");
	outFile = fopen(NEW_FILENAME, "w");

	if(inFile==NULL)
	{
		printf("Error: Can't Open Source File");
		return -1;
	}

	if(outFile==NULL)
      {
		printf("Error: Can't open Destination File.");
		return -1;
	}
	else
	{
        printf(".");
		while(Byte!=EOF)
		{
		    Byte=fgetc(inFile);
            newByte=ENCRYPTION_FORMULA(Byte);
            fputc(newByte,outFile);
        }
		printf("End of File");
		fclose(inFile);
		fclose(outFile);
	}
	return 1;
}

int Decrypt (char* FILENAME, char* NEW_FILENAME)
{
	FILE *inFile;
	FILE *outFile;

	char Byte=1;
	char newByte=1;

	inFile = fopen(FILENAME,"rb");
	outFile = fopen(NEW_FILENAME, "w");

	if(inFile==NULL)
	{
       	printf("Error: Can't Open Source File");
		return -1;
	}

	if(outFile==NULL)
	{
		printf("Error: Can't open Destination File.");
		return -1;
	}
	else
	{   printf(".");
		while(Byte != EOF)
		{

				Byte=fgetc(inFile);
				newByte=DECRYPTION_FORMULA(Byte);
				fputc(newByte,outFile);

        }
        printf("End of File");
		fclose(inFile);
		fclose(outFile);
	}
	return 1;
}

int main()
{
	char encFile[200];
	char newencFile[200];
	char decFile[200];
	char newdecFile[200];

	int choice;

	printf("Enter any one option");
	printf(" 1. to Encrypt");
	printf(" 2. to Decrypt");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
				printf("Enter the Source Filename:  ");
				scanf("%s",encFile);
				printf("Enter the Destination Filename:   ");
				scanf("%s",newencFile);
				Encrypt(encFile, newencFile);
				break;
		case 2:
				printf("Enter the Source Filename:   ");
				scanf("%s",decFile);
				printf("Enter the Destination Filename:   ");
				scanf("%s",newdecFile);
				Decrypt(decFile, newdecFile);
				break;
		default:
				printf("Wrong option entered");
				break;
	}

	return 0;
}
