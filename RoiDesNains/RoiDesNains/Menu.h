#pragma once
class Menu
{
public:
	enum Stat
	{
		MENU = 0,
		CONTROLS,
	};
	Menu();
	~Menu();

	virtual void OnEnter(int oldState);
	bool OnUpdate();
	virtual void OnExecute();
	virtual void OnExit(int newState);

	void addValue(int add);
	
	void newGame();

private:
	int valueMenu;
	std::chrono::steady_clock::time_point keyPress;
	std::chrono::steady_clock::time_point newKeyPress;
	int m_menuState;
};