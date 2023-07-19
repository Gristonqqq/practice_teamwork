#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int goods_code;
    char goods_name[70];
    float goods_cost;
    int goods_type_index;
} basket;

void recommendation_print(int index_of_most_popular);

void recommendation_algorithm(char* email_from_login, bool* isUserLoggedIn) {
    int count_of_order_type[7] = {0, 0, 0, 0, 0, 0, 0};
    int product_code_input, wanted_product_code, most_popular1 = 0, most_popular2 = 0, type_index;
    char *token;
    char file_line[200], account_filename[100];
    if (isUserLoggedIn) {
        strcpy(account_filename, email_from_login);
        strcat(account_filename, ".txt");
        printf("Ви обрали функцію показу рекомендацій!\n");
        FILE *purchase_history = fopen(account_filename, "rt");
        FILE *product_list;
        while (fgets(file_line, sizeof(file_line), purchase_history) != NULL) {
            product_code_input = atoi(strtok(file_line, "\t"));
            product_list = fopen("basket_search_list.txt", "rt");
            while (fgets(file_line, sizeof(file_line), product_list) != NULL) {
                wanted_product_code = atoi(strtok(file_line, "\t"));
                if (wanted_product_code == product_code_input) {
                    strtok(NULL, "\t");
                    strtok(NULL, "\t");
                    strtok(NULL, "\t");
                    token = strtok(NULL, "\t");
                    type_index = atoi(token);
                    count_of_order_type[type_index - 1]++;
                }
            }
            fclose(product_list);
        }
        for (int i = 0; i < 7; i++) {
            if (count_of_order_type[i] > count_of_order_type[most_popular1]) {
                most_popular1 = i;
            }
        }
        for (int i = 0; i < 7; i++) {
            if (count_of_order_type[i] > count_of_order_type[most_popular2] && most_popular1 != i) {
                most_popular2 = i;
            }
        }
        fclose(purchase_history);
        if (most_popular1 >= 0) {
            printf("Товари підібрані спеціально для вас!\n");
            recommendation_print(most_popular1);
            recommendation_print(most_popular2);
        } else {
            printf("Занадто мало замовлень для формування списку рекомендацій\n");
        }
    } else {
        printf("\nСпочатку треба увійти до аккаунту або пройти реєстрацію!\n");
    }
}

void recommendation_print(int index_of_most_popular){
    basket list;
    FILE* purchase_history = fopen("basket_search_list.txt", "rt");
    int limit_counter = 0;
    char file_line[200];
    index_of_most_popular++;
    while(fgets(file_line, sizeof(file_line), purchase_history) != NULL && limit_counter<3) {
        list.goods_code = atoi(strtok(file_line, "\t"));
        strcpy(list.goods_name, strtok(NULL, "\t"));
        strtok(NULL, "\t");
        list.goods_cost = atof(strtok(NULL, "\t"));
        list.goods_type_index = atoi(strtok(NULL, "\t"));
        if(list.goods_type_index == index_of_most_popular){
            printf("%d %s %.2f\n", list.goods_code, list.goods_name, list.goods_cost);
            limit_counter++;
        }
    }
    fclose(purchase_history);
}