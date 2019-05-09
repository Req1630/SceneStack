#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include "..\..\Console\Console.h"
#include "..\SceneManager\SceneManager.h"

class clsSceneManager;

static clsConsole g_clsConsole;

class clsSceneBase
{
public:
	clsSceneBase( clsSceneManager& sceneManager );
	virtual ~clsSceneBase(){};

	virtual void Updata() = 0;
	virtual void Draw() = 0;

protected:
	clsSceneManager& m_SceneManager;
};

#endif // #ifndef SCENE_BASE_H.