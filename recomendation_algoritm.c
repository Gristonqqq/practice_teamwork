#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void recommendation_algorithm(char* email_from_login){
    int count_of_order_type[7], product_code_input, wanted_product_code, i;
    char* token, *account_filename;
    strcpy(account_filename, email_from_login);
    strcat(account_filename, ".txt");
    printf("Ви обрали функцію показу рекомендацій!\n");
    FILE *purchase_history = fopen(account_filename, "rt");
    FILE *product_list = fopen("basket_search_list.txt", "rt");
    do{
        fread(&product_code_input, sizeof(int), 1, purchase_history);
        do{
            fread(&wanted_product_code, sizeof(int), 1, product_list);
            if (wanted_product_code == product_code_input){
            }
            i++;
        } while (fgets(token, sizeof(token), product_list) != NULL);
    } while(fgets(token, sizeof(token), purchase_history) != NULL);
}