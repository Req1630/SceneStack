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
	clsSceneManager();
	~clsSceneManager();

	void Update();
	void Draw();

	void Push( shared_ptr<clsSceneBase> pScenebase );
	void Pop();
	void Change( shared_ptr<clsSceneBase> pScenebase );

	void StackRelease();
	

private:
	stack<shared_ptr<clsSceneBase>> m_pStackScene;
};

#endif // #ifndef SCENE_MANAGER_H.