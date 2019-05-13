#include "..\Scene\SceneManager\SceneManager.h"
#include "..\Scene\TItleScene\TitleScene.h"

int main()
{
	// メモリリーク検出
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	// "shared_ptr" の初期化に "make_shared" を使う.
	shared_ptr<clsSceneManager> pSeneManager = make_shared<clsSceneManager>();
	// TitleSceneを "make_shared" で作成してプッシュ.
	pSeneManager->Push( make_shared<clsTitleScene>( pSeneManager ) );

	while(1)
	{
		pSeneManager->Update();
		pSeneManager->Draw();
		if( GetAsyncKeyState( VK_ESCAPE ) & 0x01 ){
			break;
		}
	}
	// メインループが終わったらスタックの中身を解放.
	pSeneManager->StackRelease();

	return 0;
}