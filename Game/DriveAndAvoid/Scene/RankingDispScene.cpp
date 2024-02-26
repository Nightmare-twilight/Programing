#include "RankingDispScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

RankingDispScene::RankingDispScene() : background_image(NULL), ranking(nullptr)
{

}
RankingDispScene::~RankingDispScene()
{

}
//画像の読み込み
background_image = LoadGraph("Resource/images/Ranking.bmp");

//エラーチェック

if(background_image == -1)
{
	throw("Resource/images/Ranking.bmpがありません\n");

}
//ランキング情報を取得
ranking = new RankingData;
ranking->Initialize();
}

//更新処理
eSceneType RankingDispScene::Update()
{
	//Bボタンが推されたら、タイトルに戻どる
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneTyoe::E_TITLE;
	}
	//描画処理
	void RankingDispScene::Draw() const
	{
		//背景画像の描画
		DrawGraoh(0, 0, bacground_image, FALSE);

		//取得したランキングデータを描画する
		for (int i = 0; i < 5; i++)

		{
			DrawFormatString(50, 170 + i * 25, 0fffff, "%2d %-15s %6d",
				ranking->GetRank(i), ranking->GetName(i), ranking->GetScore(i));
		}
	}

	//終了時処理
	void RankingDipScene::Finalize()
	{
		//読んだ画像の消去
		DeleteGraph(bacground_image);

		//動的メモリの開放
		ranking->Finalize();
		delete ranking;
	}
	//現在のシーン情報を取得
	cSceneType RankingDispScene::GetNowScene() const
	{
		return eSceneType::E_RANKING_DISP;
	}