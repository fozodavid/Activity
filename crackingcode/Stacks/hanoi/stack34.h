//stack34.h

#include <cstddef>

#ifndef HANOI_H
#define HANOI_H

struct Node {
	Node* next;
	int data;
	public:
		Node():next(NULL){}
};
struct BaseNode{
	Node* top;
	public:
		BaseNode():top(NULL){}
};

class Hanoi{
	private:
		const int num_of_towers;
		BaseNode* tower;
		int disks;
		bool win;
	public:
		Hanoi(int n_disks);
		~Hanoi();
		void push(int number);
		void move(int from, int to);
		void check();
		void test();
		void algorithm(int n_minus_disks, int source, int inter, int end);
		void solve();
};

#endif