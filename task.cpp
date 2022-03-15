#include <iostream>
#include <map>
#include <string.h>
using namespace std;

map < char, string> 
	data {
		{'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."},
		{'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."},
		{'o', "---"}, {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"},
		{'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."}, {' ', "  "},
		{'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, 
		{'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"}, {',', "--..--"}, {'.', ".-.-.-"},
		{'?', "..--.."}, {'/', "-..-."}, {'-', "-....-"}, {'(', "-.--."}, {')', "-.--.-"}
	};


void Encrypt(string word)
{
	string encryption;
	encryption = "";
	for (int i = 0; i < word.length(); i++)
	{	
		if (data.find(word[i]) == data.end()){
			string newWord;
			cout << "Invalid character/s, Enter another word/sentence to Encrypt: " << endl;
			cin >> newWord;
			break;
			Encrypt(newWord);
		}
		else{
            if (isspace(word[i])){
				encryption += data[word[i]];
			}
			else{
				encryption += data[word[i]];
				encryption += " ";
			}
		}
	}
	cout << "Encryption: " << encryption << endl;
}



// void Decrypt(string word)
// {

// }
	
int main()
{
	string word;
	cout << "Enter a word/sentence to Encrypt: ";
	getline(cin, word);
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
	}
	Encrypt(word);

	
	return 0;
	// code: .... . .-.. .-.. ---
	// main;
	// hi
}
