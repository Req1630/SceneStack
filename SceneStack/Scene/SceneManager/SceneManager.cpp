#include "SceneManager.h"

clsSceneManager::clsSceneManager()
{
}
clsSceneManager::~clsSceneManager()
{
}

void clsSceneManager::Update()
{
	m_pStackScene.top()->Updata();
}
void clsSceneManager::Draw()
{
	m_pStackScene.top()->Draw();
}
void clsSceneManager::Push( shared_ptr<clsSceneBase> pScenebase )
{
	if( pScenebase == nullptr ){
		return;
	}
	m_pStackScene.push( pScenebase );
}
void clsSceneManager::Pop()
{
	m_pStackScene.pop();
}
void clsSceneManager::Change( shared_ptr<clsSceneBase> pScenebase )
{
	clsSceneManager::Pop();
	clsSceneManager::Push( pScenebase );
}

void clsSceneManager::StackRelease()
{
	clsSceneManager::Pop();
}
