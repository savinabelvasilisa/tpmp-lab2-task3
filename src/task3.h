#ifndef TASK3_H
#define TASK3_H

#define CARS_COUNT 5
#define BRAND_LEN 30
#define COLOR_LEN 20

typedef struct {
    char brand[BRAND_LEN];     // марка
    char color[COLOR_LEN];      // цвет
    int serial_num;             // серийный номер
    char reg_num[10];            // регистрационный номер
    int year;                    // год выпуска
    int tech_year;               // год техосмотра
    float price;                 // цена
} CAR;

/**
 * Ввод данных об автомобилях
 */
void input_cars(CAR cars[], int count);

/**
 * Вывод автомобилей старше 2 лет
 */
void print_cars_older_than_2_years(CAR cars[], int count, int current_year);

#endif // TASK3_H

