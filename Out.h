#pragma once

#include <fstream>
#include "In.h"
#include "Parm.h"	
#include "Error.h"	

namespace OUT	// работа с протоколом
{
	struct Out	// протокол
	{
		wchar_t Outfile[PARM_MAX_SIZE];
		std::ofstream* stream;
	};

	static const Out INITOUT = { L"", NULL };			// начальная инициализация LOG
	Out getOut(wchar_t logfile[]);						// сформировать структуру LOG
	void WriteInOut(Out out, In::IN in);
	void WriteError(Out out, Error::ERROR error);
	void CloseOut(Out out);
};