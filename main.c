#include <math.h>
#include <stdio.h>

int sum_array_recursive(int* arr, int size)
{
    if (size == 0) { // если длина массива == -1, то
                     // return 0
        return 0;
    }
    return (arr[size - 1]
            + sum_array_recursive(
                      arr,
                      size - 1)); // return сумму элемента массива
                                  // size - 1 и рекурсивно вызванную функцию
}
int sum_array_iteration(int* arr, int size, int sum)
{
    if (size == 0) { // если длина массива становится равна 0, то return
                     // sum
        return sum;
    }
    sum += arr[size - 1]; // сумма всех пар 
    return (sum_array_iteration(
            arr, size - 1, sum)); //return рекурсивно вызванную функцию
}
int fib_number_recursive(int n)
{
    if ((n == 1) || (n == 2)) { // если числа 1 или 2 
                                // return 1
        return 1;
    }
    return (fib_number_recursive(n - 1)
            + fib_number_recursive(
                      n - 2)); // возвращаем сумму 2-х рекурсивно вызванных
    // функций(подсчет следующего члена
    // последовательности)
}
int fib_number_iter(int a, int b, int count)
{
    if (count == 0) {
        return b; // если счетчик равен 0, то возвращаем n-ый член
        // последовательности
    }

    return fib_number_iter(
            a + b, a, count - 1); // a+b = след. член последовательности, a =
    // нынешний член последовательности
}
int fib_number_iteration(int n)
{
    return fib_number_iter(1, 0, n); // вызываем итерацию
}
char num_to_string(int num, char* string)
{
    int i = 0;
    if (num / 10 != 0) {
        i = num_to_string(num / 10, string); // рекурсивно вызываем функцию,
                                             // пока не дойдем до конца числа
    } else if (num < 0) { // если число >0 до добавляем - в начало
                          // массива
        string[i++] = '-';
    }
    string[i++] = fabs(num % 10) + '0'; // добавление значения в массив
    string[i] = '\0';                   // добавление знака окончания строки в конец массива
    return i;                           //
                                        // return значение
}
int main()
{
    int x = -12345;
    char s[7];
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%d\n", sum_array_recursive(arr, 5));
    printf("%d\n", sum_array_iteration(arr, 5, 0));
    printf("%d\n", fib_number_recursive(10));
    printf("%d\n", fib_number_iteration(10));
    num_to_string(x, s);
    for (int i = 0; i < 7; i++) {
        printf("%c ", s[i]);
    }
    printf("\n");
}
