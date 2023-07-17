#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct products {
    int goods_code;
    char goods_name[70];
    float goods_cost;
} basket[100];

void create_filename_of_orders(char* email_from_login, char* filename){
    char add_txt[10] = ".txt";
    strcpy(filename, email_from_login);
    strcat(filename, add_txt);
}

void collect_list(int index, char line[], char* token){
    token = strtok(line, "\t");
    basket[index].goods_code = atoi(token);
    token = strtok(NULL, "\t");
    strcpy(basket[index].goods_name, token);
    token = strtok(NULL, "\t");
    basket[index].goods_cost = atof(token);
}

void collect_history_of_orders(char* email_from_login, int* product_count){
    char filename[32], line[200];
    char* token;
    int index = 0;
    create_filename_of_orders(email_from_login, filename);
    FILE* orders = fopen(filename, "at");
    FILE* f = fopen("basket.txt", "rt");
    for (index = 0; index < *product_count; index++){
        fgets(line, sizeof(line), f);
        collect_list(index, line, token);
        fprintf(orders, "%d\t%s\t%.2f\n", basket[index].goods_code, basket[index].goods_name,
                basket[index].goods_cost);
    }
    fclose(f);
    fclose(orders);
}

void display_history_of_orders(char* email_from_login){
    char filename[32], line[200];
    char* token;
    int index = 0;
    create_filename_of_orders(email_from_login, filename);
    FILE* orders = fopen(filename, "rt");
    if (fgets(line, sizeof(line), orders) == NULL){
        printf("Ви ще не робили замовлень\n");
    }
    else{
        do {
            collect_list(index, line, token);
            printf("%d %s %.2f\n", basket[index].goods_code, basket[index].goods_name,
                   basket[index].goods_cost);
            index++;
        }while (fgets(line, sizeof(line), orders) != NULL);
    }
    fclose(orders);
}