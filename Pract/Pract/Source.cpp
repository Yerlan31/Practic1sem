#include <conio.h>
void vvod(char* arr, int n);
void udal(char* arr, int& dlina, char& nom, int l_word);
char* analogstrstr(char* string, char* podstring);

int main()
{
	char* word = new char[15];
	int count = 0;
	int l_word = 0;
	int dlina = 100;
	char* tekst = new char[dlina];

	vvod(tekst, dlina);

	int j = 0;
	while (tekst[j] != '.')
	{	//berem slovo
		for (int i = 0; j < dlina; i++)
		{
			if (tekst[j] == ' ' || tekst[j] == '.') { word[i] = '\0'; break; }

			word[i] = tekst[j];
			j++;
			l_word = i + 1;

		}
		char* p = tekst; //

		while (p = analogstrstr(p, word)) {

			char* c = p;	//с-начало подстроки совпадения    
			p += l_word;	//р-конец подстроки совпадения
  // подстрока не в начале строки?
			if (c != tekst)
				// символ перед подстрокой совпадения не разделитель?
				if (*(c - 1) != ' ') continue;
			// символ после слова разделитель?
			if ((*p) == ' ' || (*p) == '\0' || (*p) == '.')////
				count++;	//подстрока – отдельное слово
			else continue;/////////
			if (count > 1) { udal(tekst, dlina, *c, l_word); p -= l_word; }
		}

		if (word[0] == '\0') { j++; count = 0; continue; }

		//vivod
		for (int n = 0; n < l_word; n++) {
			_putch(word[n]);
		}

		if (count > 9) { _putch('-');  _putch(48 + (int)count / 10); _putch(48 + (int)count % 10); _putch('\n'); }
		else {

			_putch('-'); _putch(48 + (int)count); _putch('\n');
		}

		count = 0;
		if (tekst[j] == '.') { break; }

		j++;
	}


	//ubirayem probely
	for (int x = 0; x < dlina - 1; x++)
	{
		if (tekst[x] == ' ' && tekst[x + 1] == ' ' || tekst[0] == ' ') {
			for (int y = x; y < dlina - 1; y++)
			{
				tekst[y] = tekst[y + 1];
			}
			x--;
			dlina--;
		}
		if (tekst[x] == '.' && tekst[x - 1] == ' ') { tekst[x - 1] = tekst[x]; dlina--; }
		else continue;
	}
	const char a[] = "The text is:";
	_putch('\n');
	for (int x = 0; a[x] != ':'; x++) { _putch(a[x]); };
	_putch('\n');
	for (int x = 0; tekst[x] != '.'; x++) { _putch(tekst[x]); }; _putch('.');
	_getch();
	return 0;
}


void vvod(char* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		char temp;
		temp = _getch();
		if ((int)temp > 122 && (int)temp != 32 && temp != '\b' && temp != '.') { i--;  continue; }//iniye simboly
		if ((int)temp < 97 && (int)temp != 32 && temp != '\b' && temp != '.') { i--; continue; }

		if (i < 1 && temp == '\b') { i--; continue; }// ne vihodil za predeli teksta
		if (temp == '\b') { i -= 2; _putch('\b'); _putch(' '); _putch('\b'); continue; } //backspace
		arr[i] = temp;
		_putch(arr[i]);
		if (arr[i] == '.') { break; }
	}
	_putch('\n');
}

void udal(char* arr, int& dlina, char& nom, int l_word)
{
	int x = 0;
	for (x = 0; x < dlina; x++)
	{
		if (&arr[x] == &nom) { break; };
	}
	for (x; x < dlina; x++)
	{
		arr[x - 1] = arr[x + l_word];// +0 +1
	}
	dlina -= l_word;

}

char* analogstrstr(char* string, char* podstring)
{
	int n = 0;
	char* str = string, * p = podstring;
	while (*str != '\0') {
		while (*str == *p)
		{
			str++; p++; n++;
			if (*p == '\0') return str - n;
			if (*str == '.')return 0;
		}
		str++;
		n = 0;
		p = podstring;
	}
	return 0;
}
