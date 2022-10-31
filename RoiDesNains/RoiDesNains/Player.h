#pragma once
class Player
{
public:
	Player();
	virtual ~Player();

	virtual void OnEnter(int oldState);
	virtual void OnExecute();
	virtual void OnExit(int newState);
	virtual void OnUpdate();

private:
	
};
