#pragma once
#include "GameScene.h"
#include "GameObjectManager.h"
#include "ParticleManager.h"
#include "Timer.h" 

class Title :
	public GameScene
{
private:
	GameObjectManager* gameObjectManager;
	ParticleManager* particleManager;
	Timer titleEnemyTimer;
	bool push;
	enum Tutorial
	{
		B,
		Y,
		RT,
		LT,
		END,
	};
	Timer tutorialTimer;
	int tutorial;
	int buttonFont;
public:
	Title();
	~Title();
	//初期化処理
	void Initialize()override;
	//毎フレーム処理
	void Update() override;
	//描画処理
	void Draw() override;
	//次のシーン
	virtual Scene Next() override;
	//現在のシーン
	Scene CurrentScene()override;
};

