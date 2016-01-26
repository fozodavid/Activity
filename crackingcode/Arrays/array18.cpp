//array18.cpp
#include<iostream>

bool IsSubstring(char text[],char pattern[]){
	//because the exercise provided a bool IsSubstring function
	return true;
}

bool IsSubstringFrom(char text[], char pattern[],int index){
	int i(0);
	while (pattern[i+index]){
		if (text[i] != pattern[i+index]) return false;
		++i;
	}
	return true;
}

bool IsRotated(char text[], char pattern[], const int length){
	int i(0);
	bool secondPart(false);
	while (!secondPart && i<length){
		if(text[0] == pattern[i]){
			secondPart=IsSubstringFrom(text,pattern,i);
		}
		++i;
	}
	//first part copy
	char firstPart[length];
	int k;
	for (k = 0; k < i; ++k)	{
		firstPart[k] = text[k];
	}
	return (secondPart && IsSubstring(text,firstPart));
}


int main(int argc, char const *argv[]) {
	char text[] = "waterbottle";
	char pattern[] = "erbottlewat";

	std::cout << IsSubstringFrom(text,pattern,8) << std::endl;
	std::cout << IsRotated(text,pattern,12) << std::endl;
	std::cout << IsSubstring(text,pattern) << std::endl;
	//std::cout << IsRotated(text,pattern,6);
	return 0;
}