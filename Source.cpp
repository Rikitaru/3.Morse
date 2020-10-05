//�������� ���������, ������� ��������������� ����� �� �������� ���������� �����
//� ������ ����� � ��������. ���������� ����� ����������� � ��������� ����.
#include <stdio.h>
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>
//-.-. .... . -.-. -.- .. -. --.   .... --- .--   - .... .   .--. .-. --- --. .-. .- --   .-- --- .-. -.- ...
//C     h   e  c    k   i  n  g     h    o    w   t   h  e     p   r   o   g   r   a  m    w   o   r   k   s   
/*
-.-. .... . -.-. -.- .. -. --.   .... --- .--   - .... .   .--. .-. --- --. .-. .- --   .-- --- .-. -.- ...

*/
using namespace std;
void main(void) {
	setlocale(LC_ALL, "Russian");

	string Alphabet[26] = {
		".-",				//a
		"-...",				//b
		"-.-.",				//c
		"-..",				//d
		".",				//e
		"..-.",				//f
		"--.",				//g
		"....",				//h
		"..",				//i
		".---",				//j
		"-.-",				//k
		".-..",				//l
		"--",				//m
		"-.",				//n
		"---",				//o
		".--.",				//p
		"--.-",				//q
		".-.",				//r
		"...",				//s
		"-",				//t
		"..-",				//u
		"...-",				//v
		".--",				//w
		".-..-",			//x
		"-.--",				//y
		"--.",				//z
	};
	char letter;
	int vibor = 0;

	try
	{
		ifstream Proverka("Input.txt");
		if (!Proverka.is_open()) {// ���� �� ��������
			cout << "������� ���� Input.txt �� ���������� � ���������� ���������." << endl;
			throw - 1;
		}
		if (Proverka.peek() == EOF) {// ���� ������ ������ ����� �����
			cout << "������� ���� Input.txt ������." << endl;
			throw - 2;
		}
		Proverka.get(letter);
		if ((letter == '.') || (letter == '-')) {
			vibor = 1;
			cout << "��������� ������������� ����������, ��� ������� ������ - ������ �����." << endl;
		}
		else {
			vibor = 2;
			cout << "��������� ������������� ����������, ��� ������� ������ - �����." << endl;
		}

		ofstream output("Output.txt");

		if (vibor == 1) {
			ifstream first("Input.txt");
			vector <int> space;
			int count1 = 0;
			int count2 = 0;
			if (first.is_open())
			{
				while (first.get(letter))
				{
					if (letter == ' ') {
						count1++;
						count2++;
					}
					else {
						count1 = 0;
					}
					if (count1 == 3) {
						space.push_back(count2 - 2);
						count2 = 0;
						count1 = 0;
					}
				}
				first.close();
			}

			ifstream input("Input.txt");
			cout << "��������� ��������:"<<endl;
			string slovo;
			cout << endl;
			count1 = 0;
			count2 = 0;
			int j = 0;
			while (input >> slovo) {
				int flag = 0;
				count1++;
				count2++;
				for (int i = 0; i < 26; i++) {
					if (slovo == Alphabet[i]) {
						cout << char(97 + i);
						output << char(97 + i);
						flag = 1;
						break;
					}
				}
				if (!flag) {
					cout << "�������� � �������� ����� : " << count1 << ". ��������� �������� ���������: " << slovo << endl;
				}
				if (j != space.size()) {
					if (count2 == space[j]) {
						count2 = 0;
						j++;
						output << " ";
						cout << " ";
					}
				}
			}
			if (!count1) {
				cout << "���� ����." << endl;
			}
			input.close();
			output.close();
		}
		else {
			ifstream input("Input.txt");
			cout << "��������� ��������:" << endl;
			if (input.is_open())
			{
				while (input.get(letter)) {
					for (int i = 0; i < 26; i++) {
						if (letter == ' ') {
							cout << "   ";
							output << "   ";
							break;
						}
						else {
							if ((int(letter) - 97) == i) {
								cout << Alphabet[i] << " ";
								output << Alphabet[i] << " ";
								break;
							}
						}
					}
				}
			}
		}
	}
	catch (int a)
	{
		cout << "��������� �������� �����������. ������ ����� " << a << endl;
	}
	cout << "\n��������� �����������." << endl;
}