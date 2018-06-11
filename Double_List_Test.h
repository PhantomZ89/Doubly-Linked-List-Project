#ifndef DOUBLE_LIST_TEST_H
#define DOUBLE_LIST_TEST_H

#include "Exceptions.h"
#include "Test.h"
#include "Double_Linked_List.h"
#include "Double_node_test.h"

#include <iostream>

template <typename Type>
class Double_List_Test:public test< Double_Linked_List<Type> > {
	using test< Double_Linked_List<Type> >::object;
	using test< Double_Linked_List<Type> >::command;

	public:
		Double_List_Test(Double_Linked_List<Type> *obj = nullptr);
		void process();
};

template <typename Type>
Double_List_Test<Type>::Double_List_Test(Double_Linked_List<Type> *obj):
test< Double_Linked_List<Type> >(obj) {
	//empty
}

template <typename Type>
void Double_List_Test<Type>::process() {
	if(command == "new") {
		object = new Double_Linked_List<Type>();
		std::cout << "Okay" << std::endl;
	} else if(command == "size") {
		//Check if the size equals the next integer read

		int expected_size;

		std::cin >> expected_size;

		int actual_size = object->size();

		if(actual_size == expected_size) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failed size(): expecting '" << expected_size << "' but got '" << actual_size << "'" << std::endl;
		}
	} else if(command == "empty") {
		//Check if the empty status equals the next Boolean read

		bool expected_empty;

		std::cin >> expected_empty;

		bool actual_empty = object->empty();

		if(actual_empty == expected_empty) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failed empty(): expecting '" << expected_empty << "' but got '" << actual_empty << "'" << std::endl;
		}
	} else if(command == "front") {
		//Checks if the first object in the linked list equals the next object read

		Type expected_front;

		std::cin >> expected_front;

		Type actual_front = object->front();

		if(actual_front == expected_front) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failed front(): expecting '" << expected_front << "' but got '" << actual_front << "'" << std::endl;
		}
	} else if(command == "front!") {
		//Front of an empty list - catch an exception

		Type actual_front;

		try {
			actual_front = object->front();
			std::cout << "Fail front(): expecting an exception but got '" << actual_front << "'" << std::endl;
		} catch(underflow) {
			std::cout << "Okay" << std::endl;
		} catch (...) {
			std::cout << "Failed front(): expecting an underflow exception but got a different exception" << std::endl;
		}
	} else if(command == "back") {
		//Checks if the last object in the linked list equals the next object read

		Type expected_back;

		std::cin >> expected_back;

		Type actual_back = object->back();

		if(actual_back == expected_back) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failed back(): expecting '" << expected_back << "' but got '" << actual_back << "'" << std::endl;
		}
	} else if(command == "back!") {
		//Back of an empty list - catch an exception

		Type actual_back;

		try {
			actual_back = object->back();
			std::cout << "Failed back(): expecting an exception but got '" << actual_back << "'" << std::endl;
		} catch(underflow) {
			std::cout << "Okay" << std::endl;
		} catch (...) {
			std::cout << "Failed back(): expecting an underflow exception but got a different exception" << std::endl;
		}
	} else if(command == "begin") {
		//Checks that the begin is not 'nullptr', and if it is not,
		//the next object gives the number of commands which should
		//be tested by the Double_Node_Test

		typename Double_Linked_List<Type>::Double_node *actual_begin = object->begin();

		if(actual_begin == nullptr) {
			std::cout << "Failed begin(): expecting non-zero begin pointer" << std::endl;
		} else {
			std::cout << "Okay" << std::endl;

			Double_Node_Test<Type> tester(actual_begin);

			tester.run();
		}
	} else if(command == "end") {
		//Checks that the end is not 'nullptr', and if it is not,
		//the next object gives the number of commands which should
		//be tested by the Double_Node_Test

		typename Double_Linked_List<Type>::Double_node *actual_end = object->end();

		if(actual_end == nullptr) {
			std::cout << "Failed end(): expecting non-zero end pointer" << std::endl;
		} else {
			std::cout << "Okay" << std::endl;

			Double_Node_Test<Type> tester(actual_end);

			tester.run();
		}
	} else if(command == "revbegin") {
		//Checks that the revbegin is not 'nullptr', and if it is not,
		//the next object gives the number of commands which should
		//be tested by the Double_Node_Test

		typename Double_Linked_List<Type>::Double_node *actual_revbegin = object->revbegin();

		if(actual_revbegin == nullptr) {
			std::cout << "Failed revbegin(): expecting non-zero revbegin pointer" << std::endl;
		} else {
			std::cout << "Okay" << std::endl;

			Double_Node_Test<Type> tester(actual_revbegin);

			tester.run();
		}
	} else if(command == "revend") {
		//Checks that the revend is not 'nullptr', and if it is not,
		//the next object gives the number of commands which should
		//be tested by the Double_Node_Test

		typename Double_Linked_List<Type>::Double_node *actual_revend = object->revend();

		if(actual_revend == nullptr) {
			std::cout << "Failed revend(): expecting non-zero revend pointer" << std::endl;
		} else {
			std::cout << "Okay" << std::endl;

			Double_Node_Test<Type> tester(actual_revend);

			tester.run();
		}
	} else if(command == "find") {
		Type value;
		std::cin >> value;

		typename Double_Linked_List<Type>::Double_node *actual_find = object->find(value);

		if(actual_find == nullptr) {
			std::cout << "Failed find(" << value << "): expecting non-zero find pointer" << std::endl;
		} else {
			std::cout << "Okay" << std::endl;

			Double_Node_Test<Type> tester(actual_find);

			tester.run();
		}
	} else if(command == "count") {
		//Check if the next object read in is in the linked list

		Type value;
		int expected_count;

		std::cin >> value;
		std::cin >> expected_count;

		if(object->count(value) == expected_count) {
			std::cout << "Okay" << std::endl;
		} else {
			if(expected_count == 1) {
				std::cout << "Failed count(): expecting '" << value << "' to be in the list" << std::endl;
			} else {
				std::cout << "Failed count(): not expecting '" << value << "' to be in the list" << std::endl;
			}
		}
	} else if(command == "push_front") {
		//Push the next object read to the front of the linked list

		Type n;

		std::cin >> n;

		object->push_front(n);
		std::cout << "Okay" << std::endl;
	} else if(command == "push_back") {
		//Push the next object read to the back of the linked list

		Type n;

		std::cin >> n;

		object->push_back(n);
		std::cout << "Okay" << std::endl;
	} else if(command == "pop_front") {
		//Pop the first object from the linked list
		object->pop_front();
		std::cout << "Okay" << std::endl;
	} else if(command == "pop_front!") {
		//Pop from an empty list - catch an exception

		try {
			object->pop_front();
			std::cout << "Failed pop_front(): expecting an exception but got none" << std::endl;
		} catch(underflow) {
			std::cout << "Okay" << std::endl;
		} catch (...) {
			std::cout << "Failed pop_front(): expecting an underflow exception but got a different exception" << std::endl;
		}
	} else if(command == "pop_back") {
		//Pop the last object from the linked list
		object->pop_back();
		std::cout << "Okay" << std::endl;
	} else if(command == "pop_back!") {
		//Pop from an empty list - catch an exception

		try {
			object->pop_back();
			std::cout << "Failed pop_front(): expecting an exception but got none" << std::endl;
		} catch(underflow) {
			std::cout << "Okay" << std::endl;
		} catch (...) {
			std::cout << "Failed pop_back(): expecting an underflow exception but got a different exception" << std::endl;
		}
	} else if(command == "erase") {
		Type n;
		int expected_count;

		std::cin >> n;
		std::cin >> expected_count;

		int actual_count = object->erase(n);

		if(actual_count == expected_count) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failed erase(" << n << "): expecting '" << expected_count << "', but got " << actual_count << std::endl;
		}
	} else if(command == "assign") {
		Double_Linked_List<Type> *new_object = new Double_Linked_List<Type>();

		*new_object = *(object);

		std::cout << "Okay" << std::endl;

		Double_List_Test<Type> tester(new_object);

		tester.run();
	} else if(command == "cout") {
		std::cout << *object << std::endl;
	} else {
		std::cout << command << ": Command not found." << std::endl;
	}
}

#endif

