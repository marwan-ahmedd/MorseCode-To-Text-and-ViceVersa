// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Morse Code Message Converter.cpp
// Program Description: xxx xxx
// Last Modification Date: 16/3/2022
// Author1 and ID and Group: Marwan 20210377 A 
// Teaching Assistant: GeeksforGeeks helped in understanding maps
// Purpose: Cipher & Decipher messages as Morse Code


#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

// Morse Code
std::map <char, std::string> morse{
    {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."},
    {'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."},
    {'o', "---"}, {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"},
    {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."}, {' ', " "},
    {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, 
    {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"}, {',', "--..--"}, {'.', ".-.-.-"},
    {'?', "..--.."}, {'/', "-..-."}, {'-', "-....-"}, {'(', "-.--."}, {')', "-.--.-"}
};

// Encrypt Function
void Encrypt(string message)
{
    cout << "Enter a message to encrypt: ";
    cin.ignore();
    getline(cin, message);   // Take input from user
    
    for (int i = 0; i < message.length(); i++)
    {
        message[i] = tolower(message[i]);   // Converts all the message to lower case
    }
    
    ostringstream encryption{};
    for (auto letter : message)
    {
        encryption << morse[letter] << " ";     // Encryption for each characted, number, or symbol to Morse code
    }

    cout << "Encryption: " << encryption.str();
}


// Decrypt Function
void Decrypt(string word)
{
    int m, size;
    m = 0;
    size = 1;
    ostringstream decryption{};

    cout << "Enter encrypted message to decrypt: ";
    cin.ignore();       // Get user input
    getline(cin, word);

    for (int j = 0; j < word.length(); j++)     // Determining the number of words in the message
    {
        if (isspace(word[j])){
            if (isspace(word[j+1])){
                size++;
                j++;

            }else{
                size++;
            }
        }
    }

    string arr[size];
    
    for (int i = 0; i < word.length(); i++)
    {
        // Checking if their are three spaces of one space to put a space in the decryption or not
        if (isspace(word[i])){
            if (isspace(word[i+1])){   
                m++;
                arr[m] += " ";
                i += 2;
                m++;
            }else{
                m++;}
        }
        else{
            arr[m] += word[i];  // If their is no space then it is the same character
        }
    }
    
    for (int k = 0; k < size; k++)
    {
        for (char letter = 32; letter <= 122; letter++)
        {
            if (arr[k] == morse[letter]){       // Decryption of the encrypted message
                decryption << letter;
                break;
            }
        }
    }
    cout << "Decryption: " << decryption.str() << endl;
}


int main()
{
    cout << "Ahlan ya user ya habibi." << endl;
    int choice;

    while (true){   
        cout << "\nWhat do you like to do today?" << endl
            << "1- Cipher a message" << endl << "2- Decipher a message" << endl << "3- End" << endl << ">> ";

        cin >> choice;

        if (choice == 1){
            string message;
            Encrypt(message);
            
        }
        else if (choice == 2)
        {
            string encrypted_messg;
            Decrypt(encrypted_messg);

        }
        else if (choice == 3)
        {
            cout << "Program ENDED !";
            return 0;
        }
    }
    
}