#include <iostream>
#include "../../Engine/Core/Random.h"
#include "../../Engine/Core/fileIO.h"
#include "../../Engine/Core/Memory.h"
#include "../../Engine/Core/Time.h"
#include "Render/Render.h"
#include <chrono>
using namespace std;

int main()
{

	kda::CreateWindow("CSC196", 800, 600);
	cin.get(); // pause

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