//---------------------------------------------------------------------------

#ifndef appliH
#define appliH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>
#include "RS232.h"
//#if ( defined(__LCC__) || defined(__WIN__) )
//#include <winsock.h> /* For windows */
//#endif

#include "include/mysql.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *ButtonSend;
	TButton *ButtonReceive;
	TMemo *Memo1;
	TMemo *Memo2;
	TEdit *Edit1;
	TMemo *Memo3;
	TLabel *latitude;
	TLabel *longitude;
	TTimer *Timer1;
	TButton *Button1;
	void __fastcall ButtonSendClick(TObject *Sender);
	void __fastcall ButtonReceiveClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// Déclarations utilisateur
	RS232 port;
	MYSQL * mySQL;

	//OVERLAPPED over;
	std::vector<char> received;
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
	UnicodeString Latitude ;
	UnicodeString Longitude ;
	double  Latitude2;
	double Longitude2;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

