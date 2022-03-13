#include <stdio.h>
#include <stdlib.h>
#define size 100

void print_num(char * p, int n)
{
  for(int i = 0; i < n; i++)
  {
    if(*p >= 'A' && *p <= 'Z')
      printf("%d", *p - 'A' + 1);
    else if(*p >= 'a' && *p <= 'z')
      printf("%d", *p - 'a' + 1);
    else if(*p >= '0' && *p <= '9')
      printf("%d", *p - '0');
    p++;
  }
}

int main()
{
  int cur_size = size;
  char * s = (char *)malloc(size * sizeof(char));
  printf("enter ");
  int i = 0;
  char c;
  scanf("%c", &c);
  while(c != '\n')
  {
    if(i >= cur_size)
    {
      cur_size += size;
      s = (char *)realloc(s, cur_size);
    }
    s[i] = c;
    scanf("%c", &c);
    i++;
  }
  print_num(s, i);
  free(s);
  return 0;
}
