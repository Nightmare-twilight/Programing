/******************************
*車避けるゲームを作ってみよう！
***********************************/

#include "DxLib.h"
#include "Scene/ScneManager.h"

//メイン関数（プログラムはここから始まります。）
int WINAPI WinMain(_In_HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_LPSTR lpCmdLine, _In_int nCmdShow)

{
	//例外処理（異常が発生したら、catch分に飛びます。）
	try
	{
		//シーンマネージャー機能の生成
		SceneManager manager;

		//シーンマネージャー機能の初期化処理
		manager.Initialize();

		//シーンマネージャー機能の更新処理
		manager.Update();

		//シーンマネージャー機能の終了処理
		manager.Finalize();

	}
	catch (const char* err_log)
	{
		//エラー発生内容の出力
		outputDebugstring(err_kog);

		//エラー終了を通知
		return -1;

	}

	//正常終了を通知
	return 0;
}