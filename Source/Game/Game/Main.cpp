#include <iostream>
#include "Render/Render.h"
#include "Render/Model.h"
#include "Core/Core.h"
#include "Player.h"
#include "Enemy.h"
#include "Framework/Scene.h"
#include "../../Engine/Core/Vector2.h"
#include <chrono>
#include <thread>
#include <vector>
#include <memory>
using namespace std;

class Star {
public:
	Star(const kda::Vector2& pos, const kda::Vector2& vel) :
		m_pos{pos},
		m_vel{vel}
	{}

	void Update(int width, int height) {
		m_pos += m_vel * kda::g_time.getDeltaTime();
		if (m_pos.x >= width) m_pos.x = 0;
		if (m_pos.y >= height) m_pos.y = 0;
	}

public:
	kda::Vector2 m_pos;
	kda::Vector2 m_vel;
};

int main(int argc, char* argv[]) {
	{
		//std::unique_ptr<int> up = std::make_unique<int>(10);
	}
	

	kda::g_memoryTracker.DisplayInfo();

	kda::seedRandom((unsigned int)time(nullptr));
	kda::setFilePath("Assets");


	kda::g_audioSystem.Initialize();
	kda::g_audioSystem.AddAudio("hit", "Laser_Shoot.wav");
	kda::g_renderer.Initialize();
	kda::g_renderer.CreateWindow("CSC196", 800, 600);

	kda::g_inputSystem.Initialize();

	//std::vector<kda::vec2> points{{ -10, 5 }, { 10, 5 }, { 0, -5 }, { -10, 5 }};

	kda::Model model;
	model.load("ship.txt");

	kda::vec2 v{5, 5};
	v.Normalize();

	vector<Star> stars;
	for (int i = 0; i < 1000; i++) {
		kda::Vector2 pos(kda::random(kda::g_renderer.GetWidth()), kda::random(kda::g_renderer.GetHeight()));
		kda::Vector2 vel(kda::randomf(100, 500), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	kda::Transform transform{{400, 300}, 0, 3};
	kda::vec2 position{ 400, 300};

	float speed = 200;
	float turnRate = kda::DegreesToRadians(180);

	kda::Scene scene;
	unique_ptr<Player> player = make_unique<Player>(200.0f, kda::pi, kda::Transform{ {400, 300}, 20, 3 }, model);
	scene.Add(std::move(player));
	for (int i = 0; i < 10; i++)
	{
		unique_ptr<Enemy> enemy = make_unique<Enemy>(200.0f, kda::pi, kda::Transform{ {400, 300}, 20, 6 }, model);
		scene.Add(std::move(enemy));
	}

	// Main game loop
	bool quit = false;
	while (!quit) {

		kda::g_audioSystem.Update();
		kda::g_time.tick();
		kda::g_inputSystem.Update();
		if (kda::g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}if (kda::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE)){
			kda::g_audioSystem.PlayOneShot("hit");
		}

		scene.Update(kda::g_time.getDeltaTime());

		/*kda::vec2 direction;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_UP)) direction.y = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_LEFT)) direction.x = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_DOWN)) direction.y = 1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_RIGHT)) direction.x = 1;*/

		//position += direction * speed * kda::g_time.getDeltaTime();

		//cout << inputSystem.GetMousePosition().x << " " << inputSystem.GetMousePosition().y << endl;
		if (kda::g_inputSystem.GetMouseButtonDown(0)) {
			cout << "Mouse Pressed value: left" << endl;
		}else if (kda::g_inputSystem.GetMouseButtonDown(1)) {
			cout << "Mouse Pressed value: middle" << endl;
		}else if (kda::g_inputSystem.GetMouseButtonDown(2)) {
			cout << "Mouse Pressed value: right" << endl;
		}

		kda::g_renderer.SetColor(0, 0, 0, 255);
		kda::g_renderer.BeginFrame();
		//draw
		kda::Vector2 vel(1.0f, 0.3f);

		for (auto& star : stars) {

			star.Update(kda::g_renderer.GetWidth(), kda::g_renderer.GetHeight());

			kda::g_renderer.SetColor(kda::random(0, 254), kda::random(0, 254), kda::random(0, 254), 255);
			kda::g_renderer.DrawPoint(star.m_pos.x, star.m_pos.y);

		}

		scene.Draw(kda::g_renderer);
		//model.Draw(kda::g_renderer, transform.position, transform.scale, transform.rotation);
		
		kda::g_renderer.EndFrame();
	}

	scene.RemoveAll();
	stars.clear();
	kda::g_memoryTracker.DisplayInfo();

	return 0;

}































/*kda::CreateWindow("CSC196", 800, 600);
	cin.get();*/ // pause

	/*kda::g_memoryTracker.DisplayInfo();
	int* p = new int;
	kda::g_memoryTracker.DisplayInfo();
	delete p;
	kda::g_memoryTracker.DisplayInfo();

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++) {}
	auto end = std::chrono::high_resolution_clock::now();
	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;

	kda::Time timer;
	for (int i = 0; i < 1000000; i++) {}
	cout << timer.GetElapsedNanoseconds() << endl;*/

	/*cout << kda::getFilePath() << endl;
	kda::setFilePath("Assets");
	cout << kda::getFilePath() << endl;

	size_t size; 
	kda::getFileSize("game.txt", size);
	cout << size << endl;

	string s;
	kda::readFile("game.txt", s);
	cout << s << endl;

	kda::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 10; i++)
	{
	cout << kda::random(69,69) << endl;
	}*/