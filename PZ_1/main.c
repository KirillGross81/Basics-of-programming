#include <stdio.h>
#include <locale.h>

int main()
{
   setlocale(0, "");
   unsigned char d, m;

   printf_s("������� ���� � �����: ");
   scanf_s("%hhu %hhu", &d, &m);

   if (d < 1 || d > 31) 
   {
      printf_s("������ ������������ ����!");
      return 0;
   }
   if (m < 1 || m > 12) 
   {
      printf_s("������ ������������ �����!");
      return 0;
   }

   if (m == 2) 
   {
      if (d > 28) 
      {
         printf_s("������ ������������ ����!");
         return 0;
      }
      else
      {
         m = m % 12 + d / 28;
         d = d % 28 + 1;
      }
   }
   else if (m == 4 || m == 6 || m == 9 || m == 11) 
   {
      if (d > 30) 
      {
         printf_s("������ ������������ ����!");
         return 0;
      }
      else 
      {
         m = m % 12 + d / 30;
         d = d % 30 + 1;
      }
   }
   else 
   {
      m = m % 12 + d / 31;
      d = d % 31 + 1;
   }

   printf_s("��������� ����: %hhu %hhu", d, m);
   return 0;
}