#include <stdio.h>

#define QUEENS 8

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

void generateSequence() {
	int positions[QUEENS];
	int solutionCount = 1;
	int i, j, k, l, m, n , o, p;
	for(i=0;i<QUEENS;i++) {
		for(j=0;j<QUEENS;j++) {
			for(k=0;k<QUEENS;k++) {
				for(l=0;l<QUEENS;l++) {
					for(m=0;m<QUEENS;m++) {
						for(n=0;n<QUEENS;n++) {
							for(o=0;o<QUEENS;o++) {
								for(p=0;p<QUEENS;p++) {
									positions[0] = i + 1;
									positions[1] = j + 1;
									positions[2] = k + 1;
									positions[3] = l + 1;
									positions[4] = m + 1;
									positions[5] = n + 1;
									positions[6] = o + 1;
									positions[7] = p + 1;
									int bool = checkSolution(positions);
									if (bool == 1) {
										printf("Solution %d\n\n", solutionCount);
										solutionCount++;
										printBoard(positions);
										printf("\n");
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int main() {

	generateSequence();

}
