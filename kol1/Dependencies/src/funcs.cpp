#include <utils/funcs.h>

#include <stdexcept>
#include <set>

std::vector<size_t> n_factorial(size_t n)
{
	if (n < 1)
	{
		throw std::invalid_argument("Natural number expected!");
	}
	std::vector<size_t> data(n);
	data[0] = 1;
	for (size_t i = 2; i <= n; i++)
	{
		data[i - 1] = i * data[i - 2];
	}
	return data;
}

std::vector<size_t> n_factorial(size_t n, size_t modulo)
{
	if (n < 1)
	{
		throw std::invalid_argument("Natural number expected!");
	}
	std::vector<size_t> data(n);
	data[0] = 1;
	for (size_t i = 2; i <= n; i++) 
	{
		data[i - 1] = (i % modulo * data[i - 2]) % modulo;
	}
	return data;
}

std::vector<double> remove_duplicates(std::vector<double> src)
{
	std::vector<double> res;
	std::set<double> mem;
	res.reserve(src.size());
	for (size_t i = 0; i < src.size(); i++) 
	{
		if (!mem.contains(src[i]))
		{
			res.push_back(src[i]);
			mem.insert(src[i]);
		}
	}
	return res;
}



