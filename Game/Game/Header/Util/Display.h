#pragma once
#include <map>


//スクリーン
enum ScreenID
{
	Player_Screen,
	PlayerBattery_Screen,
	PlayerBullet_Screen,
	Enemy_Screen,
	SkyColor_Screen,
	UI_Screen,
	ScreenID_Length,
	
};

class Display
{
private:
	std::map<ScreenID, int> screens;//作成したスクリーンを保存
	static Display* instance;//インスタンス
	int screenNum = ScreenID_Length;//作成するスクリーンの数
public:
	Display();
	~Display();
	//インスタンスを返す
	static Display* Instance();
	//マスクの生成
	void MakeDrawScreen();
	//作成したスクリーンをmapに保存
	void MakeDrawScreen(ScreenID id, int screen);
	//マスクの描画のクリア
	void ClearScreen();
	//描画するマスクをセット
	void SetScreen(ScreenID id);
	//全マスクの描画
	void DrawScreen();
};



