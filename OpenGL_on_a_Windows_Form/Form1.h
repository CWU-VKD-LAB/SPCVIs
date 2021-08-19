///-------------------------------------------------------------------------------------------------
// file:	Form1.h
//
// summary:	Declares the form 1 class
///-------------------------------------------------------------------------------------------------

#pragma once

#include "OpenGL3.h"

namespace OpenGL_on_a_Windows_Form 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	/// <summary>	Type of the graph. </summary>
	int graphType = -1;
	/// <summary>	True if fileopened. </summary>
	bool fileopened = false;

	/// <summary>	Just to hold the file name for now to send to the graphs. </summary>
	ClassData data;
	FileHandling test;

	/// <summary>	The old zoom value. </summary>
	int oldZoomValue = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	Summary for Form1
	/// 	
	/// 	WARNING: If you change the name of this class, you will need to change the
	/// 	         'Resource File Name' property for the managed resource compiler tool associated
	/// 	         with all .resx files this class depends on.  Otherwise, the designers will not
	/// 	         be able to interact properly with localized resources associated with this form.
	/// </summary>
	///
	/// <remarks>	Barim, 3/3/2019. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Default constructor. </summary>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			OpenGL3 = gcnew COpenGL3(this, this->Width - this->panel1->Width - 40 - 200, //Width
				this->Height - this->menuStrip1->Height - this->statusStrip1->Height - 55, //Height
				graphType);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Destructor. </summary>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	/// <summary>	The components. </summary>
	private: System::ComponentModel::IContainer^  components;
	private: int previousTrackBar2Value; 
	private: int previousNonOrthoXValue;
	private: int previousNonOrthoYValue;
	private: int previousTrackBar3Value; 
	//private: System::Collections::ArrayList checkedIndex;	  
	protected:
	/// <summary>	The first timer. </summary>
	/// <summary>	The first timer. </summary>
	private: System::Windows::Forms::Timer^  timer1;

	/// <summary>	The fourth graph. </summary>
	private: System::Windows::Forms::Button^  graph4;
	/// <summary>	The first panel. </summary>
	private: System::Windows::Forms::Panel^  panel1;
	/// <summary>	The first menu strip. </summary>
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	/// <summary>	The file tool strip menu item. </summary>


	/// <summary>	The first scroll bar. </summary>
	private: System::Windows::Forms::VScrollBar^  vScrollBar1;
	/// <summary>	The first scroll bar. </summary>
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	/// <summary>	The first track bar. </summary>
	private: System::Windows::Forms::TrackBar^  trackBar1;
	/// <summary>	The pannning label. </summary>
	private: System::Windows::Forms::Label^  PannningLabel;
	/// <summary>	The zooming label. </summary>
	private: System::Windows::Forms::Label^  ZoomingLabel;
	/// <summary>	The first status strip. </summary>
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	/// <summary>	The graph 8. </summary>

	/// <summary>	The first group box. </summary>
	private: System::Windows::Forms::GroupBox^  groupBox1;



	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::Button^  colorButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox2;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::TrackBar^ trackBar2;
private: System::Windows::Forms::ComboBox^ comboBox3;
private: System::Windows::Forms::Button^ button5;

private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::ComboBox^ comboBox4;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::TextBox^ textBox3;
private: System::Windows::Forms::TextBox^ textBox4;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::CheckedListBox^ checkedListBox4;
private: System::Windows::Forms::Button^ button9;
private: System::Windows::Forms::Button^ button10;
private: System::Windows::Forms::CheckBox^ checkBox3;
private: System::Windows::Forms::Button^ button11;
private: System::Windows::Forms::Button^ button12;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Button^ button13;














	private:
		/// <summary>	Required designer variable. </summary>

		OpenGLForm::COpenGL3 ^ OpenGL3;

