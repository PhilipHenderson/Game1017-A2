#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_

// Do not include initialized properties or full function definitions in this header.

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "Timer.h"
#include "Label.h"
#define WIDTH 1024
#define HEIGHT 768

class Engine
{
public: // Public methods.
	int Run();
	static Engine& Instance(); // This static method creates the static instance that can be accessed 'globally'
	SDL_Renderer* GetRenderer();
	bool& Running();
	bool KeyDown(SDL_Scancode c);
	//std::array<std::array<Tile*, COLS>, ROWS>& GetLevel() { return m_level; }

private: // Private properties.
	const Uint8* m_iKeystates; // Keyboard state container.
	bool m_running; // Loop control flag.
	Uint32 m_start, m_end, m_delta, m_fps; // Fixed timestep variables.
	SDL_Window* m_pWindow; // This represents the SDL window.
	SDL_Renderer* m_pRenderer; // This represents the buffer to draw to.

	// Example-specific properties.

private: // Private methods.
	Engine();
	bool Init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void Wake();
	void Sleep();
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
};

#endif