#pragma once
#include "../Utility/Vector2D.h"


class Barrier
{
private:
	int image;
	@@ - 13, 4 + 13, 4 @@ Class Barrier

		void Draw(const Vector2D & location);
	bool IsFinished(float speed);
}
};