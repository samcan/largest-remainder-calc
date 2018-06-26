/* tests.c

Copyright (C) 2018	Sam Cantrell

This file is licensed under the MIT License. Please see LICENSE
for more information.

See http://eradman.com/posts/tdd-in-c.html which is based off
http://www.jera.com/techinfo/jtns/jtn002.html which states we can use
the original code for any purpose, as long as we realise that it comes
with no warranty.
*/

#include <stdio.h>
#include <float.h>
#include "largest_remainder_calc.h"

int tests_run = 0;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

int wiki_test_hare() {
	/* Example problem from
	https://en.wikipedia.org/wiki/Largest_remainder_method --
	demonstrates the Hare quota */
	long total_parties = 6;
	long votes[total_parties];
	long seats;

	long expected_results[total_parties];

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

	/* the expected number of seats for each
	party is as follows */
	expected_results[0] = 5;
	expected_results[1] = 2;
	expected_results[2] = 1;
	expected_results[3] = 1;
	expected_results[4] = 1;
	expected_results[5] = 0;

	long seats_allocated = 0;
	long results[total_parties];
	seats_allocated = largest_remainder_calc(seats, total_parties, votes, HARE_QUOTA, results);

	_assert(seats_allocated == seats);
	for (long i = 0; i < total_parties; i++) {
		_assert(results[i] == expected_results[i]);
	}

	return 0;
}

int wiki_test_droop() {
	/* Example problem from
	https://en.wikipedia.org/wiki/Largest_remainder_method --
	demonstrates the Droop quota */
	long total_parties = 6;
	long votes[total_parties];
	long seats;

	long expected_results[total_parties];

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

	/* the expected number of seats for each
	party is as follows */
	expected_results[0] = 5;
	expected_results[1] = 2;
	expected_results[2] = 2;
	expected_results[3] = 1;
	expected_results[4] = 0;
	expected_results[5] = 0;

	long seats_allocated = 0;
	long results[total_parties];
	seats_allocated = largest_remainder_calc(seats, total_parties, votes, DROOP_QUOTA, results);

	_assert(seats_allocated == seats);
	for (long i = 0; i < total_parties; i++) {
		_assert(results[i] == expected_results[i]);
	}

	return 0;
}

int electorama_test_hare01() {
	/* Example problem from
	https://wiki.electorama.com/wiki/Largest_remainder_method */
	long total_parties = 6;
	long votes[total_parties];
	long seats;

	long expected_results[total_parties];

	/* the 5,100 votes were split among the following
	parties */
	votes[0] = 1500;
	votes[1] = 1500;
	votes[2] = 900;
	votes[3] = 500;
	votes[4] = 500;
	votes[5] = 200;

	/* there are 25 seats up for grabs */
	seats = 25;

	/* the expected number of seats for each
	party is as follows */
	expected_results[0] = 7;
	expected_results[1] = 7;
	expected_results[2] = 4;
	expected_results[3] = 3;
	expected_results[4] = 3;
	expected_results[5] = 1;

	long seats_allocated = 0;
	long results[total_parties];
	seats_allocated = largest_remainder_calc(seats, total_parties, votes, HARE_QUOTA, results);

	_assert(seats_allocated == seats);
	for (long i = 0; i < total_parties; i++) {
		_assert(results[i] == expected_results[i]);
	}

	return 0;
}

int electorama_test_hare02() {
	/* Example problem from
	https://wiki.electorama.com/wiki/Largest_remainder_method */
	long total_parties = 6;
	long votes[total_parties];
	long seats;

	long expected_results[total_parties];

	/* the 5,100 votes were split among the following
	parties */
	votes[0] = 1500;
	votes[1] = 1500;
	votes[2] = 900;
	votes[3] = 500;
	votes[4] = 500;
	votes[5] = 200;

	/* there are 26 seats up for grabs */
	seats = 26;

	/* the expected number of seats for each
	party is as follows */
	expected_results[0] = 8;
	expected_results[1] = 8;
	expected_results[2] = 5;
	expected_results[3] = 2;
	expected_results[4] = 2;
	expected_results[5] = 1;

	long seats_allocated = 0;
	long results[total_parties];
	seats_allocated = largest_remainder_calc(seats, total_parties, votes, HARE_QUOTA, results);

	_assert(seats_allocated == seats);
	for (long i = 0; i < total_parties; i++) {
		_assert(results[i] == expected_results[i]);
	}

	return 0;
}

int fairvote_test_hare() {
	/* Example problem from
	http://www.fairvote.org/how_proportional_representation_elections_work --
	appears to utilize the Hare method */
	long total_parties = 5;
	long votes[total_parties];
	long seats;

	long expected_results[total_parties];

	/* the 100,000 votes were split among the following
	parties */
	votes[0] = 38000;
	votes[1] = 23000;
	votes[2] = 21000;
	votes[3] = 12000;
	votes[4] = 6000;

	/* there are 10 seats up for grabs */
	seats = 10;

	/* the expected number of seats for each
	party is as follows */
	expected_results[0] = 4;
	expected_results[1] = 2;
	expected_results[2] = 2;
	expected_results[3] = 1;
	expected_results[4] = 1;

	long seats_allocated = 0;
	long results[total_parties];
	seats_allocated = largest_remainder_calc(seats, total_parties, votes, HARE_QUOTA, results);

	_assert(seats_allocated == seats);
	for (long i = 0; i < total_parties; i++) {
		_assert(results[i] == expected_results[i]);
	}

	return 0;
}

