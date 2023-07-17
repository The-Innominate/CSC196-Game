#pragma once
#include "./Framework/Actor.h"

class Pew : public kda::Actor {
public:
	Pew(float speed, const kda::Transform& transform, const kda::Model& model) :
		Actor{ transform, model },
		m_speed{ speed }
	{}

	void Update(float dt) override;

private:
	float m_speed = 0;
	float m_turnRate = 0;
};