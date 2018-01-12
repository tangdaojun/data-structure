//
// Created by Will Tang on 08/01/2018.
//

#include "struct_demo.h"
#include <string.h>
#include <stdio.h>

struct Book {
    char title[50];
    char author[50];
    char subject[50];
    int book_id;
};

void printBook(struct Book book) {
    printf("book title: %s\n", book.title);
    printf("book author: %s\n", book.author);
    printf("book subject: %s\n", book.subject);
    printf("book book_id: %d\n\n", book.book_id);
}

void printBookP(struct Book *book_p) {
    printf("book title: %s\n", book_p->title);
    printf("book author: %s\n", book_p->author);
    printf("book subject: %s\n", book_p->subject);
    printf("book book_id: %d\n\n", book_p->book_id);
}

void test() {
    struct Book book1;
    struct Book book2;

    strcpy(book1.title, "C Programming");
    strcpy(book1.author, "Nuha Ali");
    strcpy(book1.subject, "C Programming Tutoral");
    book1.book_id = 6495407;

    strcpy(book2.title, "Telecom Billing");
    strcpy(book2.author, "Zara Ali");
    strcpy(book2.subject, "Telecom Billing Tutorial");
    book2.book_id = 6495700;

    printBookP(&book1);
    printBookP(&book2);
}