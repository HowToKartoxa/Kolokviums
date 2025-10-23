#include <utils/funcs.h>
#include <utils/single_linked_list.h>

#include <iostream>
#include <vector>
#include <limits>

const size_t kModulo = 1000000007;

int main(int argc, char** argv) 
{
	std::cout << "enter N to calculate factorial:\n";
	
	size_t n;
	std::cin >> n;

	std::vector<size_t> result_vector;

	if (n > kFactorialMax) 
	{
		result_vector = n_factorial(n, kModulo);
		std::cout << "Factorials from 1 to " << n << " modulo " << kModulo << ":\n";
		for (size_t i = 0; i < n; i++) 
		{
			std::cout << i + 1 << " : " << result_vector[i] << '\n';
		}
	}
	else 
	{
		result_vector = n_factorial(n);
		std::cout << "Factorials from 1 to " << n << ":\n";
		for (size_t i = 0; i < n; i++)
		{
			std::cout << i + 1 << " : " << result_vector[i] << '\n';
		}
	}

	std::cout << "Enter vector size:\n";

	size_t size;
	std::cin >> size;

	std::vector<double> with_duplicates(size);
	std::vector<double> without_duplicates;

	std::cout << "Enter vector elements:\n";
	for (size_t i = 0; i < size; i++) 
	{
		std::cin >> with_duplicates[i];
	}
	without_duplicates = remove_duplicates(with_duplicates);

	std::cout << "Vector without duplicates:\n";
	for (size_t i = 0; i < without_duplicates.size(); i++)
	{
		std::cout << without_duplicates[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "Enter list size:\n";
	std::cin >> size;

	SingleLinkedList<int> list;
	int temp;
	Node<int>* temp_node;
	std::cout << "Enter list elements:\n";

	if (size > 0)
	{
		std::cin >> temp;
		list.head = new Node<int>(temp);
		list.head->next = nullptr;
	}
	
	temp_node = list.head;
	for (size_t i = 1; i < size; i++)
	{
		std::cin >> temp;
		temp_node->next = new Node<int>(temp);
		temp_node->next->next = nullptr;
		temp_node = temp_node->next;
	}

	list.Reverse();

	std::cout << "List after reversing:\n";
	temp_node = list.head;
	while (temp_node != nullptr) 
	{
		std::cout << temp_node->data << ' ';
		temp_node = temp_node->next;
	}
	std::cout << '\n';

	return 0;
}