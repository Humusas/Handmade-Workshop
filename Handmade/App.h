#pragma once

/*===================================================================#
| 'App' source files last updated on 22 February 2022                |
#====================================================================#
| Class has not been fully tested. No known issues found.            |
#===================================================================*/

//This class implements RAII which means the ctor and dtor manage the 
//initialization and shutdown respectively and avoid code clutter in 
//main.cpp. This class works but has not been fully tested for issues.

#include <memory>
#include "State.h"

class App
{

public:

	App(State* initialState);
	~App();
	void Run();

private:

	bool Initialize();
	bool CreateObjects();
	void Shutdown();

	int m_deltaTime = 0;
	std::unique_ptr<State> m_appState;

};