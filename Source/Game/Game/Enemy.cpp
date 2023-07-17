#include "Enemy.h"
#include "Render/Renderer.h"

void Enemy::Update(float dt) {
	kda::vec2 forward = kda::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * kda::g_time.getDeltaTime();
	m_transform.position.x = kda::wrap(m_transform.position.x, (float)kda::g_renderer.GetWidth());
	m_transform.position.y = kda::wrap(m_transform.position.y, (float)kda::g_renderer.GetHeight());
}