#include <stdbool.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char goods_name[70];
    float goods_cost;
} basket;

void adding_goods();
float basket_view(int product_count);
void buy_all_products(float product_cost_summ);

int buying(int* login_is_true){
    int menu_buy_item, product_count = 0;
    float product_cost_summ;
    remove("basket.txt");
    FILE *f = fopen("basket.txt", "wt");
    fclose(f);
    printf("Ви обрали купівлю товару!\n\n");
    if (*login_is_true == 1) {
        while (true) {
            printf("Оберіть, що ви хочете робити:\n 1. Додати товари до кошика\n 2. Переглянути кошик(і суму)\n 3. Купити все, що в кошику\n 4. Очистити кошик\n 5. Повернутися до меню\n\n");
            menu_buy_item = getch();
            switch (menu_buy_item) {
                case '1':
                    adding_goods();
                    product_count++;
                    break;
                case '2':
                    product_cost_summ = basket_view(product_count);
                    break;
                case '3':
                    buy_all_products(product_cost_summ);
                    break;
                case '4':
                    f = fopen("basket.txt", "wt");
                    fclose(f);
                    product_count = 0;
                    break;
                case '5':
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

void adding_goods(){
    basket list;
    int goods_code, entered_code;
    char line[100];
    char* token;
    FILE *basketf = fopen("basket.txt", "a");
    FILE *product_list = fopen("basket_search_list.txt", "rt");
    printf("Для того, щоб додати їжу, введіть код!\n");
    scanf("%d", &entered_code);
    for (int i = 0; i < 52; i++) {
        fgets(line, sizeof(line), product_list);
        token = strtok(line, "\t");
        goods_code = atoi(token);
        token = strtok(NULL, "\t");
        strcpy(list.goods_name, token);
        token = strtok(NULL, "\t");
        token = strtok(NULL, "\t");
        list.goods_cost = atof(token);
        if (entered_code == goods_code){
            break;
        }
    }
    printf("%d %s %.2f\n\n", goods_code, list.goods_name, list.goods_cost);
    fwrite(&list.goods_name, sizeof(list.goods_name), 1, basketf);
    fwrite(&list.goods_cost, sizeof(list.goods_cost), 1, basketf);
    fclose(basketf);
    fclose(product_list);
}

float basket_view(int product_count){
    basket list;
    float product_cost_summ = 0;
    FILE *basket = fopen("basket.txt", "rt");
    for (int i = 0; i < product_count; i++){
        fread(list.goods_name, sizeof(list.goods_name), 1, basket);
        fread(&list.goods_cost, sizeof(float), 1, basket);
        printf("%s\t", list.goods_name);
        printf("%.2f\n", list.goods_cost);
        product_cost_summ += list.goods_cost;
    }
    printf("\n Загальна ціна за обрану їжу: %.2f\n\n", product_cost_summ);
    fclose(basket);
    return product_cost_summ;
}

void buy_all_products(float product_cost_summ){
    printf("Ваше замовлення на суму %.2f було оброблене. Дякуємо що обрали наш сервіс!\n\n", product_cost_summ);
    FILE *f = fopen("basket.txt", "wt");
    fclose(f);
}