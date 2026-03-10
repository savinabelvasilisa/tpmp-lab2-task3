#ifndef TASK2_H
#define TASK2_H

#define SUBJECTS 5
#define STUDENTS 10
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];      // фамилия и инициалы
    int kurs;                  // курс
    int ses[SUBJECTS];         // успеваемость (5 оценок)
} STUDENT;

/**
 * Ввод данных о студентах с клавиатуры
 * @param students - массив студентов
 */
void input_students(STUDENT students[], int count);

/**
 * Вычисление среднего балла студента
 * @param s - студент
 * @return средний балл
 */
float average_grade(STUDENT s);

/**
 * Вычисление общего среднего балла всех студентов
 * @param students - массив студентов
 * @return общий средний балл
 */
float total_average(STUDENT students[], int count);

/**
 * Сортировка студентов по алфавиту
 */
void sort_students_by_name(STUDENT students[], int count);

/**
 * Вывод студентов, чей средний балл выше общего
 */
void print_above_average(STUDENT students[], int count);

#endif // TASK2_H
