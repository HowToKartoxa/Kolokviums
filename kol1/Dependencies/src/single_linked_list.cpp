#include <utils/single_linked_list.h>

template<typename T>
Node<T>::Node(T val) : data(val), next(nullptr) {}

template<typename T>
Node<T>::~Node() {}

template <typename T>
SingleLinkedList<T>::SingleLinkedList() : head(nullptr) {}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() 
{
	Node<T>* temp = head;
	while (temp != nullptr) 
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}

template <typename T>
void SingleLinkedList<T>::Reverse() 
{
	ReverseRecursive(head);
}

template <typename T>
void SingleLinkedList<T>::ReverseRecursive(Node<T>* curr)
{
	if (curr == nullptr) return;
	if (curr->next == nullptr) 
	{
		head = curr;
		return;
	}
	ReverseRecursive(curr->next);
	curr->next->next = curr;
	curr->next = nullptr;
}