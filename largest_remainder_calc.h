#include <float.h>

/* Define various quota calculation methods we can use
in making our determination */
#define HARE_QUOTA	1
#define DROOP_QUOTA	2

#define INTERNAL_FALSE	0
#define INTERNAL_TRUE	!(INTERNAL_FALSE)

long largest_remainder_calc(long n_seats,
			long n_parties,
			long votes[],
			int quota_method,
			long results[]);
long rank(float numbers[], long len, float n);
void sort_array_desc(float numbers[], long len);
int float_equals(float a, float b);

long largest_remainder_calc(long n_seats,
			long n_parties,
			long votes[],
			int quota_method,
			long results[]) {
	/* Calc the total number of votes */
	long n_votes = 0;
	for (int i = 0; i < n_parties; i++) {
		n_votes += votes[i];
	}

	/* Calculate the appropriate quota */
	float quota = 0.0;
	if (quota_method == HARE_QUOTA) {
		quota = n_votes / n_seats;
	} else {
		/* calc the DROOP quota. Note that this could also be called if
		an unspecified value is passed for quota_method. */
		quota = (int)(1 + (n_votes / (1 + n_seats)));
	}

	/* Calculate the votes per quota for each of the parties and allocate
	the integer portion to each of the parties. These are their automatic
	seats. */
	float votes_per_quota[n_parties];
	long n_seats_alloc = 0;
	for (int i = 0; i < n_parties; i++) {
		votes_per_quota[i] = votes[i] / quota;

		results[i] = (int) votes_per_quota[i];
		n_seats_alloc += results[i];
	}

	/* Check to see if we've automatically allocated all the seats, because
	if we have, our work here is done. */
	long diff = 0;
	if ((diff = n_seats - n_seats_alloc) > 0) {
		/* We haven't automatically allocated all the seats, so now
		we'll sort by the largest remainders and give seats in that
		order until all seats are allocated. */
		float remainders[n_parties];
		for (int i = 0; i < n_parties; i++) {
			remainders[i] = votes_per_quota[i] - (int)votes_per_quota[i];
		}

		for (int i = 1; i <= diff; i++) {
			for (int j = 0; j < n_parties; j++) {
				if (rank(remainders, n_parties, remainders[j]) == i) {
					results[j]++;
					n_seats_alloc++;
				}
			}
		}
	}

	return n_seats_alloc;
}

long rank(float numbers[], long len, float n) {
	/* given numbers[], give the descending-order rank of n */
	/* returns the rank of n; returns -1 for error */
	/* TODO Handle ties, we'll want to implement specified seed number */

	/* copy array and then sort */
	float output[len];
	for (int i = 0; i < len; i++) {
		output[i] = numbers[i];
	}
	sort_array_desc(output, len);

	long rank = -1;
	for (int i = 0; i < len; i++) {
		if (float_equals(output[i], n)) {
			rank = i + 1;
			break;
		}
	}
	return rank;
}

void sort_array_desc(float numbers[], long len) {
	/* sort numbers[] in descending order */
	/* TODO replace with faster sort algorithm */
	/* algorithm from https://en.wikipedia.org/wiki/Insertion_sort */
	int i = 1;
	while (i < len) {
		int j = i;
		while (j > 0 && numbers[j-1] < numbers[j]) {
			float temp;
			temp = numbers[j];
			numbers[j] = numbers[j-1];
			numbers[j-1] = temp;
			j--;
		}
		i++;
	}

	return;
}

int float_equals(float a, float b) {
	float diff = a - b;
	if (diff < 0)
		diff *= -1;

	if (diff < FLT_EPSILON) {
		return INTERNAL_TRUE;
	} else {
		return INTERNAL_FALSE;
	}
}