#pragma region Windows Form Designer generated code

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// 	Required method for Designer support - do not modify the contents of this method with the
		/// 	code editor.
		/// </summary>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->graph4 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->checkedListBox4 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->ZoomingLabel = (gcnew System::Windows::Forms::Label());
			this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->PannningLabel = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->colorButton = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// graph4
			// 
			this->graph4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graph4->Location = System::Drawing::Point(13, 43);
			this->graph4->Margin = System::Windows::Forms::Padding(6);
			this->graph4->Name = L"graph4";
			this->graph4->Size = System::Drawing::Size(174, 29);
			this->graph4->TabIndex = 3;
			this->graph4->Text = L"Reset Data";
			this->graph4->UseVisualStyleBackColor = true;
			this->graph4->Click += gcnew System::EventHandler(this, &Form1::graph4_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel1->Controls->Add(this->button13);
			this->panel1->Controls->Add(this->button12);
			this->panel1->Controls->Add(this->button11);
			this->panel1->Controls->Add(this->checkBox3);
			this->panel1->Controls->Add(this->button10);
			this->panel1->Controls->Add(this->button9);
			this->panel1->Controls->Add(this->checkedListBox4);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->comboBox2);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->graph4);
			this->panel1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 676);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// button13
			// 
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(10, 580);
			this->button13->Margin = System::Windows::Forms::Padding(6);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(181, 27);
			this->button13->TabIndex = 24;
			this->button13->Text = L"Automate";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(95, 500);
			this->button12->Margin = System::Windows::Forms::Padding(6);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(96, 69);
			this->button12->TabIndex = 23;
			this->button12->Text = L"Averaging";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(10, 500);
			this->button11->Margin = System::Windows::Forms::Padding(6);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(73, 68);
			this->button11->TabIndex = 22;
			this->button11->Text = L"HD Display";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->checkBox3->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
			this->checkBox3->FlatAppearance->BorderSize = 10;
			this->checkBox3->FlatAppearance->CheckedBackColor = System::Drawing::Color::Red;
			this->checkBox3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Lime;
			this->checkBox3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox3->Location = System::Drawing::Point(65, 454);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(58, 21);
			this->checkBox3->TabIndex = 21;
			this->checkBox3->Text = L"Done";
			this->checkBox3->UseVisualStyleBackColor = false;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox3_CheckedChanged);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button10->Location = System::Drawing::Point(10, 430);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(181, 54);
			this->button10->TabIndex = 21;
			this->button10->Text = L"Draw Rectangles (Or)";
			this->button10->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button9->Location = System::Drawing::Point(11, 362);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(181, 54);
			this->button9->TabIndex = 20;
			this->button9->Text = L"Draw Rectangles (And)";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// checkedListBox4
			// 
			this->checkedListBox4->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->checkedListBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->checkedListBox4->CheckOnClick = true;
			this->checkedListBox4->ForeColor = System::Drawing::SystemColors::WindowText;
			this->checkedListBox4->FormattingEnabled = true;
			this->checkedListBox4->Location = System::Drawing::Point(123, 647);
			this->checkedListBox4->Name = L"checkedListBox4";
			this->checkedListBox4->Size = System::Drawing::Size(74, 17);
			this->checkedListBox4->TabIndex = 19;
			this->checkedListBox4->ThreeDCheckBoxes = true;
			this->checkedListBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::checkedListBox4_SelectedIndexChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->label9->Location = System::Drawing::Point(12, 646);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(89, 16);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Hide Classes";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Location = System::Drawing::Point(113, 320);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(61, 20);
			this->textBox2->TabIndex = 15;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(21, 317);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(61, 20);
			this->textBox1->TabIndex = 14;
			this->textBox1->UseWaitCursor = true;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button8->Location = System::Drawing::Point(13, 151);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(173, 35);
			this->button8->TabIndex = 13;
			this->button8->Text = L"Swap Coordinates";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button7->Location = System::Drawing::Point(101, 268);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(85, 83);
			this->button7->TabIndex = 12;
			this->button7->Text = L"Non Ortho-Y";
			this->button7->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button6->Location = System::Drawing::Point(11, 268);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(84, 83);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Non Ortho-X";
			this->button6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button5->Location = System::Drawing::Point(12, 204);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(83, 58);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Show/Hide Lines";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button4->Location = System::Drawing::Point(13, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(173, 31);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Upload Data";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button3->Location = System::Drawing::Point(102, 204);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(84, 58);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Move Graph";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(152, 616);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(38, 21);
			this->comboBox2->TabIndex = 7;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->label3->Location = System::Drawing::Point(8, 618);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(147, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Choose Class for Mean";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button2->Location = System::Drawing::Point(102, 81);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 62);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Reverse Y";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button1->Location = System::Drawing::Point(12, 81);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 62);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Reverse X";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::SystemColors::Control;
			this->trackBar1->LargeChange = 1;
			this->trackBar1->Location = System::Drawing::Point(9, 112);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(185, 45);
			this->trackBar1->TabIndex = 9;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// ZoomingLabel
			// 
			this->ZoomingLabel->AutoSize = true;
			this->ZoomingLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ZoomingLabel->Location = System::Drawing::Point(17, 85);
			this->ZoomingLabel->Name = L"ZoomingLabel";
			this->ZoomingLabel->Size = System::Drawing::Size(43, 16);
			this->ZoomingLabel->TabIndex = 11;
			this->ZoomingLabel->Text = L"Zoom";
			// 
			// vScrollBar1
			// 
			this->vScrollBar1->Location = System::Drawing::Point(71, 47);
			this->vScrollBar1->Minimum = -100;
			this->vScrollBar1->Name = L"vScrollBar1";
			this->vScrollBar1->Size = System::Drawing::Size(42, 50);
			this->vScrollBar1->TabIndex = 7;
			this->vScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::vScrollBar1_Scroll);
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(21, 47);
			this->hScrollBar1->Minimum = -100;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(50, 40);
			this->hScrollBar1->TabIndex = 8;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::hScrollBar1_Scroll);
			// 
			// PannningLabel
			// 
			this->PannningLabel->AutoSize = true;
			this->PannningLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PannningLabel->Location = System::Drawing::Point(15, 27);
			this->PannningLabel->Name = L"PannningLabel";
			this->PannningLabel->Size = System::Drawing::Size(57, 16);
			this->PannningLabel->TabIndex = 10;
			this->PannningLabel->Text = L"Panning";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1530, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->statusStrip1->Location = System::Drawing::Point(0, 697);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1530, 22);
			this->statusStrip1->TabIndex = 6;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->PannningLabel);
			this->groupBox1->Controls->Add(this->ZoomingLabel);
			this->groupBox1->Controls->Add(this->vScrollBar1);
			this->groupBox1->Controls->Add(this->hScrollBar1);
			this->groupBox1->Location = System::Drawing::Point(7, 267);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 174);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			// 
			// colorButton
			// 
			this->colorButton->Location = System::Drawing::Point(4, 60);
			this->colorButton->Name = L"colorButton";
			this->colorButton->Size = System::Drawing::Size(192, 73);
			this->colorButton->TabIndex = 0;
			this->colorButton->Text = L"Select Color";
			this->colorButton->UseVisualStyleBackColor = true;
			this->colorButton->Click += gcnew System::EventHandler(this, &Form1::colorButton_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->colorButton, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->comboBox1, 0, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(6, 514);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.19048F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 48.80952F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 78)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(200, 137);
			this->tableLayoutPanel1->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(4, 1);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 16);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Change Class Color";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(4, 33);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(188, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(554, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 11;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->comboBox4);
			this->panel2->Controls->Add(this->checkBox2);
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->trackBar2);
			this->panel2->Controls->Add(this->comboBox3);
			this->panel2->Controls->Add(this->tableLayoutPanel1);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->trackBar3);
			this->panel2->Location = System::Drawing::Point(1320, 27);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(209, 671);
			this->panel2->TabIndex = 13;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(254)));
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textBox3->Location = System::Drawing::Point(54, 94);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(50, 20);
			this->textBox3->TabIndex = 19;
			this->textBox3->UseWaitCursor = true;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(254)));
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox4->Location = System::Drawing::Point(54, 124);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(50, 20);
			this->textBox4->TabIndex = 20;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->label8->Location = System::Drawing::Point(9, 447);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(137, 16);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Display Class on Top";
			// 
			// comboBox4
			// 
			this->comboBox4->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->comboBox4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(164, 444);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(42, 21);
			this->comboBox4->TabIndex = 14;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox4_SelectedIndexChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->checkBox2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox2->Location = System::Drawing::Point(20, 124);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(36, 21);
			this->checkBox2->TabIndex = 18;
			this->checkBox2->Text = L"> ";
			this->checkBox2->UseVisualStyleBackColor = false;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->checkBox1->FlatAppearance->BorderColor = System::Drawing::Color::Turquoise;
			this->checkBox1->FlatAppearance->BorderSize = 10;
			this->checkBox1->FlatAppearance->CheckedBackColor = System::Drawing::Color::Red;
			this->checkBox1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Lime;
			this->checkBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox1->Location = System::Drawing::Point(20, 92);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(36, 21);
			this->checkBox1->TabIndex = 17;
			this->checkBox1->Text = L"< ";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(7, 72);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(97, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Non Linear Scaling";
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 218);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(84, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Change Scale Y";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 10);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(151, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Select Graph to Change Scale";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 159);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Change Scale X";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// trackBar2
			// 
			this->trackBar2->LargeChange = 1;
			this->trackBar2->Location = System::Drawing::Point(10, 173);
			this->trackBar2->Minimum = -10;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(162, 45);
			this->trackBar2->TabIndex = 1;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &Form1::trackBar2_Scroll);
			// 
			// comboBox3
			// 
			this->comboBox3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->ForeColor = System::Drawing::SystemColors::WindowText;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(7, 30);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(162, 21);
			this->comboBox3->TabIndex = 10;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox3_SelectedIndexChanged);
			// 
			// trackBar3
			// 
			this->trackBar3->LargeChange = 1;
			this->trackBar3->Location = System::Drawing::Point(7, 234);
			this->trackBar3->Minimum = -10;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(162, 45);
			this->trackBar3->TabIndex = 1;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &Form1::trackBar3_Scroll);
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(192, 691);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(1128, 24);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Load Data";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label10->Click += gcnew System::EventHandler(this, &Form1::label10_Click);
			// 
			// Form1
			// 
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1530, 719);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(12);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Interactive Shifted Paired Coordinates";
			this->TransparencyKey = System::Drawing::Color::Maroon;
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Converts a str to a standard string. </summary>
		///
		/// <param name="str">	The string. </param>
		///
		/// <returns>	Str as a std::string. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		std::string toStandardString(System::String^ str)
		{
			const char* location = (const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str).ToPointer();
			std::string temp(location);
			/* Clean up the const char* location memory */
			System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)location));
			return temp;
		}

		// File Opening

		System::Void openFile(System::Void)
		{
			OpenFileDialog^ ofd = gcnew OpenFileDialog;
			ofd->InitialDirectory = ""; // NOTE "c:\\" for future reference.
			ofd->Filter = "Text Files (*.csv, *.txt, *.text)|*.csv; *.txt; *.text";
			ofd->FilterIndex = 1;
			ofd->RestoreDirectory = true;

			if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				/* Convert System::String^ to a std::string */
				System::String^ path = ofd->FileName;

				data.fileName = toStandardString(path);

				/*
				try{
					test.openFile(data);
					test.sortGraph(data);
					if (data.
					.empty()) {
						throw std::exception();
						return;
					}

				}
				catch(...){
					// display an error message
					MessageBox::Show("WARNING: Cannot correctly read data from file, try reformatting or another file.", "Trouble Reading File", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				*/

				graphType = -1;
				oldZoomValue = 0;
				graph1_oldZoom = 0;
				graph2_oldZoom = 0;
				graph3_oldZoom = 0;
				graph4_oldZoom = 0;
				graph5_oldZoom = 0;
				graph6_oldZoom = 0;
				graph7_oldZoom = 0;
				graph8_oldZoom = 0;
				graph9_oldZoom = 0;

				panel1showing = true;
				panel2showing = true;
				OpenGL3->resetDrawingArea();

				Controls->Clear();
				InitializeComponent();

				graphType = 1;
				OpenGL3->graphType = 1;
				trackBar1->Value = graph1_oldZoom;
				classnumberselected = -1;

				fileopened = true;
		        
				

				
			}
		}


	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);


		if (graphType == 4)			//Combined SPC graph4
		{
			OpenGL3->Render4();
		}



		OpenGL3->SwapOpenGLBuffers();
	}

			 // BUTTONS TO CHOOSE DISPLAY OF GRAPH TYPE





	private: System::Void graph4_Click(System::Object^  sender, System::EventArgs^  e) {	//Combined SPC graph4
		trackBar2->Value = 0;
		previousTrackBar2Value = 0;
		previousNonOrthoXValue = 0;
		trackBar3->Value = 0;
		previousTrackBar3Value = 0;
		OpenGL3->nonLinearLesserThan = 0;
		OpenGL3->nonLinearGreaterThan = 0;
		checkBox1->Checked = FALSE;
		checkBox2->Checked = FALSE;
		for (int x = 0; x < checkedListBox4->Items->Count; x++)
		{
			checkedListBox4->SetItemChecked(x, false);
		}

		if (fileopened)
		{
			OpenGL3->clearAllGraphData();
			OpenGL3->reverseDataAxis = 0;
			OpenGL3->setFileName(data);
		}
		loadInteractiveSPC();


	}
	protected:
		/// <summary>	The graph 1 old zoom. </summary>
		/// <summary>	The graph 1 old zoom. </summary>
		int graph1_oldZoom;
		/// <summary>	The graph 2 old zoom. </summary>
		int graph2_oldZoom;
		/// <summary>	The graph 3 old zoom. </summary>
		int graph3_oldZoom;
		/// <summary>	The graph 4 old zoom. </summary>
		int graph4_oldZoom;
		/// <summary>	The graph 5 old zoom. </summary>
		int graph5_oldZoom;
		/// <summary>	The graph 6 old zoom. </summary>
		int graph6_oldZoom;
		/// <summary>	The graph 7 old zoom. </summary>
		int graph7_oldZoom;
		/// <summary>	The graph 8 old zoom. </summary>
		int graph8_oldZoom;
		/// <summary>	The graph 9 old zoom. </summary>
		int graph9_oldZoom;


	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);

		openFile(); // starts select file window
		if (fileopened) {
			OpenGL3->setFileName(data);


			// clear the list to prevent duplicates on update
			this->comboBox1->Items->Clear();
			this->comboBox1->Items->Clear();
			data.numOfClasses = OpenGL3->getClassSize();
			for (int i = 1; i <= data.numOfClasses; i++) {
					this->comboBox1->Items->Add(i); // set the combobox for "Class combobox" to the data in item1 
			}

			this->comboBox2->Items->Clear();
			this->comboBox2->Items->Clear();
			data.numOfClasses = OpenGL3->getClassSize();
			for (int i = 1; i <= data.numOfClasses; i++) {
				this->comboBox2->Items->Add(i); // set the combobox for "Class combobox" to the data in item1 
			}


			loadInteractiveSPC();
		}


	}






	private: System::Void hScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		if (e->NewValue > e->OldValue)
		{
			//moved right
			OpenGL3->panHorizontal(true); // true for going right



		}
		else if (e->NewValue < e->OldValue)
		{
			//moved left
			OpenGL3->panHorizontal(false); // true for going right else false for going left

		}
	}


	private: System::Void vScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		if (e->NewValue > e->OldValue)
		{
			//moved up
			OpenGL3->panVertical(true); // true for going up else flase for down
		}
		else if (e->NewValue < e->OldValue)
		{
			//moved down
			OpenGL3->panVertical(false); // true for going up else flase for down
		}
	}


	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
		//int value = trackBar1->Value;
		//MessageBox::Show("" + value);

		if (graphType == 1) {
			OpenGL3->zoom(trackBar1->Value - graph1_oldZoom);
			graph1_oldZoom = trackBar1->Value;
		}
		else if (graphType == 2) {
			OpenGL3->zoom(trackBar1->Value - graph2_oldZoom);
			graph2_oldZoom = trackBar1->Value;
		}
		else if (graphType == 3) {
			OpenGL3->zoom(trackBar1->Value - graph3_oldZoom);
			graph3_oldZoom = trackBar1->Value;
		}
		else if (graphType == 4) {

			OpenGL3->zoom(trackBar1->Value - graph4_oldZoom);
			graph4_oldZoom = trackBar1->Value;
			
		}
		else if (graphType == 5) {
			OpenGL3->zoom(trackBar1->Value - graph5_oldZoom);
			graph5_oldZoom = trackBar1->Value;
		}
		else if (graphType == 6) {
			OpenGL3->zoom(trackBar1->Value - graph6_oldZoom);
			graph6_oldZoom = trackBar1->Value;
		}
		else if (graphType == 7) {
			OpenGL3->zoom(trackBar1->Value - graph7_oldZoom);
			graph7_oldZoom = trackBar1->Value;
		}
		else if (graphType == 8) {
			OpenGL3->zoom(trackBar1->Value - graph8_oldZoom);
			graph8_oldZoom = trackBar1->Value;
		}
		else if (graphType == 9) {
			OpenGL3->zoom(trackBar1->Value - graph9_oldZoom);
			graph9_oldZoom = trackBar1->Value;
		}
	}



	int classnumberselected = -1;
