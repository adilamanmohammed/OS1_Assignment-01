/*
Author Name: Adil Aman Mohammed
o Email: Adil.mohammed@okstate.edu
o Date:10/24/2022
o Program Description: 

*/

//Declaration of required library
#include <stdio.h>
#include<stdlib.h>








//main function
int main(int argc, char* argv[])
{
    //declaration of variables
    int n,i;
    int fcount=argc-1;
    
    //asking the user to the count of books
    printf("Enter the count of books : \n");
    scanf("%d",&n);
    
    //taking input of N number of book names
    
    char booknames[n][20];
    for (i = 0; i < n; i++)
    {
        scanf("%s", booknames[i]);
    }
    
    
    //remove the below debugging code in the end
    printf("the list of books:\n");
    for (i = 0; i < n; i++)
        printf("%d.%s \n", i+1,  booknames[i]);
  
    //remove the above debug print in the end!!!!!!!!!!!!!!!!!!!!
    
    //creating the child treads according to the count of files
    for(i=0;i<fcount;i++)
    {
        
        
        
    }
    
    
    printf("Hello World");
    
    return 0;
}
