#include "stdafx.h"
#include "In.h"
#include "Error.h"

using namespace std;

namespace In
{
	IN getin(wchar_t infile[])	// ��������� �������
	{
		IN in;										// ������ ���������� ���������
		in.size = 0; in.lines = 1; in.ignor = 0;	// ����� ������ �� 0
		int col = 1;

		unsigned char* text = new unsigned char[IN_MAX_LEN_TEXT];

		ifstream fin(infile);	// ��������� ���� � ����� �� ������
		if (fin.fail())			// ���� ���� �� ��������
			throw ERROR_THROW(110);	

		while (in.size < IN_MAX_LEN_TEXT)	// ���� �� ��������� ������������ ������
		{
			char c; 
			fin.get(c);	// ��������� ������ �� �����
			unsigned char x = c;

			if (fin.eof())	// ���� ����� �����
			{
				text[in.size] = '\0';	// � ����� ��������� \0
				break;
			}

			switch (in.code[x]) {
				case in.F:
					throw ERROR_THROW_IN(111, in.lines, col);	// ��������� ������
					break;
				case in.T:
					text[in.size] = x;	// ��������� ������ � ��� �����
					in.size++;			// ������ ������ ����� �������������
					col++;				// � ������� �������� �������������
					break;
				case in.I:				// ������� ��������
					in.ignor++;
					break;
				default:				// ������
					text[in.size] = in.code[x];
					in.size++;
					col++;
			}			

			if (x == IN_CODE_ENDL)	//���� �� ��������� \n, �� ��������� �������
			{
				in.lines++;
				col = 0;
			}
		}

		if (!fin.eof())
			throw ERROR_THROW(101);

		in.text = text;
		return in;
	}
}