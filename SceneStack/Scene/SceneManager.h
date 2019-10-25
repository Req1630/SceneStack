#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <stack>
#include <memory>

namespace stk
{
/****************************************************
*
*	シーン管理クラス : main などで使用.
*
*		クラス作成時、Push(sceneBase pScenebase)でシーンを追加.
*		もしくは、コンストラクタ使用.
*
**/
class CSceneBase;

class CSceneManager
{
	typedef std::shared_ptr<CSceneBase> sceneBase;

public:
	CSceneManager();
	CSceneManager( sceneBase& pScenebase )
	{
		if( pScenebase == nullptr ) return;
		m_pStackScene.push( pScenebase );
	}

	~CSceneManager();

	void Update(){ m_pStackScene.top()->Update(); }
	void Draw(){ m_pStackScene.top()->Draw(); }

	void Push( sceneBase& pScenebase )
	{
		if( pScenebase == nullptr ) return;
		m_pStackScene.push( pScenebase );
	}

	void Pop() { m_pStackScene.pop(); }

	void Change( sceneBase& pScenebase )
	{
		if( pScenebase == nullptr ) return;
		m_pStackScene.pop();
		m_pStackScene.push( pScenebase );
	}

	void StackRelease()
	{
		size_t st_size = m_pStackScene.size();
		for( size_t i = 0; i < st_size; i++ ) m_pStackScene.pop;
	}

private:
	std::stack<sceneBase> m_pStackScene;
};

};	// // namespace stk.

#endif // #ifndef SCENE_MANAGER_H.