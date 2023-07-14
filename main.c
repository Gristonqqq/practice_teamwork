#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int buying(bool* isEachUserLoggedIn);
int account_info(bool* isEachUserLoggedIn);
void display_list_of_products();
void recomendation_algoritm();

int main() {
    int menu_item;
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    bool isEachUserLoggedIn = false;
    printf("Вітаємо вас у нашому застосунку сервісу замовлення їжі!\n");
    while (true) {
        printf("Оберіть пункт меню для того щоб продовжити:\n 1. Дії щодо аккаунта\n 2. Інформація щодо товарів\n 3. Купівля\n 5. Вихід\n");
        printf("Введіть цифру пункту меню:\n");
        menu_item = getch();
        switch (menu_item) {
            case '1':
                account_info(&isEachUserLoggedIn);
                break;
            case '2':
                display_list_of_products();
                break;
            case '3':
                buying(&isEachUserLoggedIn);
                break;
            case '4':
                recomendation_algoritm();
                break;
            case '5':
                exit(1);
            default:
                printf("\nВиберіть коректну цифру\n");
        }
    }
}