#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
#include "Exceptions.h"

template <typename Type>
class Double_Linked_List {
	public:
		class Double_node {
			public:
				Double_node( Type const & = Type(), Double_node * = nullptr, Double_node * = nullptr );

				Type value() const;
				Double_node *previous() const;
				Double_node *next() const;

				Type         node_value;
				Double_node *previous_node;
				Double_node *next_node;
		};

		Double_Linked_List();
		Double_Linked_List( Double_Linked_List const & );
		Double_Linked_List( Double_Linked_List && );
		~Double_Linked_List();

		// Accessors
		int size() const;
		bool empty() const;

		Type front() const;
		Type back() const;

		Double_node *begin() const;
		Double_node *end() const;
		Double_node *revbegin() const;
		Double_node *revend() const;

		Double_node *find( Type const & ) const;
		int count( Type const & ) const;

		//Mutators
		void swap( Double_Linked_List & );
		Double_Linked_List &operator=( Double_Linked_List );
		Double_Linked_List &operator=( Double_Linked_List && );

		void push_front( Type const & );
		void push_back( Type const & );

		void pop_front();
		void pop_back();

		int erase( Type const & );

	private:
		Double_node *list_head;
		Double_node *list_tail;
		int list_size;

	template <typename T>
	friend std::ostream &operator<<( std::ostream &, Double_Linked_List<T> const & );
};

//CONSTRUCTORS
//Creates doubly linked list with sentinels
template <typename Type>
Double_Linked_List<Type>::Double_Linked_List():
// Updated the initialization list here
list_head( nullptr ),
list_tail( nullptr ),
list_size( 0 )
{
	// Enter your implementation here
	list_head = new Double_node(Type(), nullptr, list_tail); //This creates the head node of the doubly linked list
	list_tail = new Double_node(Type(), list_head, nullptr); //This creates the tail node of the doubly linked list
	list_head->next_node = list_tail; //Points list head's next node to the list tail
	list_tail->previous_node = list_head; //Basically does what previous line does, but points to list tail's previous node to list had
}

//COPY CONSTRUCTOR
//Creates new doubly linked list
//Copies all elements, in the same order, from linked list passed as argument
//Any changes to original linked list will not affect this new list
template <typename Type>
Double_Linked_List<Type>::Double_Linked_List( Double_Linked_List<Type> const &list ):
// Updated the initialization list here
list_head( nullptr ),
list_tail( nullptr ),
list_size( 0 )
{
	//Creates new doubly linked list
	list_head = new Double_node(Type(), nullptr, list_tail);
	list_tail = new Double_node(Type(), list_head, nullptr);
	list_head->next_node = list.begin();
	list_tail->previous_node = list_head;
	Double_node *t = list.begin(); //Creates temporary node that is the same as the passed list

	if(empty())
	{
		list_head->next_node = list_tail;
	}
	//While loop through passed list and stores all nodes into new list
	while(t != list.end())
	{
		push_back(t->value()); //Push back is used here because the function is copyong from head to tail
		t = t->next(); //Go to next list node
	}
}

//MOVE CONSTRUCTOR
//Creates new doubly linked list with all nodes found within passed linked list
//Calls upon Destructor after done running
template <typename Type>
Double_Linked_List<Type>::Double_Linked_List( Double_Linked_List<Type> &&list ):
// Updated the initialization list here
list_head( nullptr ),
list_tail( nullptr ),
list_size( 0 )
{
	swap( list );
	// ~Double_Linked_List();
}

//DESTRUCTOR
template <typename Type>
Double_Linked_List<Type>::~Double_Linked_List() {
	Double_node *t = list_head->next();
	Double_node *tmp;

	//While loops to check if t is at the tail node
	//Deletes all elements that are not
	while(t != list_tail)
	{
		//Makes the temporary variable the current node, moves current node to next and deletes temporary
		tmp = t;
		t = t->next();
		delete tmp;
	}
	//Delete both sentinels
	delete list_head;
	delete list_tail;
	list_size = 0;
}

//ACCESSORS
//Returns list size
template <typename Type>
int Double_Linked_List<Type>::size() const {
	return list_size;
}

