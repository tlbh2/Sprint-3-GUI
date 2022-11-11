#include "cMain.h"
//this is about the window

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

EVT_BUTTON(2002, cMain::Restart)
EVT_TEXT_ENTER(1000, cMain::BoardSize)
EVT_RADIOBUTTON(1001, cMain::Simple_game_Checked)
EVT_RADIOBUTTON(1002, cMain::General_game_Checked)
EVT_RADIOBUTTON(1011, cMain::Bplayer_S_Checked)
EVT_RADIOBUTTON(1022, cMain::Bplayer_O_Checked)
EVT_RADIOBUTTON(1033, cMain::Rplayer_S_Checked)
EVT_RADIOBUTTON(1044, cMain::Rplayer_O_Checked)

wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "SOS Game", wxPoint(40, 40), wxSize(600, 350))
{
	UI_object->object->SetCurrentPlayer(UI_object->object->Bplayer);
	previous_game_winner = UI_object->object->Bplayer;
	InitializeComponent();
}

cMain::~cMain()
{
	//prevent memory leak
	delete[]UI_object->btn;
}

//Event function definition

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	//Get coordinate of button in field array
	int x = (evt.GetId() - 10000) % UI_object->get_Length();
	int y = (evt.GetId() - 10000) / UI_object->get_Length();
	string temp_Label;

	if (UI_object->object->GetGameMode() == "SimpleGame")
	{
		if (UI_object->object->GetCurrentPlayer() == UI_object->object->Bplayer)
		{
			//set label to button once pressed
			UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->object->Get_Bplayer_Label());
			UI_object->object->already_fill_out++;
			//put that label to two dimentional vector
			UI_object->object->Two_D_matrix[x][y] = UI_object->object->Get_Bplayer_Label();
			
			temp_Label = UI_object->object->Get_Bplayer_Label();
			if (temp_Label == "O")
			{
				UI_object->object->Vector_of_Adjacent_elements = UI_object->object->getAdjacent(UI_object->object->Two_D_matrix, x, y);

				UI_object->is_that_an_SOS = UI_object->object->O_scenerio_checker(UI_object->object->Vector_of_Adjacent_elements);
				if (UI_object->is_that_an_SOS == true)
				{
					wxMessageBox("The winner is " + UI_object->object->GetCurrentPlayer() + " !!!- Game Over");
					UI_object->is_that_an_SOS = false;
					previous_game_winner = UI_object->object->Bplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
			}
			else
			{
				UI_object->is_that_an_SOS = UI_object->object->S_scenerio_checker(UI_object->object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
				if (UI_object->is_that_an_SOS == true)
				{
					wxMessageBox("The winner is " + UI_object->object->GetCurrentPlayer() + " !!!- Game Over");
					UI_object->is_that_an_SOS = false;
					previous_game_winner = UI_object->object->Bplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
			}		
		}
		if (UI_object->object->GetCurrentPlayer() == UI_object->object->Rplayer)
		{
			//set label to button once pressed
			UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->object->Get_Rplayer_Label());
			UI_object->object->already_fill_out++;
			//put that label to two dimentional vector
			UI_object->object->Two_D_matrix[x][y] = UI_object->object->Get_Rplayer_Label();
			
			temp_Label = UI_object->object->Get_Rplayer_Label();
			if (temp_Label == "O")
			{
				UI_object->object->Vector_of_Adjacent_elements = UI_object->object->getAdjacent(UI_object->object->Two_D_matrix, x, y);

				UI_object->is_that_an_SOS = UI_object->object->O_scenerio_checker(UI_object->object->Vector_of_Adjacent_elements);
				if (UI_object->is_that_an_SOS == true)
				{
					wxMessageBox("The winner is " + UI_object->object->GetCurrentPlayer() + " !!!- Game Over");
					UI_object->is_that_an_SOS = false;
					previous_game_winner = UI_object->object->Rplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
			}
			else
			{
				UI_object->is_that_an_SOS = UI_object->object->S_scenerio_checker(UI_object->object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
				if (UI_object->is_that_an_SOS == true)
				{
					wxMessageBox("The winner is " + UI_object->object->GetCurrentPlayer() + " !!!- Game Over");
					UI_object->is_that_an_SOS = false;
					previous_game_winner = UI_object->object->Rplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
			}
		}
		if (UI_object->object->already_fill_out == UI_object->object->total_buttons)
		{
			wxMessageBox("Unbelievable ! It is a draw - Game Over");
			//disable all button for futher input
			UI_object->Blank_out_Table(UI_object->get_Length());
		}
	}
	if (UI_object->object->GetGameMode() == "GeneralGame")
	{
		
		if (UI_object->object->already_fill_out != UI_object->object->total_buttons)
		{
			if (UI_object->object->GetCurrentPlayer() == UI_object->object->Bplayer)
			{
				//set label to button once pressed
				UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->object->Get_Bplayer_Label());
				UI_object->object->already_fill_out++;
				//put that label to two dimentional vector
				UI_object->object->Two_D_matrix[x][y] = UI_object->object->Get_Bplayer_Label();

				temp_Label = UI_object->object->Get_Bplayer_Label();
				if (temp_Label == "O")
				{
					UI_object->object->Vector_of_Adjacent_elements = UI_object->object->getAdjacent(UI_object->object->Two_D_matrix, x, y);

					UI_object->is_that_an_SOS = UI_object->object->O_scenerio_checker(UI_object->object->Vector_of_Adjacent_elements);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->object->Bplayer_SOS_counter++;
					}
				}
				else
				{
					UI_object->is_that_an_SOS = UI_object->object->S_scenerio_checker(UI_object->object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->object->Bplayer_SOS_counter++;
					}
				}
			}
			if (UI_object->object->GetCurrentPlayer() == UI_object->object->Rplayer)
			{
				//set label to button once pressed
				UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->object->Get_Rplayer_Label());
				UI_object->object->already_fill_out++;
				//put that label to two dimentional vector
				UI_object->object->Two_D_matrix[x][y] = UI_object->object->Get_Rplayer_Label();

				temp_Label = UI_object->object->Get_Rplayer_Label();
				if (temp_Label == "O")
				{
					UI_object->object->Vector_of_Adjacent_elements = UI_object->object->getAdjacent(UI_object->object->Two_D_matrix, x, y);

					UI_object->is_that_an_SOS = UI_object->object->O_scenerio_checker(UI_object->object->Vector_of_Adjacent_elements);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->object->Rplayer_SOS_counter++;
					}
				}
				else
				{
					UI_object->is_that_an_SOS = UI_object->object->S_scenerio_checker(UI_object->object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->object->Rplayer_SOS_counter++;
					}
				}
			}
		}
		if(UI_object->object->already_fill_out == UI_object->object->total_buttons)				//announce the winner when the board is filled up and end the game
		{
			if (UI_object->object->Bplayer_SOS_counter > UI_object->object->Rplayer_SOS_counter)
			{
				wxMessageBox("The winner is Blue Player !!!- Game Over");
				previous_game_winner = UI_object->object->Bplayer;
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
			else if (UI_object->object->Bplayer_SOS_counter < UI_object->object->Rplayer_SOS_counter)
			{
				wxMessageBox("The winner is Red Player !!!- Game Over");
				previous_game_winner = UI_object->object->Rplayer;
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
			else if (UI_object->object->Bplayer_SOS_counter = UI_object->object->Rplayer_SOS_counter)
			{
				wxMessageBox("Unbelievable ! It is a draw - Game Over");
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
			else
			{
				wxMessageBox("Unbelievable ! It is a draw - Game Over");
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
		}
	}

	/*
	if (object->GetCurrentPlayer() == object->Bplayer)
	{
		//set label to button once pressed
		btn[y * get_Length() + x]->SetLabel(object->Get_Bplayer_Label());
		//put that label to two dimentional vector
		object->Two_D_matrix[x][y] = object->Get_Bplayer_Label();

		temp_Label = object->Get_Bplayer_Label();
		if (temp_Label == "O")
		{
			object->Vector_of_Adjacent_elements = object->getAdjacent(object->Two_D_matrix, x, y);

			is_that_an_SOS = object->O_scenerio_checker(object->Vector_of_Adjacent_elements);
			if (is_that_an_SOS == true)
			{
				wxMessageBox("Found the winner!!!- Game Over");
				is_that_an_SOS = false;
				//reset game
				Blank_out_Table(get_Length());
			}
		}
		else 
		{
			is_that_an_SOS = object->S_scenerio_checker(object->Two_D_matrix, get_Length(), get_Length(), x, y );
			if (is_that_an_SOS == true)
			{
				wxMessageBox("Found the winner!!!- Game Over");
				is_that_an_SOS = false;
				//reset game
				Blank_out_Table(get_Length());
			}
		}
	}
	if (object->GetCurrentPlayer() == object->Rplayer)
	{
		//set label to button once pressed
		btn[y * get_Length() + x]->SetLabel(object->Get_Rplayer_Label());
		//put that label to two dimentional vector
		object->Two_D_matrix[x][y] = object->Get_Rplayer_Label();
		
		temp_Label = object->Get_Rplayer_Label();
		if ( temp_Label == "O")
		{
			object->Vector_of_Adjacent_elements = object->getAdjacent(object->Two_D_matrix, x, y);

			is_that_an_SOS = object->O_scenerio_checker(object->Vector_of_Adjacent_elements);
			if (is_that_an_SOS == true)
			{
				wxMessageBox("Found the winner!!!- Game Over");
				is_that_an_SOS = false;
				//reset game
				Blank_out_Table(get_Length());
			}
		}
		else
		{
			is_that_an_SOS = object->S_scenerio_checker(object->Two_D_matrix, get_Length(), get_Length(), x, y);
			if (is_that_an_SOS == true)
			{
				wxMessageBox("Found the winner!!!- Game Over");
				is_that_an_SOS = false;
				//reset game
				Blank_out_Table(get_Length());
			}
		}
	}
	*/

	UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again

	UI_object->object->SetNextPlayer();													//set next player
	UI_object->m_txt3->SetLabel(UI_object->object->GetCurrentPlayer() + " Player");				//update text to show whose turn
	
	evt.Skip();
}

void cMain::BoardSize(wxCommandEvent& evt)
{
	UI_object->length_string = UI_object->m_txt1->GetValue();
	UI_object->m_txt1->Clear();
	stringstream StringToInt(UI_object->length_string);                                                                                  	// object from the class stringstream
	StringToInt >> UI_object->length_int;
	UI_object->set_Length(UI_object->length_int);
	
	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	InitializeTable(font, UI_object->get_Length());

	//initialize Two_D_matrix size with length from user input
	vector<vector<string>> temp(UI_object->get_Length(), vector<string>(UI_object->get_Length(), " "));
	UI_object->object->Two_D_matrix = temp;

	UI_object->object->total_buttons = UI_object->length_int * UI_object->length_int;							//initialize value for total_buttons which is a counter for general game
}

void cMain::Simple_game_Checked(wxCommandEvent& evt)
{
	UI_object->object->SetGameMode(UI_object->object->simple_Game);
}

void cMain::General_game_Checked(wxCommandEvent& evt)
{
	UI_object->object->SetGameMode(UI_object->object->general_Game);
}
void cMain::Bplayer_S_Checked(wxCommandEvent& evt)
{
	UI_object->object->Set_Bplayer_Label(UI_object->object->s);
}
void cMain::Bplayer_O_Checked(wxCommandEvent& evt)
{
	UI_object->object->Set_Bplayer_Label(UI_object->object->o);
}
void cMain::Rplayer_S_Checked(wxCommandEvent& evt)
{
	UI_object->object->Set_Rplayer_Label(UI_object->object->s);
}
void cMain::Rplayer_O_Checked(wxCommandEvent& evt)
{
	UI_object->object->Set_Rplayer_Label(UI_object->object->o);
}
void cMain::Restart(wxCommandEvent& evt)
{
	//remove last game component
	bgPanel->Destroy();
	UI_object->m_txt1->Destroy();

	bgPanel = new wxPanel(this, wxID_ANY, wxPoint(170, 70), wxSize(200, 200));
	
	UI_object = new UI;
	UI_object -> object->SetCurrentPlayer(previous_game_winner);
	
	InitializeComponent();
}


