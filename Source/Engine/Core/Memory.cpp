#include "Memory.h"
#include <iostream>

using namespace std;
kda::MemoryTracker kda::g_memoryTracker;

void* operator new(size_t size)
{
	void* p = malloc(size);

	kda::g_memoryTracker.Add(p, size);

	return p;
}

void operator delete(void* address, size_t size)
{
	kda::g_memoryTracker.Remove(address, size);

	free(address);
}

namespace kda 
{
	void MemoryTracker::Add(void* address, size_t size)
	{
		m_bytesAllocated += size;
		m_numAllocations++;
	}
	void MemoryTracker::Remove(void* address, size_t size)
	{
		m_bytesAllocated -= size;
		m_numAllocations--;
	}
	void MemoryTracker::DisplayInfo()
	{
		cout << "Current Bytes Allocated: " << m_bytesAllocated << endl;
		cout << "Current Number Allocations: " << m_numAllocations << endl;
	}
}