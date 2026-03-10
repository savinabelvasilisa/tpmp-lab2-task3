#include <stdio.h>
#include <stdlib.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice;
    
    do {
        printf("\n=== МЕНЮ ПРОГРАММЫ ===\n");
        printf("1. Задача 1 - Максимальная сумма цифр\n");
        printf("2. Задача 2 - Структура STUDENT\n");
        printf("3. Задача 3 - Структура CAR (автомобили)\n");
        printf("0. Выход\n");
        printf("Выберите задачу: ");
        
        scanf("%d", &choice);
        clear_input();
        
        switch(choice) {
            case 1: {
                // Задача 1
                int n;
                printf("Введите размер массива: ");
                scanf("%d", &n);
                
                int arr[n];
                printf("Введите %d натуральных чисел: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                find_max_digit_sum(arr, n);
                break;
            }
            
            case 2: {
                // Задача 2
                STUDENT students[STUDENTS];
                
                input_students(students, STUDENTS);
                sort_students_by_name(students, STUDENTS);
                
                printf("\n=== ОТСОРТИРОВАННЫЙ СПИСОК СТУДЕНТОВ ===\n");
                for (int i = 0; i < STUDENTS; i++) {
                    printf("%d. %s, курс %d, ср.балл: %.2f\n", 
                           i + 1, students[i].name, students[i].kurs, 
                           average_grade(students[i]));
                }
                
                print_above_average(students, STUDENTS);
                break;
            }
            
            case 3: {
                // Задача 3
                CAR cars[CARS_COUNT];
                int current_year;
                
                input_cars(cars, CARS_COUNT);
                
                printf("Введите текущий год: ");
                scanf("%d", &current_year);
                
                print_cars_older_than_2_years(cars, CARS_COUNT, current_year);
                break;
            }
            
            case 0:
                printf("Программа завершена.\n");
                break;
                
            default:
                printf("Неверный выбор! Попробуйте снова.\n");
        }
        
    } while (choice != 0);
    
    return 0;
}
