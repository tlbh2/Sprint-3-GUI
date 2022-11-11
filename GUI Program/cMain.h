#pragma once
#include "wx/wx.h"
#include <wx/statline.h>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

//game logic class
class GameLogic
{
private:
	string CurrentPlayer;
	string Bplayer_Label, Rplayer_Label;
	string CurrentGameMode;
	
public:
	int Bplayer_SOS_counter = 0, Rplayer_SOS_counter = 0;
	int total_buttons, already_fill_out = 0;
	string simple_Game = "SimpleGame", general_Game = "GeneralGame";
	string Bplayer = "Blue", Rplayer = "Red";
	const string s = "S";
	const string o = "O";
	bool GameDone = false;
	vector<vector<string>> Two_D_matrix;
	vector< pair <int, int>> Vector_of_Adjacent_elements;

	void Set_Bplayer_Label(string label)
	{
		Bplayer_Label = label;
	}

	string Get_Bplayer_Label()
	{
		return Bplayer_Label;
	}

	void Set_Rplayer_Label(string label)
	{
		Rplayer_Label = label;
	}

	string Get_Rplayer_Label()
	{
		return Rplayer_Label;
	}

	void SetCurrentPlayer(string input)
	{
		CurrentPlayer = input;
	}

	string GetCurrentPlayer()
	{
		return CurrentPlayer;
	}

	//Checks current player and then swaps to the next player to change turns
	void SetNextPlayer()
	{
		if (CurrentPlayer == Rplayer)
		{
			CurrentPlayer = Bplayer;
		}
		else
		{
			CurrentPlayer = Rplayer;
		}
	}

	void SetGameMode(string modeInput)
	{
		if (modeInput == simple_Game)
		{
			CurrentGameMode = simple_Game;
		}
		if (modeInput == general_Game)
		{
			CurrentGameMode = general_Game;
		}
	}

	string GetGameMode()
	{
		return CurrentGameMode;
	}

	bool PlayerWin()
	{
		return true;
	}

	bool isValidPos(int i, int j, int n, int m)
	{
		if (i < 0 || j < 0 || i > n - 1 || j > m - 1)
			return 0;
		return 1;
	}

	vector< pair <int, int>> getAdjacent(vector<vector<string> >& arr, int i, int j)
	{
		int n = arr.size();
		int m = arr[0].size();

		vector< pair <int, int>> v;
		pair<int, int> index;

		if (isValidPos(i - 1, j - 1, n, m))
		{
			index.first = i - 1;
			index.second = j - 1;
			v.push_back(index);
		}
		if (isValidPos(i - 1, j, n, m))
		{
			index.first = i - 1;
			index.second = j;
			v.push_back(index);
		}
		if (isValidPos(i - 1, j + 1, n, m))
		{
			index.first = i - 1;
			index.second = j + 1;
			v.push_back(index);
		}
		if (isValidPos(i, j - 1, n, m))
		{
			index.first = i;
			index.second = j - 1;
			v.push_back(index);
		}
		if (isValidPos(i, j + 1, n, m))
		{
			index.first = i;
			index.second = j + 1;
			v.push_back(index);
		}
		if (isValidPos(i + 1, j - 1, n, m))
		{
			index.first = i + 1;
			index.second = j - 1;
			v.push_back(index);
		}
		if (isValidPos(i + 1, j, n, m))
		{
			index.first = i + 1;
			index.second = j;
			v.push_back(index);
		}
		if (isValidPos(i + 1, j + 1, n, m))
		{
			index.first = i + 1;
			index.second = j + 1;
			v.push_back(index);
		}

		return v;
	}

