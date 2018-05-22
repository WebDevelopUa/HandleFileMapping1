# HandleFileMapping1
#### Консольное приложение, C++

*HandleFileMapping1.cpp*: определяет точку входа для консольного приложения.

Приложение создает открывает текстовый файл *test1.txt*, используя фукуцию **CreateFile()**

В текстовый файл записывается строка *“new text (новый текст)”* используя фукуцию **sprintf_s()**;

Файловые дескрипторы закрываются с помощью функции **CloseHandle()**

В случае успешного создания или открытия файла, процедура **CreateFile()** возвращает его хэндл.

В случае ошибки возвращается специальное значение **INVALID_HANDLE_VALUE**.

Подробности об ошибке выводятся с помощью функции **GetLastError()**.

-----------------------------------------------------------------------------------------------------

#### Console application, C ++

*HandleFileMapping1.cpp*: Specifies the entry point for the console application.

The application creates a text file *test1.txt*, using the function **CreateFile()**

The text  *“new text (новый текст)”* is written to the *test1.txt* using the function **sprintf_s()**;

File descriptors are closed using the **CloseHandle()** function

If the file is created or opened successfully, the procedure **CreateFile()** returns its handle.

In case of an error, a special value **INVALID_HANDLE_VALUE** is returned.

Details about the error are displayed using the function **GetLastError()**.
