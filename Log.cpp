#include "stdafx.h"	
#include "Log.h"	

#pragma warning(disable:4996)
using namespace std;

namespace Log
{
	LOG getlog(wchar_t logfile[])
	{
		LOG log;					// определяем переменную
		log.stream = new ofstream;	// открываем поток
		log.stream->open(logfile);	// открываем файл
		
		if (log.stream->fail())		// если не открылся
			throw ERROR_THROW(112);
		
		wcscpy_s(log.logfile, logfile);	// копируем информацию в log
		return log;
	}

	void WriteLine(LOG log, const char* c, ...)
	{
		const char** ptr = &c;	// ставим указатель на начало масива
		int i = 0;
		while (ptr[i] != "")	// делаем проходку,и передаём символы до ""
			*log.stream << ptr[i++];
		*log.stream << endl;
	}

	void WriteLine(LOG log, const wchar_t* c, ...)
	{
		const wchar_t** ptr = &c;	// ставим указатель на начало масива
		int i = 0;
		while (ptr[i] != L"")	// делаем проходку, и передаём символы до L""
		{
			char* ptr_ch = new char[wcslen(ptr[i]) + 1]{};
			wcstombs(ptr_ch, ptr[i], wcslen(ptr[i]));
			ptr_ch[wcslen(ptr[i])] = 0;
			*log.stream << ptr_ch;
			i++;
			delete[] ptr_ch;
		}
		*log.stream << endl;
	}

	void WriteLog(LOG log)
	{
		tm* timeinf;
		time_t timet;
		time(&timet);
		timeinf = localtime(&timet);
		char temp[100];
		strftime(temp, sizeof(temp), "\n---- ПРОТОКОЛ ---- %d.%m.%y %T ----\n ", timeinf);
		*log.stream << temp;
	}

	void WriteParm(LOG log, Parm::PARM parm)	// выводим параметры переданные в log
	{
		char in_text[PARM_MAX_SIZE];
		char out_text[PARM_MAX_SIZE];
		char log_text[PARM_MAX_SIZE];
		wcstombs(in_text, parm.in, PARM_MAX_SIZE);	// копируем данные в массив char
		wcstombs(out_text, parm.out, PARM_MAX_SIZE);
		wcstombs(log_text, parm.log, PARM_MAX_SIZE);
		*log.stream << "---- Параметры ---- \n-in: " << in_text
			<< "\n-out: " << out_text
			<< "\n-log: " << log_text;
	}

	void WriteIn(LOG log, In::IN in)	// пишем исходные данные
	{
		*log.stream << "\n---- Исходные данные ----"
			<< "\nКоличество символов: " << in.size
			<< "\nКоличество строк: " << in.lines
			<< "\nПроигнорировано: " << in.ignor;
	}

	void WriteError(LOG log, Error::ERROR error)	// печатаем в поток ошибки
	{
		if (log.stream)
		{
			*log.stream << "\nОшибка " << error.id
				<< ": " << error.message
				<< "\nСтрока " << error.inext.line
				<< " позиция " << error.inext.col;
			Close(log);
		}

		else
		{
			cout << "\nОшибка " << error.id
				<< ": " << error.message
				<< "\nСтрока " << error.inext.line
				<< " позиция " << error.inext.col;
		}
	}

	void Close(LOG log)	// закрываем поток
	{
		log.stream->close();
		delete log.stream;
	}
}