	bool O_scenerio_checker(vector< pair <int, int>> Vector_of_Adjacent_elements)
	{
		switch (Vector_of_Adjacent_elements.size())
		{
		case 5:
			if (Two_D_matrix[Vector_of_Adjacent_elements[0].first][Vector_of_Adjacent_elements[0].second] == "S" && Two_D_matrix[Vector_of_Adjacent_elements[3].first][Vector_of_Adjacent_elements[3].second] == "S")
			{
				return true;
			}
			else if (Two_D_matrix[Vector_of_Adjacent_elements[0].first][Vector_of_Adjacent_elements[0].second] == "S" && Two_D_matrix[Vector_of_Adjacent_elements[1].first][Vector_of_Adjacent_elements[1].second] == "S")
			{
				return true;
			}
			else if (Two_D_matrix[Vector_of_Adjacent_elements[3].first][Vector_of_Adjacent_elements[3].second] == "S" && Two_D_matrix[Vector_of_Adjacent_elements[4].first][Vector_of_Adjacent_elements[4].second] == "S")
			{
				return true;
			}
			else if (Two_D_matrix[Vector_of_Adjacent_elements[1].first][Vector_of_Adjacent_elements[1].second] == "S" && Two_D_matrix[Vector_of_Adjacent_elements[4].first][Vector_of_Adjacent_elements[4].second] == "S")
			{
				return true;
			}
			break;

		case 8:
			if (Two_D_matrix[Vector_of_Adjacent_elements[0].first][Vector_of_Adjacent_elements[0].second] == "S" && Two_D_matrix[Vector_of_Adjacent_elements[7].first][Vector_of_Adjacent_elements[7].second] == "S")
			{
				return true;
			}
			else if (Two_D_matrix[Vector_of_Adjacent_elements[2].first][Vector_of_Adjacent_elements[2].second] == "S" && Two_D_matrix[Vector_of_Adjacent_elements[5].first][Vector_of_Adjacent_elements[5].second] == "S")
			{
				return true;
			}
			else if (Two_D_matrix[Vector_of_Adjacent_elements[1].first][Vector_of_Adjacent_elements[1].second] == "S" && Two_D_matrix[Vector_of_Adjacent_elements[6].first][Vector_of_Adjacent_elements[6].second] == "S")
			{
				return true;
			}
			else if (Two_D_matrix[Vector_of_Adjacent_elements[3].first][Vector_of_Adjacent_elements[3].second] == "S" && Two_D_matrix[Vector_of_Adjacent_elements[4].first][Vector_of_Adjacent_elements[4].second] == "S")
			{
				return true;
			}
			break;

		default:
			return false;
		}
	}

	bool S_scenerio_checker(vector<vector<string>> second_Two_D_matrix, int n, int m , int i, int j)    //in parameter (2d vector, height, width, index 1, index 2)
	{
		if (isValidPos(i + 1, j + 1, n, m) == 1 && isValidPos(i + 2, j + 2, n, m) == 1)
		{
			if (second_Two_D_matrix[i][j] == "S" && second_Two_D_matrix[i + 1][j + 1] == "O" && second_Two_D_matrix[i + 2][j + 2] == "S")
			{
				return true;
			}
		}
		if (isValidPos(i + 1, j, n, m) == 1 && isValidPos(i + 2, j, n, m) == 1)
		{
			if (second_Two_D_matrix[i][j] == "S" && second_Two_D_matrix[i + 1][j] == "O" && second_Two_D_matrix[i + 2][j] == "S")
			{
				return true;
			}
		}
		if (isValidPos(i + 1, j - 1, n, m) == 1 && isValidPos(i + 2, j - 2, n, m) == 1)
		{
			if (second_Two_D_matrix[i][j] == "S" && second_Two_D_matrix[i + 1][j - 1] == "O" && second_Two_D_matrix[i + 2][j - 2] == "S")
			{
				return true;
			}
		}
		if (isValidPos(i, j - 1, n, m) == 1 && isValidPos(i, j - 2, n, m) == 1)
		{
			if (second_Two_D_matrix[i][j] == "S" && second_Two_D_matrix[i][j - 1] == "O" && second_Two_D_matrix[i][j - 2] == "S")
			{
				return true;
			}
		}
		if (isValidPos(i - 1, j - 1, n, m) == 1 && isValidPos(i - 2, j - 2, n, m) == 1)
		{
			if (second_Two_D_matrix[i][j] == "S" && second_Two_D_matrix[i - 1][j - 1] == "O" && second_Two_D_matrix[i - 2][j - 2] == "S")
			{
				return true;
			}
		}
		if (isValidPos(i - 1, j, n, m) == 1 && isValidPos(i - 2, j, n, m) == 1)
		{
			if (second_Two_D_matrix[i][j] == "S" && second_Two_D_matrix[i - 1][j] == "O" && second_Two_D_matrix[i - 2][j] == "S")
			{
				return true;
			}
		}
		if (isValidPos(i - 1, j + 1, n, m) == 1 && isValidPos(i - 2, j + 2, n, m) == 1)
		{
			if (second_Two_D_matrix[i][j] == "S" && second_Two_D_matrix[i - 1][j + 1] == "O" && second_Two_D_matrix[i - 2][j + 2] == "S")
			{
				return true;
			}
		}
		if (isValidPos(i, j + 1, n, m) == 1 && isValidPos(i, j + 2, n, m) == 1)
		{
			if (second_Two_D_matrix[i][j] == "S" && second_Two_D_matrix[i][j + 1] == "O" && second_Two_D_matrix[i][j + 2] == "S")
			{
				return true;
			}
		}
	}
};

