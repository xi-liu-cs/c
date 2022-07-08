#include <stdio.h>
#include <string.h>
 
char * map = "___#_##_";
 
#define idx(i) (cell[i] != '_')
int evolve(char * cell, char * buf, int n)
{
	int dif = 0;
	for(int i = 0; i < n; ++i) 
	{/* use left, self, right as binary number bits for map index */
		buf[i] = map[(idx(i - 1) << 2) + (idx(i) << 1) + idx(i + 1)];
		dif += (buf[i] != cell[i]);
	}
	strcpy(cell, buf);
	return dif;
}
 
int main()
{
	char c[] = "_###_##_#_#_#_#__#__\n",
	b[] = "____________________\n";
	int n = sizeof(c) / sizeof(*c);
	do { printf("%s", c + 1); } while (evolve(c + 1, b + 1, n - 3));
}
