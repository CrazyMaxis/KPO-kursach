#include "stdafx.h"
#include "In.h"
#include "Error.h"

using namespace std;

namespace In
{
	IN getin(wchar_t infile[])	// описываем функцию
	{
		IN in;										// создаём переменную структуры
		in.size = 0; in.lines = 1; in.ignor = 0;	// везде отсчёт от 0
		int col = 1;

		unsigned char* text = new unsigned char[IN_MAX_LEN_TEXT];

		ifstream fin(infile);	// открываем файл с модом на чтение
		if (fin.fail())			// если файл не открылся
			throw ERROR_THROW(110);	

		while (in.size < IN_MAX_LEN_TEXT)	// пока не достигнем максимальной длинны
		{
			char c; 
			fin.get(c);	// считываем символ из файла
			unsigned char x = c;

			if (fin.eof())	// если конец файла
			{
				text[in.size] = '\0';	// в конец добавляем \0
				break;
			}

			switch (in.code[x]) {
				case in.F:
					throw ERROR_THROW_IN(111, in.lines, col);	// генерация ошибки
					break;
				case in.T:
					text[in.size] = x;	// добавляем символ в наш текст
					in.size++;			// размер текста тогда увеличивается
					col++;				// и счётчик столбцов увеличивается
					break;
				case in.I:				// пропуск симввола
					in.ignor++;
					break;
				default:				// замена
					text[in.size] = in.code[x];
					in.size++;
					col++;
			}			

			if (x == IN_CODE_ENDL)	//если мы встретили \n, то добавляем строчку
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