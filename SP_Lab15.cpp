#include "stdafx.h"
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "out.h"
#include "In.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "ru");
	Log::LOG log = Log::INITLOG;
	OUT::Out out = OUT::INITOUT;

	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);		// считываем параметры
		log = Log::getlog(parm.log);						// для передачи считанных параметров
		out = OUT::getOut(parm.out);
		Log::WriteLine(log, (char*)"Тест: ", (char*)"без ошибок ", "");	// печатаем строку char
		Log::WriteLine(log, (wchar_t*)L"Тест: ", (wchar_t*)L"без ошибок ", L"");	// печатаем строку wchar_t
		Log::WriteLog(log);									// вывод времени
		Log::WriteParm(log, parm);							// печатаем параметры
		In::IN in = In::getin(parm.in);						// считываем содержимое файла
		Log:WriteIn(log, in);								// пишем преобразованное в Log
		Log::Close(log);
		OUT::WriteInOut(out, in);
		OUT::CloseOut(out);
	}

	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
		OUT::WriteError(out, e);
	}

	return 0;
}