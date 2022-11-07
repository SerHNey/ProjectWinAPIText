#include <Windows.h>
#define SIZE_BUFFER 260

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	DWORD dwBytesRead = 0;
	char ReadBuffer[20];
	int space = 0;
	int coun_space = 0;
	int countnumbers = 0;
	float a, b, c;
	HANDLE file = CreateFile("vvod.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (file != INVALID_HANDLE_VALUE)
	{
		DWORD size = 100,//кол-во символов которые надо прочитать
			bytes;//типо счетчик реально прочитанных символов
		char* text = calloc(size + 1, 1);//буфер куда записывается прочитанное 
		ReadFile(file, text, size, &bytes, NULL);
		for (size_t i = 0; i < bytes; i++)
		{
			if (text[i] == '\n') {
				space = 1;
			}
			if (text[i] < -1 || text[i] > 96) {
				file = CreateFile("otvter", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
				WriteFile(file, "Данные не верны", size, bytes, NULL);
				return 1;
			}
		}
		if (space) {
			for (size_t i = 0; i < bytes; i++)
			{
				if (text[i] == "\r" && text[i + 1] == "\n") {
					coun_space++;
					char* countnumber = calloc(countnumbers + 1, 1);
					for (size_t l = 0; l < countnumbers; l++)
					{
						countnumber = text[i - (countnumbers - i)];
					}
					countnumbers = 0;
					switch (coun_space)
					{
					case 1:
						a = atof(countnumbers);
						break;
					case 2:
						b = atof(countnumbers);
						break;
					default:
						break;
					}
					i++;
					continue;
				}
				if (i == bytes)//в конце нет разделителей, тк что заместо него конец текста
				{
					char* f = calloc(countnumbers, 1);
					for (size_t l = 0; l < countnumbers; l++)
					{
						f[l] = text[i - (countnumbers - l)];
					}
					c = atof(f);
				}
				countnumbers++;
			}
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
