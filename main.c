/*
Author Name: Adil Aman Mohammed
o Email: Adil.mohammed@okstate.edu
o Date:10/24/2022
o Program Description: 

*/

//Declaration of required library

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#define MAX 100
#define MAX_LENGTH 10000
int k=0,n;
char booknames[MAX][255];
int is_not_present[MAX];


void* searchbook(void* fname){
FILE *fp;
printf("File Open :%s \n", fname);
   char line[MAX_LENGTH];
   fp = fopen(fname, "r");
   if(fp == NULL){
       printf("Cannot open file");
   }
   char thisLine[12000];
   while (fgets(line, MAX_LENGTH , fp) != NULL){
//   printf("%s",line);
    strcpy(thisLine, line);
    char title[300];
    char genre[20];
    char rating[10];
    char summary[1000];
    char *token;
    int col = 0;
    token = strtok(line, ",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");
    strcpy(title,token);
    token = strtok(NULL, ",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");

    // printf(" \n --> %s \n", title);
      for(int i=0;i<n;i++){
        
        if(strcmp(title, booknames[i]) == 0){
            is_not_present[i] = 0;
            printf("\n%s \n",thisLine);
            }
            
        }
      }
    
    close(fp);
    printf("file : %s closed successfully \n", fname);
    
}




//main function
int main(int argc, char* argv[])
{
    //declaration of variables
    int i;
    int fcount=argc-1;
    char s[10];
    
    //asking the user to the count of books
    printf("Enter the count of books : \n");
    scanf("%d",&n);
    fgets(s,10,stdin);
    
    //taking input of N number of book names
    
    
    for (i = 0; i < n; i++)
    {
        scanf("%[^\n]s", booknames[i]);
        fgets(s,10,stdin);
    }
    
    
    //remove the below debugging code in the end
    printf("the list of books:\n");
    for (i = 0; i < fcount; i++)
        printf("%d : %s \n", i+1,  argv[i+1]);
  
    //remove the above debug print in the end!!!!!!!!!!!!!!!!!!!!
    
    //defining a tread array
    pthread_t th[20];
    
    for(int j = 0; j< n;j++){
        is_not_present[j] = 1;
    }
    //creating the child treads according to the count of files
    for(i=0;i<fcount;i++)
    {
        sleep(1);
        if(pthread_create(&th[i],NULL,&searchbook,(void *) argv[i+1])!=0)
        {
            perror("Failed to create thread\n");
            return 1;
        }
        
        printf("Thread %d has started\n",i);
        
    }
    
    for(i=0;i<fcount;i++)
    {
        if(pthread_join(th[i],NULL)!=0)
        {
            return 2;
        }
       
        printf("Thread %d has finished execution successfully\n",i);
         printf("Thread %d Exited \n", i);
    }
    
    for(int j=0;j<n;j++){
        if(is_not_present[j] == 1){
            printf("book : %s Not Found! \n", booknames[j]);
        }
    }
    
    return 0;
}
