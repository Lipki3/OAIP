#include <stdio.h>
#include <locale.h>
#define n 50
int rec(char*str, int kr, int kv, int fg, int i);
int main()
{
	setlocale(LC_ALL, "Rus");
	char* str;
	int kr = 0, kv = 0, fg = 0; 
	int i = 0;
	str = (char*)malloc((n + 1) * sizeof(char));
	printf("\nВведите выражение: ");
	fgets(str, (n + 1), stdin);
	rec(str, kr, kv, fg, i);
}

int rec(char* str, int kr, int kv, int fg, int i)
{

	if (kr < 0 || kv < 0 || fg < 0) 
		return (printf("Cкобки расставлены НЕВЕРНО\n"));

	for (i; str[i]; )
		switch (str[i])
		{
		case '(': return rec(str + 1, kr + 1, kv, fg, i++);
		case ')': return rec(str + 1, kr - 1, kv, fg, i++);
		case '[': return rec(str + 1, kr, kv + 1, fg, i++);
		case ']': return rec(str + 1, kr, kv - 1, fg, i++);
		case '{': return rec(str + 1, kr, kv, fg + 1, i++);
		case '}': return rec(str + 1, kr, kv, fg - 1, i++);
		default: return rec(str + 1, kr, kv, fg, i++);
		}
	if (kr == 0 && kv == 0 && fg == 0)
		return(printf("Скобки расставлены ВЕРНО\n"));
	else
		return (printf("Cкобки расставлены НЕВЕРНО\n"));
}

