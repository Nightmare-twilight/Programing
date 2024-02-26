#pragma once

#include"SeneBase.h"
#include"../Object/RankingData.h"

class RankingDispScene : public SceneBase
{

private:
private:
	int backGround_image; //”wŒi‰æ‘œ
	RankingData* ranking;//ƒ‰ƒ“ƒLƒ“ƒOî•ñ
	
public:
	RankingDispScene();
	virtual ~RankingDispScene();

	virtual void Initialize() override;
	virtual eSceneType Upadete() override;
	virtual void Draw() override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};

