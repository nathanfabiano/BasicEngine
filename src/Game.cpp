/*
• 
Game: A Estrutura Básica da Engine
Game
 - Game        (title  : string, 
                width  : int, 
                height : int) 
 + ~Game       () 
 + Run         () : void 
 + GetRenderer () : SDL_Renderer* 
 + GetState    () : State&
 + GetInstance () : Game&
 - instance   : Game*
 - window     : SDL_Window* 
 - renderer   : SDL_Renderer* 
 - state      : State* 
 */

 #define INCLUDE_SDL
 #define INCLUDE_SDL_IMAGE
 #define INCLUDE_SDL_MIXER
 #include "SDL_include.h"
 #include "Game.h"
 #include <iostream>

//------------------------------------------- MUSIC -------------------------------------------------------
Music::Music() : m_music(nullptr)
{

}

Music::Music(std::string file)
{
	Music();
	Open(file);
}

void Music::Open(std::string file)
{
	if (IsOpen())
	{
		//delete m_music;
		Mix_FreeMusic(m_music);
	}
	
	m_music = Mix_LoadMUS(file.c_str());
	if (!IsOpen())
	{
        SDL_Log("Unable to load music: %s", SDL_GetError());
        //return 1;
	}
}

void Music::Play(int times=-1)
{
	if (IsOpen())
	{
		Mix_PlayMusic(m_music, times); //times: -1 = loop infinito, 0 = nao toca
	}
}

void Music::Stop(int msToStop=1500)
{
	Mix_FadeOutMusic(msToStop);
}

bool Music::IsOpen()
{
	if (m_music == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Music::~Music()
{
	Stop(0);
	Mix_FreeMusic(m_music);
}

//------------------------------------------- SPRITE ------------------------------------------------------

Sprite::Sprite() : m_texture(nullptr)
{

}

Sprite::Sprite(std::string file)
{
	Sprite();
	Open(file);
}

Sprite::~Sprite()
{
	//SDL_DestroyTexture(SDL_Texture*);
}

void Sprite::Open(std::string file)
{
	Game* game = Game::GetInstance();
	if (IsOpen())
	{
		SDL_DestroyTexture(m_texture);
	}

	m_texture = IMG_LoadTexture(game->GetRenderer(), file.c_str());
	if (!IsOpen())
	{
        SDL_Log("Unable to load texture: %s", SDL_GetError());
        //return 1;
	}
	SDL_QueryTexture(m_texture, nullptr, nullptr, &m_width, &m_height); //
	SetClip(0, 0, m_width, m_height);
}

void Sprite::SetClip(int x, int y, int w, int h)
{
	m_clipRect.x = x;
	m_clipRect.y = y;
	m_clipRect.w = w;
	m_clipRect.h = h;
}

void Sprite::Render(int x, int y)
{
	Game* game = Game::GetInstance();
	SDL_Rect clipRectDest;
	clipRectDest.x = x;
	clipRectDest.y = y;
	clipRectDest.w = GetWidth();
	clipRectDest.h = GetHeight();

	SDL_RenderCopy(game->GetRenderer(), m_texture, &m_clipRect, &clipRectDest);

}

bool Sprite::IsOpen()
{
	if (m_texture == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//------------------------------------------- STATE -------------------------------------------------------
State::State() : m_quitRequest(false)
{
	//sprite
	printf("music opening\n");
	m_music.Open("assets/audio/stageState.ogg");
	m_music.Play(-1);
}

void State::LoadAssets()
{

}

void State::Update(float dt)
{
	if(SDL_QuitRequested())
	{
		m_quitRequest = true;
	}
}

void State::Render()
{
	m_bg.Open("assets/img/ocean.jpg");
	m_bg.Render(0, 0);
}
//------------------------------------------- GAME --------------------------------------------------------
void Game::Run()
{
	Game* game = Game::GetInstance();
	State* state = game->GetState();
	printf("teste3\n");
	int n = 0;
	while(!state->QuitRequest())
	{
		//std::cout << "t1" << std::endl;
		n++;
		printf("testeLoop: %d\n", n);
		state->Update(0);
		state->Render();
		SDL_RenderPresent(game->GetRenderer());
		SDL_Delay(33); //Aprox. 30FPS
	}
}

Game::Game(std::string title, int width, int height) : m_width(width), m_height(height)
{
	m_title = title;
	//Inicializa as bibliotecas SDL, SDL_img e SDL_mixer
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) != 0) 
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        std::cout << "Unable to initialize SDL:";
        //return 1;
    }
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)
	{
		SDL_Log("Unable to initialize SDL_IMG: %s", SDL_GetError());
       	std::cout << "Unable to initialize SDL:";
       	//return 1;
	}
	Mix_Init(MIX_INIT_MP3);
	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0){
		SDL_Log("Unable to initialize SDL_MIX: %s", SDL_GetError());
   		std::cout << "Unable to initialize SDL:";
   		//return 1;
	}
	Mix_AllocateChannels(32);

	//Cria a Janela do jogo
	m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, 0);
	if (m_window == nullptr)
	{
		SDL_Log("Could not create WINDOW: %s\n", SDL_GetError());
		std::cout << "Unable to initialize SDL:";
		//return 1;
	}

	//Cria o Renderizador
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == nullptr)
	{
		SDL_Log("Could not create RENDERER: %s\n", SDL_GetError());
		std::cout << "Unable to initialize SDL:";
		//return 1;
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
//-- Singleton --
Game* Game::s_instance = 0;

Game* Game::GetInstance()
{
	if(s_instance == 0)
	{
		s_instance = new Game("11/0134338", 1024, 600);
	}

	return s_instance;
}

int main(int argc, char* argv[])
{
	printf("teste1\n");
    //std::cout << "pqplsl 1";
    // codigo
	Game* game = Game::GetInstance();
	//std::cout << "pqplsl";
	printf("teste2\n");
	game->Run();


    return 0;
}

//-----------------------------------------------------------------------------------------------------------------