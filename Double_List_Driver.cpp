#include <iostream>
#include <cstring>
#include "Test.h"
#include "Double_List_Test.h"
#include "Double_Node_Test.h"

int main( int argc, char *argv[] ) {
	if ( argc > 2 ) {
		std::cerr << "Cannot excede maximum of one command-line argument" << std::endl;

		return -1;
	}

	std::cout << "Starting Test Run" << std::endl;

	if ( argc == 1 || !std::strcmp( argv[1], "int" ) ) {
		if ( argc == 1 ) {
			std::cerr << "Command-line argument must be either 'int' or 'double'. Got none, so using 'int' by default." << std::endl;
		}

		Double_List_Test<int> tester;

		tester.run();
	} else if ( !std::strcmp( argv[1], "double" ) ) {
		Double_List_Test<double> tester;

		tester.run();
	}

	std::cout << "Finishing Test Run" << std::endl;

	return 0;
}
