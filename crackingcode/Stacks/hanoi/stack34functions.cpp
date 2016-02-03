//stack34functions.cpp

#include<iostream>
#include "stack34.h"

Hanoi::Hanoi(int n_disks): disks(n_disks),num_of_towers(3) {
	tower = new BaseNode[num_of_towers];
	int i;
	for (i = num_of_towers; i > 0; --i)	{
		tower[i].top = NULL;
	}
	for (i = disks; i > 0; --i){
		push(i);
	}
}
Hanoi::~Hanoi(){
	delete tower;
}
void Hanoi::push(int number){
	Node* temp = new Node;
	temp -> data = number;
	temp -> next = tower[0].top;
	tower[0].top = temp;
}
void Hanoi::move(int from, int to){
	if(tower[from].top == NULL){
		std::cout << std::endl <<"Cannot move!" << std::endl;
		return;
	}
	if(tower[from].top != NULL && tower[to].top != NULL){
		if (tower[from].top -> data > tower[to].top -> data){
		std::cout << std::endl << "Cannot move!" << std::endl;
		return;
		}
	}
	Node* temp = tower[from].top;
	tower[from].top = tower[from].top -> next;
	temp -> next = tower[to].top;
	tower[to].top = temp;
}
void Hanoi::check(){
	Node* current = NULL;
	int i;
	std::cout << std::endl;
	for (i = 0; i < num_of_towers; ++i)	{
		current = tower[i].top;
		std::cout << std::endl << i << ": ";
		while(current != NULL){
			std::cout << current -> data << ' ';
			current = current -> next;
		}
	}
	std::cout << std::endl << std::endl;
}
void Hanoi::test(){
	check();
	move(0,1);	check();
	move(0,2);	check();
	move(1,2);	check();
	move(0,1);  check();
	move(2,0);  check();
	move(2,1);  check();
	move(0,1);  check();


}

void Hanoi::solve(){
	int turns(1);
	int i(1);
	while(i < disks-1){
		turns *= 2;
		std::cout << turns << std::endl;
		++i;
	}
	int x(0);
	int y(1);
	int z(2);
	i = 1;
	while(i < turns){
		std::cout << "x: " << x << "y: " << y << "z: " << z << std::endl;
		x=x+1;y=y+1;z=z+1;
		++i;
	}
	x = x%3; y = y%3; z = z%3;
	std::cout << "x: " << x << "y: " << y << "z: " << z << std::endl;
	if (disks % 2 == 0){
		algorithm(turns,x,y,z);
	} else {
		algorithm(turns,x,z,y);
	}
}

