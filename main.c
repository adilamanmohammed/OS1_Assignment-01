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
int main()
{
    //declaration of variables
    int N,i;
    char booknames[1000];
    
    
    
    //asking the user to the count of books
    printf("Enter the count of books : \n");
    scanf("%d",&N);
    
    //taking input of N number of book names
    for(i=0;i<N;i++)
    {
        printf("Enter the %d)book name :",i+1);
        scanf("%s",&booknames[i]);
    }
    
    //for debugging the above scanf
    //remove it in the end!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    printf("\n");
    for(i=0;i<N;i++)
    {
        printf("\n%s",booknames[i]);
    }
    printf("\n");
    //remove the above debug print in the end!!!!!!!!!!!!!!!!!!!!
    
    
    
    
    
    printf("Hello World");
    
    return 0;
}
