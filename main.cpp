#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

int main(int argc, char *argv[]) {
  vector<string> tokens;
	set <string> unique;
	string next_line;  // Each data line
	string filename = argv[1];
	ifstream in(filename);
	while (getline(in, next_line)) {
			istringstream iss(next_line);
			string token;
			while (iss >> token) {
					string nopunct = "";
					for(auto &c : token) { // Remove Punctuation      
							if (isalpha(c)) {  // c = one of the char in token(string)
									nopunct +=c;       
							}
					}
					tokens.push_back(nopunct);
					unique.insert(nopunct);
			// cout << token<<endl;
		}
	}
	cout << "Number of words "<<tokens.size()<<endl;
	cout << "Number of unique words "<<unique.size()<<endl;
	ofstream setfile(filename + "_set.txt");
	for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it) {
			// cout << ' ' << *it;
			setfile << ' ' << *it;
	}
	cout << endl;

	map<string, string> wordmap;
	string last="";
	ofstream setMapFile(filename + "_map.txt");
	for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
			wordmap[last]=*it; // last = key, *it = value
			last = *it;
	}
	for (map<string, string>::iterator it=wordmap.begin(); it!=wordmap.end(); ++it) {
			// ++it moves 'it' to the next value in the container
			// cout << it->first<<", " << it->second<<endl;
			setMapFile << it->first<< ", " << it->second<<endl;
	}

	string state = "";
	for(int i = 0; i < 100; i++){
		// cout << wordmap[state] << " ";
		state = wordmap[state];
	}
	cout << endl;

	map<string, vector<string>> createText;
	state = "";
	for(vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
		createText[state].push_back(*it);
		// state = key, push_back(*it) = push 'value' to vector
		state = *it;
  }

	for(vector<string>::iterator it=createText["Nephi"].begin(); it!=createText["Nephi"].end(); it++) { // search every value in 'vector' that has key 'Nephi', so 
							// only need to loop 'vector' dont need 'map'
		// cout << *it << ", ";
	}

	srand(time(NULL)); // this line initializes the random number generated
										// so you dont get the same thing every time
	state = "";
	for (int i = 0; i < 100; i++) {
		int ind = rand() % createText[state].size();
		cout << createText[state][ind] << " ";
		// ind = get a random word from the 'key'
		state = createText[state][ind];

	}
	cout << endl;
	
}