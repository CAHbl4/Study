#include <iostream>
#include <Windows.h>

using namespace std;

void main() {
	SetConsoleCP(1251);					//РџРѕ СѓРјРѕР»С‡Р°РЅРёСЋ РІ РєРѕРЅСЃРѕР»Рё cp866 
	SetConsoleOutputCP(1251);			//РџРµСЂРµРІРѕРґРёРј РєРѕРЅСЃРѕР»СЊ РЅР° 1251

	/*
	РџРѕР»СЊР·РѕРІР°С‚РµР»СЊ РІРІРѕРґРёС‚ СЃ РєР»Р°РІРёР°С‚СѓСЂС‹ СЃРёРјРІРѕР». РћРїСЂРµРґРµР»РёС‚СЊ, РєР°РєРѕР№ СЌС‚Рѕ СЃРёРјРІРѕР»: Р‘СѓРєРІР°, С†РёС„СЂР°, Р·РЅР°Рє РїСЂРµРїРёРЅР°РЅРёСЏ РёР»Рё РґСЂСѓРіРѕРµ.

	*/

	//РљРѕРґ РїСЂРѕРіСЂР°РјРјС‹

	unsigned char c;

	cout << "Р’РІРµРґРёС‚Рµ СЃРёРјРІРѕР»: ";
	cin >> c;

	//for (int i = 0; i < 256; i++) {
	//	cout << i << " " << (char)i << " ";
	//}


	if (c >= 'A' && c <= 'Z')
		cout << "РђРЅРіР»РёР№СЃРєСЏР°СЏ Р·Р°РіР»Р°РІРЅР°СЏ Р±СѓРєРІР°";
	else if (c >= 'a' && c <= 'z')
		cout << "РђРЅРіР»РёР№СЃРєР°СЏ СЃС‚СЂРѕС‡РЅР°СЏ Р±СѓРєРІР°";
	else if (c >= 192 && c <= 223 || (int)c == 168)
		cout << "Р СѓСЃСЃРєР°СЏ Р·Р°РіР»Р°РІРЅР°СЏ Р±СѓРєРІР°";
	else if (c >= 224 && c <= 255 || (int)c == 184)
		cout << "Р СѓСЃСЃРєР°СЏ СЃС‚СЂРѕС‡РЅР°СЏ Р±СѓРєРІР°";
	else if (c >= '0' && c <= '9')
		cout << "Р¦РёС„СЂР°";
	else if ((c >= ' ' && c <= '/') ||
		(c >= ':' && c <= '@') ||
		(c >= '[' && c <= '`') ||
		(c >= '{' && c <= '~'))
		cout << "Р—РЅР°Рє РїСЂРµРїРёРЅР°РЅРёСЏ";
	else if (c >= 128 && c <= 191)
		cout << ("РљР°РєРѕР№ С‚Рѕ РёР· СЃРёРјРІРѕР»РѕРІ СЂР°СЃС€РёСЂРµРЅРёСЏ 1251 РЅРµ РѕС‚РЅРѕСЃСЏС‰РёР№СЃСЏ Рє СЂСѓСЃСЃРєРѕРјСѓ Р°Р»С„Р°РІРёС‚Сѓ");
	else cout << ("РЈРїСЂР°РІР»СЏСЋС‰РёР№ СЃРёРјРІРѕР»");

	cout << endl;
	system("pause");
}