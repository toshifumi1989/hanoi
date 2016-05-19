#include<stdio.h>

const int MaxDisk = 3;

int a[3] = { 1 ,2 ,3 };
int b[3] = { 0 ,0 ,0 };
int c[3] = { 0 ,0 ,0 };

int diskCounter[3] = { 2,0,0 };

void printPole() {

	for (int i = 0; i < 3; i++) {
		printf(" %d ", a[i]);

	}
	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf(" %d ", b[i]);
	}
	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf(" %d ", c[i]);
	}
	printf("\n");
	printf("\n");
}

void move(int from[], int to[], int work[] ,int n) {

	if (n == 1) {
		to[0] = from[MaxDisk - 1];
		from[MaxDisk - 1] = 0;

		printPole();
	}
	else {

		if (n % 2 == 0)
		{
			int temporary = work[diskCounter[1]];

			work[diskCounter[1]] = from[diskCounter[0]];
			diskCounter[1] += 1;

			from[diskCounter[0]] = temporary;
			diskCounter[0] -= 1;

		}
		else
		{
			int temporary = to[diskCounter[2]];

			to[diskCounter[2]] = from[diskCounter[0]];
			diskCounter[2] += 1;

			from[n - 1] = temporary;
			diskCounter[0] -= 1;
		}
		

		printPole();

		move(work, to, from, n - 1);

	}

}


void main() {

	printPole();

	move(a, c, b, 3);

	getchar();

}