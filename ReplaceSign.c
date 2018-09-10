#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ReplaceSign.h"

void ReplaceSign(void)
{

    char sign;      //remove
    char sign_2;    //new

    printf("\n Enter a new/old sign:\n");     //inputting a new and an old sign
    scanf("%c-%c",&sign_2,&sign);



    FILE *file;
    FILE *another;

    char array[100];
    char *point;


    if((file = fopen (OLD_FILE_PATH,"r"))==NULL)       //opening a core file
    {
        printf ("\nError, the file not found, please try again");
        exit(EXIT_FAILURE);
    }

    if((another = fopen (NEW_FILE_PATH,"w"))==NULL)    //opening file where a changed tekst is going to be saved
    {
        printf ("\nError, the file not found, please try again");
        exit(EXIT_FAILURE);
    }

    while(fgets(array,100,file) != NULL) //extracting data from a file
    {

        if (strchr(array,sign) != NULL) //looking for common signs
        {
            do
            {
                point = strchr(array,sign); //changing signs
                *point = sign_2;


            }while(strchr(array,sign) != NULL);

            fputs(array,another);   //saving changed strings

        }
        else
        {
            fputs(array,another);   //saving unchanged strings
        }

    }
    fclose(file);
    fclose(another);
}
