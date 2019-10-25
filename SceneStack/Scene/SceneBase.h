#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include "SceneManager.h"

class stk::CSceneBase;

class sc : public stk::CSceneBase
{
public:
	virtual void Update(){}
	virtual void Draw(){}
};

namespace stk
{
/************************************************
*
*	�V�[�����N���X : 
*		�e�V�[���͂��̃N���X���p�����Ďg�p����.
*
**/
class CSceneBase
{
	typedef std::shared_ptr<CSceneManager> sceneManager;

public:
	CSceneBase( sceneManager sceneManager )
		: m_pSceneManager	( sceneManager )
	{}

	virtual ~CSceneBase(){}

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	CSceneBase(){}
	sceneManager m_pSceneManager;

};

};	// namespace stk.

#endif // #ifndef SCENE_BASE_H.