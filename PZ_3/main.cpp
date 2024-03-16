#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <limits.h>

const UCHAR Nmax = UCHAR_MAX;

int main()
{   
   setlocale(0, "");

   size_t a[Nmax] {};
   UCHAR N = 0;
   
   printf_s("Введите размер массива (<= %u): ", Nmax / 2);
   scanf_s("%hhu", &N);

   if (N < 1 || N > Nmax / 2)
   {
      puts("Неверный размер массива!");
      return 0 * _getch();
   }

   printf_s("Введите элементы массива: ");

   for (UCHAR i = 0; i < N; i++) 
      if (!scanf_s("%llu", &a[i]))
      {
         puts("Введено не число!");
         return 0 * _getch();
      }

   for (UCHAR i = 0, k = N; i < k; i++)
      if (a[i] % 2 == 0) a[N++] = a[i];

   printf_s("Результат: ");

   for (UCHAR i = 0; i < N; i++)
      printf_s("%llu ", a[i]);

   return 0 * _getch();
}