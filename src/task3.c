#include <stdio.h>
#include "task3.h"

void input_cars(CAR cars[], int count) {
    printf("\nВведите данные о %d автомобилях:\n", count);
    
    for (int i = 0; i < count; i++) {
        printf("\nАвтомобиль #%d:\n", i + 1);
        
        printf("Марка: ");
        getchar();
        fgets(cars[i].brand, BRAND_LEN, stdin);
        cars[i].brand[strcspn(cars[i].brand, "\n")] = 0;
        
        printf("Цвет: ");
        fgets(cars[i].color, COLOR_LEN, stdin);
        cars[i].color[strcspn(cars[i].color, "\n")] = 0;
        
        printf("Серийный номер: ");
        scanf("%d", &cars[i].serial_num);
        
        printf("Регистрационный номер: ");
        scanf("%s", cars[i].reg_num);
        
        printf("Год выпуска: ");
        scanf("%d", &cars[i].year);
        
        printf("Год техосмотра: ");
        scanf("%d", &cars[i].tech_year);
        
        printf("Цена: ");
        scanf("%f", &cars[i].price);
    }
}

void print_cars_older_than_2_years(CAR cars[], int count, int current_year) {
    printf("\nАвтомобили старше 2 лет (на %d год):\n", current_year);
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (current_year - cars[i].year > 2) {
            printf("Марка: %s, Цвет: %s, Рег.номер: %s, Год: %d, Цена: %.2f\n",
                   cars[i].brand, cars[i].color, cars[i].reg_num, 
                   cars[i].year, cars[i].price);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Автомобилей старше 2 лет не найдено\n");
    }
}
