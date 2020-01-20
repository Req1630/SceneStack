#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include <stack>
#include <memory>

namespace scene
{

class CSceneManager;

/************************************************
*
*	シーン基底クラス : 
*		各シーンはこのクラスを継承して使用する.
*
**/

class CSceneBase
{
public:
	typedef std::shared_ptr<CSceneManager> sceneManager_s;
public:
	CSceneBase( sceneManager_s sceneManager )
		: m_pSceneManager	( sceneManager )
	{}

	virtual ~CSceneBase(){}

	// 更新処理.
	virtual void Update() = 0;
	// 描画処理.
	virtual void Render() = 0;

protected:
	CSceneBase()
		: m_pSceneManager	( nullptr )
	{}
	sceneManager_s m_pSceneManager;
};

}	// namespace scene.

#endif // #ifndef SCENE_BASE_H.