private: System::Void colorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// FOR CHANGING COLOR
	if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		//this->colorPanel->BackColor = this->colorDialog1->Color;
		float red = this->colorDialog1->Color.R;
		float green = this->colorDialog1->Color.G;
		float blue = this->colorDialog1->Color.B;

		OpenGL3->setClassColor(red, green, blue, classnumberselected);
	}

	
}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	classnumberselected = comboBox1->SelectedIndex+1;

}

		 bool panel1showing = true;

		 bool panel2showing = true;



		 int loadInteractiveSPC();
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Setting reverse data axis to x
	OpenGL3->reverseDataAxis = 1;
	OpenGL3->swapAxes = 0;
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (fileopened) {
		OpenGL3->setFileName(data);
	}
	OpenGL3->setMeanData(comboBox2->SelectedIndex);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// Setting reverse data axis to y
	OpenGL3->reverseDataAxis = 2;
	OpenGL3->swapAxes = 0;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenGL3->reverseDataAxis = 0;
	OpenGL3->drawingAndRectEnabled = false;
	OpenGL3->drawingOrRectEnabled = false;
	OpenGL3->nonOrtho = 0;
	OpenGL3->swapAxes = 0;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	UNREFERENCED_PARAMETER(sender);
	UNREFERENCED_PARAMETER(e);
	
	openFile(); // starts select file window
	if (fileopened) {
		OpenGL3->setFileName(data);


		// clear the list to prevent duplicates on update
		this->comboBox1->Items->Clear();
		this->comboBox1->Items->Clear();
		data.numOfClasses = OpenGL3->getClassSize();
		for (int i = 1; i <= data.numOfClasses; i++) {
			this->comboBox1->Items->Add(i); // set the combobox for "Class combobox" to the data in item1 
		}

		this->comboBox2->Items->Clear();
		this->comboBox2->Items->Clear();
		data.numOfClasses = OpenGL3->getClassSize();
		for (int i = 1; i <= data.numOfClasses; i++) {
			this->comboBox2->Items->Add(i); // set the combobox for "Class combobox" to the data in item1 
		}
		this->comboBox4->Items->Clear();
		this->comboBox4->Items->Clear();
		data.numOfClasses = OpenGL3->getClassSize();
		for (int i = 1; i <= data.numOfClasses; i++) {
			this->comboBox4->Items->Add(i); // set the combobox for "Class combobox" to the data in item1 
		}

		this->comboBox3->Items->Clear();
		for (int i = 1; i <= OpenGL3->getNumberOfGraphs(); i++) {
			this->comboBox3->Items->Add(i); // set the combobox for "Class combobox" to the data in item1 
		}

		this->comboBox3->SelectedIndex = 0;
		OpenGL3->nonLinearLesserThan = 0;
		OpenGL3->nonLinearGreaterThan = 0;
		loadInteractiveSPC();


		this->checkedListBox4->Items->Clear();
		this->checkedListBox4->Items->Clear();
		data.numOfClasses = OpenGL3->getClassSize();
		for (int i = 1; i <= data.numOfClasses; i++) {
			this->checkedListBox4->Items->Add(i); // set the combobox for "Class combobox" to the data in item1 
		}
	}
	label10->Text = OpenGL3->displayCoordinateLabels(data.covScore);

}


