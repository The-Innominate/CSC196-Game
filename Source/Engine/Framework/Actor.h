#pragma once
#include "../Core/Core.h"
#include "../Render/Model.h"
#include <memory>


namespace kda {
	class Actor {
		public:
			Actor() = default;
			Actor(const kda::Transform& transform, std::shared_ptr<Model> model) :
				m_transform{ transform },
				m_model{ model }
			{}

			virtual void Update(float dt);
			virtual void Draw(kda::Renderer& renderer);
			float getRadius() { return m_model->getRadius() * m_transform.scale;}
			virtual void onCollision(Actor* other) {}

			
			class Scene* m_scene = nullptr;
			friend class Scene;
			
			kda::Transform m_transform;
			std::string m_tag;

		protected:
			bool m_destroyed = false;
			float m_lifespan = -1.0f;

			std::shared_ptr<Model> m_model;
	};
}
