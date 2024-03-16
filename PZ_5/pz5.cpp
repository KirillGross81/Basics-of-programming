#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

const UCHAR MAX_SIZE = UCHAR_MAX;

void CompressStr(char *S);

void DecompressStr(char *S);

int main(void)
{
   UINT cp = GetConsoleCP(), ocp = GetConsoleOutputCP();
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   char S[MAX_SIZE] {};
   printf_s("Введите строку S: ");
   gets_s(S, _countof(S) * sizeof(char));

   if (strlen(S) < 5)
   {
      printf_s("Строку \"%s\" нельзя сжать", S);
      return 0 * _getch();
   }

   CompressStr(S);
   printf_s("Результат сжатия: %s\n", S);

   DecompressStr(S);
   printf_s("Результат расжатия: %s\n", S);

   SetConsoleCP(cp);
   SetConsoleOutputCP(ocp);

   return 0 * _getch();
}

void CompressStr(char *S)
{
   size_t sl = strlen(S),
      b = 0,          // Индекс первого вхождения символа
      e = 0,          // Индекс последнего вхождения символа
      j = 0;          // Число символов, записанных в строку

   for ( ; S[e]; )
   {
      //for (char *p = strchr(&S[e], S[b]); p && p - S <= e + 1; p = strchr(&S[++e], S[b]));
      for ( ; S[e] == S[b]; e++);

      if (e - b > 4)
      {
         // Считаем число записанных символов строки вида C{k} 
         j = snprintf(S + b, MAX_SIZE, "%c{%llu}", S[b], e - b);

         // Сдвигаем элементы подстроки с её конца влево сразу после символа '}'
         memmove_s(S + b + j, MAX_SIZE, S + e, sl - e + 1);
         sl += j - (e - b), e = b += j;
      }
      else b = e;
   }
}

void DecompressStr(char *S)
{
   UCHAR j = 0, count, sl = strlen(S);

   // Ищем символы начала и завершения строки {k}
   for(char *b = strchr(S, '{'), *e = strchr(S, '}'); b && e; b = strchr(S, '{'), e = strchr(S, '}'))
   {
      j = sscanf_s(b + 1, "%hhd", &count); // Читаем количество повторов символа
      
      // Делаем сдвиг элементов вправо для вставки расжатой подстроки
      memmove_s(b + count - 1, MAX_SIZE, e + 1, sl - j - 2);

      memset(b, *(b - 1), count - 1);      // После чего вставляем символ count раз
   }
}