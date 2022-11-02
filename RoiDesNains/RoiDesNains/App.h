#pragma once
class App
{
public:
	App();
	~App();

	Controls* GetController() { return &m_controls; };

protected:

	Controls m_controls;
};

