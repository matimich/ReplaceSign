#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "ReplaceSign.h"

#define OLD_FILE_PATH "text.txt"
#define NEW_FILE_PATH "new.txt"

void ReplaceSign(void)
{

    char sign;      //remove
    char sign_2;    //new

    printf("Enter  new-old sign:");
    scanf("%c-%c",&sign_2,&sign);



    FILE *file;
    FILE *another;

    char array[100];
    char *point;


    if((file = fopen (OLD_FILE_PATH,"r"))==NULL)       //opening core file
    {
        printf ("Error, please try again");
        exit(EXIT_FAILURE);
    }

    if((another = fopen (NEW_FILE_PATH,"w"))==NULL)    //opening file where changed tekst is going to be saved
    {
        printf ("Error, please try again");
        exit(EXIT_FAILURE);
    }

    while(fgets(array,100,file) != NULL) //changing signs
    {


        if (strchr(array,sign) != NULL)
        {
            do
            {
                point = strchr(array,sign);
                *point = sign_2;


            }while(strchr(array,sign) != NULL);

            fputs(array,another);

        }
        else
        {   fputs(array,another);

        }

    }
    fclose(file);
    fclose(another);
}
