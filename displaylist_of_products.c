#include <stdio.h>
#include <string.h>

void readAndProcessFile(const char *filename) {\
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
    const char *arr[7] = {
            "1. Фрукти та овочі\n",
            "2. М'ясо та риба\n",
            "3. Вода\n",
            "4. Сік та безалкогольні напої\n",
            "5. Молочні продукти та яйця\n",
            "6. Хлібні вироби\n",
            "7. Бакалії, крупи, та макаронні вироби\n"
    };

    printf("Каталог меню:\n");

    for (int i = 0; i < 7; i++) {
        printf("%s", arr[i]);
    }
}

int displaylist_of_products() {

    int choice;
    char filename[100];

    printMenu();

    printf("Виберіть пункт меню: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 7) {
        const char *filenames[7] = {
                "Fruits_vegetables.txt",
                "Meat_fish.txt",
                "water.txt",
                "Juice_soft_drinks.txt",
                "Dairy_products_eggs.txt",
                "bread_products.txt",
                "Groceries_cereals_pasta.txt"
        };

        const char *menuOptions[7] = {
                "Фрукти та овочі",
                "М'ясо та риба",
                "Вода",
                "Сік та безалкогольні напої",
                "Молочні продукти та яйця",
                "Хлібні вироби",
                "Бакалії, крупи, та макаронні вироби"
        };

        printf("Ви обрали '%s'.\n", menuOptions[choice - 1]);
        strcpy(filename, filenames[choice - 1]);
        readAndProcessFile(filename);
    } else if (choice == 0) {
        printf("Ви обрали вихід. До побачення!\n");
    } else {
        printf("Невірний вибір. Спробуйте ще раз.\n");
    }

    return 0;
}
