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

	Controls GetControler() { return m_controler; };

private:
	Controls m_controler;

	int valueMenu;
};