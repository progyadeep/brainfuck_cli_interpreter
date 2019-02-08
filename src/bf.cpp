#include <iostream>
using namespace std;

#include "preprocess.h"

signed char array[30000];
int ptr;

void process(string);

int main(){
		ptr = 0;
		string inp = "";
		cout << "*** ";
    cin >> inp;
		while(inp[0] != '#'){
			process(preprocess(inp));
			cout << "\n\n*** ";
			cin >> inp;
		}
	}

void	process(string inp){
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
						process(inp.substr(i+1, e-i-1));
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
					cout << (char)array[ptr];
				break;
				case ',':
          signed char tmp;
          cin >> tmp;
					array[ptr] = (signed char)tmp;
				break;
				default:
					cout << "Invalid token: \"" << inp[i] << "\" at " << i << endl;
					exit(0);
			}
		}
	}
