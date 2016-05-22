#include<stdio.h>

int a[] = { 1 ,2 ,3 ,4};
int b[] = { 0 ,0 ,0 ,0};
int c[] = { 0 ,0 ,0 ,0};

const int MaxDisk = 4;

void printPole()
{

	for (int i = MaxDisk - 1 ; i >= 0; i--)
	{
		printf(" %d %d %d\n", a[i],b[i],c[i]);

	}
	printf("\n");
	printf("\n");
}

int diskCounter(int _pole[]) 
{
	int counter = 0;
	for (int i = 0; i < MaxDisk; i++)
	{
		if (_pole[i] != 0)
		{
			counter++;
		}
	}
	//printf("%d\n", counter);
	return counter;
}

void move(int from[], int to[], int other[], int n)
{


	if (n < 1)
	{
		return;
	}
	else if (n == 1)
	{

		int temporary = to[diskCounter(to)];
		to[diskCounter(to)] = from[ diskCounter(from) - 1 ];
		from[diskCounter(from) - 1] = temporary;

		printPole();

	}
	else
	{

		move(from, other, to, n - 1);

		int temporary = to[diskCounter(to)];
		to[diskCounter(to)] = from[diskCounter(from) - 1];
		from[diskCounter(from) - 1] = temporary;

		printPole();
	
		move(other , to , from, n - 1);

	}

}


void main() {

	printPole();

	move(a, c, b, MaxDisk);

	getchar();

}