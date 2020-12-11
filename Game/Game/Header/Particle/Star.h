#pragma once
#include "Particle.h"
#include "Vector2.h"
#include "Timer.h"
class Star :
	public Particle
{
private:
	int angle;
	Timer deadTimer;
	int addAngle;
public:
	Star(Vector2 *position);
	~Star();
	//����������
	virtual void Initialize()override;
	//���t���[������
	virtual void Update()override;
	//�`�揈��
	virtual void Draw()override;
};

