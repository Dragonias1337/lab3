#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;



void SaveToFile(string _path, string _text)
{
	ofstream outStream;
	outStream.open(_path, ios::out); // Флаг ios::out чистит файл
	if (outStream.is_open())
	{
		outStream << _text << endl;
		cout << "Cypher text is saved to " << _path << endl;
	}
	else cerr << "File opening error";
}

string ReadFromFile(string _path)
{
	ifstream inputStream;
	inputStream.open(_path); 
	if (inputStream.is_open())
	{
		string readText;
		getline(inputStream, readText);
		cout << "Cypher text is loaded" << endl;		
		return readText;
	}
	else cerr << "File opening error";
}

string Encrypt(string _plainText, int _key)
{
	srand(_key);
	string cypherText = _plainText;
	for (int i = 0; i < cypherText.length(); i++)
	{
		char gamma = -128 + rand() % 256;	//превращение [0:32767] в [-128:127] без потерь	
		cypherText[i] ^= gamma;
		cypherText[i]++;
	}
	return cypherText;
}

string Decrypt(string _cypherText, int _key)
{
	srand(_key);
	string plainText = _cypherText;
	for (int i = 0; i < plainText.length(); i++)
	{
		char gamma = -128 + rand() % 256;
		plainText[i]--;
		plainText[i] ^= gamma;
	}
	return plainText;
}

void SetStdinEcho(bool enable = true)
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	if (!enable)
		mode &= ~ENABLE_ECHO_INPUT;
	else
		mode |= ENABLE_ECHO_INPUT;
	SetConsoleMode(hStdin, mode);
}

int main(int argc, const char* argv[]) 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc != 3) 
	{
		cerr << "Error: Use three parameters\n";
		return 5;
	}

	const string mode(argv[1]); 
	const string fileName(argv[2]); 

	if (mode == "encryption") 
	{
		string plainText;
		int key;

		cout << "Enter the plain text: ";
		getline(cin, plainText);

		cout << "Enter the key (integer): ";
		SetStdinEcho(false);
		cin >> key;
		SetStdinEcho(true);
		cout << endl;

		SaveToFile(fileName, Encrypt(plainText, key));
	}

	else if (mode == "decryption") 
	{
		int key;

		cout << "Enter the key (integer): ";
		SetStdinEcho(false);
		cin >> key;
		SetStdinEcho(true);
		cout << endl;

		string cypherText = ReadFromFile(fileName);

		cout << "Plain text is: " << Decrypt(cypherText, key);
	}
	return 0;
}


