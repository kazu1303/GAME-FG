#include "Sound.h"
#include "DxLib.h"

using namespace std;
Sound* Sound::instance = nullptr;

Sound::Sound()
{
	instance = this;
	ses = map<string, int>();
	bgms = map<string, string>();
}


Sound::~Sound()
{
}

//�C���X�^���X��Ԃ�
Sound * Sound::Instance()
{
	return instance;
}

//SE�̃��[�h
void Sound::LoadSE(string assetName, string filePath,string Path)
{
	string fName = Path + assetName + "." + filePath;
	LoadSE(assetName, LoadSoundMem(fName.c_str()));
}

//���[�h����SE��map�ɕۑ�
void Sound::LoadSE(string assetname, int sound)
{
	ses[assetname] = sound;
}

//SE�𗬂�
void Sound::PlaySE(string name)
{
	PlaySoundMem(ses[name], DX_PLAYTYPE_BACK);
}

//SE������Ă��邩���ׂĂ���
bool Sound::CkeckSEPlay(string name)
{
	return CheckSoundMem(ses[name]);
}

//BGM�𗬂�
void Sound::PlayBGM(string name,string Path)
{
	string fname = Path + name;
	PlayMusic(fname.c_str(), DX_PLAYTYPE_LOOP);
}

//BGM������Ă��邩���ׂ�
bool Sound::CkeckBGMPlay()
{
	return CheckMusic();
}

//BGM���~�߂�
void Sound::StopBGM()
{
	StopMusic();
}
