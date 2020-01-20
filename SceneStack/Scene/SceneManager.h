#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "SceneBase.h"

namespace scene
{

/****************************************************
*
*	�V�[���Ǘ��N���X : main �ȂǂŎg�p.
*
*		�N���X�쐬���APush(sceneBase pScenebase)�ŃV�[����ǉ�.
*		�������́A�R���X�g���N�^�g�p.
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
	// �X�^�b�N�̈�ԏ�ɂ���V�[���̍X�V�E�`�揈��.

	// �X�V����.
	void Update(){ m_pStackScene.top()->Update(); }
	// �`�揈��.
	void Render(){ m_pStackScene.top()->Render(); }

	// �����Ɏ����Ă����V�[������ɐς�.
	void Push( sceneBase_s pScenebase )
	{
		if( pScenebase == nullptr ) return;
		m_pStackScene.push( pScenebase );
	}
	// ���݂̈�ԏ�̃V�[�������o��.
	void Pop()
	{
		if( m_pStackScene.empty() == true ) return;
		m_pStackScene.pop(); 
	}
	// �����̃V�[�������݂̈�ԏ�̃V�[�������ւ���.
	void Change( sceneBase_s pScenebase )
	{
		if( pScenebase == nullptr ) return;
		m_pStackScene.pop();
		m_pStackScene.push( pScenebase );
	}
	// ���݂���V�[���̃X�^�b�N��S�����o��.
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