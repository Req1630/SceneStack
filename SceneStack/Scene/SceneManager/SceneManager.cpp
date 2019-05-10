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
void clsSceneManager::Push( clsSceneBase* pScenebase )
{
	m_pStackScene.emplace( pScenebase );
}
void clsSceneManager::Pop()
{
	m_pStackScene.pop();
}
void clsSceneManager::Change( clsSceneBase* pScenebase )
{
	clsSceneManager::Pop();
	clsSceneManager::Push( pScenebase );
}