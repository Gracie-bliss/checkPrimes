Gracie Bliss
COP 4520
Spring 2023

Summary:

First I created a function that checks if the number is a prime. I then created a function that call the first function and that marks it as a prime with a 1 or leaves it as a 0 as not prime. I then created the threads and divided that 1 to 10^8 by 8 threads. Finally I found the sum, then the count, and added a clock around the threads. I then opened a file called primes.txt to output to.

Justification: 
By dividing the numbers into 8 threads each thread is checking around the same amount of numbers at the same time and can determine if it is a prime much faster.


Evaluation:
First I made sure the checkPrimes fucntion recognized all the numbers it needed to. Once I knew that I checked that it found the primes correctly with no threads. Once that was confirmed I checked that the threads worked. Finally I printed out all the correct information. The program was much slower without being multi-threaded.

To run the progra use g++.
