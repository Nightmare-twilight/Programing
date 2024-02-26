#include "RanlingInputScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

RankingInputScene::RankingInputScene() : background_image(NULL),
ranking(nullptr), score(0),

name_num(0), cursor_x(0),
cursor_y(0)
{
	memset(name, NULL, (sizeof(char) * 15));
}
RankingInputScene::~RankinggInputScene()
{

}

//初期化処理
void RankingInputScebe::Initialize()
{
	//画像読み込み
	background_image = LoadGraph("Resource/images/Ranking.bmp");

	//エラーチェック
	if (background_image == -1)
	{
		throw ("Resource/image/Ranking.bmpがありません\n");

	}
	//メモリの動的確保
	rankinf = new RankingData;
	ranking->Initialize();

	//リザルトデータを取得する
	FILE* fp = nullptr;
	//ファイルオープン
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "r");
	//エラーチェック
	if (resulut != 0)
	{
		throw ("Resource/dat/resulut_data_.csvが読めません\n")
	}
	//結界を読み込み
	fsclose(fp);

	//ファイルクローズ
	fclose(fp);
}

//更新処理
eSceneType RankingIngInputScene::Updare()
{
	bool is_change = false;
	//名前の入力処理
	is_change = InputName();
	//シーン変更は可能か？
	if (is_change)
	{
		//ランキング表示に　移

		return eSceneType::E_RANKING_DISP;

	}
	else
	{
		return GetNowScene();
	}
}
//描画処理
void RankingIngInputScene::Draw() cont
{
	//背景画像の描画
	DrawGraph(0, 0, bckground_image, TRUE);
	//名前入力指示文字れるの描画

	DrawString(150, 100, "ランキングに登場します", ">%s", name);
	DrawFormatString(100, 200, GetColor(255, 255, 255), ">%s", name);

	//選択用文字を描画
	const int font_size = 25;
	for (int i = 0; i < 26; i++)
	{
		int x = (i % 13) * font_size + 15;
		int y = (i / 13) * font_size + 300;
		DrawString(x, y, GetColor(255, 255, 255), "%-3c", 'a' + i);
		y = ((i / 13) + 2) * font_size + 300;
		DrawFormatString(x, y, GetColor(255, 255, 255));
		DrawString(40 + font_size * 2, 405, "消す", GetColor(255, 255, 255));

		//選択文字をフォーカスする
		if (cursor_y < 4)
		{
			int x = cursor_x * font_size + 10;
			int y = cursor_y * font_size + 295;
			DrawBox(x, y, x + font_size, y + font_size, Getcolor(255, 255, 255), FALSE);
		}
		else
		{
			if (cursor_x == 0)
			{
				DrawBox(35, 400, 35 + font_size * 2, 400 + font_size,
					GetContlor(255, 255, 255), FALSE);
			}
			else 
			{
				DrawBox(0, 0, font_size, GetColor(255, 255, 255),
					FALSE);

		}
	}
}
	//終了処理
	void RankingInputScene :: FInalize()
	{
		//ランキングにデータを格納
		ranking->setRankingData(score, name);

		//読み込んだ画像を消去

		DeleteGraph(background_image);

		//動的メモリの解放
		delete ranking;

		//現在のシーン情報を取得
		eSceneType RankingInoutScene::GetNowScene() const
		{
			return eSceneType::E_RANKING_INPUT;
		}
		//名前入力処理
		bool RankingInoutScene::InoutName()
		{
			//カーソル操作処理
			if (InoutControl::GetButtonDown(XINPUT_BUTTON_DPAD_LEFT))
			{
				if (cursor_x > 0)
				{
					cursor_x--;
				}
				else
				{
					cursor_x = 12;
				}
			}if (InoutControl::GetButtonDown(XINPUT_BUTTON_DPAD_RIGHT))
			{
				if (cursor_x < 12)
				{
					cursor_x++;
				}
				else
				{
					cursor_x = 0;
				}
			}
			if (InputControl::GetButtonDaown(XINPUT_BUTTON_DPAD_UP))
			{
				if (cursor_y > 0)
				{
					cursor_y--;
				}
			}
			if (InputControl::GetButtonDown(XIPUT_BUTTON_DPAD_DOWN))
			{
				if (cursor_y < 4)
				{
					cursor_y++;
					if (cursor_ == 4)
					{
						cursor_x = 0;
					}
				}
			}
			//カーソル位置の文字を決定する
			if (IputControl::GetButtonDown(XINPUT_BUTTON_B))
			{
				if (cursor_y < 2)
				{
					name[name_num++] = 'a' + cursor_x + (cursor_y * 13);
					if (name(_num == 14))
					{
						cursor__x = 0;
						cursor_y = 4;
					}
				}
				else if (cursor_y < 4)
				{
					name[name_num++] = 'A' + cursor_x + ((cursor_y - 2) * 13);
					if
					{
