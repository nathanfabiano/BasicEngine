
 #define INCLUDE_SDL
 #define INCLUDE_SDL_IMAGE
 #define INCLUDE_SDL_MIXER
 #include "SDL_include.h"
 #include "Game.h"
 #include "State.h"
 #include <iostream>

void Game::Run()
{
	Game* game = Game::GetInstance();
	State* state = game->GetState();
	//BackGround..
	state->GetGameObject(0)->GetComponent("Sprite")->Open("assets/img/ocean.jpg");
	while(!state->QuitRequest())
	{
		state->Update(0);
		state->Render();
		SDL_RenderPresent(game->GetRenderer());
		SDL_Delay(33); //Aprox. 30FPS
	}
}

Game::Game(std::string title, int width, int height) : m_width(width), m_height(height), m_window(nullptr), m_renderer(nullptr), m_state(nullptr)
{
	m_title = title;
	//Inicializa as bibliotecas SDL, SDL_img e SDL_mixer
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) != 0) 
    {
    	std::cout << "Unable to initialize SDL: " << SDL_GetError();
        printf("Unable to initialize SDL: %s", SDL_GetError());
    }
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)
	{
		std::cout << "Unable to initialize SDL_IMG: " << SDL_GetError();
		printf("Unable to initialize SDL_IMG: %s", SDL_GetError());
	}
	Mix_Init(MIX_INIT_MP3);
	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
	{
		std::cout << "Unable to initialize SDL_MIX: " << SDL_GetError();
		printf("Unable to initialize SDL_MIX: %s", SDL_GetError());
	}
	Mix_AllocateChannels(32);

	//Cria a Janela do jogo
	if (m_window == nullptr)
	{
		m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, 0);
	}
	if (m_window == nullptr)
	{
		std::cout << "Unable to create WINDOW: " << SDL_GetError();
		printf("Could not create WINDOW: %s\n", SDL_GetError());
	}

	//Cria o Renderizador
	if (m_renderer == nullptr)
	{
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
		if (m_renderer == nullptr)
		{
			std::cout << "Unable to create RENDERER: " << SDL_GetError();
			printf("Could not create RENDERER: %s\n", SDL_GetError());
		}

	}
	//Inicializar STATE
	m_state = new State();

}

Game::~Game()
{
	Game::GetInstance()->GetState()->~State();

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}
//---- Singleton ----
Game* Game::s_instance = 0;

Game* Game::GetInstance()
{
	if(s_instance == 0)
	{
		s_instance = new Game("11/0134338", 1024, 600);
	}

	return s_instance;
}
