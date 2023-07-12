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
int log_info_of_acc (int login_is_true);

int function_acc(int login_is_true) {
     int menu_char_acc = 0;
     while (true){
         printf("1. Реєстрація\n2. Ввійти в акаунт\n3. Показати всіх зареєстрованих користувачів\n4. Назад\n");
         menu_char_acc = getch();
         switch (menu_char_acc) {
             case '1':
                 reg_info_of_acc();
                 break;
             case '2':
                 //log_info_of_acc (login_is_true);
                 break;
             case '3':
             case '4': return 0;
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
    for (int i = 0; i < 100; i++) {
        if (strlen(people[i].email_of_acc) == 0) {
            break;
        }
        fprintf(acc, "%s %s %s %s\n", people[i].email_of_acc, people[i].password_of_acc,
                people[i].name_of_acc, people[i].surname_of_acc);
    }
    fclose(acc);
}

void loadDataFromFile() {
    FILE* acc = fopen("info_acc.txt", "rt");
    int i = 0;
    while (fscanf(acc, "%s %s %s %s", people[i].email_of_acc, people[i].password_of_acc,
                  people[i].name_of_acc, people[i].surname_of_acc) == 4) {
        i++;
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
    fscanf(stdin, "%s", &people[index].email_of_acc);
    if (isEmailRegistered(people[index].email_of_acc, index)) {
        fclose(acc);
        return printf("\nТакий акаунт уже зареєстрований, спробуйте ввійти у акаунт\n");
    }
    printf("Введіть пароль: ");
    fscanf(stdin, "%s", &people[index].password_of_acc);
    printf("Введіть своє ім'я: ");
    fscanf(stdin, "%s", &people[index].name_of_acc);
    printf("Введіть своє прізвище: ");
    fscanf(stdin, "%s", &people[index].surname_of_acc);
    fprintf(acc, "%s %s %s %s\n", people[index].email_of_acc, people[index].password_of_acc,
            people[index].name_of_acc, people[index].surname_of_acc);
    fclose(acc);
    saveDataToFile();
    return printf("\nАкаунт зареєстровано\n");
}

int log_info_of_acc (int login_is_true) {

}