//Checks if list is empty
//If list size is 0, then it returns true. Vice versa if list has nodes
template <typename Type>
bool Double_Linked_List<Type>::empty() const {
	if(list_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Fetches the value of the node after head
template <typename Type>
Type Double_Linked_List<Type>::front() const {
	if(empty())
	{
		throw underflow(); //From Exception.h, if empty
	}
	return list_head->next()->value(); // This returns the value of the argument after the head node
}

//Fetches the value of the node before tail
template <typename Type>
Type Double_Linked_List<Type>::back() const {
	if(empty())
	{
		throw underflow(); //From Exception.h, if empty
	}
	return list_tail->previous()->value(); // This returns the value of the argument before the tail node
}

//Gives the head of the list
template <typename Type>
typename Double_Linked_List<Type>::Double_node *Double_Linked_List<Type>::begin() const {
	return list_head->next_node;
}

//Gives the tail of the list
template <typename Type>
typename Double_Linked_List<Type>::Double_node *Double_Linked_List<Type>::end() const {
	return list_tail;
}

//Gives the tail of the list (reverse begin)
template <typename Type>
typename Double_Linked_List<Type>::Double_node *Double_Linked_List<Type>::revbegin() const {
	return list_tail->previous_node;
}

//Gives the head of the list (reverse end)
template <typename Type>
typename Double_Linked_List<Type>::Double_node *Double_Linked_List<Type>::revend() const {
	return list_head;
}

//Gives the address of the node that equals the searched value
//Returns tail if none is found
template <typename Type>
typename Double_Linked_List<Type>::Double_node *Double_Linked_List<Type>::find( Type const &obj ) const {
	Double_node *t;
	t = list_head->next(); //Start at node after head
	//While loop all nodes between head and tail
	while(t->next() != nullptr)
	{
		//Check if the node has the searched value
		//If true, return that address
		if(t->value() != obj)
		{
			t = t->next();
		}
		else
		{
			break;
		}
	}
	return t;
}

//Counts the number of nodes in list that stores searched value
template <typename Type>
int Double_Linked_List<Type>::count( Type const &obj ) const {
	int i = 0; //Argument counter, resets to 0 everytime it's called
	Double_node *t = list_head->next();

	//While loop through all elements of the linked list until it reaches tail node
	while(t->next() != nullptr)
	{
		if(t->value() == obj)
		{
			i += 1; //Add 1 to the counter
		}

		t = t->next(); //Move on to next element in list
	}
	return i;
}

//MUTATORS
template <typename Type>
void Double_Linked_List<Type>::swap( Double_Linked_List<Type> &list ) {
	std::swap( list_head, list.list_head );
	std::swap( list_tail, list.list_tail );
	std::swap( list_size, list.list_size );
}

template <typename Type>
Double_Linked_List<Type> &Double_Linked_List<Type>::operator=( Double_Linked_List<Type> rhs ) {
	swap( rhs );

	return *this;
}

template <typename Type>
Double_Linked_List<Type> &Double_Linked_List<Type>::operator=( Double_Linked_List<Type> &&rhs ) {
	swap(rhs);

	return *this;
}

//Creates new Double_node<Type> and stores new_value
//This new argument has head as previous pointer and head's last next pointer as next pointer (head is index 0, new element is index 1, old index 1 is index 2)
template <typename Type>
void Double_Linked_List<Type>::push_front( Type const &obj ) {
	Double_node *t;
	//Check if list is empty
	//If empty, insert between list head and tail
	if(empty())
	{
		t = new Double_node(obj, list_head, list_tail);
		list_head->next_node = t;
		list_tail->previous_node = t;
		list_size = 1;
	}
	//If not empty, insert new Double_node between sentinel and next argument
	else
	{
		Double_node *tmp;
		tmp = list_head->next();
		t = new Double_node(obj, list_head, tmp);
		tmp->previous_node = t;
		list_head->next_node = t;
		list_size = list_size + 1;
	}
}

//Same as push_front but places new node at the back of the list
template <typename Type>
void Double_Linked_List<Type>::push_back( Type const &obj ) {
	Double_node *t;
	//Check if list is empty
	//If empty, insert between list head and tail
	if(empty())
	{
		t = new Double_node(obj, list_head, list_tail);
		list_head->next_node = t;
		list_tail->previous_node = t;
		list_size = 1;
	}
	//If not empty, insert between tail previous node and tail node
	else
	{
		Double_node *tmp;
		tmp = list_tail->previous();
		t = new Double_node(obj, tmp, list_tail);
		tmp->next_node = t;
		list_tail->previous_node = t;
		list_size = list_size + 1;
	}
}

//Delete head->next() node and update the next element with correct previous and next nodes
template <typename Type>
void Double_Linked_List<Type>::pop_front() {
	//If empty, throw exception
	if(empty())
	{
		throw underflow();
	}
	else
	{
		Double_node *first; //First node (to be deleted)
		Double_node *second; //Second node (next to to-be-deleted node)
		first = list_head->next(); //Sets first node to the one to be deleted
		second = list_head->next()->next(); //Sets second node to the first->next()
		delete first; //Removes first node
		list_head->next_node = second; //Makes node after sentinel the second node
		second->previous_node = list_head; //Sets second node's previous node to head
		list_size = list_size - 1;
	}
}

//Delete tail->previous() node and update the previous element with correct previous and next nodes
template <typename Type>
void Double_Linked_List<Type>::pop_back() {
	//If empty, throw exception
	if(empty())
	{
		throw underflow();
	}
	else
	{
		Double_node *first; //First node (to be deleted)
		Double_node *second; //Second node (previous to to-be-deleted node)
		first = list_tail->previous(); //Sets first node to last node before tail
		second = list_tail->previous()->previous(); //Sets second node to second to last node
		delete first; //Removes first node
		list_tail->previous_node = second;
		second->next_node = list_tail;
		list_size = list_size - 1;
	}
}

//Delete all nodes that have the searched value
template <typename Type>
int Double_Linked_List<Type>::erase( Type const &obj ) {
	Double_node *t = list_head->next(); //This is where we start the search for the values
	int i = 0; //Counter for number of nodes deleted

	//While loop all nodes between head and tail
	while(t->next_node != nullptr)
	{
		Double_node *t_next = t->next();
		Double_node *t_prev = t->previous();

		if(t->value() == obj)
		{
			//Connects both adjacent nodes
			t_next->previous_node = t->previous();
			t_prev->next_node = t->next();
			i += 1;
			delete t;			
		}
		t = t_next;
	}
	return i;
}

template <typename Type>
Double_Linked_List<Type>::Double_node::Double_node(
	Type const &nv,
	typename Double_Linked_List<Type>::Double_node *pn,
	typename Double_Linked_List<Type>::Double_node *nn ):
// Updated the initialization list here
node_value( Type() ), // This assigns 'node_value' the default value of Type
previous_node( nullptr ),
next_node( nullptr )
{
	node_value = nv;
	previous_node = pn;
	next_node = nn;
}

template <typename Type>
Type Double_Linked_List<Type>::Double_node::value() const {
	return node_value; // This returns a default value of Type
}

template <typename Type>
typename Double_Linked_List<Type>::Double_node *Double_Linked_List<Type>::Double_node::previous() const {
	return previous_node;
}

template <typename Type>
typename Double_Linked_List<Type>::Double_node *Double_Linked_List<Type>::Double_node::next() const {
	return next_node;
}

template <typename T>
std::ostream &operator<<( std::ostream &out, Double_Linked_List<T> const &list ) {
	out << "head";

	for ( typename Double_Linked_List<T>::Double_node *ptr = list.rend(); ptr != nullptr; ptr = ptr->next() ) {
		if ( ptr == list.rend() || ptr == list.end() ) {
			out << "->S";
		} else {
			out << "->" << ptr->value();
		}
	}

	out << "->0" << std::endl << "tail";

	for ( typename Double_Linked_List<T>::Double_node *ptr = list.end(); ptr != nullptr; ptr = ptr->previous() ) {
		if ( ptr == list.rend() || ptr == list.end() ) {
			out << "->S";
		} else {
			out << "->" << ptr->value();
		}
	}

	out << "->0";

	return out;
}

#endif
