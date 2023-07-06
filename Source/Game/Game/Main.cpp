#include <iostream>
#include "Render/Render.h"
#include "Core/Core.h"
#include "../../Engine/Core/Vector2.h"
#include <chrono>
#include <vector>
using namespace std;

class Star {
public:
	Star(const kda::Vector2& pos, const kda::Vector2& vel) :
		m_pos{pos},
		m_vel{vel}
	{}

	void Update(int width, int height) {
		m_pos += m_vel;
		if (m_pos.x >= width) m_pos.x = 0;
		if (m_pos.y >= height) m_pos.y = 0;
	}

public:
	kda::Vector2 m_pos;
	kda::Vector2 m_vel;
};

int main(int argc, char* argv[])
{

	kda::seedRandom((unsigned int)time(nullptr));

	for (int i = 0; i < 20; i++) { cout << kda::randomf(68, 70) << endl; }

	

	kda::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	vector<Star> stars;
	for (int i = 0; i < 1000; i++) {
		kda::Vector2 pos(kda::random(renderer.GetWidth()), kda::random(renderer.GetHeight()));
		kda::Vector2 vel(kda::randomf(1, 4), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	while (true) {
		renderer.SetColor(0, 0, 0, 255);
		renderer.BeginFrame();
		//draw
		kda::Vector2 vel(1.0f, 0.3f);

		for (auto& star : stars) {

			star.Update(renderer.GetWidth(), renderer.GetHeight());

			renderer.SetColor(kda::random(0, 254), kda::random(0, 254), kda::random(0, 254), 255);
			renderer.DrawPoint(star.m_pos.x, star.m_pos.y);	

		}


		//for (int i = 0; i < 1000; i++)
		//{
		//	//kda::Vector2 pos(kda::randomf(renderer.GetWidth()), kda::random())
		//	renderer.SetColor(kda::random(0, 254), kda::random(0, 254), kda::random(0, 254), 255);
		//	renderer.DrawLine(kda::random(renderer.GetWidth()), kda::random(renderer.GetHeight()), kda::random(renderer.GetWidth()), kda::random(renderer.GetHeight()));
		//}
		
		renderer.EndFrame();
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
}