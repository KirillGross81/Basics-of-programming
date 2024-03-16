#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

int main() 
{
   setlocale(0, "");
   ULONGLONG N;

   printf_s("������� ����� N (> 1): ");
   scanf_s("%llu", &N);
      
   if (N < 2) 
   {
      puts("�� ��������� �������: N > 1");
      return 0; 
   } 

   ULONGLONG m = (ULONGLONG)floor(sqrt(N)), i = 2;

   for (; i < m && N % i; i++);

   puts(i == m ? "true" : "false");
  
   return 0 * _getch();
}