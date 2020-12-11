#pragma once
#include "Enemy.h"
#include "Vector2.h"
class TitleEnemy
	:public Enemy
{
private:
	int enemyNum;
	bool inversion;
public:
	TitleEnemy(Vector2 *position);
	~TitleEnemy();
	//������
	void Initialize()override;
	//���t���[������
	void Update()override;
	//�`�揈��
	void Draw()override;
	//�q�b�g������
	void Hit(GameObject *obj)override;
};

