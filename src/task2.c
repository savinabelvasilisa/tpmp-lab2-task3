#include <stdio.h>
#include <string.h>
#include "task2.h"

void input_students(STUDENT students[], int count) {
    printf("Введите данные о %d студентах:\n", count);
    
    for (int i = 0; i < count; i++) {
        printf("\nСтудент #%d:\n", i + 1);
        
        // Ввод ФИО
        printf("Фамилия и инициалы: ");
        while (getchar() != '\n');
        fgets(students[i].name, NAME_LEN, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // убираем \n
        
        // Ввод курса
        printf("Курс: ");
        scanf("%d", &students[i].kurs);
        
        // Ввод оценок
        printf("Оценки по 5 предметам: ");
        for (int j = 0; j < SUBJECTS; j++) {
            scanf("%d", &students[i].ses[j]);
        }
    }
}

float average_grade(STUDENT s) {
    int sum = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        sum += s.ses[i];
    }
    return (float)sum / SUBJECTS;
}

float total_average(STUDENT students[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += average_grade(students[i]);
    }
    return total / count;
}

void sort_students_by_name(STUDENT students[], int count) {
    STUDENT temp;
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void print_above_average(STUDENT students[], int count) {
    float avg = total_average(students, count);
    printf("\nОбщий средний балл: %.2f\n", avg);
    
    printf("\nСтуденты с баллом выше среднего:\n");
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        float student_avg = average_grade(students[i]);
        if (student_avg > avg) {
            printf("%s, курс %d, средний балл: %.2f\n", 
                   students[i].name, students[i].kurs, student_avg);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Таких студентов нет\n");
    }
}
