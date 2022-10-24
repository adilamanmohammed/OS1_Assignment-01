/*
Author Name: Adil Aman Mohammed
o Email: Adil.mohammed@okstate.edu
o Date:10/24/2022
o Program Description: 

*/

//Declaration of required library
#include<stdio.h>/*
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
int k=0,n;
char booknames[MAX][255];


void* searchbook(void* fname)
{
    
    printf("%d is good %s \n",k, fname);
    printf("%s\n",booknames[k]);
    k=k+1;
    return 0;
    
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
    
    //creating the child treads according to the count of files
    for(i=0;i<fcount;i++)
    {
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
        
    }
    
    
    
    printf("Hello World");
    
    return 0;
}
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
int k=0;



void* searchbook()
{
    
    printf("%d is good\n",k);
    k=k+1;
    return 0;
    
}




//main function
int main(int argc, char* argv[])
{
    //declaration of variables
    int n,i;
    int fcount=argc-1;
    char s[10];
    
    //asking the user to the count of books
    printf("Enter the count of books : \n");
    scanf("%d",&n);
    fgets(s,10,stdin);
    
    //taking input of N number of book names
    
    char booknames[n][255];
    for (i = 0; i < n; i++)
    {
        scanf("%[^\n]s", booknames[i]);
        fgets(s,10,stdin);
    }
    
    
    //remove the below debugging code in the end
    printf("the list of books:\n");
    for (i = 0; i < n; i++)
        printf("%d : %s \n", i+1,  booknames[i]);
  
    //remove the above debug print in the end!!!!!!!!!!!!!!!!!!!!
    
    //defining a tread array
    pthread_t th[20];
    
    //creating the child treads according to the count of files
    for(i=0;i<fcount;i++)
    {
        if(pthread_create(&th[i],NULL,&searchbook,NULL)!=0)
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
        
    }
    
    
    
    printf("Hello World");
    
    return 0;
}
