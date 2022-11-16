#include "stdafx.h"	
#include "Out.h"	
#include <time.h>

#pragma warning(disable:4996)
using namespace std;

namespace OUT
{
	Out getOut(wchar_t Outfile[])
	{
		Out out;
		out.stream = new ofstream;
		out.stream->open(Outfile);
		if (out.stream->fail())
			throw ERROR_THROW(112);
		wcscpy_s(out.Outfile, Outfile);
		return out;
	}
	
	void WriteInOut(Out out, In::IN in)
	{
		*out.stream << in.text;
	}
	
	void WriteError(Out out, Error::ERROR error)	// печатаем в поток ошибки
	{
		if (out.stream)
		{
			*out.stream	<< "Строка " << error.inext.line
				<< " позиция " << error.inext.col;
			CloseOut(out);
		}

		else
		{
				cout << "Строка " << error.inext.line
				<< " позиция " << error.inext.col;
		}
	}

	void CloseOut(Out out)
	{
		out.stream->close();
		delete out.stream;
	}

}