class UI : public wxFrame
{
	//put cMain class into this
	//create this class object in CMain as for GameLogic
	//might fix the restart
private:
	int length = 0;

	//add components into window 
public:
	int length_int = 0;
	string length_string;
	wxStaticText* m_txt2 = nullptr, * m_txt3 = nullptr;
	wxStaticLine* m_staticline1;
	wxTextCtrl* m_txt1 = nullptr;
	wxCheckBox* m_cbox1 = nullptr;
	wxRadioButton* m_radiobtn1, * m_radiobtn2, * m_radiobtn3, * m_radiobtn4, * m_radiobtn5, * m_radiobtn6 = nullptr;
	wxListBox* m_list1 = nullptr;
	//wxButton* m_btn1 = nullptr;
	wxButton* new_Game = nullptr;
	GameLogic* object = new GameLogic;
	bool is_that_an_SOS = false;

	wxButton** btn = new wxButton * [length_int * length_int];

	wxGridSizer* buttonSizer = new wxGridSizer(length_int, length_int, 0, 0);								        // ( row, column, horz gap, vert gap )

	//function
	void set_Length(int x)
	{
		length = x;
	}

	int get_Length()
	{
		return length;
	}

	//disable all button on table to prevent further input
	void Blank_out_Table(int lengthx)
	{
		for (int x = 0; x < lengthx; x++)
		{
			for (int y = 0; y < lengthx; y++)
			{
				btn[y * lengthx + x]->Enable(false);
			}
		}
	}

};

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
public:
	UI* UI_object = new UI;
	string previous_game_winner;

	//initialize SOS panel of button with pre-fix value - length_int - for panel size  
	wxPanel* bgPanel = new wxPanel(this, wxID_ANY, wxPoint(170, 70), wxSize(200, 200));

	//declare event
	void BoardSize(wxCommandEvent& evt);
	void OnButtonClicked(wxCommandEvent& evt);
	void Simple_game_Checked(wxCommandEvent& evt);
	void General_game_Checked(wxCommandEvent& evt);
	void Bplayer_S_Checked(wxCommandEvent& evt);
	void Bplayer_O_Checked(wxCommandEvent& evt);
	void Rplayer_S_Checked(wxCommandEvent& evt);
	void Rplayer_O_Checked(wxCommandEvent& evt);
	void Restart(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

	void InitializeTable(wxFont font, int lengthx)                                                                       //panel of button for SOS placement
	{
		//updating value for panel size n*n base on user input 
		UI_object->btn = new wxButton * [lengthx * lengthx];
		UI_object->buttonSizer = new wxGridSizer(lengthx, lengthx, 0, 0);								        // ( row, column, horz gap, vert gap )

		for (int x = 0; x < lengthx; x++)
		{
			for (int y = 0; y < lengthx; y++)
			{
				UI_object->btn[y * lengthx + x] = new wxButton(bgPanel, 10000 + (y * lengthx + x));                      //create new button and give it a unique id
				UI_object->btn[y * lengthx + x]->SetFont(font);                                                         //set font to that instance for better visual
				UI_object->buttonSizer->Add(UI_object->btn[y * lengthx + x], 1, wxEXPAND | wxALL);                                 //add button to wxGridSizer

				UI_object->btn[y * lengthx + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);     //bind event handler to button when clicked
			}

			bgPanel->SetSizer(UI_object->buttonSizer);
			bgPanel->Layout();
		}
	}

	void InitializeComponent()
	{
		UI_object->m_txt2 = new wxStaticText(this, wxID_ANY, "SOS", wxPoint(130, 21), wxSize(50, 50));
		UI_object->m_txt2 = new wxStaticText(this, wxID_ANY, "Current turn:", wxPoint(220, 275), wxSize(100, 50));
		UI_object->m_txt3 = new wxStaticText(this, wxID_ANY, UI_object->object->GetCurrentPlayer() + " Player", wxPoint(320, 275), wxSize(150, 50));
		UI_object->m_txt2 = new wxStaticText(this, wxID_ANY, "Blue Player", wxPoint(10, 80), wxSize(100, 50));
		UI_object->m_txt2 = new wxStaticText(this, wxID_ANY, "Red Player", wxPoint(470, 80), wxSize(100, 50));
		UI_object->m_txt2 = new wxStaticText(this, wxID_ANY, "Board size", wxPoint(450, 22), wxSize(70, 50));
		UI_object->m_txt1 = new wxTextCtrl(this, 1000, UI_object->length_string, wxPoint(510, 19), wxSize(25, 25), wxTE_PROCESS_ENTER);
		UI_object->m_radiobtn1 = new wxRadioButton(this, 1001, "Simple game", wxPoint(190, 5), wxSize(100, 50), wxRB_GROUP);
		UI_object->m_radiobtn2 = new wxRadioButton(this, 1002, "General game", wxPoint(330, 5), wxSize(100, 50));
		UI_object->m_radiobtn3 = new wxRadioButton(this, 1011, "S", wxPoint(30, 120), wxSize(35, 35), wxRB_GROUP);
		UI_object->m_radiobtn4 = new wxRadioButton(this, 1022, "O", wxPoint(30, 150), wxSize(35, 35));
		UI_object->m_radiobtn5 = new wxRadioButton(this, 1033, "S", wxPoint(490, 120), wxSize(35, 35), wxRB_GROUP);
		UI_object->m_radiobtn6 = new wxRadioButton(this, 1044, "O", wxPoint(490, 150), wxSize(35, 35));
		UI_object->new_Game = new wxButton(this, 2002, "New Game", wxPoint(470, 270), wxSize(70, 25));
	}
};

