#include <stdbool.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int goods_code;
    char goods_name[70];
    float goods_cost;
} basket;

float adding_goods();
void basket_view(int product_count, float product_cost_summ);
void buy_all_products(float product_cost_summ, int* product_count, char* email_from_login);
void collect_history_of_orders(char* email_from_login, int* product_count);
void display_history_of_orders(char* email_from_login);

int buying(bool* isUserLoggedIn, char* email_from_login){
    int menu_buy_item, product_count = 0;
    float product_cost_summ = 0;
    remove("basket.txt");
    FILE *f = fopen("basket.txt", "wt");
    fclose(f);
    printf("Ви обрали купівлю товару!\n\n");
    if (*isUserLoggedIn == true) {
        while (true) {
            printf("Оберіть, що ви хочете робити:\n 1. Додати товари до кошика\n 2. Переглянути кошик(і суму)\n 3. Купити все, що в кошику\n 4. Очистити кошик\n 5. Переглянути історію замовлень\n 6. Повернутися до меню\n\n");
            menu_buy_item = getch();
            switch (menu_buy_item) {
                case '1':
                    product_cost_summ += adding_goods();
                    product_count++;
                    break;
                case '2':
                    basket_view(product_count, product_cost_summ);
                    break;
                case '3':
                    buy_all_products(product_cost_summ, &product_count, email_from_login);
                    product_cost_summ = 0;
                    product_count = 0;
                    break;
                case '4':
                    f = fopen("basket.txt", "wt");
                    fclose(f);
                    product_count = 0;
                    break;
                case '5':
                    display_history_of_orders(email_from_login);
                    break;
                case '6':
                    remove("basket.txt");
                    return 0;
                default:
                    printf("\nВиберіть коректну цифру\n");
            }
        }
    } else{
        printf("\nСпочатку треба увійти до аккаунту або пройти реєстрацію!\n");
        return 1;
    }
}

float adding_goods(){
    bool product_founded = false;
    basket list;
    float product_cost_summ = 0;
    int entered_code;
    char line[200];
    char* token;
    FILE *basketf = fopen("basket.txt", "a");
    FILE *product_list = fopen("basket_search_list.txt", "rt");
    printf("Для того, щоб додати їжу, введіть код!\n");
    scanf("%d", &entered_code);
    while (fgets(line, sizeof(line), product_list) != NULL) {
        token = strtok(line, "\t");
        list.goods_code = atoi(token);
        token = strtok(NULL, "\t");
        strcpy(list.goods_name, token);
        strtok(NULL, "\t");
        token = strtok(NULL, "\t");
        list.goods_cost = atof(token);
        if (entered_code == list.goods_code){
            product_founded = true;
            break;
        }
    }
    if (product_founded) {
        printf("%d %s %.2f\n\n", list.goods_code, list.goods_name, list.goods_cost);
        fprintf(basketf, "%d\t%s\t%f\n", list.goods_code, list.goods_name, list.goods_cost);
        product_cost_summ = list.goods_cost;
    } else {
        printf("Подивіться в каталог і введіть коректне число!\n");
    }
    fclose(basketf);
    fclose(product_list);
    return product_cost_summ;
}

void basket_view(int product_count, float product_cost_summ){
    basket list;
    char* token;
    char line[200];
    FILE *basket = fopen("basket.txt", "rt");
    for (int i = 0; i < product_count; i++){
        fgets(line, sizeof(line), basket);
        token = strtok(line, "\t");
        list.goods_code = atoi(token);
        token = strtok(NULL, "\t");
        strcpy(list.goods_name, token);
        token = strtok(NULL, "\t");
        list.goods_cost = atof(token);
        printf("%d\t", list.goods_code);
        printf("%s\t", list.goods_name);
        printf("%.2f\n", list.goods_cost);
    }
    printf("\n Загальна ціна за обрану їжу: %.2f\n\n", product_cost_summ);
    fclose(basket);
}

void buy_all_products(float product_cost_summ, int* product_count, char* email_from_login){
    printf("Ваше замовлення на суму %.2f було оброблене. Дякуємо що обрали наш сервіс!\n\n", product_cost_summ);
    collect_history_of_orders(email_from_login, product_count);
    FILE* f = fopen("basket.txt", "wt");
    fclose(f);
}