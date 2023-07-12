#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

int function_acc() {
     struct info {
         char email_of_acc[32];
         char password_of_acc[32];
         char name_of_acc[24];
         char surname_of_acc[24];
     } people[100];
     int menu_char_acc = 0;
     FILE *acc;
     while (true){
         printf("1. Реєстрація\n2. Ввійти в акаунт\n3. Показати всіх зареєстрованих користувачів\n4. Назад\n");
         menu_char_acc = getch();
         switch (menu_char_acc) {
             case '1':
                 acc = fopen("info_acc.txt", "at");
                 int index;
                 for (index = 0; index < 100; index++) {
                     if (strlen(people[index].email_of_acc) == 0) {
                         break;
                     }
                 }
                 printf("Введіть свою пошту (email): ");
                 fscanf(stdin, "%s", &people[index].email_of_acc);
                 printf("Введіть пароль: ");
                 fscanf(stdin, "%s", &people[index].password_of_acc);
                 printf("Введіть своє ім'я: ");
                 fscanf(stdin,"%s", &people[index].name_of_acc);
                 printf("Введіть своє прізвище: ");
                 fscanf(stdin, "%s", &people[index].surname_of_acc);
                 fprintf(acc, "%s %s %s %s\n", people[index].email_of_acc, people[index].password_of_acc,
                         people[index].name_of_acc, people[index].surname_of_acc);
                 fclose(acc);
                 break;
             case '4': return 0;
         }
     }
}
