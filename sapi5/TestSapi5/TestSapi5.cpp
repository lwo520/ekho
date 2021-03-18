
#include "stdafx.h"
#include <iostream>
#include <sapi.h>
#include <sphelper.h>
#include <atlcom.h>

using namespace std;

int main ( int NumOfArguments, char** Argument )
{
HRESULT                             hr = S_OK;
CComPtr<IEnumSpObjectTokens>        cpEnum;
ULONG                               ulCount = 0;

/*
CComPtr<ISpVoice>                   cpVoice;
CComPtr<ISpObjectToken>             cpVoiceToken;

// Initialize COM
    CoInitialize(NULL);

// Create the SAPI voice
if(SUCCEEDED(hr))
    hr = cpVoice.CoCreateInstance( CLSID_SpVoice ); 


//Enumerate the available voices 
if(SUCCEEDED(hr))
    hr = SpEnumTokens(SPCAT_VOICES, NULL, NULL, &cpEnum);

//Get the number of voices
if(SUCCEEDED(hr))
    hr = cpEnum->GetCount(&ulCount);

// Obtain a list of available voice tokens, set the voice to the token, and call Speak
while (SUCCEEDED(hr) && ulCount -- )
{
    cpVoiceToken.Release();
    if(SUCCEEDED(hr))
        hr = cpEnum->Next( 1, &cpVoiceToken, NULL );

    if(SUCCEEDED(hr))
        hr = cpVoice->SetVoice(cpVoiceToken);

    if(SUCCEEDED(hr))
        hr = cpVoice->Speak( L"123", SPF_DEFAULT, NULL); 
}

return 0;
*/

for (int i = 0; i < 1; i++) {
	// Initialize COM
    CoInitialize(NULL);
 
    ISpVoice * pSpVoice = NULL;
	CComPtr<ISpObjectToken>	cpToken;

	// Create the voice interface object
    if (FAILED(CoCreateInstance(CLSID_SpVoice, NULL, 
        CLSCTX_INPROC_SERVER, IID_ISpVoice, (void **)&pSpVoice)))
    {
        cerr << "Fail to create instance of ISpVoice!" << endl;
        return -1;
    }

	hr = pSpVoice->SetInterest( SPFEI(SPEI_WORD_BOUNDARY),SPFEI(SPEI_WORD_BOUNDARY) );
	if (FAILED(hr))	{
		cerr << "Fail to make event notifications!" << endl;
        return -1;
	}

	//====================== Test case for Cantonese ==========================
	if (FAILED(SpEnumTokens(SPCAT_VOICES, L"Name=Ekho Cantonese", NULL, &cpEnum))) {
		cerr << "Fail to get voices!" << endl;
		return -1;
	}

	//Get the closest token
	cpToken.Release();
	if (FAILED(cpEnum ->Next(1, &cpToken, NULL))) {
		cerr << "Fail to get voice EkhoVoice!" << endl;
		return -1;
	}
	
	//set the voice 
	if (FAILED(pSpVoice->SetVoice( cpToken))) {
		cerr << "Fail to set voice EkhoVoice!" << endl;
		return -1;
	}

	// set rate
	pSpVoice->SetRate(0);

	// set volume
	pSpVoice->SetVolume(90);

	cout << "speak 123\r\n321 in Cantonese ... ";
	pSpVoice->Speak(L"  NULL)  左花括号    cerr     Fail to open      voice dir    endl;   return;     右花括号       string symbol;    Symbol Code  星号 symbol code  等号  0;       斜杠  斜杠  prepare output file    FILE  星号 file  等号  fopen(voice file 点 c str(),  wb );     斜杠  斜杠  SNDFILE  星号 sndfile  等号  sf open(voice file 点 c str(), SFM WRITE,  和号 m Sfinfo);    unsigned int total bytes  等号  0;      do  左花括号    if ((dp  等号  readdir(dirp))   等号  NULL)  左花括号    char  星号 suffix  等号  strstr(dp  d name, m Voice File Type);   if ( suffix    suffix   dp  d name   2) continue;     symbol  等号  dp  d name;   symbol  等号  symbol 点 substr(0, suffix   dp  d name   1);     if (symbol 点 find(   )  等号  等号  string::npos)  左花括号     斜杠  斜杠 cerr     index      symbol    endl;    斜杠  斜杠  single phonetic symbol   os 点 put(1);   unsigned short code  等号  get Code Of Symbol(symbol);   os 点 put(code  和号  0x FF);   os 点 put((code    8)  和号  0x FF);      斜杠  斜杠  get file content   char buffer 128000 ;   string path  等号  voice dir  加    斜杠    加  symbol  加   .   加  m Voice File Type;   FILE  星号 gsmfile  等号  fopen(path 点 c str(),  rb );   int bytes  等号  0;   int b  等号  0;   do  左花括号    b  等号  fread(buffer, 1, 128000, gsmfile);   bytes  加  等号  b;   fwrite(buffer, 1, b, file);    右花括号  while ( feof(gsmfile)  和号  和号  b   0);      斜杠  星号     fseek(gsmfile, 0L, SEEK END);   int size  等号  ftell(gsmfile);    if (size   等号  bytes)  左花括号     cout     bytes 等号      bytes     , size 等号      size    endl;     右花括号  星号  斜杠      fclose(gsmfile);     os 点 put(total bytes  和号  0x FF);   os 点 put((total bytes    8)  和号  0x FF);   os 点 put((total bytes    16)  和号  0x FF);   os 点 put((total bytes    24)  和号  0x FF);   total bytes  加  等号  bytes;     os 点 put(bytes  和号  0x FF);   os 点 put((bytes    8)  和号  0x FF);   os 点 put((bytes    16)  和号  0x FF);      斜杠  斜杠 cerr     code:     code     , offset 等号      total bytes       斜杠  斜杠   , bytes 等号      bytes    endl;    右花括号  else  左花括号     斜杠  斜杠  multiple symbols (word)   cerr     found word:     symbol    endl;   list string  symbols;   string symbol 0  等号  symbol;   int pos  等号  0;   do  左花括号    pos  等号  symbol 点 find(   );   symbols 点 push back(symbol 点 substr(0, pos));   symbol 点 erase(0, pos  加  1);    右花括号  while (pos  等号  等号  string::npos);   symbols 点 push back(symbol);     os 点 put(symbols 点 size());   for (list string ::iterator sym  等号  symbols 点 begin(); sym   等号  symbols 点 end();   sym 加  加 )  左花括号    unsigned short code  等号  get Code Of Symbol( 星号 sym);   os 点 put(code  和号  0x FF);   os 点 put((code    8)  和号  0x FF);    右花括号       斜杠  斜杠  get file content   char buffer 512000 ;   string path  等号  voice dir  加    斜杠    加  symbol 0  加   .   加  m Voice File Type;   FILE  星号 gsmfile  等号  fopen(path 点 c str(),  rb );     int bytes  等号  0;   int b  等号  0;   do  左花括号    b  等号  fread(buffer, 1, 512000, gsmfile);   bytes  加  等号  b;   fwrite(buffer, 1, b, file);    右花括号  while (b  等号  等号  512000);     fclose(gsmfile);     os 点 put(total bytes  和号  0x FF);   os 点 put((total bytes    8)  和号  0x FF);   os 点 put((total bytes    16)  和号  0x FF);   os 点 put((total bytes    24)  和号  0x FF);   total bytes  加  等号  bytes;     os 点 put(bytes  和号  0x FF);   os 点 put((bytes    8)  和号  0x FF);   os 点 put((bytes    16)  和号  0x FF);    右花括号     右花括号      右花括号  while (dp   等号  NULL);      closedir(dirp);    fclose(file);    os 点 close();   右花括号     void Dict::load Ekho Voice File(string path)  左花括号      斜杠  斜杠  only support Cantonese and Mandarin    if (m Language  等号  等号  HAKKA    m Language  等号  等号  TOISANESE    m Language  等号  等号  KOREAN      m Language  等号  等号  NGANGIEN)  左花括号    return;     右花括号       unsigned char lowbyte;    unsigned short code;    unsigned int offset;    int bytes;    unsigned int tmpint;      string index file  等号  path  加    点 index ;    string voice file  等号  path  加    点 voice ;       斜杠  斜杠  get samplerate    ifstream is(index file 点 c str(), ifstream::binary);    lowbyte  等号  (unsigned char)is 点 get();    unsigned short samplerate  等号  (unsigned char)is 点 get();    samplerate  等号  (samplerate    8)  加  lowbyte;       斜杠  斜杠  get audio type    lowbyte  等号  is 点 get();    if (lowbyte  等号  等号  1)   m Voice File Type  等号   wav ;    else if (lowbyte  等号  等号  2)   m Voice File Type  等号   gsm ;       斜杠  斜杠  get symbol count    is 点 get();    is 点 get();       斜杠  斜杠  get code count    int code count;    while ((code count  等号  is 点 get())   等号  std::char traits char ::eof())  左花括号    if (code count  等号  等号  1)  左花括号     斜杠  斜杠  code   lowbyte  等号  (unsigned char)is 点 get();   code  等号  (unsigned char)is 点 get();   code  等号  (code    8)  加  lowbyte;      斜杠  斜杠  offset   offset  等号  (unsigned char)is 点 get();   tmpint  等号  (unsigned char)is 点 get();   offset  加  等号  (tmpint    8);   tmpint  等号  (unsigned char)is 点 get();   offset  加  等号  (tmpint    16);   tmpint  等号  (unsigned char)is 点 get();   offset  加  等号  (tmpint    24);      斜杠  斜杠  bytes   bytes  等号  (unsigned char)is 点 get();   tmpint  等号  (unsigned char)is 点 get();   bytes  加  等号  (tmpint    8);   tmpint  等号  (unsigned char)is 点 get();   bytes  加  等号  (tmpint    16);      斜杠  斜杠 cerr    code     :     offset     ,     bytes    endl;     m Symbol Array code  点 offset  等号  offset;   m Symbol Array code  点 bytes  等号  bytes;    右花括号  else  左花括号     斜杠  斜杠  bytes for word   char symbols 256   等号   左花括号 0 右花括号 ;   for (int i  等号  0; i   code count; i 加  加 )  左花括号     斜杠  斜杠  code   lowbyte  等号  (unsigned char)is 点 get();   code  等号  (unsigned char)is 点 get();   code  等号  (code    8)  加  lowbyte;    斜杠  斜杠 m Symbol Array code  点 symbol;    斜杠  斜杠 cerr    m Symbol Array code  点 symbol    endl;   strcat(symbols, m Symbol Array code  点 symbol);   if (i   code count   1)  左花括号    strcat(symbols,    );    右花括号     右花括号       斜杠  斜杠  offset   offset  等号  (unsigned char)is 点 get();   tmpint  等号  (unsigned char)is 点 get();   offset  加  等号  (tmpint    8);   tmpint  等号  (unsigned char)is 点 get();   offset  加  等号  (tmpint    16);   tmpint  等号  (unsigned char)is 点 get();   offset  加  等号  (tmpint    24);      斜杠  斜杠  bytes   bytes  等号  (unsigned char)is 点 get();   tmpint  等号  (unsigned char)is 点 get();   bytes  加  等号  (tmpint    8);   tmpint  等号  (unsigned char)is 点 get();   bytes  加  等号  (tmpint    16);      斜杠  斜杠 cerr    symbols    offset    bytes    endl;     m Word Symbol Map symbols   等号  Phonetic Symbol(symbols, offset, bytes);    右花括号      右花括号       is 点 close();      if (m Voice File)  左花括号    fclose(m Voice File);     右花括号       memset( 和号 m Sfinfo, 0, sizeof(m Sfinfo));    m Sfinfo 点 samplerate  等号  samplerate;    m Sfinfo 点 channels  等号  1;    if (strcmp(m Voice File Type,  gsm ))  左花括号    m Sfinfo 点 format  等号  SF FORMAT WAV   SF FORMAT GSM 610;     右花括号      斜杠  斜杠 m Voice File  等号  sf open(voice file 点 c str(), SFM READ,  和号 m Sfinfo);    m Voice File  等号  fopen(voice file 点 c str(),  rb );      Symbol Code  星号 sym code;    if (m Language  等号  等号  MANDARIN)  左花括号    sym code  等号  ZH P Hash::in word set( de 5 , 3);   int size  等号  0;   m Symbol Array sym code  code  点 get Pcm(m Voice File, size);   m Sfinfo 点 frames  等号  size  斜杠  2;     右花括号  else  左花括号    m Sfinfo 点 frames  等号  0;     右花括号       if (m Debug)  左花括号    cerr     sample Rate 等号      samplerate     , file Type 等号      m Voice File Type    endl;     右花括号    右花括号     Phonetic Symbol 星号  Dict::get Phonetic Symbol(const char  星号 symbol)  左花括号     if (Dict::me)  左花括号    string s(symbol);   unsigned short code  等号  Dict::me  get Code Of Symbol(s);   return  和号 Dict::me  m Symbol Array code ;     右花括号       return 0;   右花括号      右花括号  ", SPF_DEFAULT, NULL);
	pSpVoice->Speak(L"6 W 2 1", SPF_DEFAULT, NULL);
	pSpVoice->Speak(L"사랑을hello world", SPF_DEFAULT, NULL);
	pSpVoice->Speak(L"Folder View  列表  D: nvda 20161  状态栏 就绪   行 66 列 14 Ch 14   Ins  ", SPF_ASYNC, NULL);
	pSpVoice->Speak(L"123你好\r\n321", SPF_PURGEBEFORESPEAK, NULL);
	pSpVoice->Speak(L"<Bookmark mark=\"12\" />我挥一挥衣袖", SPF_IS_XML, NULL);
	pSpVoice->Speak(L"<spell>为什么hello world</spell>", SPF_IS_XML, NULL);
	pSpVoice->Speak(L"<pitch absmiddle=\"10\">为												,什么hello world</pitch>", SPF_IS_XML, NULL);
	pSpVoice->Speak(L"<pitch absmiddle=\"-10\">为,,,,,,,,,,什么hello world</pitch>", SPF_IS_XML, NULL);
	cout << "done" << endl;

	//======================= Test case for English ==============================
	if (FAILED(SpEnumTokens(SPCAT_VOICES, L"Name=Ekho English", NULL, &cpEnum))) {
		cerr << "Fail to get voices!" << endl;
		return -1;
	}

	//Get the closest token
	cpToken.Release();
	if (FAILED(cpEnum ->Next(1, &cpToken, NULL))) {
		cerr << "Fail to get voice EkhoVoice!" << endl;
		return -1;
	}
	
	//set the voice 
	if (FAILED(pSpVoice->SetVoice( cpToken))) {
		cerr << "Fail to set voice EkhoVoice!" << endl;
		return -1;
	}

	cout << "speak hello in Mandarin ... ";
	pSpVoice->Speak(L"hello", SPF_DEFAULT, NULL);

	//======================= Test case for Mandarin ==============================
	if (FAILED(SpEnumTokens(SPCAT_VOICES, L"Name=Ekho Mandarin", NULL, &cpEnum))) {
		cerr << "Fail to get voices!" << endl;
		return -1;
	}

	//Get the closest token
	cpToken.Release();
	if (FAILED(cpEnum ->Next(1, &cpToken, NULL))) {
		cerr << "Fail to get voice EkhoVoice!" << endl;
		return -1;
	}
	
	//set the voice 
	if (FAILED(pSpVoice->SetVoice( cpToken))) {
		cerr << "Fail to set voice EkhoVoice!" << endl;
		return -1;
	}

	cout << "speak 123 in Mandarin ... ";
	pSpVoice->Speak(L"hello 123 . 大。\n\n也可以", SPF_DEFAULT, NULL);
	pSpVoice->Speak(L"Á, á, é, í, ó, ú and ü, hola mundo. 为什么", SPF_DEFAULT, NULL);
	cout << "done" << endl;

	if (FAILED(SpEnumTokens(SPCAT_VOICES, L"Name=Ekho Mandarin", NULL, &cpEnum))) {
		cerr << "Fail to get voices!" << endl;
		return -1;
	}

	//Get the closest token
	cpToken.Release();
	if (FAILED(cpEnum ->Next(1, &cpToken, NULL))) {
		cerr << "Fail to get voice EkhoVoice!" << endl;
		return -1;
	}
	
	//set the voice 
	if (FAILED(pSpVoice->SetVoice( cpToken))) {
		cerr << "Fail to set voice EkhoVoice!" << endl;
		return -1;
	}

	cout << "speak 123 with rate 5... ";
	// set rate
	pSpVoice->SetRate(5);
	pSpVoice->Speak(L"为什么", SPF_DEFAULT, NULL);
  pSpVoice->SetRate(0);
	cout << "done" << endl;

	//======================= Test case for Korean ==============================
	if (FAILED(SpEnumTokens(SPCAT_VOICES, L"Name=Ekho Korean", NULL, &cpEnum))) {
		cerr << "Fail to get voices!" << endl;
		return -1;
	}

	//Get the closest token
	cpToken.Release();
	if (FAILED(cpEnum ->Next(1, &cpToken, NULL))) {
		cerr << "Fail to get voice EkhoVoice!" << endl;
		return -1;
	}
	
	//set the voice 
	if (FAILED(pSpVoice->SetVoice( cpToken))) {
		cerr << "Fail to set voice EkhoVoice!" << endl;
		return -1;
	}

	cout << "speak 사랑을 나누면 부러울것이 없습니다 in Korean ... ";
	pSpVoice->Speak(L"사랑을 나누면 부러울것이 없습니다", SPF_DEFAULT, NULL);

	//===================== Test case for Hakka ==============================
	if (FAILED(SpEnumTokens(SPCAT_VOICES, L"Name=Ekho Hakka", NULL, &cpEnum))) {
		cerr << "Fail to get voices!" << endl;
		return -1;
	}

	//Get the closest token
	cpToken.Release();
	if (FAILED(cpEnum ->Next(1, &cpToken, NULL))) {
		cerr << "Fail to get voice EkhoVoice!" << endl;
		return -1;
	}
	
	//set the voice 
	if (FAILED(pSpVoice->SetVoice( cpToken))) {
		cerr << "Fail to set voice EkhoVoice!" << endl;
		return -1;
	}

	cout << "speak 123 in Hakka ... ";

	pSpVoice->Speak(L"123", SPF_DEFAULT, NULL);
	cout << "done" << endl;

	// Shutdown the voice
	cpToken.Release();
	cpEnum.Release();
	pSpVoice->Release();
	pSpVoice = NULL;

	// Shutdown COM
	CoUninitialize ();
}
	cout << "press 1<ENTER> to continue";
	int a;
	cin >> a;

	return 0;
	
}
