//stack34algo.cpp

#include<iostream>
#include "stack34.h"

void Hanoi::algorithm(int n_minus_disks, int source, int inter, int end){
	std::cout   << "Test with " << disks << " disks" << std::endl;
	std::cout 	<< " n-1: " << n_minus_disks -1 << " src: " << source
				<< " int: " << inter << " end: " << end << std::endl;
	if (n_minus_disks == 1){
		std::cout << "Last move" << std::endl;
		check();
	} else if (n_minus_disks % 2 == 1){
		std::cout << "else if n-1 // 2 == 1" << std::endl;
		algorithm(n_minus_disks-1, inter, end, source); check();
		std::cout << "move end-inter: " << end << ' ' << inter << std::endl;
		move(end,inter);
	} else if ((n_minus_disks > 0) && (n_minus_disks % 2 == 0)) {
		std::cout << "else" << std::endl;
		algorithm(n_minus_disks-1, inter, end, source); check();
		std::cout << "move inter-end: " << inter << ' ' << end << std::endl;
		move(inter,end);
	}
		std::cout 	<< "moves: " << source << ' ' << inter << std::endl
					<< "       " << source << ' ' << end << std::endl
					<< "       " << inter << ' ' << end << std::endl;
		move(source,inter); check();
		move(source,end);   check();
		move(inter, end);   check();
		check();
}
/*
void Hanoi::algorithm2(int n_minus_disks, int source, int inter, int end){
	std::cout << "disks" << n_minus_disks << "source" << source << "inter"
				<< inter << "end" << end << std::endl;
	if (n_minus_disks == 0){
		std::cout << "move: " << source << ' ' << end << std::endl;
		move(source,end); check();
	} else {
		algorithm2(n_minus_disks - 1, source, end, inter);   // Step 1 above
	    std::cout << "move: " << source << ' ' << end << std::endl;						              // Step 2 above
	    move(source,end); check();
    	algorithm2(n_minus_disks - 1, end, inter, source);   // Step 3 above
	}
}*/