#include "Player.h"
#include "Framework/Scene.h"
#include "Render/Renderer.h"
#include "Pew.h"

void Player::Update(float dt){
	Actor::Update(dt);

	float rotate = 0;
	if (kda::g_inputSystem.GetKeyDown(SDL_SCANCODE_LEFT)) rotate = -1;
	if (kda::g_inputSystem.GetKeyDown(SDL_SCANCODE_RIGHT)) rotate = 1;
	m_transform.rotation += rotate * m_turnRate * kda::g_time.getDeltaTime();

	float thrust = 0;
	if (kda::g_inputSystem.GetKeyDown(SDL_SCANCODE_UP)) thrust = 1;

	kda::vec2 forward = kda::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * thrust * kda::g_time.getDeltaTime();
	m_transform.position.x = kda::wrap(m_transform.position.x, (float)kda::g_renderer.GetWidth());
	m_transform.position.y = kda::wrap(m_transform.position.y, (float)kda::g_renderer.GetHeight());

	//fire weapon
	if (kda::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE) && !kda::g_inputSystem.GetPreviousKeyDown(SDL_SCANCODE_SPACE)) {
		kda::Transform transform{m_transform.position, m_transform.rotation, 1};
		std::unique_ptr<Pew> pew = std::make_unique<Pew>( 400.0f, m_transform, m_model );
		m_scene->Add(std::move(pew));
	}
}

