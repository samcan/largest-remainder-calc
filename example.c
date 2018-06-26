/* example.c
Sample code showing how to use the library.*/
#include <stdio.h>
#include "largest_remainder_calc.h"

int main() {
	long total_parties = 6;
	long votes[total_parties];
	long seats;

	/* the 100,000 votes were split among the following
	parties */
	votes[0] = 47000;
	votes[1] = 16000;
	votes[2] = 15800;
	votes[3] = 12000;
	votes[4] = 6100;
	votes[5] = 3100;

	/* there are 10 seats up for grabs */
	seats = 10;

	long seats_allocated = 0;
	long results[total_parties];
	seats_allocated = largest_remainder_calc(seats, total_parties, votes, HARE_QUOTA, results);

	printf("Party\tSeats\n");
	for (int i = 0; i < total_parties; i++) {
		printf("%d\t%4ld\n", i+1, results[i]);
	}
	printf("Total\t%4ld\n", seats_allocated);

	return 0;
}
