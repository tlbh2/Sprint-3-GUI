#include "pch.h"
#include "gtest/gtest.h"
#include "wx/wx.h"
#include "cMain.h"

//test fixture

struct GameLogicTest : testing::Test
{
	GameLogic* GameLogic_obj;

	GameLogicTest() //constructor
	{
		GameLogic_obj = new GameLogic;
	}

	~GameLogicTest() //destructor
	{
		delete GameLogic_obj;
	}
};


struct cMainTest : testing::Test
{
	cMainn* cMain_object;

	cMainTest() //constructor
	{
		cMain_object = new cMainn;
	}

	~cMainTest() //destructor
	{
		delete cMain_object;
	}
};

struct SimpleGameTest : testing::Test
{
	SimpleGame* SimpleGame_object;

	SimpleGameTest() //constructor
	{
		SimpleGame_object = new SimpleGame;
	}

	~SimpleGameTest() //destructor
	{
		delete SimpleGame_object;
	}
};

struct GeneralGameTest : testing::Test
{
	GeneralGame* GeneralGame_object;

	GeneralGameTest() //constructor
	{
		GeneralGame_object = new GeneralGame;
	}

	~GeneralGameTest() //destructor
	{
		delete GeneralGame_object;
	}
};


TEST_F(cMainTest, AC_1_1)
{
	int num = cMain_object->length_int;
	EXPECT_EQ(4, num);
}


TEST_F(GameLogicTest, AC_2_1)
{
	GameLogic_obj->SetGameMode(GameLogic_obj->simple_Game);
	bool tf = GameLogic_obj->PlayerWin();
	EXPECT_EQ(true, tf);
	EXPECT_EQ("SimpleGame", GameLogic_obj->GetGameMode());
}


TEST_F(GameLogicTest, AC_2_2)
{
	GameLogic_obj->SetGameMode(GameLogic_obj->general_Game);
	bool tf = GameLogic_obj->PlayerWin();
	EXPECT_EQ(true, tf);
	EXPECT_EQ("GeneralGame", GameLogic_obj->GetGameMode());
}

TEST_F(cMainTest, AC_3_1)
{
	cMain_object->length_int = 9;
	EXPECT_EQ(9, cMain_object->length_int);
}

TEST_F(GameLogicTest, AC_4_1)
{
	string move = GameLogic_obj->o;
	EXPECT_EQ("O", move);
}

TEST_F(SimpleGameTest, AC_5_1)
{
	vector < vector < string>> temp_2d_matrix = { {"S", " ", " "} ,
												  {" ", "O", " "} ,
												  {" ", " ", "S"} };

	int x = 0; int y = 0;
	bool is_that_an_SOS = SimpleGame_object->S_scenerio_checker(temp_2d_matrix, 3 , 3 , x , y);

	EXPECT_EQ(true, is_that_an_SOS);
}

TEST_F(GameLogicTest, AC_6_1)
{
	string move = GameLogic_obj->s;
	EXPECT_EQ("S", move);
}

TEST_F(GeneralGameTest, AC_7_1)
{
	int n = 3; //length of the SOS table

	GeneralGame_object->total_buttons = n * n;
	GeneralGame_object->already_fill_out = n * n;

	EXPECT_EQ(GeneralGame_object->total_buttons, GeneralGame_object->already_fill_out);
}
