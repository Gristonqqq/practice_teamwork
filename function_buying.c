#include <stdbool.h>
#include <conio.h>
#include <stdio.h>

typedef struct {
    char goods_name[30];
    int goods_cost;
} basket;

void adding_goods();

int function_buying(){
    int menu_buy_item;
    printf("Ви обрали купівлю товару!\n\n");
    while (true) {
        printf("Оберіть, що ви хочете робити:\n 1. Додати товари до кошика\n 2. Переглянути кошик(і суму)\n 3. Купити все, що в кошику\n 4. Очистити кошик\n 5. Повернутися до меню\n\n");
        menu_buy_item = getch();
        switch (menu_buy_item) {
            case '1': adding_goods();
            case '2':
            case '3':
            case '4':
            case '5': return 0;
            default:
                printf("\nВиберіть коректну цифру\n");
        }
    }
}

void adding_goods(){
    basket list[30];
    FILE *f = fopen("basket.txt", "a");

}