#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void import(int size, int *a) {
    for (int i = 0; i < size; i++) {
        printf("A[%d]= ", i);
        scanf("%d", a + i);
    }
}

void export(int size, int *a) {
    for (int i = 0; i < size; i++) {
        printf("%5d", *(a + i));
    }
}
int Find(int find, int *a, int size)
{
      for ( int i =0; i<= size - 1; i++) if(a[i] == find) return i;
      return -1;
}
void ascending(int size, int *a)
{
  for(int i = 0; i<= size - 1; i++)
  {
      for( int j = size - 1; j > i; j--)
      {
          if(a[j] < a[j-1])
          {
              int temp = a[j];
              a[j] = a[j - 1];
              a[j - 1] = temp;
          }
      }
  }
}
void descending(int size, int *a)
{
  for(int i = 0; i<= size - 1; i++)
  {
      for( int j = size - 1; j > i; j--)
      {
          if(a[j] > a[j-1])
          {
              int temp = a[j];
              a[j] = a[j - 1];
              a[j - 1] = temp;
          }
      }
  }
}
void removeFirstOccurrence(int *a, int *size) {
    for (int i = 0; i < *size; i++) {
        if (a[i] == a[0]) {
            for (int j = i; j < *size - 1; j++) {
                a[j] = a[j + 1];
            }
            (*size)--;

}
}
}
void removevalueindex(int *a, int*size,int index, int value)
{
    
}
void removeAllOccurrences(int *a, int *size, int value) {
    int newSize = 0;
    for (int i = 0; i < *size; i++) {
        if (a[i] != value) {
            a[newSize] = a[i];
            newSize++;
        }
    }
    *size = newSize;// size --
}

int menu() {
    int choice;
    printf("\n==================MENU================\n");
    printf("1. Add value\n");
    printf("2. Search a value\n");
    printf("3. Remove the first existence of the value\n");
    printf("4. Remove all existence of the value\n");
    printf("5.remove value index\n");
    printf("6. Print out the array\n");
    printf("7. Sort the array in ascending order\n");
    printf("8. Sort the array in descending order\n");
    printf("9. QUIT\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    int size;
     int newvalue, index;
     int removeAllValue;
     int x;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int *a = (int *)malloc(size * sizeof(int));

    if (a == NULL) {
        printf("Can not allocate memory");
        return 1;
    }

    import(size, a);
    export(size, a);
    printf("\n");

    do {
        choice = menu();
        switch (choice) {
            case 1:
                
                printf("Enter the value you want to add: ");
                scanf("%d", &newvalue);

                do {
                    printf("Enter index where you want to add the value: ");
                    scanf("%d", &index);
                } while (index < 0 || index > size);

                a = (int *)realloc(a, (size + 1) * sizeof(int));

                if (a == NULL) {
                    printf("Failed to reallocate memory!");
                    return 1;
                }

                for (int i = size; i > index; i--) {
                    a[i] = a[i - 1];
                }
                a[index] = newvalue;
                size++;
                printf("Updated Array: ");
                export(size, a);
                break;
            case 2:
            
            printf("The value you want to search: ");
            scanf("%d",&x);
            int check = Find(x,a,size);
            if(check >= 0) 
            printf("\n Have found %d in array !",x);
            else printf("\n Not found %d in array ! ",x);
            break;
            case 3:
            printf("Array after remove first value: ");
           removeFirstOccurrence(a, &size);
            export(size,a);
            break;
            case 4:
        
                printf("Enter the value you want to remove all occurrences of: ");
                scanf("%d", &removeAllValue);
                removeAllOccurrences(a, &size, removeAllValue);
                printf("Updated Array: ");
                export(size, a);
                break;
            case 5:
                break;
            case 6:
             printf("Your array: ");
                export(size, a);
                break;
            case 7:
           printf("Array after ascending arrangement: ");
            ascending(size,a);
            export(size,a);
            break;
            case 8:
            printf("Array after descending arrangement: ");
            descending(size,a);
            export(size,a);
            break;
            case 9:
                printf("EXIT\n");
                free(a);
                return 0;

            default:
                printf("Please enter a valid option!\n");
                break;
        }
    } while (true);
}





