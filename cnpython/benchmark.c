#ifndef __cplusplus
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#else
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#endif

#include "./include/cnpython.h"

/**
 * Gets the current time.
 * @return The current time, in seconds.
 **/
double get_current_time();

double benchmark(void func(void *, size_t), void *data, size_t numBytes, int numBenchmarks)
{
	double mean_time = 0.0; /** The time the benchmark ran. **/
	double total_time = 0.0; /** The total time. **/
	int i;

	printf("----------------------------\nStarting benchmark...\n----------------------------\n");

	for(i = 0; i < numBenchmarks; ++i)
	{
		double start_time = 0.0; /** The time the benchmark started. **/
		double end_time = 0.0; /** The time the benchmark ended. **/
		double bench_time = 0.0; /** end_time - start_time **/

		/* Start the benchmark. */
		start_time = get_current_time();

		/* Call the function to benchmark. */
		func(data, numBytes);

		/* End the benchmark. */
		end_time = get_current_time();
		bench_time = end_time - start_time;

		/* Add the benchmark time to the total time. */
		total_time += bench_time;

		/* Add the benchmark time to mean_time and if it wasn't 0, divide by 2. */
		if(mean_time)
			mean_time = (mean_time + bench_time) / 2;
		else
			mean_time = bench_time;

		/* Print the current step. */
		printf("Completed step %d\tTime spent: %fms\n", i + 1, bench_time * 1000);
	}

	/* Gobal time spent in the benchmark. */
	printf("----------------------------\nEnded benchmark!\n");
	printf("Total time spent: %fms\n", total_time * 1000);
	printf("Mean time spent: %fms\n----------------------------\n", mean_time * 1000);

	/* Return the mean time. */
	return mean_time;
}

/* Implement get_current_time() depending on the OS. */
#if defined(WIN32) || defined(__WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN32_)

#include <windows.h>

double get_current_time() {
	LARGE_INTENGER t, f;
	QueryPerformanceCounter(&t);
	QueryPerformanceFrequency(&f);
	return (double)t.QuadPart/(double)f.QuadPart;
}

#else

#include <sys/time.h>
#include <sys/resource.h>

double get_current_time() {
	struct timeval t;
	gettimeofday(&t, 0);
	return t.tv_sec + t.tv_usec*1e-6;
}

#endif


static void bm_bin(){
    bin(1000);
}


int main(void){
    benchmark(bm_bin, NULL, 100, 100);

    return 0;
}