private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) 
{
	
	if (trackBar2->Value > previousTrackBar2Value)
	{
		OpenGL3->changeScaleX(comboBox3->SelectedIndex + 1, 1, OpenGL3->nonLinearScaleX);
	}
	else if (trackBar2->Value < previousTrackBar2Value)
	{
		OpenGL3->changeScaleX(comboBox3->SelectedIndex + 1, -1, OpenGL3->nonLinearScaleX);
	}
	else if(trackBar2->Value == previousTrackBar2Value)
	{
		OpenGL3->changeScaleX(comboBox3->SelectedIndex + 1, 0, OpenGL3->nonLinearScaleX);
	}
	previousTrackBar2Value = trackBar2->Value;

	

}

	   private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	   {
		
		   trackBar2->Value = 0;
		   trackBar3->Value = 0;
		   previousTrackBar3Value = 0;
		   previousTrackBar2Value = 0;
	   }

private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	if (trackBar3->Value > previousTrackBar3Value)
	{
		OpenGL3->changeScaleY(comboBox3->SelectedIndex + 1, 1, OpenGL3->nonLinearScaleY);
	}
	else 
	{
		OpenGL3->changeScaleY(comboBox3->SelectedIndex + 1, -1, OpenGL3->nonLinearScaleY);
	}

	previousTrackBar3Value = trackBar3->Value;


}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenGL3->showHideLines(); 
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) 
{
	OpenGL3->nonOrtho = 1;
	if (textBox1->Text == "" || textBox1->Text == "-")
	{
		OpenGL3->nonOrthoXAngle = previousNonOrthoXValue;
	}

	else
		OpenGL3->nonOrthoXAngle = (float)Convert::ToDouble(textBox1->Text);

	// = OpenGL3->nonOrthoXAngle - previousNonOrthoXValue;
	OpenGL3->nonOrthoXDiff = -30;
	previousNonOrthoXValue = OpenGL3->nonOrthoXAngle;
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) 
{
	OpenGL3->nonOrtho = 2;
	if (textBox2->Text == "" || textBox2->Text == "-")
	{
		OpenGL3->nonOrthoYAngle = previousNonOrthoYValue;
	}

	else
		OpenGL3->nonOrthoYAngle = (float)Convert::ToDouble(textBox2->Text);

	OpenGL3->nonOrthoYDiff = OpenGL3->nonOrthoYAngle - previousNonOrthoYValue;
	previousNonOrthoYValue = OpenGL3->nonOrthoYAngle;
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox1->Checked)
	{
		trackBar2->Value = 0;
		previousTrackBar2Value = 0;
		trackBar3->Value = 0;
		previousTrackBar3Value = 0;
		OpenGL3->nonLinearScaleX = 1;
		OpenGL3->nonLinearScaleY = 1;
		//OpenGL3->changeScaleX(comboBox3->SelectedIndex + 1, 0, OpenGL3->nonLinearScaleX);
		//OpenGL3->changeScaleY(comboBox3->SelectedIndex + 1, 0, OpenGL3->nonLinearScaleY);
		checkBox2->Checked = FALSE;
	}
}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox2->Checked)
	{
		trackBar2->Value = 0;
		previousTrackBar2Value = 0;
		trackBar3->Value = 0;
		previousTrackBar3Value = 0;
		OpenGL3->nonLinearScaleX = 2;
		OpenGL3->nonLinearScaleY = 2;
		OpenGL3->changeScaleX(comboBox3->SelectedIndex + 1, 0, OpenGL3->nonLinearScaleX);
		OpenGL3->changeScaleY(comboBox3->SelectedIndex + 1, 0, OpenGL3->nonLinearScaleY);
		checkBox1->Checked = FALSE;
	}
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) 
{
	OpenGL3->swapAxes = 1;
	OpenGL3->reverseDataAxis = 0;
}
private: System::Void comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	 OpenGL3->displayClassOnTop(comboBox4->SelectedIndex);
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{
	/*if (OpenGL3->nonOrtho == 1)
	{
		if (textBox1->Text == "" || textBox1->Text == "-")
		{
			OpenGL3->nonOrthoXAngle = previousNonOrthoXValue;
		}

		else
			OpenGL3->nonOrthoXAngle = (float)Convert::ToDouble(textBox1->Text);

		OpenGL3->nonOrthoXDiff = OpenGL3->nonOrthoXAngle - previousNonOrthoXValue;
		previousNonOrthoXValue = OpenGL3->nonOrthoXAngle;

	}*/

	
}


