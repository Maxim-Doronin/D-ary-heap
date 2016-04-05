#pragma once
#include "windows.h"
#include <stdio.h>
#include <vcclr.h>
#include <fstream>
#include <string>

namespace graphdrawing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::Glee::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Microsoft::Glee::GraphViewerGdi::GViewer^  gViewer1;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;





	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  random;
	private: System::Windows::Forms::TextBox^  minBox;
	private: System::Windows::Forms::TextBox^  maxBox;




	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  startBox;
	private: System::Windows::Forms::TextBox^  weightBox;


	private: System::Windows::Forms::TextBox^  endBox;

	private: System::Windows::Forms::Button^  addEdge;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  nextDijkstra;
	private: System::Windows::Forms::Button^  treeDijkstra;


	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  treeKruskal;

	private: System::Windows::Forms::Button^  nextKruskal;
	private: System::Windows::Forms::Button^  reset;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;






	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->gViewer1 = (gcnew Microsoft::Glee::GraphViewerGdi::GViewer());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->random = (gcnew System::Windows::Forms::Button());
			this->minBox = (gcnew System::Windows::Forms::TextBox());
			this->maxBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->startBox = (gcnew System::Windows::Forms::TextBox());
			this->weightBox = (gcnew System::Windows::Forms::TextBox());
			this->endBox = (gcnew System::Windows::Forms::TextBox());
			this->addEdge = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->nextDijkstra = (gcnew System::Windows::Forms::Button());
			this->treeDijkstra = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->treeKruskal = (gcnew System::Windows::Forms::Button());
			this->nextKruskal = (gcnew System::Windows::Forms::Button());
			this->reset = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// gViewer1
			// 
			this->gViewer1->AsyncLayout = false;
			this->gViewer1->AutoScroll = true;
			this->gViewer1->BackwardEnabled = false;
			this->gViewer1->ForwardEnabled = false;
			this->gViewer1->Graph = nullptr;
			this->gViewer1->Location = System::Drawing::Point(201, 12);
			this->gViewer1->MouseHitDistance = 0.05;
			this->gViewer1->Name = L"gViewer1";
			this->gViewer1->NavigationVisible = true;
			this->gViewer1->PanButtonPressed = false;
			this->gViewer1->SaveButtonVisible = true;
			this->gViewer1->Size = System::Drawing::Size(793, 647);
			this->gViewer1->TabIndex = 0;
			this->gViewer1->ZoomF = 1;
			this->gViewer1->ZoomFraction = 0.5;
			this->gViewer1->ZoomWindowThreshold = 0.05;
			this->gViewer1->Load += gcnew System::EventHandler(this, &Form1::gViewer1_Load);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(9, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Vertices";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(112, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Edges";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(50, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Weight ranges";
			// 
			// random
			// 
			this->random->Location = System::Drawing::Point(12, 118);
			this->random->Name = L"random";
			this->random->Size = System::Drawing::Size(172, 40);
			this->random->TabIndex = 8;
			this->random->Text = L"Random!";
			this->random->UseVisualStyleBackColor = true;
			this->random->Click += gcnew System::EventHandler(this, &Form1::random_Click);
			// 
			// minBox
			// 
			this->minBox->Location = System::Drawing::Point(12, 90);
			this->minBox->Name = L"minBox";
			this->minBox->Size = System::Drawing::Size(69, 22);
			this->minBox->TabIndex = 9;
			// 
			// maxBox
			// 
			this->maxBox->Location = System::Drawing::Point(115, 90);
			this->maxBox->Name = L"maxBox";
			this->maxBox->Size = System::Drawing::Size(69, 22);
			this->maxBox->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(9, 175);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Set edge:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(9, 192);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Start";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(71, 192);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(33, 17);
			this->label6->TabIndex = 13;
			this->label6->Text = L"End";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(134, 192);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(52, 17);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Weight";
			// 
			// startBox
			// 
			this->startBox->Location = System::Drawing::Point(12, 212);
			this->startBox->Name = L"startBox";
			this->startBox->Size = System::Drawing::Size(47, 22);
			this->startBox->TabIndex = 15;
			// 
			// weightBox
			// 
			this->weightBox->Location = System::Drawing::Point(137, 212);
			this->weightBox->Name = L"weightBox";
			this->weightBox->Size = System::Drawing::Size(47, 22);
			this->weightBox->TabIndex = 16;
			// 
			// endBox
			// 
			this->endBox->Location = System::Drawing::Point(74, 212);
			this->endBox->Name = L"endBox";
			this->endBox->Size = System::Drawing::Size(47, 22);
			this->endBox->TabIndex = 17;
			// 
			// addEdge
			// 
			this->addEdge->Location = System::Drawing::Point(12, 240);
			this->addEdge->Name = L"addEdge";
			this->addEdge->Size = System::Drawing::Size(172, 40);
			this->addEdge->TabIndex = 18;
			this->addEdge->Text = L"Add";
			this->addEdge->UseVisualStyleBackColor = true;
			this->addEdge->Click += gcnew System::EventHandler(this, &Form1::AddEdgeClick);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(9, 305);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(127, 17);
			this->label8->TabIndex = 19;
			this->label8->Text = L"Dijkstra\'s algorithm";
			// 
			// nextDijkstra
			// 
			this->nextDijkstra->Location = System::Drawing::Point(12, 325);
			this->nextDijkstra->Name = L"nextDijkstra";
			this->nextDijkstra->Size = System::Drawing::Size(80, 60);
			this->nextDijkstra->TabIndex = 20;
			this->nextDijkstra->Text = L"Next \r\nstep";
			this->nextDijkstra->UseVisualStyleBackColor = true;
			// 
			// treeDijkstra
			// 
			this->treeDijkstra->Location = System::Drawing::Point(104, 325);
			this->treeDijkstra->Name = L"treeDijkstra";
			this->treeDijkstra->Size = System::Drawing::Size(80, 60);
			this->treeDijkstra->TabIndex = 21;
			this->treeDijkstra->Text = L"Spanning tree";
			this->treeDijkstra->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(9, 407);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(127, 17);
			this->label9->TabIndex = 22;
			this->label9->Text = L"Kruskal\'s algorithm";
			// 
			// treeKruskal
			// 
			this->treeKruskal->Location = System::Drawing::Point(104, 427);
			this->treeKruskal->Name = L"treeKruskal";
			this->treeKruskal->Size = System::Drawing::Size(80, 60);
			this->treeKruskal->TabIndex = 24;
			this->treeKruskal->Text = L"Spanning tree";
			this->treeKruskal->UseVisualStyleBackColor = true;
			// 
			// nextKruskal
			// 
			this->nextKruskal->Location = System::Drawing::Point(12, 427);
			this->nextKruskal->Name = L"nextKruskal";
			this->nextKruskal->Size = System::Drawing::Size(80, 60);
			this->nextKruskal->TabIndex = 23;
			this->nextKruskal->Text = L"Next \r\nstep";
			this->nextKruskal->UseVisualStyleBackColor = true;
			// 
			// reset
			// 
			this->reset->Location = System::Drawing::Point(12, 517);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(172, 40);
			this->reset->TabIndex = 25;
			this->reset->Text = L"Reset";
			this->reset->UseVisualStyleBackColor = true;
			this->reset->Click += gcnew System::EventHandler(this, &Form1::ResetClick);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(12, 38);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(69, 22);
			this->numericUpDown1->TabIndex = 28;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(115, 38);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(69, 22);
			this->numericUpDown2->TabIndex = 29;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1006, 671);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->reset);
			this->Controls->Add(this->treeKruskal);
			this->Controls->Add(this->nextKruskal);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->treeDijkstra);
			this->Controls->Add(this->nextDijkstra);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->addEdge);
			this->Controls->Add(this->endBox);
			this->Controls->Add(this->weightBox);
			this->Controls->Add(this->startBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->maxBox);
			this->Controls->Add(this->minBox);
			this->Controls->Add(this->random);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->gViewer1);
			this->Name = L"Form1";
			this->Text = L"Graphs";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		static unsigned int vertices = 0;
		static unsigned int edges = 0;
		static float minRange;
		static float maxRange;
		
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

			 }
	private: System::Void gViewer1_Load(System::Object^  sender, System::EventArgs^  e) {

			 }
	private: System::Void graphUpd(){
				 using namespace std;
				 ifstream input("tree.txt");
				 int n, m;
				 input >> n;
				 input >> m;
				 vertices = n;
				 edges = m;
				 Graph ^g = gcnew Graph("graph");
				 for (int i = 0; i < vertices; i++)
					 g->AddNode(System::Convert::ToString(i));
				 int N, K;
				 float W;
				 for (int i = 0; i < edges; i++){
					 input >> N;
					 input >> K;
					 input >> W;
					 g->AddEdge(System::Convert::ToString(N),
								System::Convert::ToString(W),
								System::Convert::ToString(K));
				 }
				 gViewer1->Graph = g;
				 input.close();
			 
			 }
	private: System::Void nBox_SelectedItemChanged(System::Object^  sender, System::EventArgs^  e) {

			 }

	private: System::Void random_Click(System::Object^  sender, System::EventArgs^  e) {
				 vertices = (unsigned int)numericUpDown1->Value;
				 edges = (unsigned int)numericUpDown2->Value;
				 System::String^ minRangeText;
				 minRangeText = minBox->Text;
				 minRange = (float)(Convert::ToDouble(minRangeText));
				 System::String^ maxRangeText;
				 maxRangeText = maxBox->Text;
				 maxRange = (float)(Convert::ToDouble(maxRangeText));

				 System::String^ pathToExec = "Kruskal_sample.exe";
				 System::String^ verticesText = System::Convert::ToString(vertices);
				 System::String^ edgesText = System::Convert::ToString(edges);

				 System::String^ fullCommandLine = System::String::Concat(pathToExec, " ");
				 fullCommandLine = System::String::Concat(fullCommandLine, verticesText, " ");
				 fullCommandLine = System::String::Concat(fullCommandLine, edgesText, " ");
				 fullCommandLine = System::String::Concat(fullCommandLine, minRangeText, " ");
				 fullCommandLine = System::String::Concat(fullCommandLine, maxRangeText);

				 IntPtr hglob = Marshal::StringToHGlobalAnsi(fullCommandLine);
				 char* msg = static_cast<char*>(hglob.ToPointer());
				
				 STARTUPINFO si;
				 PROCESS_INFORMATION pi;
				 ZeroMemory(&pi, sizeof(pi));
				 ZeroMemory(&si, sizeof(STARTUPINFO));

				 if (CreateProcess(
					 0,
					 msg,
					 0, 
					 0, 
					 TRUE, 
					 0, 
					 0, 
					 0, 
					 &si, 
					 &pi))
				 {
					 WaitForSingleObject(pi.hProcess, INFINITE);
				 }
				 CloseHandle(pi.hProcess);
				 CloseHandle(pi.hThread);
				 graphUpd();
			 };
	
	private: System::Void AddEdgeClick(System::Object^  sender, System::EventArgs^  e) {
				 using namespace std;

				 int newN = (int)(Convert::ToInt32(startBox->Text));
				 int newK = (int)(Convert::ToInt32(endBox->Text));
				 float newWeight = (float)(Convert::ToDouble(weightBox->Text));

				 fstream input;
				 input.open("tree.txt", fstream::in | fstream::out);
				 if(!input){
					 ofstream ofs("tree.txt");		
					 ofs.close();
				 }
				 
				 
				 remove("graph.txt");
				 ofstream graph("graph.txt");			
				 
				 int n = 0, m = 0;
				 input >> n;
				 input >> m;
				 
				 if ((newN >= n)||(newK >= n))
					 n = max(newN + 1, newK + 1);

				 graph << n << ' ' << m + 1 << endl;

				 int N, K;
				 float weight;
				 for (int j = 0; j < m; j++) {
					 input >> N;
					 input >> K;
					 input >> weight;
					 graph << N << ' ' << K << ' ' << weight << endl;
				 }
				 		 
				 graph << newN << ' ' << newK << ' ' << newWeight;

				 input.close();
				 graph.close();


				 System::String^ pathToExec = "Kruskal_sample.exe";
				 System::String^ sourseGraph = "../../graph-drawing/graph-drawing/graph.txt";
			 	 System::String^ fullCommandLine = System::String::Concat(pathToExec, " ", 	sourseGraph);	 

				 IntPtr hglob = Marshal::StringToHGlobalAnsi(fullCommandLine);
				 char* msg = static_cast<char*>(hglob.ToPointer());
				
				 STARTUPINFO si;
				 PROCESS_INFORMATION pi;
				 ZeroMemory(&pi, sizeof(pi));
				 ZeroMemory(&si, sizeof(STARTUPINFO));

				 if (CreateProcess(
					 0,
					 msg,
					 0, 
					 0, 
					 TRUE, 
					 0, 
					 0, 
					 0, 
					 &si, 
					 &pi))
				 {
					 WaitForSingleObject(pi.hProcess, INFINITE);
				 }
				 CloseHandle(pi.hProcess);
				 CloseHandle(pi.hThread);
				 graphUpd();
			 }


	private: System::Void ResetClick(System::Object^  sender, System::EventArgs^  e) {
				 Graph ^g = gcnew Graph("graph");
				 gViewer1->Graph = g;
			 }
};
}

