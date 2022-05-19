#include <stdio.h>
#pragma pack(1)
struct store{
    double price;
    union{
        struct{
            char *title;
            char *author;
            int num_pages;
        } book;
        struct {
            int color;
            int size;
            char *design;
        }shirt;
    }item;
};

int main(){
    struct store book = {
        .price = 100,
        .item.book.title = "C Programming",
        .item.book.author = "Dennis Ritchie",
        .item.book.num_pages = 200
    };
    printf("%s\n", book.item.book.title);
    printf("%s\n", book.item.book.author);
    printf("%d\n", book.item.book.num_pages);
    printf("%lf\n", book.price);


    struct store shirt = {
        .price = 200,
        .item.shirt.color = 0xFF0000,
        .item.shirt.size = 10,
        .item.shirt.design = "Design"
    };
    printf("%d\n", shirt.item.shirt.color);
    printf("%d\n", shirt.item.shirt.size);
    printf("%s\n", shirt.item.shirt.design);
    printf("%lf\n", shirt.price);


    typedef union{
        int a;
        char b;
        double c;
    }data;
    data arr[10];
    arr[0].a = 10;
    arr[1].a = "a";
    arr[2].a = 10.5;

    printf("%d\n", arr[0].a);
    printf("%d\n", arr[1].a);
    printf("%lf\n", arr[2].a);
    return 0;
}