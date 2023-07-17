#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

void create_review(char* email_from_login);
void display_review(char* email_from_login);

int reviews_menu(char* email_from_login, bool* isUserLoggedIn) {
    int menu_reviews = 0;
    if (*isUserLoggedIn == true) {
        while (true) {
            printf("\n 1. Ввести відгук про послугу\n 2. Показати відгуки\n 3. Вихід\n");
            menu_reviews = getch();
            switch (menu_reviews) {
                case '1':
                    create_review(email_from_login);
                    break;
                case '2':
                    display_review(email_from_login);
                    break;
                case '3':
                    return 0;
                default:
                    printf("Введіть коректну цифру");
            }
        }
    } else {
        printf("Спочатку увійдіть в акаунт");
    }
}

void create_review(char* email_from_login) {
    char user_review[1000];
    FILE* review = fopen("reviews.txt", "at");
    fprintf(review, "\nUser: %s\n", email_from_login);
    printf("Введіть свій коментар:\n");
    scanf("%s", user_review);
    fprintf(review, "Review: %s\n", user_review);
    fclose(review);
}

void display_review(char* email_from_login) {
    FILE* review = fopen("reviews.txt", "rt");
    char line[1000];
    printf("Відгуки:\n");
    while (fgets(line, sizeof(line), review) != NULL) {
        if (strstr(line, email_from_login) != NULL) {
            printf("%s", line);
            fgets(line, sizeof(line), review);
            printf("%s\n", line);
        }
    }
    fclose(review);
}
