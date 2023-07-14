#include <stdio.h>
#include <string.h>

#define NUM_CATEGORIES 7

void readAndProcessFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        printf("Файл '%s' відкрито успішно.\n", filename);

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
}

void printMenu() {
    const char *categories[NUM_CATEGORIES] = {
            "Фрукти та овочі",
            "М'ясо та риба",
            "Вода",
            "Сік та безалкогольні напої",
            "Молочні продукти та яйця",
            "Хлібні вироби",
            "Бакалії, крупи, та макаронні вироби"
    };

    printf("Каталог меню:\n");

    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("%d. %s\n", i + 1, categories[i]);
    }
}

const char *categories[NUM_CATEGORIES];

int display_list_of_products() {

    int choice;
    char filename[100];

    printMenu();

    printf("Виберіть пункт меню: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= NUM_CATEGORIES) {
        const char *filenames[NUM_CATEGORIES] = {
                "Fruits_vegetables.txt",
                "Meat_fish.txt",
                "water.txt",
                "Juice_soft_drinks.txt",
                "Dairy_products_eggs.txt",
                "bread_products.txt",
                "Groceries_cereals_pasta.txt"
        };

        printf("Ви обрали '%s'.\n", categories[choice - 1]);
        strcpy(filename, filenames[choice - 1]);
        readAndProcessFile(filename);
    } else if (choice == 0) {
        printf("Ви обрали вихід. До побачення!\n");
    } else {
        printf("Невірний вибір. Спробуйте ще раз.\n");
    }
    
    return 0;
}
