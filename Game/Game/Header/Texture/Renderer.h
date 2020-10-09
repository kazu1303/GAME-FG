#pragma once
#include "Vector2.h"
#include "Textures.h"

#include<map>

class Renderer
{
private:
	std::map<std::string, int> textures;//���[�h�����摜���̕ۑ��p
    static Renderer* instance;//�C���X�^���X
	int texNum = 0;
public:
	Renderer();
	~Renderer();
	//�C���X�^���X��Ԃ�
    static Renderer* Instance();
	//�摜�̃��[�h
	void Load();
	//�摜�ǂݍ���
	void LoadContent(std::string assetName, std::string failPath, std::string Path = "");
	//�摜��map�ɕۑ�
	void LoadContent(std::string assetName,int graph);
	//�摜����Ԃ�
	int Texture(std::string name);
	//���W�ɕ`��
	void DrawTexture(std::string name,Vector2* position);
	//�g�k�A��]���ł���`��
	void DrawTexture1(std::string name, Vector2* position, float angle, float scale = 4.0f, bool reverse = false);
	//��_��ύX����`��
	void DrawTexture2(std::string name, Vector2* position, Vector2* center, float angle,float scale = 4.0f,bool reverse = false);
	//XY���ꂼ��g�k�ł���`��
	void DrawTexture3(std::string name, Vector2* position, Vector2* center, float angle, float scaleX = 4.0f, float scaleY = 4.0f, bool reverse = false);
};





