#pragma once
#include "Particle.h"
class GreenPlus :
	public Particle
{
public:
	GreenPlus(Vector2 *position);
	~GreenPlus();
	//����������
	virtual void Initialize();
	//���t���[������
	virtual void Update();
	//�`�揈��
	virtual void Draw();
};

