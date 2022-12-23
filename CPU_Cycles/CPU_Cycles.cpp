// CPU_Cycles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>


// Credits to VMRAY for their talk on antisandboxing
// Nicer way to do it than just comparing the amount of CPU cycles burnt
// by CloseHandle and GetProcessHeap for instance.
int main()
{
	long long tsc, acc = 0; // setup tsc and accumulator var
	int avg = 0;
	int out[4]; // buffer for cpuidex to write into


	// loop a 100 times for precision idk (tweak to your needs)
	for (int i = 0; i < 100; ++i) {
		tsc = __rdtsc(); // get the amount of cpu cycles
		__cpuidex(out, 0, 0); // burn some cpu cycles
		acc += __rdtsc() - tsc; // smack in the accumulator the current cpu timestamp - the previous one 
	}

	avg = acc / 100; // divide per 100 to get the average
	std::cout << "Burnt cycles between resets average: " << avg;

}