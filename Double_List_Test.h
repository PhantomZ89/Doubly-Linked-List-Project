#ifndef DOUBLE_LIST_TEST_H
#define DOUBLE_LIST_TEST_H

#include "Exceptions.h"
#include "Test.h"
#include "Double_Linked_List.h"
#include "Double_node_test.h"

#include <iostream>

template <typename Type>
class Double_List_Test:public Tester< Double_Linked_List<Type> > {
	using Tester< Double_Linked_List<Type> >::object;
	using Tester< Double_Linked_List<Type> >::command;

	public:
		Double_List_Test( Double_Linked_List<Type> *obj = nullptr );
		void process();
};

template <typename Type>
Double_List_Test<Type>::Double_List_Test( Double_Linked_List<Type> *obj ):
Tester< Double_Linked_List<Type> >( obj ) {
	// empty
}

template <typename Type>
void Double_List_Test<Type>::process() {
	if ( command == "new" ) {
		object = new Double_Linked_List<Type>();
		std::cout << "Okay" << std::endl;
	} else if ( command == "size" ) {
		//Check if the size equals the next integer read

		int expected_size;

		std::cin >> expected_size;

		int actual_size = object->size();

		if ( actual_size == expected_size ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failed size(): expecting '" << expected_size << "' but got '" << actual_size << "'" << std::endl;
		}
	} else if ( command == "empty" ) {
		//Check if the empty status equals the next Boolean read

		bool expected_empty;

		std::cin >> expected_empty;

		bool actual_empty = object->empty();

		if ( actual_empty == expected_empty ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failed empty(): expecting '" << expected_empty << "' but got '" << actual_empty << "'" << std::endl;
		}
	} else if ( command == "front" ) {
		//Checks if the first object in the linked list equals the next object read

		Type expected_front;

		std::cin >> expected_front;

		Type actual_front = object->front();

		if ( actual_front == expected_front ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failed front(): expecting '" << expected_front << "' but got '" << actual_front << "'" << std::endl;
		}
	} else if ( command == "front!" ) {
		//Front of an empty list - catch an exception

		Type actual_front;

		try {
			actual_front = object->front();
			std::cout << "Fail front(): expecting an exception but got '" << actual_front << "'" << std::endl;
		} catch( underflow ) {
			std::cout << "Okay" << std::endl;
		} catch (...) {
			std::cout << "Failed front(): expecting an underflow exception but got a different exception" << std::endl;
		}
	} else if ( command == "back" ) {
		//Checks if the last object in the linked list equals the next object read

		Type expected_back;

		std::cin >> expected_back;

		Type actual_back = object->back();

		if ( actual_back == expected_back ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failed back(): expecting '" << expected_back << "' but got '" << actual_back << "'" << std::endl;
		}
