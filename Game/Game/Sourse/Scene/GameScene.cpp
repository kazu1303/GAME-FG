#include "GameScene.h"
#include "DxLib.h"

GameScene::GameScene()
{
	pixelMFont = LoadFontDataToHandle("Font/PixelMplus.dft", 0);
	pixelMFont64 = LoadFontDataToHandle("Font/PixelMplus_64.dft", 0);
}


GameScene::~GameScene()
{
}

//����������
void GameScene::Initialize()
{
}

//���t���[������
void GameScene::Update()
{
}

//�`�揈��
void GameScene::Draw()
{
}

//�V�[���I��
bool GameScene::IsEnd()
{
	return isEnd;
}

//���̃V�[��
Scene GameScene::Next()
{
	return Scene();
}

//���݂̃V�[��
Scene GameScene::CurrentScene()
{
	return Scene();
}
