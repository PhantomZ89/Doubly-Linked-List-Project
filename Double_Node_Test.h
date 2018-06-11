#ifndef DOUBLE_NODE_TEST_H
#define DOUBLE_NODE_TEST_H

#include "Exceptions.h"
#include "Test.h"
#include "Double_Linked_List.h"

#include <iostream>

template <typename Type>
class Double_Node_Test:public test< typename Double_Linked_List<Type>::Double_node > {
	using test< typename Double_Linked_List<Type>::Double_node >::object;
	using test< typename Double_Linked_List<Type>::Double_node >::command;

	public:
		Double_Node_Test(typename Double_Linked_List<Type>::Double_node *obj = nullptr);
		void process();
};

template <typename Type>
Double_Node_Test<Type>::Double_Node_Test(typename Double_Linked_List<Type>::Double_node *obj):
test< typename Double_Linked_List<Type>::Double_node >(obj) {
	//empty
}

template <typename Type>
void Double_Node_Test<Type>::process() {
	if(command == "next") {
		typename Double_Linked_List<Type>::Double_node *actual_next = Double_Node_Test<Type>::object->next();

		if(actual_next != nullptr) {
			object = actual_next;
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failed next(): expecting to follow a non-null next pointer" << std::endl;
		}
	} else if(command == "next0") {
		if(object->next() == nullptr) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failed next(): expecting a null next pointer" << std::endl;
		}
	} else if(command == "value") {
		Type expected_value;
		std::cin >> expected_value;

		Type actual_value;
		actual_value = object->value();

		if(expected_value == actual_value) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failued value(): expecting '" << expected_value <<
				"' but got '" << actual_value << "'" << std::endl;
		}
	} else if(command == "previous") {
		typename Double_Linked_List<Type>::Double_node *actual_previous = Double_Node_Test<Type>::object->previous();

		if(actual_previous != nullptr) {
			object = actual_previous;
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failed previous(): expecting to follow a non-null previous pointer" << std::endl;
		}
	} else if(command == "previous0") {
		if(object->previous() == nullptr) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failed previous(): expecting a null previous pointer" << std::endl;
		}
	} else if(command == "value") {
		Type expected_value;
		std::cin >> expected_value;

		Type actual_value;
		actual_value = object->value();

		if(expected_value == actual_value) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failed value(): expecting '" << expected_value <<
				"' but got '" << actual_value << "'" << std::endl;
		}
	} else {
		std::cout << command << ": Command not found." << std::endl;
	}
}

#endif
