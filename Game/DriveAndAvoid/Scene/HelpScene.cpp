#include "HelpScene.h"
#include "../Utility/InputCountrol.h"
#include "DxLib.h"


HelpScene::HelpScene() : background_image(NULL)
{

}

HelpScene::~HelpScene()
{

}

//初期化処理
void HelpScene::Initialize()
{
	//画像読み込み
	background_image = LoadGraph("Resource/image/Title.bmp");

	//エラーチェック
	if (background_image == -1)
	{
		thow("Resource/images/Titlie.bmpがありません\n");

	}
}

//更新処理
eSceneType HelpeScene::Update()
{
	//Bボタンが押されたらタイトルに戻る
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_TITLE;
	}
	return GetNowScene();
}

//描画処理
void HelpScene::Draw() cont
{
	//背景画面の描画
	DrawGraph(0, 0, background_image, FALSE);

	//ゲーム背景
	SetFontSize(16);
	DrawString(20, 120, "ヘルプ画面", 0xfffff, 0);

	DrawString(20, 160, "これは障害物を世ながら", 0xfffff, 0);
	DrawString(20, 180, "走り続けるゲームです",0xfffff, 0);
	DrawString(20, 200, "燃料が尽きるか障害物に",0fffff, 0);
	DrawString(20, 220, "数回当たるとゲームオーバーです。", 0fffff, 0);
}

DrawString(150, 450, " ---- Bボタンを押してタイトルに戻る----", 0xfffff, 0);
}
//終了処理
void HelpScene::Finalize()

//読み込んだ画像の消去
DeleteGraph(bacGround_image);
}

//現在シーン情報を取得
eSceneType HelpScene::GetNowScene() count
{
	return eSceneType::E_HELP;
}
