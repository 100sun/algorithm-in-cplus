//
//  main.cpp
//  simple_vector
//
//  Created by sophia100 on 9/9/19.
//  Copyright © 2019 sophia100. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector> // error : implicit-function defn
#include <list>
#include <fstream>

// using std::list;
// using std::string; 
// using std::cout; 
// => I can use them without std::
using std::cerr;

int main(int argc, const char * argv[]) {
	// std::list<T>		std::vector<T>
	// c=list<char>;	c=vector<char>	// container
	//			c.size();
	//			c.push_back('A');
	//    for (char el : c) { cout << el; } // ranged based for

	std::list<std::string> hopes;
	// push_front => reverse printing // only in list ( vector only push_back ) 
	hopes.push_back("I");
	hopes.push_back("will");
	hopes.push_back("pass");
	hopes.push_back("EPP");

	// < vector > 
	// all together in memory => fast 
	// add only in the back ( not front or middle ) => expensive / container
	//    for(int i=0;i<hopes.size();++i){
	//        std::cout<<hopes[i]<<" ";
	//    }

	// < list >
	std::cout << "size of hopes is : " << hopes.size() << "\n";
	for (std::string el : hopes) {
		std::cout << el << " ";
	}
	std::cout << "\n";

	system("pause");
	return 0; // everything is cool
}
