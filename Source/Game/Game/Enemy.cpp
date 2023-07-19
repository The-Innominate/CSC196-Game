#include "Enemy.h"
#include "Player.h"
#include "Pew.h"
#include "./Framework/Scene.h"
#include "Render/Renderer.h"

void Enemy::Update(float dt) {

	Actor::Update(dt);

	Player* player = m_scene->GetActor<Player>();
	if (player) {
		kda::Vector2 direction = player->m_transform.position - m_transform.position;
		m_transform.rotation = direction.angle() + kda::halfpi;
	}

	kda::vec2 forward = kda::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * kda::g_time.getDeltaTime();
	m_transform.position.x = kda::wrap(m_transform.position.x, (float)kda::g_renderer.GetWidth());
	m_transform.position.y = kda::wrap(m_transform.position.y, (float)kda::g_renderer.GetHeight());

	m_fireRate -= dt;
	if (m_fireRate <= 0) {
		kda::Transform transform{m_transform.position, m_transform.rotation, 1};
		std::unique_ptr<Pew> pew = std::make_unique<Pew>(400.0f, m_transform, m_model);
		m_scene->Add(std::move(pew));

		m_fireRate = m_fireTime;
	}
	
}