#pragma once

#include <fstream>
#include "In.h"
#include "Parm.h"	
#include "Error.h"	

namespace OUT	// ������ � ����������
{
	struct Out	// ��������
	{
		wchar_t Outfile[PARM_MAX_SIZE];
		std::ofstream* stream;
	};

	static const Out INITOUT = { L"", NULL };			// ��������� ������������� LOG
	Out getOut(wchar_t logfile[]);						// ������������ ��������� LOG
	void WriteInOut(Out out, In::IN in);
	void WriteError(Out out, Error::ERROR error);
	void CloseOut(Out out);
};