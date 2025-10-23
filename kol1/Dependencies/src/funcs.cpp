#include <utils/funcs.h>
#include <stdexcept>

std::vector<size_t> n_factorial
(
	size_t n,
	size_t modulo
)
{
	if (n < 1)
	{
		throw std::invalid_argument("Natural number expacted!");
	}
	std::vector<size_t> data(n);
	data[0] = 1;
	for (size_t i = 2; i <= n; i++) 
	{
		data[i - 1] = i * data[i - 2];
	}
	return data;
}

std::vector<long long> remove_duplicates
(
	std::vector<long long> src
)
{

}