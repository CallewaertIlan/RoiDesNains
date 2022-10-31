#pragma once

class Controls
{
public:
	enum
	{
		NONE,
		DOWN,
		UP,
		PUSH,
	};

public:
	Controls();
	virtual ~Controls();

	void Reset();
	int GetKey(int key, bool press);

	bool Back() { return m_back == DOWN; }
	bool Start() { return m_start == DOWN; }
	bool menuUp() { return m_menu_up == DOWN; }
	bool menuDown() { return m_menu_down == DOWN; }

	bool Up() { return m_jump; }
	bool Down() { return m_down; }
	bool Left() { return m_left; }
	bool Right() { return m_right; }

	void OnUpdate();

public:

protected:
	int m_back;
	int m_start;

	int m_menu_up;
	int m_menu_down;

	bool m_jump;
	bool m_down;
	bool m_left;
	bool m_right;
};