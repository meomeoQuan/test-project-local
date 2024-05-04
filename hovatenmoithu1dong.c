#include<stdio.h>
#include<string.h>

int namespaces( char*fullname)
{
    char*firstName;
    char*middleName;
    char*lastName;
    char*token;
 
    token = strtok(fullname, " ");

    if (token != NULL) {
        firstName = token;
        printf("First name: %s\n", firstName);

        while ((token = strtok(NULL, " ")) != NULL) {
            if (lastName != NULL) {
                middleName = lastName;
            }
            lastName = token;
        }
     if (middleName != NULL) {
            printf("Middle name: %s\n", middleName);
        }
        printf("Last name: %s\n", lastName);
    }
    return 0;
    
}


int main()
{
    char fullname[100];
    printf("enter: ");
    fgets(fullname,sizeof(fullname),stdin);
    namespaces(fullname);
}
