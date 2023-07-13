#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

int function_buying(int* login_is_true);
int function_acc(int* login_is_true);

int main() {
    int menu_item, login_is_true = 0;
    printf("Вітаємо вас у нашому застосунку сервісу замовлення їжі!\n");
    while (true) {
        printf("Оберіть пункт меню для того щоб продовжити:\n 1. Дії щодо аккаунта\n 2. Інформація щодо товарів\n 3. Купівля\n 4. Вихід\n");
        printf("Введіть цифру пункту меню:\n");
        menu_item = getch();
        switch (menu_item) {
            case '1': function_acc(&login_is_true); break;
            case '2':
            case '3':
                function_buying(&login_is_true);
                break;
            case '4':
                exit(1);
            default:
                printf("\nВиберіть коректну цифру\n");
        }
    }
}