int polyas_test_hare() {
	/* Example problem from
	https://www.polyas.com/election-glossary/hare-niemeyer --
	uses the Hare method */
	long total_parties = 4;
	long votes[total_parties];
	long seats;

	long expected_results[total_parties];

	/* the 176 votes were split among the following
	parties */
	votes[0] = 85;
	votes[1] = 35;
	votes[2] = 44;
	votes[3] = 12;


	/* there are 8 seats up for grabs */
	seats = 8;

	/* the expected number of seats for each
	party is as follows */
	expected_results[0] = 4;
	expected_results[1] = 2;
	expected_results[2] = 2;
	expected_results[3] = 0;

	long seats_allocated = 0;
	long results[total_parties];
	seats_allocated = largest_remainder_calc(seats, total_parties, votes, HARE_QUOTA, results);

	_assert(seats_allocated == seats);
	for (long i = 0; i < total_parties; i++) {
		_assert(results[i] == expected_results[i]);
	}

	return 0;
}

int mlwiki_test_hare01() {
	/* Example problem from
	http://mlwiki.org/index.php/Hamilton%27s_Method --
	appears to use the Hare method */
	long total_parties = 4;
	long votes[total_parties];
	long seats;

	long expected_results[total_parties];

	/* the votes were split among the following
	parties */
	votes[0] = 6373;
	votes[1] = 2505;
	votes[2] = 602;
	votes[3] = 520;


	/* there are 10 seats up for grabs */
	seats = 10;

	/* the expected number of seats for each
	party is as follows */
	expected_results[0] = 6;
	expected_results[1] = 2;
	expected_results[2] = 1;
	expected_results[3] = 1;

	long seats_allocated = 0;
	long results[total_parties];
	seats_allocated = largest_remainder_calc(seats, total_parties, votes, HARE_QUOTA, results);

	_assert(seats_allocated == seats);
	for (long i = 0; i < total_parties; i++) {
		_assert(results[i] == expected_results[i]);
	}

	return 0;
}

int mlwiki_test_hare02() {
	/* Example problem from
	http://mlwiki.org/index.php/Hamilton%27s_Method --
	appears to use the Hare method */
	long total_parties = 4;
	long votes[total_parties];
	long seats;

	long expected_results[total_parties];

	/* the votes were split among the following
	parties */
	votes[0] = 6373;
	votes[1] = 2512;
	votes[2] = 603;
	votes[3] = 512;


	/* there are 10 seats up for grabs */
	seats = 10;

	/* the expected number of seats for each
	party is as follows TODO this is arbitrary due to the tie */
	expected_results[0] = 6;
	expected_results[1] = 2;
	expected_results[2] = 1;
	expected_results[3] = 1;

	long seats_allocated = 0;
	long results[total_parties];
	seats_allocated = largest_remainder_calc(seats, total_parties, votes, HARE_QUOTA, results);

	_assert(seats_allocated == seats);
	for (long i = 0; i < total_parties; i++) {
		_assert(results[i] == expected_results[i]);
	}

	return 0;
}

int test_tie_distribute_parties() {
	/* This is to help verify that in cases of ties and multiple seats
	remaining that seats are given to multiple parties rather than all to
	the same one. */
	long total_parties = 3;
	long votes[total_parties];
	long seats;

	long expected_results[total_parties];

	/* the votes were split among the following
	parties */
	votes[0] = 100;
	votes[1] = 100;
	votes[2] = 100;


	/* there are 8 seats up for grabs */
	seats = 8;

	/* the expected number of seats for each
	party is as follows TODO this is arbitrary due to the tie */
	expected_results[0] = 3;
	expected_results[1] = 3;
	expected_results[2] = 2;

	long seats_allocated = 0;
	long results[total_parties];
	seats_allocated = largest_remainder_calc(seats, total_parties, votes, HARE_QUOTA, results);

	_assert(seats_allocated == seats);
	for (long i = 0; i < total_parties; i++) {
		_assert(results[i] == expected_results[i]);
	}

	return 0;
}


int all_tests() {
	_verify(wiki_test_hare);
	_verify(wiki_test_droop);
	_verify(fairvote_test_hare);
	_verify(polyas_test_hare);
	_verify(electorama_test_hare01);
	_verify(electorama_test_hare02);
	_verify(mlwiki_test_hare01);
	_verify(mlwiki_test_hare02);
	_verify(test_tie_distribute_parties);
	return 0;
}

int main() {
	int result = all_tests();
	if (result == 0) {
		printf("PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
