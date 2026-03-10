#include <stdio.h>
#include "task1.h"

int digit_sum(int number) {
    int sum = 0;
    int num = number;  // работаем с копией
    
    while (num > 0) {
        sum += num % 10;  // добавляем последнюю цифру
        num /= 10;        // отбрасываем последнюю цифру
    }
    
    return sum;
}

void find_max_digit_sum(int arr[], int n) {
    if (n <= 0) {
        printf("Массив пуст!\n");
        return;
    }
    
    // Сначала найдём максимальную сумму цифр
    int max_sum = digit_sum(arr[0]);
    
    for (int i = 1; i < n; i++) {
        int current_sum = digit_sum(arr[i]);
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    // Выведем все числа с максимальной суммой
    printf("Числа с максимальной суммой цифр (%d): ", max_sum);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (digit_sum(arr[i]) == max_sum) {
            printf("%d ", arr[i]);
            count++;
        }
    }
    printf("\nНайдено %d чисел\n", count);
}
