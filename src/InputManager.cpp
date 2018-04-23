#include "InputManager.h"
#include "Resources.h"
#include "Game.h"
#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include <iostream>
#include <unordered_map>

InputManager& InputManager::GetInstance()
{
    static InputManager instance;
    return instance;
}

InputManager::InputManager() : m_mouseState{}, m_mouseUpdate{}, m_keyState{}, m_keyUpdate(), m_quitRequested {}, m_updateCounter {}
{

}

InputManager::~InputManager()
{

}

void InputManager::Update()
{
	SDL_Event event;
	m_updateCounter++;
	int key;

	// Obtem as coordenadas do mouse
	SDL_GetMouseState(&m_mouseX, &m_mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// --- UPDATE QUIT REQUEST
		if(event.type == SDL_QUIT) {
			m_quitRequested = true;
		}

		// --- UPDATE KEYS
		if( event.type == SDL_KEYDOWN ) {
			//Ajusta Deslocamento
			if( event.key.keysym.sym > 0x4000000) 
			{
				// Teclas que não tem valor de caracter, como Caps Lock, teclas F, Shift, Alt, etc.,
				// estão no range 0x40000000 até 0x4000011A. (foi subtraido 0x3FFFFF81 p/ alinhar)
				key = event.key.keysym.sym - 0x3FFFFF81;	// 128 a 409
			}
			else 
			{
				// Range normal da tabela ASCII - 0x0 to 0x7F
				key = event.key.keysym.sym;		// 0 a 127
			}
			// Atualiza o estado e quando o botao foi atualizado
			if (!m_keyState[key])
			{
				m_keyUpdate[key] = m_updateCounter;
				std::cout << "Tecla '" << (char)key << "' down!" << std::endl;
			}
			m_keyState[key] = true;
		}
		if( event.type == SDL_KEYUP )
		{ 
			//if(event.key.reapeat)
			// Mesmo Funcionamento de SDL_KEYDOWN
			if( event.key.keysym.sym > 0x4000000) 
			{
				key = event.key.keysym.sym - 0x3FFFFF81;
			}
			else 
			{
				key = event.key.keysym.sym;
			}
			// Atualiza o estado e quando o botao foi atualizado
			if (m_keyState[key])
			{
				m_keyUpdate[key] = m_updateCounter;
				std::cout << "Tecla '" << (char)key << "' up!" << std::endl;
			}
			m_keyState[key] = false;
		}

		// --- UPDATE MOUSE BUTTON
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (!m_mouseState[event.button.button]) //1 = left click, 2 = right click
			{
				m_mouseUpdate[event.button.button] = m_updateCounter;
				std::cout << "Mouse '" << (int)event.button.button << "' down!" << std::endl;
			}
			m_mouseState[event.button.button] = true;
		}
		if(event.type == SDL_MOUSEBUTTONUP)
		{
			if (m_mouseState[event.button.button])
			{
				m_mouseUpdate[event.button.button] = m_updateCounter;
				std::cout << "Mouse '" << (int)event.button.button << "' up!" << std::endl;
			}
			m_mouseState[event.button.button] = false;
		}
	}
}

bool InputManager::KeyPress(int key)
{
	if ((m_keyState[key])&&(m_keyUpdate[key] == m_updateCounter))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::KeyRelease(int key)
{
	if ((!m_keyState[key])&&(m_keyUpdate[key] == m_updateCounter))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::IsKeyDown(int key)
{
	if (m_keyState[key])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::MousePress(int button)
{
	if ((m_mouseState[button])&&(m_mouseUpdate[button] == m_updateCounter))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::MouseRelease(int button)
{
	if ((!m_mouseState[button])&&(m_mouseUpdate[button] == m_updateCounter))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::IsMouseDown(int button)
{
	if (m_mouseState[button])
	{
		return true;
	}
	else
	{
		return false;
	}
}

int InputManager::GetMouseX()
{
	return m_mouseX;
}

int InputManager::GetMouseY()
{
	return m_mouseY;
}

bool InputManager::QuitRequested()
{
	return m_quitRequested;
}