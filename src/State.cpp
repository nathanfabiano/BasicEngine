#include "State.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"
#include "Face.h"
#include "Vec2.h"
#include "Game.h"
#include "Sound.h"
#include "TileSet.h"
#include "TileMap.h"
#include "InputManager.h"
#include "Camera.h"
#include "CameraFollower.h"
//#include "Game.h"
#define INCLUDE_SDL
#include "SDL_include.h"

#define PI 3.1415926535

State::State() : m_quitRequest{}, m_started{}
{
	GameObject* bg = new GameObject(512.0f, 300.0f);

	Component* sprite = new Sprite(*bg);
	Component* camFollower = new CameraFollower(*bg);
	bg->AddComponent(sprite);
	bg->AddComponent(camFollower);

	m_objectArray.emplace_back(bg);

	//m_music.Open("assets/audio/stageState.ogg");
	//m_music.Play(-1);

	GameObject* map = new GameObject(0.0f, 0.0f);
	TileSet* tileSet = new TileSet(*map, 64, 64, "assets/img/tileset.png");
	Component* tileMap = new TileMap(*map, "assets/map/tileMap.txt", tileSet);
	map->AddComponent(tileMap);

	m_objectArray.emplace_back(map);
}

void State::Start()
{
	std::cout << "State Started" << std::endl;
	LoadAssets();
	for (int i = 0; i < (int)m_objectArray.size(); ++i)
	{
		m_objectArray[i].get()->Start();
	}
	m_started = true;
}

State::~State()
{
	m_objectArray.clear();
}

GameObject* State::GetGameObject(int indice)
{
	return m_objectArray[indice].get();
}

void State::LoadAssets()
{
	//???
}

void State::Update(float dt)
{
	/*
No começo do método, chame Input(). Depois, percorra o vetor de
GameObjects chamando o Update dos mesmos. No final, percorra o array de
objetos testando se algum dos GameObjects morreu. Se sim, remova-a do
array (erase). O loop de percorrimento do array precisa usar índices
numéricos, já que iteradores se tornam inválidos caso um elemento seja
adicionado ao vetor (o que vai acontecer em trabalhos futuros).
Sendo assim, para obter o iterador exigido como argumento de
vector::erase, use o iterador de início (vector::begin) somado à posição
do elemento.
	*/
	InputManager& input = InputManager::GetInstance();
	//CRIAR PENGUIN
	camera.Update(dt);
	if (input.KeyPress(' '))
	{
		Vec2 objPos = Vec2( 200, 0 );
		Vec2 objPos2 = Vec2( input.GetMouseX(), input.GetMouseY() );
		objPos = (objPos.GetRotated( -PI + PI*(rand() % 1001)/500.0 ));
		objPos = objPos + objPos2;
		AddObject((int)objPos.x, (int)objPos.y);
	}
	//DESTROI OBJETOS
	for (int i = 0; i < (int)m_objectArray.size(); ++i)
	{
		//std::cout << "t2" << std::endl;
		m_objectArray[i].get()->Update(dt);
		if (m_objectArray[i].get()->IsDead())
		{
			std::cout << "t4" << std::endl;
			m_objectArray.erase(m_objectArray.begin()+i);
			//m_objectArray.erase(m_objectArray[i]);
		}
	}
}

void State::Render()
{
	for (int i = 0; i < (int)m_objectArray.size(); ++i)
	{
		if (m_objectArray[i].get()->GetComponent("Sprite"))
		{
			m_objectArray[i].get()->GetComponent("Sprite")->Render();
		}
		if (m_objectArray[i].get()->GetComponent("tilemap"))
		{
			m_objectArray[i].get()->GetComponent("tilemap")->Render();
		}
	}
}

void State::AddObject(int mouseX, int mouseY)
{
	Game* game = Game::GetInstance();
	GameObject* gameObject = new GameObject(mouseX + (int)game->GetState()->camera.pos.x, mouseY + (int)game->GetState()->camera.pos.y);
	//Set Face - HP system
	Face* face = new Face(*gameObject);
	gameObject->AddComponent(face);
	//Sprite
	Sprite* sprite = new Sprite(*gameObject, "assets/img/penguinface.png");
	gameObject->AddComponent(sprite);
	//Set Sound 'boom'
	Sound* sound = new Sound(*gameObject, "assets/audio/boom.wav");
	gameObject->AddComponent(sound);

	m_objectArray.emplace_back(gameObject);
}

std::weak_ptr<GameObject> State::AddObject(GameObject* go)
{
	std::shared_ptr<GameObject> goPtr(go);
	m_objectArray.push_back(goPtr);
	if (m_started)
	{
		go->Start();
	}
	std::weak_ptr<GameObject> rPtr(goPtr);
	return rPtr;
}

std::weak_ptr<GameObject> State::GetObjectPtr(GameObject* go)
{
	for (int i = 0; i < (int)m_objectArray.size(); ++i)
	{
		if (m_objectArray[i].get() == go)
		{
			std::weak_ptr<GameObject> rPtr(m_objectArray[i]);
			return rPtr;
		}
	}
	return std::weak_ptr<GameObject>();
}