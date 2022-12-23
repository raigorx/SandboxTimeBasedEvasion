// KSYSTEM_TIME.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "windows.h"

#define MS_PER_SECOND 10000000

unsigned long long __get_timestamp()
{
	const size_t UNIX_TIME_START = 0x019DB1DED53E8000; // Start of Unix epoch in ticks.
	const size_t TICKS_PER_SECOND = 10000000; // A tick is 100ns.
	LARGE_INTEGER time;
	time.LowPart = *(DWORD*)(0x7FFE0000 + 0x14); // Read LowPart as unsigned long.
	time.HighPart = *(long*)(0x7FFE0000 + 0x1c); // Read High1Part as long.
	return (unsigned long long)((time.QuadPart - UNIX_TIME_START) / TICKS_PER_SECOND);
}

void __alt_sleep_seconds(size_t seconds)
{
	volatile size_t x = rand(); // random buffer var 
	const unsigned long long end = __get_timestamp() + seconds; // calculate when we shall stop sleeping
	while (__get_timestamp() < end) { x += 1; } // increment random var by 1 till we reach our endtime
	if (__get_timestamp() - end > 2000) return; // Fast Forward check, might need some tuning

}

int main()
{
	const size_t SECONDS = 5;
	std::cout << "__get_timestamp()\n";
    std::cout << __get_timestamp() << "\n";
	__alt_sleep_seconds(SECONDS);
	std::cout << __get_timestamp() << "\n";
	return 0;
}
