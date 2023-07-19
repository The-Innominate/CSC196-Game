#include "Scene.h"

void kda::Scene::Update(float dt){
	//for (auto& actor : m_actors) {
	//	actor->Update(dt);
	//}

	//Remove destroyed actors
	auto iter = m_actors.begin();
	while (iter != m_actors.end()) {
		(*iter)->Update(dt);
		if ((*iter)->m_destroyed) {
			iter = m_actors.erase(iter);
		}else {
			iter++;
		}
	}
}

void kda::Scene::Draw(Renderer& renderer){
	for (auto& actor : m_actors) {
		actor->Draw(renderer);
	}
}

void kda::Scene::Add(std::unique_ptr<Actor> actor){
	actor->m_scene = this;
	m_actors.push_back(std::move(actor));
}

void kda::Scene::RemoveAll(){
	m_actors.clear();
}
