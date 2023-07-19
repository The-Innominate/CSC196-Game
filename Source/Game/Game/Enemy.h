#pragma once
#include "./Framework/Actor.h"

class Enemy : public kda::Actor {
public:
	Enemy(float speed, float turnRate, const kda::Transform& transform, const kda::Model& model) :
		Actor{ transform, model },
		m_speed{ speed },
		m_turnRate{ turnRate }
	{
		m_fireTime = 2.0f;
		m_fireRate = m_fireTime;
	}

	void Update(float dt) override;

private:
	float m_speed = 0;
	float m_turnRate = 0;

	float m_fireTime = 0;
	float m_fireRate = 0;
};