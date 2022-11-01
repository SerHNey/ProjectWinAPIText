#include <Windows.h>
#define SIZE_BUFFER 260
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	DWORD dwBytesRead = 0;
	char ReadBuffer[20];
	HANDLE file = CreateFile(L"vvod.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (file != INVALID_HANDLE_VALUE)
	{
		LPSTR buffer = (CHAR*)calloc(SIZE_BUFFER + 1, sizeof(CHAR));
		DWORD iNumRead = 0;//Обязательный параметр. получает кол-во считанных байт
		LPCSTR str = " 4 5 8\r\n";
		DWORD iNumWrite = 0;
		if (!WriteFile(file, str, strlen(str), &iNumWrite, NULL)) {
			ReadFile(file, str, strlen(str), &iNumWrite, NULL);
		}
		file = CreateFile(L"otvet.txt", GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (file != INVALID_HANDLE_VALUE) {
			WriteFile(file, str, strlen(str), &iNumWrite, NULL);
		}
	}
}


int kradrat_koren(double a, double b, double c) {
	double diskrimenant = sqrt(pow(b, 2) - 4 * a * c);
	if (diskrimenant < 0) {
	}
	if (diskrimenant == 0) {
		c = (-b) / (2 * a);
	}
	if (diskrimenant > 0) {
		c = (-b + diskrimenant) / (2 * a);
		c = (-b - diskrimenant) / (2 * a);
	}

	return 0;
}
