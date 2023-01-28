
#include <thread>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
int primes[100000001];
int lastprimes[100];
int index = 2;
int counter = 0;
#define MAX 100000000

bool isPrime(int tempind)
{
	if (tempind == 2 || tempind == 3)
		return true;

	if (tempind <= 1 || tempind % 2 == 0 || tempind % 3 == 0)
		return false;

	for (int i = 5; i * i <= tempind; i += 6)
	{
		if (tempind % i == 0 || tempind % (i + 2) == 0)
			return false;
	}
	return true;
}

void checkPrimes(int min, int max) {
	
	for(int i=min; i<=max; i++){

		if (isPrime(i)) {
			primes[i] = 1;
		}
	}
}



int main()
{
	int primesindex = 0;
	memset(primes, 0, sizeof(primes));

	auto start = std::chrono::steady_clock::now();


	std::thread t1(checkPrimes, 1, 15000000 );
	std::thread t2(checkPrimes, 15000001, 30000000);
	std::thread t3(checkPrimes, 30000001, 45000000);
	std::thread t4(checkPrimes, 45000001, 60000000);
	std::thread t5(checkPrimes, 60000001, 70000000);
	std::thread t6(checkPrimes, 70000001, 80000000);
	std::thread t7(checkPrimes, 80000001, 90000000);
	std::thread t8(checkPrimes, 90000001, 100000000);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();


	//auto finish = std::chrono::steady_clock::now();

	unsigned long long int sum = 0;

	int numOfPrimes = 5761455;

	for (int i = 0; i <= MAX; i++) {
		if (primes[i] == 1) {
			counter++;
			sum += i;
			numOfPrimes--;
			if (numOfPrimes < 10) {
				lastprimes[primesindex] = i;
				primesindex++;
			}
		}
	}

	auto finish = std::chrono::steady_clock::now();

	double time = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();


	
	ofstream prime;
	prime.open("primes.txt");

	prime << time << " ";
	prime << counter << " ";
	prime << sum << " ";

	for (int i = 0; i < 10; i++) {
		prime<<lastprimes[i]<< " ";
	}


	prime.close();




	return 0;

}

