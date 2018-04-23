#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include <iostream>
#include "GameObject.h"
#include "Component.h"

class InputManager
{
private:
	bool m_mouseState[6];
	int m_mouseUpdate[6];

	bool m_keyState[410];
	int m_keyUpdate[410];

	bool m_quitRequested;
	int m_updateCounter;

	int m_mouseX;
	int m_mouseY;

	InputManager();
	~InputManager();
public:
	void Update();

	bool KeyPress(int key);
	bool KeyRelease(int key);
	bool IsKeyDown(int key);

	bool MousePress(int button);
	bool MouseRelease(int button);
	bool IsMouseDown(int button);

	int GetMouseX();
	int GetMouseY();

	bool QuitRequested();

	static InputManager& GetInstance();
};

#endif