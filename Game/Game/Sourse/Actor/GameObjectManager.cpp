#include "GameObjectManager.h"
#include "Clock.h"

using namespace std;

vector<shared_ptr<GameObject>> GameObjectManager::gameObjects;
vector<shared_ptr<GameObject>> GameObjectManager::addgameObjects;

//vector<GameObject*>::iterator itr;

GameObjectManager* GameObjectManager::instance = nullptr;



GameObjectManager::GameObjectManager()
{
	instance = this;
	Initialize();
}

//インスタンス
GameObjectManager * GameObjectManager::Instance()
{
	return instance;
}

//初期化処理
void GameObjectManager::Initialize()
{
	//すべてのvectorをクリアしサイズを合わせる
	gameObjects.clear();
	addgameObjects.clear();
	gameObjects.shrink_to_fit();
	addgameObjects.shrink_to_fit();
}

//ブロック以外のキャラを配列に加える
void GameObjectManager::Add(GameObject* obj)
{
	shared_ptr<GameObject> addobj(obj);
	addgameObjects.push_back(addobj);
}

//毎フレーム処理
void GameObjectManager::Update()
{
	//新しく生成されたオブジェクトの追加
	gameObjects.insert(gameObjects.end(), addgameObjects.begin(), addgameObjects.end());
	addgameObjects.clear();

	//アップデート
	for (auto obj1 : gameObjects)
	{
		for (auto obj2 : gameObjects)
		{
			obj1->SetPlayerPos(obj2->GetPos(), obj2->GetType());
		}
	}
	//キャラクターの毎フレーム処理
	for (auto itr : gameObjects)
	{
		itr->Update();
	}

	HitToObject();
	//死亡判定
	//キャラクターの死亡処理
	for (auto itr = gameObjects.begin(); itr != gameObjects.end(); )
	{
		//死亡してたらvectorから消す
		if ((*itr)->IsDead())
		{
		    itr  = gameObjects.erase(itr);
		}
		//死亡してなかったら次のオブジェクトを見る
		else
		{
			itr++;
		}
	}

	//サイズを合わせる
	gameObjects.shrink_to_fit();
}

//描画処理
void GameObjectManager::Draw()
{
	for (auto itr : gameObjects)
	{
		itr->Draw();
	}
}

//ヒット処理
void GameObjectManager::HitToObject()
{
	//ヒット判定
	for (auto obj1 : gameObjects)
	{
		//当たり判定がない場合処理しない
		if (!obj1->EntityObject() ||
			obj1->IsDead())
		{
			continue;
		}
		for (auto obj2 : gameObjects)
		{
			//同じものと当たり判定がないものは処理しない
			if (obj1->Equal(obj2.get()) ||
				!obj2->EntityObject() ||
				obj2->IsDead())
			{
				continue;
			}
			//ヒットしていたらヒット時の処理
			if (obj1->IsCollision(obj2.get()))
			{
				obj1->Hit(obj2.get());
			}
		}
	}
}

//スタートするか
bool GameObjectManager::Start()
{
	return false;
}

//死んだか
bool GameObjectManager::GameOver()
{
	return false;
}

//クリアしたか（ゲームプレイに返す用）
bool GameObjectManager::GameClear()
{
	return false;
}

//クリアしたか（このクラス内で使うよう）
bool GameObjectManager::ClearFlag()
{
	return false;
}

GameObjectManager::~GameObjectManager()
{
}
