#include <iostream>
#include "App.hpp"
#define version "0.4.0";
const int WIDTH = 1136;
const int HEIGHT = 640;

int main(int argc, char ** argv)
{
	const std::string version("v0.4.0");
	const char* data = version.data();
	std::cout << "Version: " << version.data() << std::endl;
	
	
	Engine::App* app = new Engine::App("Asteroids!!", WIDTH, HEIGHT);	


	if(!app->Init())
	{
		std::cout << "App Init error!\n";
		return -1;
	}	


	app->Execute();

	
	delete app;

	return 0;
}