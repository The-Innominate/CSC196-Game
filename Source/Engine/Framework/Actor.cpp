#include "Actor.h"

namespace kda {
	void Actor::Draw(kda::Renderer& renderer){
		m_model.Draw(renderer, m_transform);
	}
}

