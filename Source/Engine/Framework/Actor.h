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

			virtual void Update(float dt) = 0;
			virtual void Draw(kda::Renderer& renderer);

			friend class Scene;
			class kda::Scene* m_scene = nullptr;

		protected:
			kda::Transform m_transform;
			kda::Model m_model;
	};
}
