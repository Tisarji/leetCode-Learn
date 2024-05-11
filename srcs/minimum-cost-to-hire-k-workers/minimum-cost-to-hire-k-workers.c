/** FILE: minimum-cost-to-hire-k-workers.c
 * Subject: MINIMUM-COST-TO-HIRE-K-WORKERS
 *
 * There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.
 *
 * We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:
 *
 * Every worker in the paid group must be paid at least their minimum wage expectation.
 * In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.
 * Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.
 *
 * Example 1:
 *
 * Input: quality = [10,20,5], wage = [70,50,30], k = 2
 * Output: 105.00000
 * Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
 *
 * Example 2:
 *
 * Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
 * Output: 30.66667
 * Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
 *
 * Constraints:
 *
 * n == quality.length == wage.length
 * 1 <= k <= n <= 104
 * 1 <= quality[i], wage[i] <= 104
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * The struct Worker contains data members for quality, wage, and ratio.
 * @property {int} quality - Quality refers to the level of skill or proficiency of the worker in
 * performing their job tasks. It can be measured based on factors such as experience, education, and
 * performance.
 * @property {int} wage - The `wage` property in the `Worker` struct represents the amount of money a
 * worker is paid for their work. It typically refers to the hourly or monthly salary that a worker
 * receives for their services.
 * @property {double} ratio - The `ratio` property in the `Worker` struct represents the ratio of the
 * worker's wage to their quality of work. It is calculated by dividing the worker's wage by their
 * quality score.
 */
struct Worker
{
	int quality;
	int wage;
	double ratio;
};

/**
 * The function `compare` compares the `ratio` values of two `Worker` structures.
 * 
 * @param a The parameter `a` is a pointer to a constant void type, which is then cast to a pointer to
 * a constant struct Worker type in the `compare` function.
 * @param b The parameter `b` in the `compare` function is a pointer to a constant void type. In this
 * specific context, it is being cast to a pointer to a constant struct Worker type.
 * 
 * @return The `compare` function is returning the result of the expression `(worker1->ratio <
 * worker2->ratio) - (worker1->ratio > worker2->ratio)`. This expression compares the `ratio` values of
 * two `Worker` structures and returns -1 if the ratio of `worker1` is less than the ratio of
 * `worker2`, 0 if they are equal, and
 */

// Comparator function for qsort to sort workers by their ratio
int compare(const void *a, const void *b)
{
	const struct Worker *worker1 = (const struct Worker *)a;
	const struct Worker *worker2 = (const struct Worker *)b;
	return (worker1->ratio < worker2->ratio) - (worker1->ratio > worker2->ratio);
}

/**
 * The function calculates the minimum cost to hire k workers based on their quality and wage ratios.
 * 
 * @param quality The `quality` array contains the quality values of workers. Each element represents
 * the quality of a worker at a specific index.
 * @param qualitySize The parameter `qualitySize` represents the number of workers available for hire.
 * It indicates the size of the arrays `quality` and `wage`, which contain the quality and wage values
 * for each worker respectively.
 * @param wage The `wage` parameter is an array containing the wages of workers. The size of this array
 * is given by `wageSize`. Each element in the `wage` array corresponds to the wage of a specific
 * worker.
 * @param wageSize The `wageSize` parameter represents the size of the `wage` array, which contains the
 * wages of the workers. It is used to determine the number of elements in the `wage` array.
 * @param k The parameter `k` in the `mincostToHireWorkers` function represents the number of workers
 * you want to hire. It is used to calculate the minimum cost of hiring `k` workers based on their
 * quality and wage values.
 * 
 * @return The function `mincostToHireWorkers` returns a `double` value, which represents the minimum
 * cost to hire `k` workers based on their quality and wage information provided as input.
 */
double mincostToHireWorkers(int *quality, int qualitySize, int *wage, int wageSize, int k)
{
	struct Worker *workers = malloc(qualitySize * sizeof(struct Worker));
	for (int i = 0; i < qualitySize; i++)
	{
		workers[i].quality = quality[i];
		workers[i].wage = wage[i];
		workers[i].ratio = (double)wage[i] / quality[i];
	}

	qsort(workers, qualitySize, sizeof(struct Worker), compare);

	double minCost = __INT_MAX__;
	int qualitySum = 0;
	for (int i = 0; i < qualitySize; i++)
	{
		qualitySum += workers[i].quality;
		if (i >= k - 1)
		{
			minCost = fmin(minCost, (double)qualitySum * workers[i].ratio);
			qualitySum -= workers[i - k + 1].quality;
		}
	}

	free(workers);
	return (minCost);
}

int main(void)
{
	int quality1[] = {10, 20, 5};
	int wage1[] = {70, 50, 30};
	int k1 = 2;
	double result1 = mincostToHireWorkers(quality1, 3, wage1, 3, k1);
	printf("Example 1: %.5f\n", result1);

	int quality2[] = {3, 1, 10, 10, 1};
	int wage2[] = {4, 8, 2, 2, 7};
	int k2 = 3;
	double result2 = mincostToHireWorkers(quality2, 5, wage2, 5, k2);
	printf("Example 2: %.5f\n", result2);

	return 0;
}
