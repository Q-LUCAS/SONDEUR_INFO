//---------------------------------------------------------------------------

#ifndef RS232H
#define RS232H

#include <Windows.h>
#include <deque>

class RS232
{
	private:
		HANDLE com;
		std::deque<char> buffer;

	public:
		bool Open();
		void Close();
		char* Read();
		void Write(char * buf, int len);

		std::deque<char> & getBuffer();
};

//---------------------------------------------------------------------------
#endif
