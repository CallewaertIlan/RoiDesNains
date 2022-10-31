#pragma once

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

	bool Fire() { return m_fire; }
	bool Up() { return m_up; }
	bool Down() { return m_down; }
	bool Left() { return m_left; }
	bool Right() { return m_right; }
	bool invincible() { return m_invincible == DOWN; }

	void OnUpdate();

public:

protected:
	int m_back;
	int m_start;
	int m_invincible;

	bool m_fire;
	bool m_up;
	bool m_down;
	bool m_left;
	bool m_right;
};