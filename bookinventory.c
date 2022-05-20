/*
    This is a book inventory program. It can add and list up to 100 books.
 
*/

#include<stdio.h>
#include<string.h>
#include <unistd.h>
#define MAX 100  //size of the inventory
#define LEN 256  //character length for keyboard input

struct book {    //library structure
    char title[LEN];
    char author[LEN];
    char year[LEN];
    char edition[LEN];
    char isbn[LEN];
};

void my_input(char * book_element ) {  // call by reference
    int k, c; 
    fflush(stdin); // clears the keyboard input
    for (k = 0; k < LEN; ++k) { //character input loop
            c = getc(stdin); 
            if (c == '\n' || c == EOF) { //  new line  or  when there is no more data to be read 
                book_element[k] = '\0'; //  set the k’th element array to end of line
                break; // break the loop
            }
            book_element[k] = c; // set the kth element to the character
        }
        book_element[k] = '\0'; // set it to end of line
}

int main() { 
    struct book arr_book[MAX]; // acessing the structure array
    FILE* out; // defining file handles 
    int i, j;
    char t; //  declaring character input for the menu
    char z[31]; // char array for name

  printf("Enter Your Name: ");
         scanf("%s", z);
          printf("                                       ___ \n");
          printf("                                      | O |\n");
          printf("                                      |___|\n");
          printf("                                      (   )\n ");
          printf("                                     |   |\n ");
          printf("                                     |   |\n ");
          printf("                                     |   |\n ");
          printf("                                     |   |\n ");
          printf("                                     '.-.'\n ");
          printf("                                      ) (\n ");
          printf("                                     (   )\n ");
          printf("                                      '|'\n ");
            
         
    printf("Welcome to %s's book inventory program.\n",z);

while(1){    //here starts the endless loop

    fflush(stdin);          //Cleaning Input
   
    printf("====================================================== \n\n");
    printf("Press 'a' to add a book to the inventory.\n");
    printf("Press 'l' to see the list of the whole inventory.\n");
    printf("Press 'n' to leave the program.\n");

    scanf("%c", &t);    //The user enters a, l or n

    switch(t)
    {
    case 'a' : {
    printf("How many books do you want to save? ");
    scanf("%d", &j);
    if(j<=0 || j>=100) break;
    out=fopen("books.txt","a+");     //Opening the file
    for (i = 0; i < j && i < MAX; i++) {
    printf("Enter details of book %d\n\n", i+1);

        printf("Title: ");
        my_input(arr_book[i].title);

        printf("Author: ");
        my_input(arr_book[i].author);

        printf("Year: ");
        my_input(arr_book[i].year);

        printf("Edition: ");
        my_input(arr_book[i].edition);

        printf("ISBN: ");
        my_input(arr_book[i].isbn);

        printf("\n");

        fprintf(out, "Title: %s \nAuthor: %s \nYear: %s \nEdition: %s\nISBN: %s \n\n",                 //Writing in the file
        arr_book[i].title,arr_book[i].author,arr_book[i].year,arr_book[i].edition,arr_book[i].isbn);
    }
    fclose(out);       //Closing the file
    };
    break;

case 'l' :
{
    printf("========== Your Books! ==========\n\n");
    int k;
    char c;

    out = fopen("books.txt","r"); //Open Input file for read
    if(out == NULL) {
        printf("The file does not exist!\n\n"); break;    //In case the file is not created yet
    }
    k=0;
    while(1){                //Read character after character from file and write it to stout
       c = getc(out);
            if (c == EOF) {
                c = '\0';
                break;};

            putc(c, stdout);
            k++;
        }
        putc('\0', stdout);
        fclose(out);
   };
   break;

case 'n' : {

    printf("Library closed. 📕 🔒 📚 \n Have a nice day, %s! 🌞 \n",z);
return 0;};
break;
}
}
}