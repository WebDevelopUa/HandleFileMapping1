// Консольное приложение, C++
/** HandleFileMapping1.cpp: определяет точку входа для консольного приложения.
Приложение создает открывает текстовый файл test1.txt, используя фукуцию CreateFile()
В текстовый файл записывается строка “new text (новый текст)” используя фукуцию sprintf_s();
Файловые дескрипторы закрываются с помощью функции CloseHandle()
-------------------------------------------------------------------------------------------
В случае успешного создания или открытия файла, процедура CreateFile() возвращает его хэндл.
В случае ошибки возвращается специальное значение INVALID_HANDLE_VALUE.
Подробности об ошибке выводятся с помощью функции GetLastError().
*/


#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>


int _tmain(int argc, _TCHAR* argv[]) {

	HANDLE hFile;
	TCHAR fileName[256] = L"test1.txt";

	HANDLE hMemFile;
	char *lpData;

	// открываем существующий файл;
	hFile = CreateFile(fileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	// создаем объект "проекция файла", связанный с файлом данных
	hMemFile = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 1024, L"test1");

	// выполненяем отображение на память файла
	// проецируем представление всего файла на наше адресное пространство
	lpData = (char *)MapViewOfFile(hMemFile, FILE_MAP_ALL_ACCESS, 0, 0, 1024);

	// вывод содержимого файла на экран без использования стандартной функции чтения из файла - ReadFile()
	printf("%s\n", lpData);

	// изменение содержимого файла, записав строку «new text (новый текст)»
	// начиная с 10-го символа с новой строки, 160 - размер буфера
	// Если в стандартном файле необходимо сначала выставить положение указателя 
	// и выполнить функцию WriteFile(), то здесь достаточно одного действия
	sprintf_s(lpData + 10, 160, "\nnew text (новый текст)");

	// В случае успешного создания или открытия файла,
	// процедура CreateFile()s возвращает его хэндл. 
	// В случае ошибки возвращается специальное значение INVALID_HANDLE_VALUE. 
	// Узнать подробности об ошибке можно с помощью GetLastError().
	if (hFile == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		return 3;
	}

	// отобразится строка, которая была сохранена в файле
	// функция ждёт нажатия любой клавиши, и возвращает её код
	getwchar();

	// снятие отображения содержимого файла
	UnmapViewOfFile(lpData);

	// закрытие открытых дескрипторов
	CloseHandle(hFile);
	CloseHandle(hMemFile);

	return 0;
}
