#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

struct info {
    char email_of_acc[32];
    char password_of_acc[32];
    char name_of_acc[24];
    char surname_of_acc[24];
} people[100];

int reg_info_of_acc ();
int log_info_of_acc (int* check_log);
void show_info_of_acc ();

int function_acc(int* login_is_true) {
     int menu_char_acc = 0;
     int check_log = 0;
     while (true){
         printf("1. Реєстрація\n2. Ввійти в акаунт\n3. Показати всіх зареєстрованих користувачів\n4. Назад\n");
         menu_char_acc = getch();
         switch (menu_char_acc) {
             case '1':
                 reg_info_of_acc();
                 break;
             case '2':
                 if (check_log == 1){
                     printf("\nВи вже увійшли до акаунта!\n");
                 }
                 else{
                     log_info_of_acc (&check_log);
                 }
                 break;
             case '3':
                 show_info_of_acc ();
                 break;
             case '4':
                 *login_is_true = check_log;
                 return *login_is_true;
             default:
                 printf("\nВиберіть коректну цифру\n");
         }
     }
}

bool isEmailRegistered(const char* email, int index) {
    for (int check_acc = 0; check_acc < index; check_acc++) {
        if (strcmp(email, people[check_acc].email_of_acc) == 0) {
            return true;
        }
    }
    return false;
}

void saveDataToFile() {
    FILE* acc = fopen("info_acc.txt", "wt");
    for (int index = 0; index < 100; index++) {
        if (strlen(people[index].email_of_acc) == 0) {
            break;
        }
        fprintf(acc, "%s %s %s %s\n", people[index].email_of_acc, people[index].password_of_acc,
                people[index].name_of_acc, people[index].surname_of_acc);
    }
    fclose(acc);
}

void loadDataFromFile() {
    FILE* acc = fopen("info_acc.txt", "rt");
    int index = 0;
    while (fscanf(acc, "%s %s %s %s", people[index].email_of_acc, people[index].password_of_acc,
                  people[index].name_of_acc, people[index].surname_of_acc) == 4) {
        index++;
    }
    fclose(acc);
}

int reg_info_of_acc() {
    loadDataFromFile();
    FILE* acc = fopen("info_acc.txt", "at");
    int index;
    for (index = 0; index < 100; index++) {
        if (strlen(people[index].email_of_acc) == 0) {
            break;
        }
    }
    printf("Введіть свою пошту (email): ");
    fscanf(stdin, "%s", people[index].email_of_acc);
    if (isEmailRegistered(people[index].email_of_acc, index)) {
        fclose(acc);
        return printf("\nТакий акаунт уже зареєстрований, спробуйте ввійти у акаунт\n");
    }
    printf("Введіть пароль: ");
    fscanf(stdin, "%s", people[index].password_of_acc);
    printf("Введіть своє ім'я: ");
    fscanf(stdin, "%s", people[index].name_of_acc);
    printf("Введіть своє прізвище: ");
    fscanf(stdin, "%s", people[index].surname_of_acc);
    fprintf(acc, "%s %s %s %s\n", people[index].email_of_acc, people[index].password_of_acc,
            people[index].name_of_acc, people[index].surname_of_acc);
    fclose(acc);
    saveDataToFile();
    return printf("\nАкаунт зареєстровано\n");
}

int log_info_of_acc (int* check_log) {
    int index;
    char log_email[32], log_password[32];
    FILE* acc;
    loadDataFromFile();
    acc = fopen("info_acc.txt", "rt");
    printf("Введіть свою пошту (email): ");
    scanf("%s", log_email);
    for (index = 0; index < 100; index++){
        fscanf(stdout, "%s %s %s %s", people[index].email_of_acc, people[index].password_of_acc,
               people[index].name_of_acc, people[index].surname_of_acc);
        if (strcmp(people[index].email_of_acc, log_email) == 0){
            printf("Введіть пароль (якщо забули пароль введіть: 'IForgotPass'): ");
            while (strcmp(people[index].password_of_acc, log_password) != 0){
                scanf("%s", log_password);
                if (strcmp(people[index].password_of_acc, log_password) != 0){
                    printf("Не вірний пароль, спробуйте ще раз.\n");
                }
                if (strcmp((const char *) "IForgotPass", log_password) == 0){
                    printf("Згадайте пароль і повертайтесь!\n");
                    fclose(acc);
                    return *check_log = 0;
                }
            }
            printf("Вітаємо, ви авторизувалися!\n");
            fclose(acc);
            return *check_log = 1;
        }
    }
}

void show_info_of_acc (){
    int index = 0;
    FILE* acc;
    loadDataFromFile();
    acc = fopen("info_acc.txt", "rt");
    while (fscanf(acc, "%s %s %s %s", people[index].email_of_acc, people[index].password_of_acc,
                  people[index].name_of_acc, people[index].surname_of_acc) == 4) {
        printf("%s %s %s\n", people[index].email_of_acc, people[index].name_of_acc,
               people[index].surname_of_acc);
        index++;
    }
}