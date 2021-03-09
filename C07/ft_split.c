#include <stdlib.h>
#include <stdio.h>

int is_same(char *str, char *charset)
{
	int cnt;
	
	cnt = 0;
	while(charset[cnt])
	{
		if(charset[cnt] != str[cnt])
			return (0);
		cnt++;
	}
	return (cnt);
}
void arr_fill(char *str, char *charset, int *arr)
{
	int i;
	int cnt;
	int a_cnt;
	int tmp;

	a_cnt = 0;
	cnt = 0;
	i = -1;
	while(str[++i])
	{
		if(tmp = is_same(&str[i], charset))
		{
			arr[a_cnt] = cnt;
			cnt = 0;
			a_cnt ++;
			i += tmp - 1;
		}
		cnt++;
	}
	arr[a_cnt] = cnt;
}
void split(char *str, char *charset, char **sol)
{
	int move;
	int i;
	int j;
	int tmp;

	move = -1;
	i = 0;
	j = 0;
	while(str[++move])
	{
		if(tmp = is_same(&str[move], charset))
		{
			sol[i][j] = '\0';
			i++;
			j = 0;
			move += tmp - 1;
		}
		else
			sol[i][j++] = str[move];	
	}
	sol[i][j] = '\0';
}
char **ft_split(char *str, char *charset)
{
	int size;
	int move;
	int *arr;
	char **sol;
	
	size = 0;
	move = -1;
	while (str[++move])
		if(is_same(&str[move], charset))
			size++;	
	arr = (int *)malloc(sizeof(int) * (size + 1));
	sol = (char **)malloc(sizeof(char *) * (size + 1));
	arr_fill(str, charset, arr);
	move = -1;
	while(++move <= size)
		sol[move] = (char *)malloc(sizeof(char *) * (arr[move] + 1));
	split(str, charset, sol);
	return (sol);
}
int main()
{
	char srr[100] = "hello||mynameis|korea";
	char set[3] = "|";
	char **tmp = ft_split(srr,set);
	for(int i = 0 ; i < 4; i++)
		printf("%s\n", tmp[i]);

}
