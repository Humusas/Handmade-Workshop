#pragma once
#include <SDL.h>
#include <glm.hpp>

typedef const Uint8* KeyState;

class Input
{

public:

	enum class ButtonState
	{
		Up,
		Down
	};

	enum class CursorState
	{
		On = 1,
		Off = 0,
		Show = 1,
		Hide = 0
	};

	enum class CursorType
	{
		Arrow = SDL_SYSTEM_CURSOR_ARROW,
		IBeam = SDL_SYSTEM_CURSOR_IBEAM,
		Wait = SDL_SYSTEM_CURSOR_WAIT,
		Crosshair = SDL_SYSTEM_CURSOR_CROSSHAIR,
		WaitArrow = SDL_SYSTEM_CURSOR_WAITARROW,
		No = SDL_SYSTEM_CURSOR_NO,
		Hand = SDL_SYSTEM_CURSOR_HAND
	};

	static Input* Instance();

	char GetKeyUp() const;
	char GetKeyDown() const;
	KeyState GetKeyStates() const;

	bool IsXClicked() const;
	bool IsKeyPressed() const;
	bool IsWindowResized() const;

	bool IsLeftButtonClicked() const;
	bool IsRightButtonClicked() const;
	bool IsMiddleButtonClicked() const;

	const glm::ivec2& GetMouseWheel() const;
	const glm::ivec2& GetMouseMotion() const;
	const glm::ivec2& GetMousePosition() const;

	void SetCursorType(CursorType cursorType = CursorType::Arrow);
	void SetCursorState(CursorState cursorEnabled = CursorState::On,
		CursorState cursorVisible = CursorState::Show);

	void Update();

private:

	Input();
	Input(const Input&);
	Input& operator=(const Input&);

	char m_keyUp{ 0 };
	char m_keyDown{ 0 };

	bool m_isXClicked{ false };
	bool m_isKeyPressed{ false };
	bool m_isWindowResized{ false };

	KeyState m_keyStates{ nullptr };
	SDL_Cursor* m_cursor{ nullptr };

	glm::ivec2 m_mouseWheel{ 0 };
	glm::ivec2 m_mouseMotion{ 0 };
	glm::ivec2 m_mousePosition{ 0 };

	bool m_isLeftButtonClicked{ false };
	bool m_isRightButtonClicked{ false };
	bool m_isMiddleButtonClicked{ false };

};