#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
int num =0;
char word[2000];
char *string[50];

FILE *in_file = fopen("student.txt", "r");
//FILE *out_file = fopen("output.txt", "w");

if (in_file == NULL)
{
    printf("Error file missing\n");
    exit(-1);
}

while(student[0]!= '0')
{
    printf("please enter a word(enter 0 to end)\n");
    scanf("%s", student);


    while(!feof(in_file))
    {
        fscanf(in_file,"%s", string);
        if(!strcmp(string, student))==0//if match found
        num++;
    }
    printf("we found the word %s in the file %d times\n",word,num );
    num = 0;
}

return 0;
 } 
