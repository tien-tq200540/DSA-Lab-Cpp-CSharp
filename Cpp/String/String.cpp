#include <iostream>
#include <stdexcept>
using namespace std;

struct MyString {
	char* data;
	int length;
	int capacity = 1000;
	
	public:
		MyString() {
			length = 0;
			data = new char[capacity+1];
		}
		
		MyString(const MyString& other) {
			length = other.length;
			capacity = other.capacity;
			data = new char[capacity+1];
			for (int i = 0; i < length; i++) *(data + i) = *(other.data + i);
			*(data+length) = '\0';
		}
		
		MyString& operator = (const MyString& other) {
			if (this != &other) {
				delete[] data;
				length = other.length;
				capacity = other.capacity;
				data = new char[capacity+1];
				for (int i = 0; i < length; i++) *(data + i) = *(other.data + i);
				*(data+length) = '\0';
			}
			return *this;
		}
		
		~MyString() {
			delete[] data;
		}
		
		void push_back(char ch) {
			if (length >= capacity) {
				capacity *= 2;
				char* newData = new char[capacity+1];
				for (int i = 0; i < length; i++) *(newData + i) = *(data + i);
				delete[] data;
				data = newData;
			}
			
			*(data + length) = ch;
			length++;
			*(data + length) = '\0';	
		}
		
		void print() {
			for (int i = 0; i < length; i++) cout << *(data + i);
		}
		
		int count_character(char ch) {
			int count = 0;
			for (int i = 0; i < length; i++) {
				if (*(data + i) == ch) count++;
			}
			
			return count;
		}
		
		MyString substring(int start) {
			if (start < 0 || start >= length) throw std::out_of_range("substring(start): start index invalid");
			MyString newStr;
			for (int i = start; i < length; i++) newStr.push_back(data[i]);
			return newStr;
		}	
		
		MyString substring(int start, int len) {
			if (start < 0 || start >= length || len < 0 || start + len > length) throw std::out_of_range("substring(start,len): range out of bounds");
			MyString newStr;
			for (int i = start; i < start + len; i++) newStr.push_back(data[i]);
			return newStr;
		}			
};

void reverse(MyString& str);
bool is_palindrome(const MyString& str);
MyString concat(const MyString& str1, const MyString& str2);

int main() {
	//DEMO
	//Get input
	MyString str;
	char ch;
	while (cin.get(ch) && ch != '\n') str.push_back(ch);
	
	cout << "Str = "; str.print(); cout << " have length = " << str.length << endl;
	MyString str2 = str;
	cout << "Reverse str = "; reverse(str);
	str.print(); cout << endl;
	cout << "Str2 = "; str2.print(); cout << endl;
	cout << "Is palindrome = " << is_palindrome(str) << endl;
	
	try {
		MyString substringTest = str2.substring(9, 0);
		cout << "Substring test of str2 = "; substringTest.print(); cout << endl;
	} catch (const exception& e) {
		cout << "Caught: " << e.what() << endl;
	}
	
	MyString concatTest = concat(str, str2);
	cout << "Concat str and str2 = ";concatTest.print();
	return 0;
}

void reverse(MyString& str) {
	int len = str.length;
	for (int i = 0; i < len/2; i++) {
		char tmp = str.data[i];
		str.data[i] = str.data[len-1-i];
		str.data[len-1-i] = tmp;
	}
}

bool is_palindrome(const MyString& str) {
	int len = str.length;
	for (int i = 0; i < len/2; i++) {
		if (str.data[i] != str.data[len-1-i]) return false;
	}
	return true;
}

MyString concat(const MyString& str1, const MyString& str2) {
	MyString newStr;
	for (int i = 0; i < str1.length; i++) newStr.push_back(str1.data[i]);
	for (int i = 0; i < str2.length; i++) newStr.push_back(str2.data[i]);
	return newStr;
}
