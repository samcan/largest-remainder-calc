# largest-remainder-calc

`largest_remainder_calc` is a single-file C header library for calculating seat apportionment using the largest remainder method (also known as the Hamilton method, Hare-Niemeyer method, and Vinton's method).

Note that this library only maintains compatibility with C99 and C11. We are not maintaining compatibility with C89.

## How to use with example
Download `largest_remainder_calc.h` into your source code folder.

Include the header file in your source code:

    #include "largest_remainder_calc.h"
    
A fully commented source code example follows:

    #include <stdio.h>
    #include "largest_remainder_calc.h"
    
    int main() {
      /* Example from https://en.wikipedia.org/wiki/Largest_remainder_method */
      /* We have 10 seats to apportion */
      long num_seats = 10;
      
      /* There were 6 parties to vote for, and of the 100,000 votes
      cast, they received the following number of votes */
      long num_parties = 6;
      long votes[num_parties];
      votes[0] = 47000;
      votes[1] = 16000;
      votes[2] = 15800;
      votes[3] = 12000;
      votes[4] = 6100;
      votes[5] = 3100;
      
      long seats_allocated = 0;
      long results[num_parties];
      seats_allocated = largest_remainder_calc(num_seats, num_parties, votes, HARE_QUOTA, results);
      
      /* Print the results */
      printf("Party\tSeats\n");
      for (int i = 0; i < num_parties; i++) {
        printf("%d\t%4ld\n", i+1, results[i]);
      }
      printf("Total\t%4ld\n", seats_allocated);
      
      return 0;
    }

To compile, if the source file is named `example.c` and we want to compile to program `example`:

    gcc -std=c99 example.c -o example

Running `example` will provide the below output:

    Party	Seats
    1	   5
    2	   2
    3	   1
    4	   1
    5	   1
    6	   0
    Total	  10
