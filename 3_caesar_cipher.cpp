#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char caesar_encrypt(const char c, const char start, const int size, const int offset)
{
	char encoded = (int)start + ((int)c - (int)start + offset) % size;
	return encoded;
}
string caesar_encrypt(const string &str, const int n)
{ 
	string result(str);

	for(int i=0; i< str.size(); i++)
	{
		char c = str[i];
		if(c >= 'A' && c <= 'Z')
		{
			result[i] = caesar_encrypt(c, 'A', 26, n);
		}
		else if (c >= 'a' && c <= 'z')
		{
			result[i] = caesar_encrypt(c, 'a', 26, n);
		}
	}

	return result;
}

int main()
{   
	cout << "Enter the string: ";
	string str;
	cin >> str;
	cout << "Enter n: ";
	int n;
	cin >> n;
	cout << "The encrypted code is: " << caesar_encrypt(str,n) << endl;
	system("pause");
	return 0;
}
