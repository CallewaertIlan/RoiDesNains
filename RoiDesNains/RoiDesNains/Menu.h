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
	
	void newGame();
	void keysInfo();

private:
	int valueMenu;
};