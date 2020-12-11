#pragma once
#include "Sounds.h"
#include <map>

class Sound
{
private:
	std::map<std::string, int> ses;
	std::map<std::string, std::string> bgms;
	static Sound* instance;
public:
	Sound();
	~Sound();
	//�C���X�^���X��Ԃ�
	static Sound* Instance();
	//�ǂݍ��މ��y�̐��������[�h
	void Load();
	//SE�̃��[�h
	void LoadSE(std::string assetname, std::string filePath, std::string Path = "");
	//���[�h����SE��map�ɕۑ�
	void LoadSE(std::string assetname, int sound);
	//SE�𗬂�
	void PlaySE(std::string name);
	//SE������Ă��邩���ׂĂ���
	bool CkeckSEPlay(std::string name);
	//BGM�𗬂�
	void PlayBGM(std::string name, std::string Path = "Sound/");
	//BGM������Ă��邩���ׂ�
	bool CkeckBGMPlay();
	//BGM���~�߂�
	void StopBGM();
};

//�ǂݍ��މ��y�̐��������[�h
inline void Sound::Load()
{
	for (int i = 0; i < 2; i++)
	{
		LoadSE(Sounds::SEDate[i][0], Sounds::SEDate[i][1], "Sound/");
	}
}


