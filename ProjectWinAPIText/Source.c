#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <math.h>
#include <stdio.h>


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	HANDLE file = CreateFile("data.txt", GENERIC_READ, NULL, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);


	if (file != INVALID_HANDLE_VALUE) {
		DWORD countreadbytes = 100;
		DWORD readingbytes = 100;
		char* stroka = calloc(100, sizeof(char));
		if (!(ReadFile(file, stroka, countreadbytes, &readingbytes, NULL))) {
			file = CreateFile("result.txt", GENERIC_READ, NULL, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			sprintf(stroka, "Данные неудалось считать");
			WriteFile(file, stroka, strlen(stroka), &readingbytes, NULL);
			return 1;
		}
		int i = 0;
		while (stroka[i]) {
			i++;
			if (stroka[i] > 96 || stroka[i] < -1) {
				file = CreateFile("result.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
				sprintf(stroka, "Введены не те данные");
				WriteFile(file, stroka, strlen(stroka), &readingbytes, NULL);
				return 1;
			}
		}
		char* number;
		number = strtok(stroka, " ");
		double numbers[3] = { 0,0,0 };
		numbers[0] = atof(number);
		i = 1;
		while (number != NULL)
		{
			number = strtok(NULL, " ");
			if (number != NULL) {
				if (number[0] != '\r') {
					numbers[i] = atof(number);
					i++;
				}
			}
			if (i > 3)
				break;
		}
		kradrat_koren(numbers[0], numbers[1], numbers[2]);
	}
}


int kradrat_koren(double a, double b, double c) {
	HANDLE file = CreateFile("result.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD countreadbytes = 100;
	DWORD readingbytes = 100;
	char* stroka = calloc(100, sizeof(char));
	float x1, x2;
	
	if ((a != 0) && (b != 0) && (c != 0))
	{
		double diskrimenant = pow(b, 2) - 4 * a * c;
		if (diskrimenant < 0)
		{
			sprintf(stroka, "Дискриминант = %f Корней нет\n ", diskrimenant);
			WriteFile(file, stroka, strlen(stroka) , &readingbytes, NULL);
		}
		else if (diskrimenant == 0)
		{
			x1 = -b / (2 * a);
			sprintf(stroka, "Дискриминант = %f \nКол-во корней:1\n x1: %f", &diskrimenant, x1);
			WriteFile(file, stroka, strlen(stroka), &readingbytes, NULL);

		}
		else if (diskrimenant > 0)
		{
			x1 = (-b + sqrt(diskrimenant)) / (2 * a);
			x2 = (-b - sqrt(diskrimenant)) / (2 * a);
			sprintf(stroka, "Дискриминант = %f \nКол-во корней:2 \nx1: %f x2: %f", diskrimenant, x1, x2);
			WriteFile(file, stroka, strlen(stroka), &readingbytes, NULL);

		}
	}
	else if ((c == 0) && (b == 0))
	{
		x1 = 0;
		sprintf(stroka, "Корень равен = %f", x1);
		WriteFile(file, stroka, strlen(stroka), &readingbytes, NULL);

	}
	else if (b == 0)
	{

		if (-c / a < 0)
		{
			sprintf(stroka, "Корней нет");
			WriteFile(file, stroka, strlen(stroka), &readingbytes, NULL);

		}
		else
		{
			x1 = sqrt((-c / a));
			sprintf(stroka, "Корени равены = %f и -%f", x1, x1);
			WriteFile(file, stroka, strlen(stroka), &readingbytes, NULL);

		}
	}
	else if (c == 0)
	{
		x1 = -b / a;
		x2 = 0;
		sprintf(stroka, "Корени равены = %f и %f", x1, x2);
		WriteFile(file, stroka, strlen(stroka), &readingbytes, NULL);
	}
	else if (a == 0)
	{
		x1 = -c / b;
		sprintf(stroka, "Корень равен = %f", x1);
		WriteFile(file, stroka, strlen(stroka), &readingbytes, NULL);

	}

	return 0;
}
