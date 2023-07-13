#include <stdio.h>
#include <string.h>

int function_list_of_products () {
    int choice;
    char filename[100];

    printf("Каталог меню:\n");
    printf("1. Фрукти та овочі\n");
    printf("2. М'ясо та риба\n");
    printf("3. Вода\n");
    printf("4. Сік та безалкогольні напої\n");
    printf("5. Молочні продукти та яйця\n");
    printf("6. Хлібні вироби\n");
    printf("7. Бакалії, крупи, та макаронні вироби\n");
    printf("0. Вихід\n");

    printf("Виберіть пункт меню: ");
    scanf("%d", &choice);

    switch (choice) {
        case 0:
            printf("Ви обрали вихід. До побачення!\n");
            break;
        case 1:
            printf("Ви обрали 'Фрукти та овочі'.\n");
            strcpy(filename, "Fruits_vegetables.txt");
            break;
        case 2:
            printf("Ви обрали 'М'ясо та риба'.\n");
            strcpy(filename, "Meat_fish.txt");
            break;
        case 3:
            printf("Ви обрали 'Вода'.\n");
            strcpy(filename, "water.txt");
            break;
        case 4:
            printf("Ви обрали 'Сік та безалкогольні напої'.\n");
            strcpy(filename, "Juice_soft_drinks.txt");
            break;
        case 5:
            printf("Ви обрали 'Молочні продукти та яйця'.\n");
            strcpy(filename, "Dairy_products_eggs.txt");
            break;
        case 6:
            printf("Ви обрали 'Хлібні вироби'.\n");
            strcpy(filename, "bread_products.txt");
            break;
        case 7:
            printf("Ви обрали 'Бакалії, крупи, та макаронні вироби'.\n");
            strcpy(filename, "Groceries_cereals_pasta.txt");
            break;
        default:
            printf("Невірний вибір. Спробуйте ще раз.\n");
            return 0;
    }

    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        // Читання та обробка файлу
        printf("Файл '%s' відкрито успішно.\n", filename);

        // Перевірка наявності вмісту
        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        if (size > 0) {
            fseek(file, 0, SEEK_SET);
            char content[size + 1];
            fread(content, sizeof(char), size, file);
            content[size] = '\0';
            printf("Вміст файлу '%s':\n%s\n", filename, content);
        } else {
            printf("Файл '%s' порожній.\n", filename);
        }

        fclose(file);
    } else {
        printf("Помилка відкриття файлу '%s'.\n", filename);
    }

    return 0;
}
