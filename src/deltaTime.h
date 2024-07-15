#ifndef DELTATIME__H
#define DELTATIME__H

#include <chrono>

static std::chrono::high_resolution_clock::time_point startPoint__ = std::chrono::high_resolution_clock::now();
static std::chrono::high_resolution_clock::time_point endPoint__;

//class DeltaTime
//{
//public:
//	DeltaTime();
//	void update();
//
//
//
//private:
//	//std::chrono::high_resolution_clock::time_point startPoint;
//	//std::chrono::high_resolution_clock::time_point endPoint;
//	float deltaTime;
//
//};
//


void updateDeltaTime(float& deltaTime);

#endif