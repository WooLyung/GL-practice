#pragma once

enum KeyState
{
	ENTER, EXIT, STAY, NONE
};

class WInput
{
private:
	static bool keys[256];
	static KeyState keyState[256];

public:
	WInput();

	void update();

	void keyboard(unsigned char);
	void keyboardUp(unsigned char);

	static KeyState getKeyState(unsigned char);
};