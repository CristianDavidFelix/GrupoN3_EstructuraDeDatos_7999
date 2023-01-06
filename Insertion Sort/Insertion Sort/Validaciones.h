#pragma once


int ingresarDatoint(char const* msj)
{
	char* dato = new char[15];
	int datoInt;
	char c;
	int i = 0;
	std::cout << "\n" << msj << std::endl;
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			dato[i++] = c;
			printf("%c", c);
		}
		else if (c == 8)
		{
			dato[i] = 0;
			i--;
			putchar(8);
			putchar(32);
			putchar(8);
			if (i < 0)
			{
				i = 0;
			}

		}

	}
	dato[i] = '\0';
	datoInt = atoi(dato);
	fflush(stdin);
	return  datoInt;
}
/**
	@brief   Ingresar datos
	@details ~
	@tparam
	@return char
**/
char* ingresarDato(char const* msj)
{
	std::cout <<"\n" << msj << std::endl;
	char* dato = new char[15];
	char c;
	int i = 0;
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			dato[i++] = c;
			printf("%c", c);
		}
		else if (c == 8)
		{
			dato[i] = 0;
			i--;
			putchar(8);
			putchar(32);
			putchar(8);
			if (i < 0)
			{
				i = 0;
			}

		}

	}
	dato[i] = '\0';
	fflush(stdin);
	return  dato;
}
/**
	@brief   Ingresar datos flotantes
	@details ~
	@tparam
	@return float
**/
char* ingresarDatosChar(char const* msj)
{
	char* dato = new char[10];
	char c;
	int i = 0;
	printf("\n%s\n", msj);
	while ((c = _getch()) != 13) {
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			printf("%c", c);
			dato[i++] = c;
		}
		//eliminar ultimo carracter
		else if (c == 8) {
			printf("%c", c);
			printf("%c", ' ');
			printf("%c", c);
			i--;
		}
	}

	dato[i] = '\0';
	fflush(stdin);
	return  dato;
}