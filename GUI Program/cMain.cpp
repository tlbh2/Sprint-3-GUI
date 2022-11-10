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
	object->SetCurrentPlayer(object->Bplayer);

	InitializeComponent();
}

cMain::~cMain()
{
	//prevent memory leak
	delete[]btn;
}

//Event function definition

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	//Get coordinate of button in field array
	int x = (evt.GetId() - 10000) % get_Length();
	int y = (evt.GetId() - 10000) / get_Length();
	string temp_Label;

	if (object->GetGameMode() == "SimpleGame")
	{
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
					wxMessageBox("The winner is " + object->GetCurrentPlayer() + " !!!- Game Over");
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
					wxMessageBox("The winner is " + object->GetCurrentPlayer() + " !!!- Game Over");
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
			if (temp_Label == "O")
			{
				object->Vector_of_Adjacent_elements = object->getAdjacent(object->Two_D_matrix, x, y);

				is_that_an_SOS = object->O_scenerio_checker(object->Vector_of_Adjacent_elements);
				if (is_that_an_SOS == true)
				{
					wxMessageBox("The winner is " + object->GetCurrentPlayer() + " !!!- Game Over");
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
					wxMessageBox("The winner is " + object->GetCurrentPlayer() + " !!!- Game Over");
					is_that_an_SOS = false;
					//reset game
					Blank_out_Table(get_Length());
				}
			}
		}
	}
	if (object->GetGameMode() == "GeneralGame")
	{
		
		if (object->already_fill_out != object->total_buttons)
		{
			if (object->GetCurrentPlayer() == object->Bplayer)
			{
				//set label to button once pressed
				btn[y * get_Length() + x]->SetLabel(object->Get_Bplayer_Label());
				object->already_fill_out++;
				//put that label to two dimentional vector
				object->Two_D_matrix[x][y] = object->Get_Bplayer_Label();

				temp_Label = object->Get_Bplayer_Label();
				if (temp_Label == "O")
				{
					object->Vector_of_Adjacent_elements = object->getAdjacent(object->Two_D_matrix, x, y);

					is_that_an_SOS = object->O_scenerio_checker(object->Vector_of_Adjacent_elements);
					if (is_that_an_SOS == true)
					{
						object->Bplayer_SOS_counter++;
					}
				}
				else
				{
					is_that_an_SOS = object->S_scenerio_checker(object->Two_D_matrix, get_Length(), get_Length(), x, y);
					if (is_that_an_SOS == true)
					{
						object->Bplayer_SOS_counter++;
					}
				}
			}
			if (object->GetCurrentPlayer() == object->Rplayer)
			{
				//set label to button once pressed
				btn[y * get_Length() + x]->SetLabel(object->Get_Rplayer_Label());
				object->already_fill_out++;
				//put that label to two dimentional vector
				object->Two_D_matrix[x][y] = object->Get_Rplayer_Label();

				temp_Label = object->Get_Rplayer_Label();
				if (temp_Label == "O")
				{
					object->Vector_of_Adjacent_elements = object->getAdjacent(object->Two_D_matrix, x, y);

					is_that_an_SOS = object->O_scenerio_checker(object->Vector_of_Adjacent_elements);
					if (is_that_an_SOS == true)
					{
						object->Rplayer_SOS_counter++;
					}
				}
				else
				{
					is_that_an_SOS = object->S_scenerio_checker(object->Two_D_matrix, get_Length(), get_Length(), x, y);
					if (is_that_an_SOS == true)
					{
						object->Rplayer_SOS_counter++;
					}
				}
			}
		}
		if(object->already_fill_out == object->total_buttons)				//announce the winner when the board is filled up and end the game
		{
			if (object->Bplayer_SOS_counter > object->Rplayer_SOS_counter)
			{
				wxMessageBox("The winner is Blue Player !!!- Game Over");
				//reset game
				Blank_out_Table(get_Length());
			}
			else if (object->Bplayer_SOS_counter < object->Rplayer_SOS_counter)
			{
				wxMessageBox("The winner is Red Player !!!- Game Over");
				//reset game
				Blank_out_Table(get_Length());
			}
			else if (object->Bplayer_SOS_counter = object->Rplayer_SOS_counter)
			{
				wxMessageBox("Unbelievable ! It is a draw - Game Over");
				//reset game
				Blank_out_Table(get_Length());
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

	btn[y * get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again

	object->SetNextPlayer();													//set next player
	m_txt3->SetLabel(object->GetCurrentPlayer() + " Player");				//update text to show whose turn
	
	evt.Skip();
}

void cMain::BoardSize(wxCommandEvent& evt)
{
	length_string = m_txt1->GetValue();
	stringstream StringToInt(length_string);                                                                                  	// object from the class stringstream
	StringToInt >> length_int;
	set_Length(length_int);
	
	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	InitializeTable(font, get_Length());

	//initialize Two_D_matrix size with length from user input
	vector<vector<string>> temp(get_Length(), vector<string>(get_Length(), " "));
	object->Two_D_matrix = temp;

	object->total_buttons = length_int * length_int;							//initialize value for total_buttons which is a counter for general game
}

void cMain::Simple_game_Checked(wxCommandEvent& evt)
{
	object->SetGameMode(object->simple_Game);
}

void cMain::General_game_Checked(wxCommandEvent& evt)
{
	object->SetGameMode(object->general_Game);
}
void cMain::Bplayer_S_Checked(wxCommandEvent& evt)
{
	object->Set_Bplayer_Label(object->s);
}
void cMain::Bplayer_O_Checked(wxCommandEvent& evt)
{
	object->Set_Bplayer_Label(object->o);
}
void cMain::Rplayer_S_Checked(wxCommandEvent& evt)
{
	object->Set_Rplayer_Label(object->s);
}
void cMain::Rplayer_O_Checked(wxCommandEvent& evt)
{
	object->Set_Rplayer_Label(object->o);
}
void cMain::Restart(wxCommandEvent& evt)
{
	bgPanel->Destroy();
	wxPanel* bgPanel = new wxPanel(this, wxID_ANY, wxPoint(170, 70), wxSize(200, 200));
	GameLogic* object = new GameLogic;
	object->SetCurrentPlayer(object->Bplayer);
	set_Length(0);
	length_int = 0;
	length_string = "";
	InitializeComponent();

}


