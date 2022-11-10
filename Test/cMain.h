#pragma once
#include "pch.h"
#include "wx/wx.h"
#include <wx/statline.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//game logic class
struct GameLogic
{
public:
	string simple_Game = "SimpleGame", general_Game = "GeneralGame", CurrentGameMode;
	string Bplayer = "Blue", Rplayer = "Red", CurrentPlayer;
	const string s = "S";
	const string o = "O";
	bool GameDone = false;

	//Checks current player and then swaps to the next player to change turns
	void SetNextPlayer()
	{
		if (CurrentPlayer == Bplayer)
		{
			CurrentPlayer = Rplayer;
		}
		else
		{
			CurrentPlayer = Bplayer;
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

	bool PlayerWin()
	{
		return true;
	}

};

//user interface class
struct cMain : public wxFrame
{
public:
	cMain();
	~cMain();
private:
	int length = 0;
	//add components into window 
public:
	int length_int = 4;
	string length_string;
	wxStaticText* m_txt2 = nullptr;
	wxStaticLine* m_staticline1;
	wxTextCtrl* m_txt1 = nullptr;
	wxCheckBox* m_cbox1 = nullptr;
	wxRadioButton* m_radiobtn1, * m_radiobtn2, * m_radiobtn3, * m_radiobtn4, * m_radiobtn5, * m_radiobtn6 = nullptr;
	wxListBox* m_list1 = nullptr;
	wxButton* m_btn1 = nullptr;
	GameLogic object;


	//for SOS panel of button
	wxPanel* bgPanel = new wxPanel(this, wxID_ANY, wxPoint(170, 70), wxSize(200, 200));
	wxButton** btn = new wxButton * [length_int * length_int];
	wxGridSizer* buttonSizer = new wxGridSizer(length_int, length_int, 0, 0);								        // ( row, column, horz gap, vert gap )

	//declare event
	void BoardSize(wxCommandEvent& evt);
	void OnButtonClicked(wxCommandEvent& evt);
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
		object.CurrentPlayer = object.Bplayer;
		m_txt2 = new wxStaticText(this, wxID_ANY, "SOS", wxPoint(130, 21), wxSize(50, 50));
		m_txt2 = new wxStaticText(this, wxID_ANY, "Current turn:", wxPoint(220, 275), wxSize(100, 50));
		m_txt2 = new wxStaticText(this, wxID_ANY, object.CurrentPlayer + " Player", wxPoint(300, 275), wxSize(150, 50));
		m_txt2 = new wxStaticText(this, wxID_ANY, "Blue Player", wxPoint(10, 80), wxSize(100, 50));
		m_txt2 = new wxStaticText(this, wxID_ANY, "Red Player", wxPoint(470, 80), wxSize(100, 50));
		m_txt2 = new wxStaticText(this, wxID_ANY, "Board size", wxPoint(450, 22), wxSize(70, 50));
		m_txt1 = new wxTextCtrl(this, 1000, length_string, wxPoint(510, 19), wxSize(25, 25), wxTE_PROCESS_ENTER);
		m_radiobtn1 = new wxRadioButton(this, wxID_ANY, "Simple game", wxPoint(190, 5), wxSize(100, 50), wxRB_GROUP);
		m_radiobtn2 = new wxRadioButton(this, wxID_ANY, "General game", wxPoint(330, 5), wxSize(100, 50));
		m_radiobtn3 = new wxRadioButton(this, wxID_ANY, "S", wxPoint(30, 120), wxSize(35, 35), wxRB_GROUP);
		m_radiobtn4 = new wxRadioButton(this, wxID_ANY, "O", wxPoint(30, 150), wxSize(35, 35));
		m_radiobtn5 = new wxRadioButton(this, wxID_ANY, "S", wxPoint(490, 120), wxSize(35, 35), wxRB_GROUP);
		m_radiobtn6 = new wxRadioButton(this, wxID_ANY, "O", wxPoint(490, 150), wxSize(35, 35));
	}

	void InitializeTable(wxFont font, int lengthx)                                                                       //panel of button for SOS placement
	{

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


};

struct cMainn 
{
	int length_int = 4;
	string length_string;
};



