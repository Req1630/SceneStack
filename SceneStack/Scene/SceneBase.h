#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include <stack>
#include <memory>

namespace scene
{

class CSceneManager;

/************************************************
*
*	�V�[�����N���X : 
*		�e�V�[���͂��̃N���X���p�����Ďg�p����.
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

	// �X�V����.
	virtual void Update() = 0;
	// �`�揈��.
	virtual void Render() = 0;

protected:
	CSceneBase()
		: m_pSceneManager	( nullptr )
	{}
	sceneManager_s m_pSceneManager;
};

}	// namespace scene.

#endif // #ifndef SCENE_BASE_H.