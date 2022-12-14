#pragma once

#define WINSIZE_X												1600
#define WINSIZE_Y												900
#define SIZE_X_SPRITE_PLAYER									53.0f
#define SIZE_Y_SPRITE_PLAYER									53.0f
#define SIZE_X_SPRITE_CUBE										32.0f
#define SIZE_Y_SPRITE_CUBE										18.0f

using namespace std;


#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <vector>
#include <chrono>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Animations.h"
#include "Entity.h"
#include "Player.h"
#include "Menu.h"
#include "Game.h"