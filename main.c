/* main v9*/
// outra1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "cartesian_tree.h"

#include <stdio.h> // for printf
#include <stdlib.h> // for calloc, malloc and free
#include <string.h> // for strcmp

// using struct to package all information into a single variable
typedef struct
{
    char **list;
    int length;
} string_list;

// if you are planning on using several lists, it's better to create an init function
void init(string_list *list)
{
    list->list = calloc(1, sizeof(char *));
    list->length = 0;
}

/*void convert(pNODE T, string_list *list) // converte char em long.
{
    long numero;
    
    for (int i = 0; i < list->length; i++){
    char * my_char = list->list[i];
    numero = strtol(my_char, NULL, 10);
    insert(T, numero, NULL);
    }
}*/

void append_item(string_list *list, char *string) // note that I am using "string_list *" instead of just "string_list".
{
    // it is okay to use a fixed-sized array here because it is a temporary array
    char *temp_array[list->length + 1]; // + 1 is for a new element

    // adding the list->list elements to the temp_array
    for (int i = 0; i < list->length; i++)
    {
        temp_array[i] = list->list[i];
    }

    // adding the new element to the temp_array
    temp_array[list->length] = string; // 0 is the first number, that's why "list->length" instead of "list->length + 1"

    // freeing the list->list (it should be allocated to make this function work)
    free(list->list);

    // allocating memory for list->list
    list->list = calloc(list->length + 1, sizeof(char *)); // I am using calloc instead of malloc here because it just makes the code cleaner, apart from that there is no difference between them

    // adding elements from temp_array to list->list
    for (int i = 0; i < list->length + 1; i++)
    {
        list->list[i] = temp_array[i];
    }

    list->length++;
}

void remove_item(string_list *list, char *string) // note that I am using "string_list *" instead of just "string_list".
{
    // it is okay to use a fixed-sized array here because it is a temporary array
    char *temp_array[list->length]; // without "-1" because it is uncertain if the list includes the element
    // a variable for tracking, whether or not the list includes the element; set to "false" by default
    int found = 0;

    // adding all elements from list->list to temp_array, except the one that should be removed
    for (int i = 0; i < list->length; i++)
    {
        // if the element is not the one that should be removed
        if (strcmp(list->list[i], string) != 0)
        {
            temp_array[i] = list->list[i];
        }
        else
        {
            found = 1;
        }
    }

    // if not found there is no point of doing the following
    if (found)
    {
        // freeing the list->list (it should be allocated to make this function work)
        free(list->list);

        // allocating memory for list->list
        list->list = calloc(list->length - 1, sizeof(char *)); // I am using calloc instead of malloc here because it just makes the code cleaner, apart from that there is no difference between them

        // adding elements from temp_array to list->list
        for (int i = 0; i < list->length - 1; i++)
        {
            list->list[i] = temp_array[i];
        }

        list->length--;
    }
}

int main() {
/*FILE *fpt, *fpt_add, *fpt_remove;*/

int randomized_int = 0;
char * my_char = "0";
long numero = 0;
double float_seconds = 0;
clock_t start = 0, end = 0;

pNODE T = construct_tree();

string_list list;

// note that I am passing to the functions the pointer to the list, not the list itself
init(&list);


append_item(&list, "1");
append_item(&list, "2");
append_item(&list, "3");
append_item(&list, "4");
append_item(&list, "5");


/*Adiciona a Arvore*/
for (int i = 0; i < list.length; i++){
    printf("----%d-----\n",i);
    my_char = list.list[i];
    numero = strtol(my_char, NULL, 10);
    start = clock();
    if(insert(T, numero, NULL)){
        end = clock();
        float_seconds = ((float)(end - start)) / CLOCKS_PER_SEC;
        printf("%s \t %f \t Encontrado\n",my_char,float_seconds);
    }  else{
        end = clock();
        float_seconds = ((float)(end - start)) / CLOCKS_PER_SEC;
        printf("%s \t %f \t Sem Correspondencia\n",my_char,float_seconds);
    }
    
}

    
/*Lookup*/
for (int i = 0; i < list.length; i++){
    my_char = list.list[i];
    numero = strtol(my_char, NULL, 10);
    
    start = clock();
    find(T, numero);
    end = clock();
    
    double float_seconds = ((float)(end - start)) / CLOCKS_PER_SEC;
    if(find(T, numero)){
        printf("%s \t %f \t Encontrado\n", my_char,float_seconds);
    }  else {
        printf("%s \t %f \t Sem Correspondencia\n",my_char,float_seconds);
}

}

/*Exclui*/

for (int i = 0; i < list.length; i++){
    randomized_int = rand() % list.length;
    printf("========");
    printf("%d \n",i);
    my_char = list.list[randomized_int];
    numero = strtol(my_char, NULL, 10);
    remove_item(&list, my_char);
    printf("%d \n",randomized_int);
    start = clock();
    if(!erase(T, numero)){
    end = clock();
    float_seconds = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("%s \t %f \t Encontrado\n",my_char,float_seconds);
    } else{
    end = clock();
    float_seconds = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("%s \t %f \t Sem Correspondencia\n",my_char,float_seconds);
}

}


free(list.list);
destruct_tree(T);

}


/*for (int i = 0; i < list.length; i++){
    fprintf(fpt, "%s\n", list.list[i]);
}

printf("----------------\n");

remove_item(&list, "another string");

for (int i = 0; i < list.length; i++){
    fprintf(fpt, "%s\n", list.list[i]);
}
    

    // don't forget to free the list after usage
free(list.list);

    return 0;
}
    
  
/*  char buf[10];
  pNODE T = construct_tree();
  long key;

  printf("Usage:\nadd <key>\nremove <key>\nlookup <key>\n\n");

 while(1) {
    /* dealing with user */
/*    scanf("%s %ld", buf, &key);

    if(!strcmp(buf, "add")) {
      if(!insert(T, key, NULL))
    puts("Inserted, OK.");
      else
    puts("Ooops, a duplicate detected.");
    }
    else if(!strcmp(buf, "remove")) {
      if(!erase(T, key))
    puts("Found and erased, OK.");
      else
    puts("No such element.");
    }
    else if(!strcmp(buf, "lookup")) {
      if(find(T, key))
    puts("Yup, found.");
      else
    puts("Not found.");
    } else {
      destruct_tree(T);
      puts("Bye!");
      exit(0);
    }
  }
}





/* Contar Tempo:
clock_t start = clock();
/*Do something*/
/*clock_t end = clock();
float seconds = (float)(end - start) / CLOCKS_PER_SEC;'

/* main */


/*

int main()
{
FILE *fpt;

fpt = fopen("MyFile.csv", "w+");

fprintf(fpt,"ID, Name, Email, Phone Number\n");

fclose(fpt);
}
*/