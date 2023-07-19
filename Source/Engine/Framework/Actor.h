#pragma once
#include "../Core/Core.h"
#include "../Render/Model.h"

namespace kda {
	class Actor {
		public:
			Actor() = default;
			Actor(const kda::Transform& transform, const kda::Model& model) :
				m_transform{ transform },
				m_model{ model }
			{}

			virtual void Update(float dt);
			virtual void Draw(kda::Renderer& renderer);

			friend class Scene;
			class kda::Scene* m_scene = nullptr;

			kda::Transform m_transform;

		protected:
			bool m_destroyed = false;
			float m_lifespan = -1.0f;

			kda::Model m_model;
	};
}
