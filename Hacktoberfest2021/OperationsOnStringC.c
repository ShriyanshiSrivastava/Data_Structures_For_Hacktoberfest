#include<stdio.h>
#include<string.h>
int main(){
    char String1[50];
    char String2[50];
    int ch;
    printf("Enter String1: ");
    scanf("%s", String1);
    printf("Enter String2: ");
    scanf("%s", String2);
    printf("\nMenu:\n1.Concatenate Strings\n2.Compare Strings\n3.Calculate length of strings");
	printf("\nEnter your choice:");
	scanf("%d", &ch);
	switch(ch)
	{
	    case 1:strcat(String1, String2);
	    printf("Answer= %s\n", String1);
	    break;
	    int i;
	    case 2: i = strcmp(String1, String2);
	    if(i=0){
	        printf("Strings are same");
	    }
	    else{
	       printf("Strings are not the same");
	    }
	    break;
	    int k,l;
	    case 3:k = strlen(String1);
	           l = strlen(String2);
	           printf("length of %s = %d\n", String1, k); 
               printf("length of %s = %d\n", String2, l);
        break;
	 
	    default: 
	    {
            printf("Invalid choice!!!!");
            break;
        }
    return 0;
}
}