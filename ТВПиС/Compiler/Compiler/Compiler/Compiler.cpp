// Compiler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include "Defaults.h"
#include <iostream>
#include "ASTBuilder.h"
#include "Exceptions.h"
#include "Exception.h"
#include <ctime>

#define R "factorials.txt"

using namespace std;

static char* messages[] =
{
	"CharError: ошибка конечного автомата.",
	"StringError: ошибка конечного автомата.",
	"FileReaderError: ошибка чтения файла.",
	"TypeNameLengthError: слишком длинное имя типа.",
	"UnknownType: неподдерживаемый тип данных.",
	"UnknownOperation: неподдерживаемая операция.",
	"MissingBracket: пропущена скобка.",
	"ArgumentOutOfRange: значение аргумента находится вне допустимого диапазона значений.",
	"InvalidOperation: недопустимая операция.",
	"NoTree: необходимо построить синтексное дерево до выполнения.",
	"TokenNotFound: токен не найден.",
	"VariableNameNotFound: необъявленная переменная или константа.",
	"VariableTypeNotFound: неподдерживаемый тип данных.",
	"RedefinitionVariable: недопустимое переопределение переменной.",
	"ConstInitializationError: ошибка инициализации константы.",
	"VariableInitializationError: ошибка объявления константы.",
	"ArrayInitializationError: ошибка объявления массива.",
	"InitializationError: ошибка объявления или инициализации.",
	"InvalidCharacter: недопустимый символ.",
	"UninitializedConstant: неинициализированная константа.",
	"VariableNameIsNotSpecified: не указано имя переменной.",
	"InvalidVariableName: недопустимое имя переменной.",
	"ArraySizeIsNotAConstant: размер массива должен быть задан константой.",
	"ArraySizeIsNotAnInteger: размер массива должен быть целым положительным числом.",
	"IndexIsNotSpecified: не указан индекс элемента массива.",
	"ArrayIndexIsNotAnInteger: индекс массива не является целым числом.",
	"ConstantReinitialization: изменение значения константы невозможно.",
	"SystemFunctionIsNotSupported: неподдерживаемая системная функция.",
	"MissingArguments: пропущены аргументы при вызове функции.",
	"UnexpectedEndOfFile: неожиданный конец файла."
};

int main()
{
	srand(time(nullptr));
	try
	{
		ASTBuilder* builder = new ASTBuilder(R);
		builder->Build();
		builder->Run();
	}
	catch (Exceptions e)
	{
		setlocale(LC_ALL, "Russian");
		cout << messages[e] << endl;
	}
	catch (Exception* eline)
	{
		setlocale(LC_ALL, "Russian");
		cout << eline->GetMessage() << " Строка: " << eline->GetLine() << "." << endl;
	}

	return 0;
}

