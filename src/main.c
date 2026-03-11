#include <stdio.h>
#include <stdlib.h>
#include "task3.h"

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    STUDENT students[STUDENTS];
    
    printf("   ЗАДАЧА 2 - СТРУКТУРА STUDENT\n");

    
    input_students(students, STUDENTS);
    
    sort_students_by_name(students, STUDENTS);
    
    printf("\n=== ОТСОРТИРОВАННЫЙ СПИСОК СТУДЕНТОВ ===\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("%d. %s, курс %d, ср.балл: %.2f\n", 
               i + 1, 
               students[i].name, 
               students[i].kurs, 
               average_grade(students[i]));
    }
    
    printf("\n=== СТУДЕНТЫ С БАЛЛОМ ВЫШЕ СРЕДНЕГО ===\n");
    print_above_average(students, STUDENTS);
    
    return 0;
}