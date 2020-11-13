#pragma once
#include <string>

#include "Vector2.h"

enum Direction
{
	Top,
	Bottom,
	Right,
	Left
};

enum CharaType
{
	player,
	player_bullet,
	slow_bullet,
	enemy,
	enemy_bullet,
	clock,
	slow_area,
};

//オブジェクトの基底クラス
class GameObject
{
protected:
	Vector2* position = new Vector2(0,0);//座標
	Vector2* velocity = new Vector2(0,0);//移動量
	float size;
	float angle;//実際の角度、描画の際の角度
	int hp;//体力
	int attack;//攻撃力
	float defaultSpeed, speed;
    bool isDead;//死亡真偽
	bool entity;//当たり判定真偽
	CharaType type;//キャラクターのタイプ
public:
	GameObject(Vector2* position, CharaType type, bool entity, float scale = 1.0f,int hp = 1,std::string name = " " );
	virtual ~GameObject();
	//初期化処理
	virtual void Initialize();
	//毎フレーム処理
	virtual void Update();
	//描画処理
	virtual void Draw();
	//死亡の真偽
	bool IsDead();
	//ヒット処理
	virtual void Hit(GameObject* obj);
	//同オブジェクトかの真偽
	bool Equal( GameObject* other);
	//基本的な当たり判定（四角形）
	bool IsCollision(GameObject* other);
	//ヒットした方向を返す
	Direction CheckDirection( GameObject* other);
	//キャラタイプを返す
	virtual CharaType GetType();
	//当たり判定の真偽
	virtual bool EntityObject();
	//オブジェクトの座標を返す
	Vector2* GetPos();
	//ダメージ計算
	virtual void Damege(int attack);
	//スピード変化
	virtual void SpeedDown(int percentage);
};




