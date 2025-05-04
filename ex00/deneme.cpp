#include <iostream>
using namespace std;
/*
int main()
{

		try {
			int x = 10;
			int y = 0;

			if (y == 0)
			throw "Sıfıra bölme hatası!";

			cout << x / y << endl;
		}
		catch (const char* mesaj) {
			cout << "Hata yakalandı: " << mesaj << endl;
		}

		return 0;
}
 */

int main()
{

	try
	{
		int x = 10;
		int y = 0;

		if (y == 0)
		{
			throw std::runtime_error("Sıfıra bölme hatası!");
			y++;
			cout << "Bu satır çalışmaz." << endl;
		}

		cout << x / y << endl;
	}
	catch (std::exception &e)
	{
		cout << "Hata yakalandı: " << e.what() << endl;
	}

	return 0;
}
