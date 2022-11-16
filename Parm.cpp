#include "stdafx.h"
#include "Parm.h"
#include "Error.h"

namespace Parm
{
	PARM getparm(int argc, _TCHAR* argv[])
	{
		PARM parm;	// ������ ���������� ���������
		bool in = 0, out = 0, log = 0;	// ���������� ����� ��������� ��������
		for (int i = 1; i < argc; i++)	// ��������� ������� ���,������� ���������� �������
		{
			if (wcslen(argv[i]) > PARM_MAX_SIZE)		// �������� �� ���������� �����
				throw ERROR_THROW(104);							// ���������� ������

			if (wcsstr(argv[i], PARM_IN))				// ���� �� ��������� -in
			{
				wcscpy_s(parm.in, argv[i] + wcslen(PARM_IN));	// �������� ��������� -in
				in = 1;											// ��������,��� -in �������� ������
			}

			if (wcsstr(argv[i], PARM_OUT))				// ���� ��������� -out
			{
				wcscpy_s(parm.out, argv[i] + wcslen(PARM_OUT));	// �������� ���������
				out = 1;										// ��������,��� -out �������� ������
			}

			if (wcsstr(argv[i], PARM_LOG))				// ���� ��������� -log
			{
				wcscpy_s(parm.log, argv[i] + wcslen(PARM_LOG));	// �������� ���������
				log = 1;										// ��������,��� -log �������� ������
			}
		}

		if (!in)										// ���� �������� -in �� ������,�� ���������� ������
			throw ERROR_THROW(100);

		if (!out)
		{
			wcscpy_s(parm.out, parm.in);				// �������� �������� � ���������� in
			wcscat_s(parm.out, PARM_OUT_DEFAULT_EXIT);	// ��������� ���������� .out
		}

		if (!log)
		{
			wcscpy_s(parm.log, parm.in);				// �������� �������� � ���������� in
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXIT);	// ��������� ���������� .log
		}

		return parm;
	}
}