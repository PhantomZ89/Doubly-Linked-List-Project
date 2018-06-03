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
	} 