/*
//user interface class
class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
private:
	int length = 0;
	
	//add components into window 
public:
	int length_int;
	string length_string;
	wxStaticText* m_txt2 = nullptr, * m_txt3 = nullptr;
	wxStaticLine* m_staticline1;
	wxTextCtrl* m_txt1 = nullptr;
	wxCheckBox* m_cbox1 = nullptr;
	wxRadioButton* m_radiobtn1, * m_radiobtn2, * m_radiobtn3, * m_radiobtn4, * m_radiobtn5, * m_radiobtn6 = nullptr;
	wxListBox* m_list1 = nullptr;
	//wxButton* m_btn1 = nullptr;
	wxButton* new_Game = nullptr;
	GameLogic* object = new GameLogic;
	bool is_that_an_SOS = false;

	//initialize SOS panel of button with pre-fix value - length_int - for panel size  
	wxPanel* bgPanel = new wxPanel(this, wxID_ANY, wxPoint(170, 70), wxSize(200, 200));
	wxButton** btn = new wxButton * [length_int * length_int];
	
	wxGridSizer* buttonSizer = new wxGridSizer(length_int, length_int, 0, 0);								        // ( row, column, horz gap, vert gap )

	
	//declare event
	void BoardSize(wxCommandEvent& evt);
	void OnButtonClicked(wxCommandEvent& evt);
	void Simple_game_Checked(wxCommandEvent& evt);
	void General_game_Checked(wxCommandEvent& evt);
	void Bplayer_S_Checked(wxCommandEvent& evt);
	void Bplayer_O_Checked(wxCommandEvent& evt);
	void Rplayer_S_Checked(wxCommandEvent& evt);
	void Rplayer_O_Checked(wxCommandEvent& evt);
	void Restart(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

	//function
	void set_Length(int x)
	{
		length = x;
	}

	int get_Length()
	{
		return length;
	}

	void InitializeComponent()
	{
		m_txt2 = new wxStaticText(this, wxID_ANY, "SOS", wxPoint(130, 21), wxSize(50, 50));
		m_txt2 = new wxStaticText(this, wxID_ANY, "Current turn:", wxPoint(220, 275), wxSize(100, 50));
		m_txt3 = new wxStaticText(this, wxID_ANY, object->GetCurrentPlayer() + " Player", wxPoint(320, 275), wxSize(150, 50));
		m_txt2 = new wxStaticText(this, wxID_ANY, "Blue Player", wxPoint(10, 80), wxSize(100, 50));
		m_txt2 = new wxStaticText(this, wxID_ANY, "Red Player", wxPoint(470, 80), wxSize(100, 50));
		m_txt2 = new wxStaticText(this, wxID_ANY, "Board size", wxPoint(450, 22), wxSize(70, 50));
		m_txt1 = new wxTextCtrl(this, 1000, length_string, wxPoint(510, 19), wxSize(25, 25), wxTE_PROCESS_ENTER);
		m_radiobtn1 = new wxRadioButton(this, 1001, "Simple game", wxPoint(190, 5), wxSize(100, 50), wxRB_GROUP);
		m_radiobtn2 = new wxRadioButton(this, 1002, "General game", wxPoint(330, 5), wxSize(100, 50));
		m_radiobtn3 = new wxRadioButton(this, 1011, "S", wxPoint(30, 120), wxSize(35, 35), wxRB_GROUP);
		m_radiobtn4 = new wxRadioButton(this, 1022, "O", wxPoint(30, 150), wxSize(35, 35));
		m_radiobtn5 = new wxRadioButton(this, 1033, "S", wxPoint(490, 120), wxSize(35, 35), wxRB_GROUP);
		m_radiobtn6 = new wxRadioButton(this, 1044, "O", wxPoint(490, 150), wxSize(35, 35));
		new_Game = new wxButton(this, 2002, "New Game", wxPoint(470, 270), wxSize(70, 25));
	}

	void InitializeTable(wxFont font, int lengthx)                                                                       //panel of button for SOS placement
	{
		//updating value for panel size n*n base on user input 
		btn = new wxButton * [lengthx * lengthx];
		buttonSizer = new wxGridSizer(lengthx, lengthx, 0, 0);								        // ( row, column, horz gap, vert gap )

		for (int x = 0; x < lengthx; x++)
		{
			for (int y = 0; y < lengthx; y++)
			{
				btn[y * lengthx + x] = new wxButton(bgPanel, 10000 + (y * lengthx + x));                      //create new button and give it a unique id
				btn[y * lengthx + x]->SetFont(font);                                                         //set font to that instance for better visual
				buttonSizer->Add(btn[y * lengthx + x], 1, wxEXPAND | wxALL);                                 //add button to wxGridSizer

				btn[y * lengthx + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);     //bind event handler to button when clicked
			}

			bgPanel->SetSizer(buttonSizer);
			bgPanel->Layout();
		}
	}

	//disable all button on table to prevent further input
	void Blank_out_Table(int lengthx) 
	{
		for (int x = 0; x < lengthx; x++)
		{
			for (int y = 0; y < lengthx; y++)
			{
				btn[y * lengthx + x]->Enable(false);
			}
		}
	}
};
*/



