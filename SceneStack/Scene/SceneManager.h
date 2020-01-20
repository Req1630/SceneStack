#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "SceneBase.h"

namespace scene
{

/****************************************************
*
*	シーン管理クラス : main などで使用.
*
*		クラス作成時、Push(sceneBase pScenebase)でシーンを追加.
*		もしくは、コンストラクタ使用.
*
**/
class CSceneManager
{
	typedef std::shared_ptr<CSceneBase> sceneBase_s;
public:
	CSceneManager()
		: m_pStackScene ()
	{}

	CSceneManager( sceneBase_s pScenebase )
		: m_pStackScene ()
	{
		if( pScenebase == nullptr ) return;
		m_pStackScene.push( pScenebase );
	}

	~CSceneManager()
	{
		size_t st_size = m_pStackScene.size();
		for( size_t i = 0; i < st_size; i++ ) m_pStackScene.pop();
	}

	//---------------------------------------------.
	// スタックの一番上にあるシーンの更新・描画処理.

	// 更新処理.
	void Update(){ m_pStackScene.top()->Update(); }
	// 描画処理.
	void Render(){ m_pStackScene.top()->Render(); }

	// 引数に持ってきたシーンを上に積む.
	void Push( sceneBase_s pScenebase )
	{
		if( pScenebase == nullptr ) return;
		m_pStackScene.push( pScenebase );
	}
	// 現在の一番上のシーンを取り出す.
	void Pop()
	{
		if( m_pStackScene.empty() == true ) return;
		m_pStackScene.pop(); 
	}
	// 引数のシーンを現在の一番上のシーンを入れ替える.
	void Change( sceneBase_s pScenebase )
	{
		if( pScenebase == nullptr ) return;
		m_pStackScene.pop();
		m_pStackScene.push( pScenebase );
	}
	// 現在あるシーンのスタックを全部取り出す.
	void StackRelease()
	{
		size_t st_size = m_pStackScene.size();
		for( size_t i = 0; i < st_size; i++ ) m_pStackScene.pop();
	}

private:
	std::stack<sceneBase_s> m_pStackScene;
};

}	// namespace scene.

#endif // #ifndef SCENE_MANAGER_H.