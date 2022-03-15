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

int size_of_message(string word)
{
    int size = 1;
    for (int i = 0; i < word.length(); i++)
    {
        if (isspace(word[i])){
            if (isspace(word[i+1])){
                size++;
                i++;
            }else{
                size++;
            }
        }
    }
    return size;
}


void toDecrypt(string word)
{
    int m = 0;
    bool state = 0;
    string arr[], decryption;
    
    
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
    

//     for (int k = 0; k < size; k++)
//     {
//         for (auto item : data)
//         {
//             if (arr[k] == item.second){
//                 state = 1;
//                 decryption += item.first;
//                 break;
//             }else{
//                 state = 0;
//             }         
//         }
//         if (state == 0){
//             string new_message;
//             cout << "Invalid input. Enter a message to decrypt: ";
//             cin >> new_message;
//             break;
            
//         }
//     }

//     cout << "Decryption: " << decryption << endl;
}

int main()
{
    
    string word;
    word = "....   .   .--. .";
    // cout << "Enter a message to Decrypt: ";
    // cin >> word;
    // toDecrypt(word);
    size_of_message(word);
}