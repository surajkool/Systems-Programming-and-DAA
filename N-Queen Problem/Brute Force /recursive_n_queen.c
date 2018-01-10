#include <stdio.h>

int QUEENS;

void printBoard(int positions[QUEENS]) {
	int i, j;
	for(i = 0;i < QUEENS;i++) {
		for(j = 0;j < QUEENS;j++) {
			if (j == positions[i] - 1) {
				printf("Q\t");
			} else {
				printf("0\t");
			}
		}
		printf("\n");
	}
}

int checkSolution(int positions[QUEENS]) {

	int i;
	for(i=0;i<QUEENS;i++) {

		int position = positions[i];
		int row, column;

		// check attack in column
		for(row = 1;row<QUEENS;row++) {
			int k;
			for(k=0;k<QUEENS;k++) {
				if(k != i && positions[k] == positions[i]) {
					return 0;
				}
			}
		}
		// check attack in diagonals
		int k, count;
		for(k = i + 1, count = 1;k < QUEENS;k++, count++) {
			if (position == positions[k] + count || position == positions[k] - count) {
				return 0;
			}
		}

	}

	return 1;

}

void recursive(int positions[QUEENS], int currentPosition, int *solutionCount) {

	int i;
	for(i=0;i<QUEENS;i++) {

		positions[currentPosition] = i + 1;

		if (currentPosition + 1 == QUEENS) {

			int bool = checkSolution(positions);
			if (bool == 1) {

				printf("Solution %d\n", *solutionCount);
				*solutionCount += 1;
				printBoard(positions);

			}

		} else {

			recursive(positions, currentPosition + 1, solutionCount);

		}

	}

}

int main() {

	printf("Enter the Number of Queens\n");
	scanf("%d", &QUEENS);

	int positions[QUEENS];
	int solutionCount = 1;

	recursive(positions, 0, &solutionCount);

}
