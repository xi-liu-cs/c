#include <stdio.h>
#include <stdlib.h>
#define size 100

void print_num(char * p, int n, char separate)
{
  for(int i = 0; i < n; ++i)
  {
    if(*p >= 'A' && *p <= 'Z')
      printf(separate == 'y' ? "%d ": "%d", *p - 'A' + 1);
    else if(*p >= 'a' && *p <= 'z')
      printf(separate == 'y' ? "%d ": "%d", *p - 'a' + 1);
    else if(*p >= '0' && *p <= '9')
      printf(separate == 'y' ? "%d ": "%d", *p - '0');
    ++p;
  }
}

int main()
{
  printf("separate by char? (y/n)\n");
  char separate = getchar(), newline = getchar();
  
  int cur_size = size;
  char * s = malloc(size * sizeof(char));
  printf("enter ");
  int i = 0;
  char c;
  scanf("%c", &c);
  while(c != '\n')
  {
    if(i >= cur_size)
    {
      cur_size += size;
      s = realloc(s, cur_size);
    }
    s[i] = c;
    scanf("%c", &c);
    ++i;
  }
  print_num(s, i, separate);
  free(s);
  return 0;
}
