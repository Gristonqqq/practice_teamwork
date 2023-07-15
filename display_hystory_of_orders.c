#include <stdio.h>
#include <string.h>

struct products{
    char goods_name[70];
    float goods_cost;
} basket[100];

void create_filename_of_orders(char* email_from_login, char* filename){
    char add_txt[10] = ".txt";
    strcpy(filename, email_from_login);
    strcat(filename, add_txt);
}

void collect_history_of_orders(char* email_from_login, int* product_count){
    char filename[32];
    create_filename_of_orders(email_from_login, filename);
    FILE* orders = fopen(filename, "at");
    FILE* f = fopen("basket.txt", "rt");
    for(int index = 0; index < *product_count; index++){
        fscanf(f, "%s %f\n", basket[index].goods_name, &basket[index].goods_cost);
        fprintf(orders, "%s %.2f\n", basket[index].goods_name, basket[index].goods_cost);
    }
    fclose(f);
    fclose(orders);
}

void display_history_of_orders(char* email_from_login){
    char filename[32];
    int index = 0, expectedReadFieldsCount = 2;
    create_filename_of_orders(email_from_login, filename);
    FILE* orders = fopen(filename, "rt");
    while(fscanf(orders, "%s %f\n", basket[index].goods_name, &basket[index].goods_cost) == expectedReadFieldsCount){
        printf("%s %.2f\n", basket[index].goods_name, basket[index].goods_cost);
        index++;
    }
    fclose(orders);
}