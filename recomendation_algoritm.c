#include <stdio.h>
#include <stdlib.h>

/*void recommendation_algorithm(){
    int count_of_order_type[7], product_code_input, wanted_product_code, i;
    char* token;
    printf("Ви обрали функцію показу рекомендацій!\n");
    FILE *purchase_history = fopen(file_undefined, "rt");
    FILE *product_list = fopen("basket_search_list.txt", "rt");
    do{
        fread(&product_code_input, sizeof(int), 1, file_undefined);
        do{
            fread(&wanted_product_code, sizeof(int), 1, product_list);
            if (wanted_product_code == product_code_input){

            }
            i++;
        } while (fgets(token, sizeof(token), product_list) != NULL);
    } while(fgets(token, sizeof(token), file_undefined) != NULL);
}*/