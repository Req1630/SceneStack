#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include "..\..\Console\Console.h"
#include "..\SceneManager\SceneManager.h"

class clsSceneManager;

class clsSceneBase
{
public:
	clsSceneBase( shared_ptr<clsSceneManager> sceneManager );
	virtual ~clsSceneBase(){};

	virtual void Updata() = 0;
	virtual void Draw() = 0;

protected:
	shared_ptr<clsSceneManager> m_pSceneManager;
};

#endif // #ifndef SCENE_BASE_H.