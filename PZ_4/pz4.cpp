#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

const UCHAR LMAX = UCHAR_MAX;

int main() 
{
   UINT cp = GetConsoleCP(), ocp = GetConsoleOutputCP();
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   char S[LMAX]{}, S0[LMAX]{}, C = 0;

   printf("Введите строку S: ");
   gets_s(S, _countof(S) * sizeof(char));

   printf("Введите строку S0: ");
   gets_s(S0, _countof(S0) * sizeof(char));
   
   printf("Введите символ C: ");
   scanf_s("%c", &C, 1);

   char* r = strchr(S, C);                      // Поиск первого вхождения символа

   if (r == NULL)
      printf("Символа \"%c\" нет в строке \"%s\"\n", C, S);
   else 
   {
      size_t l = strlen(S), l0 = strlen(S0);

      for ( ; r; r = strchr(r + l0 + 1, C))
      {
         memmove_s(r + l0, LMAX, r, l + l0);   // Сдвиг вправо от r на l0 
         memcpy_s(r, LMAX, S0, l0);            // Вставка строки S0 перед r
      }
   }

   printf_s("Результат: %s\n", S);

   SetConsoleCP(cp);
   SetConsoleOutputCP(ocp);

   return 0 * _getch();
}