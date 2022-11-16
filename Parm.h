#pragma once
#define PARM_IN		L"-in:"					// Ключ для файла исходного кода
#define	PARM_OUT	L"-out:"				// Ключ для файла объектного кода
#define	PARM_LOG	L"-log:"				// Ключ для файла журнала
#define	PARM_MAX_SIZE	300					// Максимальная длинна строки параметра
#define	PARM_OUT_DEFAULT_EXIT	L".out"		// Расширение файла объектного кода по умолчанию
#define	PARM_LOG_DEFAULT_EXIT	L".log"		// Расширение файла протокола по умолчанию

namespace Parm		// Обработка входных параметров
{
	struct PARM		// Входные параметры
	{
		wchar_t in[PARM_MAX_SIZE];		// -in: имя файла исходного кода
		wchar_t out[PARM_MAX_SIZE];		// -out: имя файла объектного кода
		wchar_t log[PARM_MAX_SIZE];		// -log: имя файла протокола
	};

	PARM getparm(int argc, _TCHAR* argv[]);	// Cформировать PARM на основе параметров функции main
}