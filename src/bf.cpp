#include <iostream>
#include <cstdlib>
#include "preprocess.h"
using namespace std;

union Cell{
    signed char c;
};

union Cell* ptr;
union Cell* start;

void process(string);

int main(){
    ptr = (union Cell*)calloc(30000, sizeof(union Cell));
    start = ptr;
	cout << "*** ";
	cin >> inpMain;
	while(inpMain[0] != '#'){
		inpMain = preprocess(inpMain);
		//checking for fucked up input:
		if(inpMain != "IT")
			process(inpMain);

		//on to next cycle:	
		cout << "\n*** ";
		cin >> inpMain;
	}
	
	free(start);
	return 0;
}

void process(string inp){
	for(int i=0; i<inp.length(); i++){
		switch(inp[i]){
			case '[':
				int e,c;
				e = i+1; c=0;
				while(inp[e] != ']' || c!=0){
					if(inp[e] == '[')
						c++;
					else if(inp[e] == ']')
						c--;
					e++;
				}
				while(ptr->c != 0){
					process(inp.substr(i+1, e-i-1));
				}
				i=e;
			break;
			case '+':
				ptr->c++;
			break;
			case '-':
				ptr->c--;
			break;
			case '>':
				ptr++;
			break;
			case '<':
				ptr--;
			break;
			case '.':
				cout << ptr->c;
			break;
			case ',':
        		signed char tmp;
         		cin >> tmp;
				ptr->c = (signed char)tmp;
			break;
			case '$':
				free(start);
				ptr = (union Cell*)calloc(30000, sizeof(union Cell));
			break;
			default:
				cout << "IDK What to do now\n";
		}
	}
}
