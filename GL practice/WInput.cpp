#include "WInput.h"

bool WInput::keys[256];
KeyState WInput::keyState[256];

WInput::WInput()
{
	for (int i = 0; i < 256; i++)
	{
		keys[i] = false;
		keyState[i] = KeyState::NONE;
	}
}

void WInput::update()
{
	for (int i = 0; i < 256; i++)
	{
		if (keys[i])
		{
			if (keyState[i] == KeyState::NONE || keyState[i] == KeyState::EXIT)
				keyState[i] = KeyState::ENTER;
			else if (keyState[i] == KeyState::ENTER)
				keyState[i] = KeyState::STAY;
		}
		else
		{
			if (keyState[i] == KeyState::ENTER || keyState[i] == KeyState::STAY)
				keyState[i] = KeyState::EXIT;
			else if (keyState[i] == KeyState::EXIT)
				keyState[i] = KeyState::NONE;
		}
	}
}

void WInput::keyboard(unsigned char key)
{
	keys[key] = true;
}

void WInput::keyboardUp(unsigned char key)
{
	keys[key] = false;
}

KeyState WInput::getKeyState(unsigned char key)
{
	return keyState[key];
}