#include <iostream>
using namespace std;

#include "preprocess.h"

signed char array[30000];
int ptr;
string inpMain = "";
void process(string, int);

int main(){
	ptr = 0;
	cout << "*** ";
    cin >> inpMain;
	while(inpMain[0] != '#'){
		process(preprocess(inpMain), 0);
		cout << "\n*** ";
		cin >> inpMain;
	}
}

void process(string inp, int IBF){
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
				while(array[ptr] != 0){
					process(inp.substr(i+1, e-i-1), i+1);
				}
				i=e;
			break;
			case '+':
				array[ptr]++;
			break;
			case '-':
				array[ptr]--;
			break;
			case '>':
				ptr++;
			break;
			case '<':
				ptr--;
			break;
			case '.':
				cout << array[ptr];
			break;
			case ',':
        		signed char tmp;
         		cin >> tmp;
				array[ptr] = (signed char)tmp;
			break;
			case '$':
				ptr=0;
				for(int a=0; a<30000; a++)
					array[a] = (signed char)0;
			break;
			default:
				cout << "Invalid token: \"" << inpMain[IBF+i] << "\" at index: " << IBF+i << endl;
				//exit(0);
		}
	}
}
