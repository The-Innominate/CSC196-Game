#include "Scene.h"

void kda::Scene::Update(float dt){
	for (auto actor : m_actors) {
		actor->Update(dt);
	}
}

void kda::Scene::Draw(Renderer& renderer){
	for (auto actor : m_actors) {
		actor->Draw(renderer);
	}
}

void kda::Scene::Add(Actor* actor){
	actor->m_scene = this;
	m_actors.push_back(actor);
}

void kda::Scene::Remove(Actor* actor){
	m_actors.remove(actor);
}

void kda::Scene::RemoveAll(){
	m_actors.clear();
}
