#include "stdafx.h"
#include "SimpleGameModel.h"


SimpleGameModel::SimpleGameModel()
{
}

SimpleGameModel::SimpleGameModel(shared_ptr<GraphicsEngine> graphics_engine)
{
	random_map_seed_ = 106328;
	Init(graphics_engine);
}


SimpleGameModel::~SimpleGameModel()
{
}

void SimpleGameModel::Init(shared_ptr<GraphicsEngine> graphics_engine)
{
	int cannons_count = 5;
	int guardians_count = 7;

	graphics_engine_ = graphics_engine;
	grid_ = make_shared<SimpleGrid>(graphics_engine_, random_map_seed_);
	GameSystem::GetInstance()->AddGrid(grid_);
	int2 player_start(0, grid_->GetDim().y - 1);
	finish_point_ = int2(grid_->GetDim().x - 1, 0);
	grid_->SetFinishPoint(finish_point_);
	grid_->SetBlockMask(player_start, false);
	grid_->SetBlockMask(finish_point_, false);
	player_ = make_shared<PlayerCharacter>(graphics_engine_, grid_, player_start);
	GameSystem::GetInstance()->AddGridActor(player_);
	shared_ptr<GridActor> actor;

	mt19937 gen;
	gen.seed(random_map_seed_);
	uniform_int_distribution<int> dist_x(0, grid_->GetDim().x - 1);
	uniform_int_distribution<int> dist_y(0, grid_->GetDim().y - 1);
	uniform_int_distribution<int> dist_dir(-1, 1);
	int2 dir(0,0);
	int2 pos;
	int max_iter = 1000;
	int k = 0;
	for (int i = 0; i < max_iter; i++)
	{
		pos.x = dist_x(gen);
		pos.y = dist_y(gen);
		if (pos != player_start && pos != finish_point_ && !grid_->CheckBlockMask(pos) && !grid_->CheckEmployMask(pos))
		{
			dir = int2(0, 0);
			dir.x = dist_dir(gen);
			if (dir.x == 0)
			{
				dir.y = dist_dir(gen);
				if (dir.y == 0)
				{
					dir.x = 1;
				}
			}
			int2 tmp = pos + dir;
			if (tmp.x == -1)
			{
				dir.x = 1;
			}
			else if (tmp.x == grid_->GetDim().x)
			{
				dir.x = -1;
			}
			else if (tmp.y == -1)
			{
				dir.y = 1;
			}
			else if (tmp.y == grid_->GetDim().y)
			{
				dir.y = -1;
			}
			if (grid_->CheckEmployMask(pos + dir))
			{
				continue;
			}
			actor = make_shared<Guardian>(graphics_engine_, grid_, pos, dir);
			GameSystem::GetInstance()->AddGridActor(actor);
			grid_->SetEmployMask(pos, true);
			k++;
			if (k >= guardians_count)
			{
				break;
			}
		}
	}
	k = 0;
	for (int i = 0; i < max_iter; i++)
	{
		pos = int2(0, 0);
		pos.x = dist_dir(gen);
		if (pos.x == 0)
		{
			pos.y = dist_dir(gen);
			if (pos.y == 0)
			{
				//pos.x = -1;
				continue;
			}
			else
			{
				if (pos.y == 1)
				{
					pos.y = grid_->GetDim().y;
				}
				pos.x = dist_x(gen);
			}
		}
		else
		{
			if (pos.x == 1)
			{
				pos.x = grid_->GetDim().x;
			}
			pos.y = dist_y(gen);
		}
		if (!grid_->CheckEmployMask(pos))
		{
			actor = make_shared<SimpleCannon>(graphics_engine_, grid_, pos);
			GameSystem::GetInstance()->AddGridActor(actor);
			grid_->SetEmployMask(pos, true);
			k++;
			if (k >= cannons_count)
			{
				break;
			}
		}
	}

	//actor = make_shared<SimpleCannon>(graphics_engine_, grid_, int2(4, -1));
	/*
	while (k < guardians_count)
	{

	}
	for (int i = 0; i < size; i++)
	{
		if (dist(gen))
		{
			//SetBlockMask(i, true);
			block_mask_.Set(i, true);
		}
	}
	//uniform_int_distribution<int> sprite_dist(0, sprite_sheet_component_->);
	if (sprite_sheet_component_)
	{
		uniform_int_distribution<int> sprite_dist(0, sprite_sheet_component_->GetTilesCount() - 1);
		generate(cells_map_.begin(), cells_map_.end(), [&sprite_dist, &gen]() { return sprite_dist(gen); });
	}
	///
	actor = make_shared<Guardian>(graphics_engine_, grid_, int2(0, 0), int2(1, 0));
	GameSystem::GetInstance()->AddGridActor(actor);
	actor = make_shared<Guardian>(graphics_engine_, grid_, int2(1, 1), int2(0, -1));
	GameSystem::GetInstance()->AddGridActor(actor);

	actor = make_shared<SimpleCannon>(graphics_engine_, grid_, int2(-1, 6));
	GameSystem::GetInstance()->AddGridActor(actor);
	actor = make_shared<SimpleCannon>(graphics_engine_, grid_, int2(grid_->GetDim().x, 3));
	GameSystem::GetInstance()->AddGridActor(actor);
	actor = make_shared<SimpleCannon>(graphics_engine_, grid_, int2(4, -1));
	GameSystem::GetInstance()->AddGridActor(actor);
	actor = make_shared<SimpleCannon>(graphics_engine_, grid_, int2(5, grid_->GetDim().y));
	GameSystem::GetInstance()->AddGridActor(actor);
	*/
	//player_->MoveTo(int2(8, 5));
}

void SimpleGameModel::Update()
{
	grid_->ClearKillzoneMask();
	GameModel::Update();
	if (!game_over_)
	{
		if (player_->IsActive() && grid_->CheckKillzoneMask(player_->GetGridCellLocation()))
		{
			player_->Destroy();
			string game_over_image_path = "Content/Game_over.png";
			shared_ptr<DrawableObject> lose_screen = make_shared<DrawableObject>(graphics_engine_, game_over_image_path);
			lose_screen->CenterOrigin();
			GameSystem::GetInstance()->AddScreenElement(lose_screen);
			game_over_ = true;
		}
		if (player_->GetGridCellLocation() == finish_point_)
		{
			string game_over_image_path = "Content/Victory.png";
			shared_ptr<DrawableObject> victory_screen = make_shared<DrawableObject>(graphics_engine_, game_over_image_path);
			victory_screen->CenterOrigin();
			GameSystem::GetInstance()->AddScreenElement(victory_screen);
			game_over_ = true;
		}
	}
}

void SimpleGameModel::Render(shared_ptr<Screen> screen)
{
	/*
	screen->Clear();
	grid_->Draw(screen);
	actor_->Draw(screen);
	player_->Draw(screen);
	//cout << "Actor: " << actor_->GetScreenLocation().x << " " << actor_->GetScreenLocation().y << endl;
	screen->Present();
	*/
	GameSystem::GetInstance()->Render(screen);
}

/*
void SimpleGameModel::Restart()
{
	GameModel::Restart();
	Init(graphics_engine_);
}
*/