private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{	OpenGL3->nonLinearLesserThan = (float)Convert::ToDouble(textBox3->Text);
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{	OpenGL3->nonLinearGreaterThan = (float)Convert::ToDouble(textBox4->Text);
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox5_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkedListBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	if (checkedListBox4->CheckedItems->Count != 0)
	{
		for (int x = 0; x < checkedListBox4->CheckedItems->Count; x++)
		{
			if (checkedListBox4->CheckedIndices[x] == checkedListBox4->SelectedIndex)
			{
				OpenGL3->showHideClass(checkedListBox4->SelectedIndex, 0);
				break;
			}
			else
				OpenGL3->showHideClass(checkedListBox4->SelectedIndex, 255);
		}

	}

	else
		OpenGL3->showHideClass(checkedListBox4->SelectedIndex, 255);
	
}




private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) 
{
	OpenGL3->drawingAndRectEnabled = true;
	OpenGL3->drawingOrRectEnabled = false;
	//OpenGL3->clipAndData();
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) 
{

	OpenGL3->drawingOrRectEnabled = true;
	OpenGL3->drawingAndRectEnabled = false;
	
}
private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	/*if (checkBox3->Checked == true)
		OpenGL3->drawingOrRectComplete = true;*/
	if (checkBox3->Checked == true)
	{
		OpenGL3->clipOrData();
	}
	}
	
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) 
{
	OpenGL3->displayHdData();
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) 
{
	OpenGL3->reduceOcclusion();
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) 
{
	OpenGL3->automateClassification();
	label10->Text = OpenGL3->displayCoordinateLabels(data.covScore);
}
};
}



int OpenGL_on_a_Windows_Form::Form1::loadInteractiveSPC()
{
	if (fileopened) {
		graphType = 4;
		OpenGL3->graphType = 4;
		trackBar1->Value = graph4_oldZoom;
	}
	return 0;
} 


