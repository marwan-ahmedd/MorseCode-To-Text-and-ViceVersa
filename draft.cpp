#include <iostream>
#include <map>
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

void toDecrypt()
{
    int m = 0;
    const int size = 5;
    string word, arr[size], decryption;
    word = "....   .   .--.";
    
    for (int i = 0; i < word.length(); i++)
    {
        if (isspace(word[i])){
            if (isspace(word[i+1])){
                m++;
                arr[m] += "  ";
                i++; 
            }else{
                m++;
            }

        }else{
            arr[m] += word[i];
        }
    }
    int state = 1;
    for (int k = 0; k < size; k++)
    {
        for (auto item : data)
        {
            if (arr[k] != item.second){
                state = 0;
                // break;
            }
            else{
                state = 1;
            }
        if (state == 0){
            cout << "Wrong Input" << endl;
            break;
        }
        }

    }

    cout << decryption << endl;
}

int main()
{
    toDecrypt();
}