#pragma once
#define IN_MAX_LEN_TEXT 1024*1024	// максимальный размер исходного кода = 1 МБ
#define IN_CODE_ENDL '\n'			// символ конца строки

// таблица проверки входной информации,	индекс = код (Windows-1251) символа
// значение IN::F - запрещенный символ, IN::T - разрешенный символ, IN::I - игнорирвоать (не вводить)
// если  0 <= значение < 256, то вводится данное значение
#define IN_CODE_TABLE {\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, '|', IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::T,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::T,	IN::F, IN::T, IN::F, IN::T,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::T, IN::F, IN::F,\
	IN::T,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::I,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::T, IN::F, IN::F, IN::T,	IN::F, IN::F, IN::F, IN::F,	IN::T, IN::F, IN::T, IN::F,	IN::T, IN::T, IN::T,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::T, IN::F, IN::T,	IN::T, IN::T, IN::F, IN::F,	IN::F, IN::F, IN::F,\
																												    \
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	'-',	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::T,	IN::F, IN::F, IN::T,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::T,	IN::F, IN::T, IN::F, IN::T,	IN::F, IN::F, IN::T, IN::T,	IN::F, IN::T, IN::F, IN::T,	IN::T, IN::T, IN::F,\
	IN::F,	IN::T, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::T,\
					}

namespace In
{
	struct IN	// исходные данные
	{
		enum { T = 1024, F = 2048, I = 4096 };	// T - допустимый символ, F - недопустимый, I - игнорировать, иначе заменить
		int size;								// размер исходного кода
		int lines;								// количество строк
		int ignor;								// количество проигнорированных символов
		unsigned char* text;					// исходный код (Windows-1251)
		int code[256] = IN_CODE_TABLE;			// таблица проверки: T, F, I, новое значение
	};

	IN getin(wchar_t infile[]);					// ввести и проверить входной поток
}