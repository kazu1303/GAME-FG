#include "Renderer.h"
#include "DxLib.h"
using namespace std;

Renderer* Renderer::instance = nullptr;

Renderer::Renderer()
{
	instance = this;
	textures = map<string, int>();
}

Renderer::~Renderer()
{
}

//�C���X�^���X��Ԃ�
Renderer* Renderer::Instance()
{
	return instance;
}

//�摜�̃��[�h
void Renderer::Load()
{
	//for (int i = 0; i < texNum; i++)
	//{
	//	LoadContent(Textures::Date[i][0], Textures::Date[i][1], "Content/Texture/");
	//}
}

//�摜�ǂݍ���
void Renderer::LoadContent(string assetName,string failPath, string Path)
{
	string fName = Path + assetName + failPath;
	LoadContent(assetName, LoadGraph(fName.c_str()));
}

//�摜��map�ɕۑ�
void Renderer::LoadContent(string assetName, int graph)
{
	textures[assetName] = graph;
}

//�摜����Ԃ�
int Renderer::Texture(string name)
{
	return textures[name];
}

//���W�ɕ`��
void Renderer::DrawTexture(string name, Vector2* position)
{
	DrawGraph((int)position->x, (int)position->y, textures[name], 1);
}

//�g�k�A��]���ł���`��
void Renderer::DrawTexture1(string name, Vector2 * position, float angle, float scale, bool reverse)
{
	double radian = angle * PI / 180.0f;
	DrawRotaGraph((int)position->x, (int)position->y, (double)scale, radian, textures[name], 1, reverse);
}

//��_��ύX����`��
void Renderer::DrawTexture2(string name, Vector2 * position, Vector2* center, float angle,float scale,bool reverse)
{
	double radian = angle * PI / 180;
	DrawRotaGraph2((int)position->x, (int)position->y,(int)center->x,(int)center->y, (double)scale, radian , textures[name], 1,reverse);
}

//XY���ꂼ��g�k�ł���`��
void Renderer::DrawTexture3(string name, Vector2 * position, Vector2 * center, float angle, float scaleX, float scaleY, bool reverse)
{
	double radian = angle * PI / 180;
	DrawRotaGraph3((int)position->x, (int)position->y, (int)center->x, (int)center->y, (double)scaleX,(double)scaleY, radian, textures[name], 1, reverse);
}
