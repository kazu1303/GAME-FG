#pragma once
#include <vector>
#include <memory>

#include "GameObject.h"




//オブジェクトを管理するクラス
class GameObjectManager
{
private:
	static GameObjectManager* instance;//インスタンス
	//ブロック以外のオブジェクトを入れるよう
	static std::vector<std::shared_ptr<GameObject>> gameObjects;//キャラを格納
	static std::vector<std::shared_ptr<GameObject>> addgameObjects;//新しく生成したキャラを格納

public:
	GameObjectManager();
	//インスタンス
	static GameObjectManager* Instance();
	//初期化処理
	void Initialize();
	//ブロック以外のキャラを配列に加える
	void Add(GameObject* obj);
	//毎フレーム処理
	void Update();
	//描画処理
	void Draw();
	//ヒット処理
	void HitToObject();
	//スタートするか
	bool Start();
	//死んだか
	bool GameOver();
	//クリアしたか
	bool GameClear();
	//クリアしたか
	bool ClearFlag();


	~GameObjectManager();
};