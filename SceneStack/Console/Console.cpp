#include "Console.h"

clsConsole::clsConsole()
{
	m_hConStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	// CONSOLE_CURSOR_INFO構造体の現在の状態を取得する
	GetConsoleCursorInfo(m_hConStdOut, &cci);

	// メンバ変数であるbVisibleがカーソルの表示・非表示を制御する変数なので、これをFALSEにする事でカーソルを非表示にできる
	cci.bVisible = FALSE;

	// 変更した構造体情報をコンソールWindowにセットする
	SetConsoleCursorInfo(m_hConStdOut, &cci);
}
clsConsole::~clsConsole()
{
	if ( m_hConStdOut != INVALID_HANDLE_VALUE ){
		CloseHandle( m_hConStdOut );
	}
}

void clsConsole::Draw( int x, int y, string c, bool isnewline )
{
	COORD coord;

	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition( m_hConStdOut,coord );

	if ( isnewline ){
		cout << c << endl;
	} else {
		cout << c;
	}
}
void clsConsole::Draw( int x, int y, const int value, bool isnewline )
{
	COORD coord;

	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition( m_hConStdOut,coord );
	if ( isnewline ){
		cout << value << endl;
	} else {
		cout << value;
	}
}

void clsConsole::Input( int x, int y, string *c )
{
	COORD coord;

	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition( m_hConStdOut,coord );

	cin >> *c;
}
void clsConsole::Input( int x, int y, int *value )
{
	COORD coord;

	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition( m_hConStdOut,coord );

	cin >> *value;
}

void clsConsole::SetColor( int fore, int back )
{
	WORD wFore = fore;
	WORD wBack = back;
	SetConsoleTextAttribute( m_hConStdOut, wFore + (wBack << 4) );
}

void clsConsole::Clear( int x, int y, const char *c, enColor f , enColor b )
{
	SetColor( static_cast<int>(f), static_cast<int>(b) );
	Draw ( x, y, c );
}

HANDLE clsConsole::GetHandle()
{
	return m_hConStdOut;
}