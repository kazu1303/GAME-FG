#pragma once
#include "GameScene.h"
#include "Timer.h"

class GameOver :
	public GameScene
{
private:
	Timer enemy1Summon;//生成間隔
	Timer enemy2Summon;//生成間隔
	Timer enemy3Summon;//生成間隔
public:
	GameOver();
	~GameOver();
	//初期化処理
	void Initialize();
	//毎フレーム処理
	void Update();
	//描画処理
	void Draw() override;
	//次のシーン
	virtual Scene Next() override;
	//現在のシーン
	Scene CurrentScene()override;
};

