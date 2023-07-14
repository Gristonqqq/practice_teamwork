#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

int buying(int* login_is_true);
int account_info(int* login_is_true);
int list_Of_Products();
void recomendation_algoritm();

int main() {
    int menu_item, login_is_true = 0;
    printf("Вітаємо вас у нашому застосунку сервісу замовлення їжі!\n");
    while (true) {
        printf("Оберіть пункт меню для того щоб продовжити:\n 1. Дії щодо аккаунта\n 2. Інформація щодо товарів\n 3. Купівля\n 4. Вихід\n");
        printf("Введіть цифру пункту меню:\n");
        menu_item = getch();
        switch (menu_item) {
            case '1':
                account_info(&login_is_true);
                break;
            case '2':
                list_Of_Products();
                break;
            case '3':
                buying(&login_is_true);
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