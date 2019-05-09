#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <stack>
#include <memory>

#include "..\SceneBase\SceneBase.h"

using namespace std;

class clsSceneBase;

class clsSceneManager
{
public:
	void Update();
	void Draw();

	void Push( clsSceneBase* pScenebase );
	void Change( clsSceneBase* pScenebase );
	void Pop();

private:
	stack<shared_ptr<clsSceneBase>> m_pScene;
};

#endif // #ifndef SCENE_MANAGER_H.