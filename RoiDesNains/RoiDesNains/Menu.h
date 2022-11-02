#pragma once
class Menu
{
public:
	Menu();
	~Menu();

	virtual void OnEnter(int oldState);
	virtual void OnUpdate();
	virtual void OnExecute();
	virtual void OnExit(int newState);

	void addValue(int add);

	Controls* GetController() { return &m_controls; };
	
	void newGame();
	void keysInfo();

private:
	int valueMenu;
	std::chrono::steady_clock::time_point keyPress;
	std::chrono::steady_clock::time_point newKeyPress;

	Controls m_controls;
};