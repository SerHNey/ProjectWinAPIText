#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <math.h>
#include <stdio.h>
DWORD countreadbytes = 100;
DWORD readingbytes = 100;

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	HANDLE file = CreateFile("data.txt", GENERIC_READ, NULL, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (file != INVALID_HANDLE_VALUE) {
		char* stroka = calloc(100, sizeof(char));
		if (!(ReadFile(file, stroka, countreadbytes, &readingbytes, NULL))) {
			file = CreateFile("result.txt", GENERIC_READ, NULL, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			sprintf(stroka, "������ ��������� �������");
			readingbytes = strlen(stroka);
			WriteFile(file, stroka, countreadbytes, &readingbytes, NULL);
			return 1;
		}
		int i = 0;
		while (stroka[i]) {
			i++;
			if (stroka[i] > 96 || stroka[i] < -1) {
				file = CreateFile("result.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
				sprintf(stroka, "������� �� �� ������");
				readingbytes = strlen(stroka);
				WriteFile(file, stroka, readingbytes, &readingbytes, NULL);
				return 1;
			}
		}
		char* istr;
		istr = strtok(stroka, " ");
		double numbers[3];
		numbers[0] = atof(istr);
		i = 1;
		while (istr != NULL)
		{
			istr = strtok(NULL, " ");
			if (istr != NULL) {
				if (istr[0] != '\r') {
					numbers[i] = atof(istr);
					i++;
				}

			}
		}
		kradrat_koren(numbers[0], numbers[1], numbers[2]);
	}
}


int kradrat_koren(double a, double b, double c) {
	HANDLE file = CreateFile("result.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	double diskrimenant = sqrt(pow(b, 2) - 4 * a * c);
	char* stroka = calloc(100, sizeof(char));
	if (diskrimenant < 0) {
		sprintf(stroka, "������������ ������ 0\n ������ ���");
		readingbytes = strlen(stroka);
		WriteFile(file, stroka, readingbytes, &readingbytes, NULL);
	}
	if (diskrimenant == 0) {
		c = (-b) / (2 * a);
		sprintf(stroka,"������������ ����� = 0\n x1 = %f\n x2 = %f", c,c);
		readingbytes = strlen(stroka);
		WriteFile(file, stroka, readingbytes, &readingbytes, NULL);
	}
	if (diskrimenant > 0) {
		c = (-b + diskrimenant) / (2 * a);
		a = (-b - diskrimenant) / (2 * a);
		sprintf(stroka, "������ ������������� ����� = %f\n x1 = %f\n x2 = %f", diskrimenant , c, a);
		readingbytes = strlen(stroka);
		WriteFile(file, stroka, readingbytes, &readingbytes, NULL);
	}
	return 0;
}
