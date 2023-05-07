// for input and output
# include <iostream>
// for std::numeric_limits::max
# include <limits>
// for dynamic arrays
# include <unordered_set>
// for std::sort()
# include <algorithm>
/*
	Author: LeeTuah
	Program: Common items among two lists 
	Date: 07/05/23
	For SuperB League event
*/

// for reducing syntax
# define list std::unordered_set<int>

// fixes std::cin if bad input is provided
void fixCin(){
	if(std::cin.fail()){
		// clearing std::cin from bad to good
		std::cin.clear();
		// removing all of the bad input from std::cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}	
}

// returning the common items
// list1 -> first list
// list2 -> second list
list commonItems(list &list1, list &list2){
	list commonItems;
	
	// looping through list1
	for(auto i = list1.begin(); i != list1.end(); i++){
		auto key = *i;
		// checking if list2 has the current key, then adding it to common list
		if(list2.find(key) != list2.end()) commonItems.insert(*i);
	}
	
	// returning the common list
	return commonItems;
}

// fills a list with all the necessary items from user
// lisp -> the list which is to be filled
// first -> determine whether the list is the first list or the second list
void fillList(list &lisp, bool first){
	int size, num;
	
	// asking for size of the list
	if(first)	
	std::cout << "How many items for first list?: ";
	else
	std::cout << "How many items for second list?: ";
	std::cin >> size;
	fixCin();
	
	// iterating for the given size and taking in all the integers
	std::cout << "\n\n";
	for(int i = 0; i < size; i++){
		std::cout << "Enter item number " << i + 1 << ": ";
		std::cin >> num;
		fixCin();
		lisp.insert(num);
	}
	std::cout << "\n\n";
}

// execution starts from here
// int argc -> total argument count from run
// char** argv -> all the provided arguments in a string array
int main(int argc, char** argv){
	// variables declared here
	list first, second, common;
	
	// filled the first and second list
	fillList(first, true);
	fillList(second, false);
	
	// found the common members among lists
	common = commonItems(first, second);
	
	// iterating through the common list and printing all the common items
	std::cout << "The common items are:\n";
	for(auto x : common){
		std::cout << x << " ";
	}
	
	return 0;
}
