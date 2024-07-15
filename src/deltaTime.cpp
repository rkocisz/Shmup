#include "deltaTime.h"

void updateDeltaTime(float& deltaTime)
{
	endPoint__ = std::chrono::high_resolution_clock::now();

	deltaTime = std::chrono::duration<float>(endPoint__ - startPoint__).count();

	startPoint__ = std::chrono::high_resolution_clock::now();
}
