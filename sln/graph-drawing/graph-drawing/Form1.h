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
	private: System::Windows::Forms::Label^  verticesLbl;
	private: System::Windows::Forms::Label^  edgeLbl;
	private: System::Windows::Forms::Label^  weightRangesLbl;
	private: System::Windows::Forms::Button^  random;
	private: System::Windows::Forms::TextBox^  minBox;
	private: System::Windows::Forms::TextBox^  maxBox;
	private: System::Windows::Forms::Label^  setEdgeLbl;
	private: System::Windows::Forms::Label^  startLbl;
	private: System::Windows::Forms::Label^  endLbl;
	private: System::Windows::Forms::Label^  weightLbl;
	private: System::Windows::Forms::TextBox^  startBox;
	private: System::Windows::Forms::TextBox^  weightBox;
	private: System::Windows::Forms::TextBox^  endBox;
	private: System::Windows::Forms::Button^  addEdge;
	private: System::Windows::Forms::Label^  DijkstraLbl;

	private: System::Windows::Forms::Button^  treeDijkstra;
	private: System::Windows::Forms::Label^  KruskalLbl;
	private: System::Windows::Forms::Button^  treeKruskal;
	private: System::Windows::Forms::Button^  nextKruskal;
	private: System::Windows::Forms::Button^  cleanBtm;
	private: System::Windows::Forms::NumericUpDown^  verticesUpDown;
	private: System::Windows::Forms::NumericUpDown^  edgesUpDown;


	private: System::Windows::Forms::Button^  resetBtm;
	private: System::Windows::Forms::TextBox^  startDijBox;
	private: System::Windows::Forms::Label^  startDijLbl;

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
			this->verticesLbl = (gcnew System::Windows::Forms::Label());
			this->edgeLbl = (gcnew System::Windows::Forms::Label());
			this->weightRangesLbl = (gcnew System::Windows::Forms::Label());
			this->random = (gcnew System::Windows::Forms::Button());
			this->minBox = (gcnew System::Windows::Forms::TextBox());
			this->maxBox = (gcnew System::Windows::Forms::TextBox());
			this->setEdgeLbl = (gcnew System::Windows::Forms::Label());
			this->startLbl = (gcnew System::Windows::Forms::Label());
			this->endLbl = (gcnew System::Windows::Forms::Label());
			this->weightLbl = (gcnew System::Windows::Forms::Label());
			this->startBox = (gcnew System::Windows::Forms::TextBox());
			this->weightBox = (gcnew System::Windows::Forms::TextBox());
			this->endBox = (gcnew System::Windows::Forms::TextBox());
			this->addEdge = (gcnew System::Windows::Forms::Button());
			this->DijkstraLbl = (gcnew System::Windows::Forms::Label());
			this->treeDijkstra = (gcnew System::Windows::Forms::Button());
			this->KruskalLbl = (gcnew System::Windows::Forms::Label());
			this->treeKruskal = (gcnew System::Windows::Forms::Button());
			this->nextKruskal = (gcnew System::Windows::Forms::Button());
			this->cleanBtm = (gcnew System::Windows::Forms::Button());
			this->verticesUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->edgesUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->resetBtm = (gcnew System::Windows::Forms::Button());
			this->startDijBox = (gcnew System::Windows::Forms::TextBox());
			this->startDijLbl = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->verticesUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->edgesUpDown))->BeginInit();
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
			this->gViewer1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			// verticesLbl
			// 
			this->verticesLbl->AutoSize = true;
			this->verticesLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->verticesLbl->Location = System::Drawing::Point(9, 18);
			this->verticesLbl->Name = L"verticesLbl";
			this->verticesLbl->Size = System::Drawing::Size(59, 17);
			this->verticesLbl->TabIndex = 2;
			this->verticesLbl->Text = L"Vertices";
			// 
			// edgeLbl
			// 
			this->edgeLbl->AutoSize = true;
			this->edgeLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->edgeLbl->Location = System::Drawing::Point(112, 18);
			this->edgeLbl->Name = L"edgeLbl";
			this->edgeLbl->Size = System::Drawing::Size(48, 17);
			this->edgeLbl->TabIndex = 3;
			this->edgeLbl->Text = L"Edges";
			// 
			// weightRangesLbl
			// 
			this->weightRangesLbl->AutoSize = true;
			this->weightRangesLbl->Location = System::Drawing::Point(51, 71);
			this->weightRangesLbl->Name = L"weightRangesLbl";
			this->weightRangesLbl->Size = System::Drawing::Size(95, 16);
			this->weightRangesLbl->TabIndex = 7;
			this->weightRangesLbl->Text = L"Weight ranges";
			// 
			// random
			// 
			this->random->Location = System::Drawing::Point(12, 118);
			this->random->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->random->Name = L"random";
			this->random->Size = System::Drawing::Size(172, 39);
			this->random->TabIndex = 8;
			this->random->Text = L"Random!";
			this->random->UseVisualStyleBackColor = true;
			this->random->Click += gcnew System::EventHandler(this, &Form1::random_Click);
			// 
			// minBox
			// 
			this->minBox->Location = System::Drawing::Point(12, 90);
			this->minBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->minBox->Name = L"minBox";
			this->minBox->Size = System::Drawing::Size(69, 22);
			this->minBox->TabIndex = 9;
			// 
			// maxBox
			// 
			this->maxBox->Location = System::Drawing::Point(115, 90);
			this->maxBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->maxBox->Name = L"maxBox";
			this->maxBox->Size = System::Drawing::Size(69, 22);
			this->maxBox->TabIndex = 10;
			// 
			// setEdgeLbl
			// 
			this->setEdgeLbl->AutoSize = true;
			this->setEdgeLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->setEdgeLbl->Location = System::Drawing::Point(9, 175);
			this->setEdgeLbl->Name = L"setEdgeLbl";
			this->setEdgeLbl->Size = System::Drawing::Size(69, 17);
			this->setEdgeLbl->TabIndex = 11;
			this->setEdgeLbl->Text = L"Set edge:";
			// 
			// startLbl
			// 
			this->startLbl->AutoSize = true;
			this->startLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->startLbl->Location = System::Drawing::Point(9, 192);
			this->startLbl->Name = L"startLbl";
			this->startLbl->Size = System::Drawing::Size(38, 17);
			this->startLbl->TabIndex = 12;
			this->startLbl->Text = L"Start";
			// 
			// endLbl
			// 
			this->endLbl->AutoSize = true;
			this->endLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->endLbl->Location = System::Drawing::Point(71, 192);
			this->endLbl->Name = L"endLbl";
			this->endLbl->Size = System::Drawing::Size(33, 17);
			this->endLbl->TabIndex = 13;
			this->endLbl->Text = L"End";
			// 
			// weightLbl
			// 
			this->weightLbl->AutoSize = true;
			this->weightLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->weightLbl->Location = System::Drawing::Point(133, 192);
			this->weightLbl->Name = L"weightLbl";
			this->weightLbl->Size = System::Drawing::Size(52, 17);
			this->weightLbl->TabIndex = 14;
			this->weightLbl->Text = L"Weight";
			// 
			// startBox
			// 
			this->startBox->Location = System::Drawing::Point(12, 212);
			this->startBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->startBox->Name = L"startBox";
			this->startBox->Size = System::Drawing::Size(47, 22);
			this->startBox->TabIndex = 15;
			// 
			// weightBox
			// 
			this->weightBox->Location = System::Drawing::Point(137, 212);
			this->weightBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->weightBox->Name = L"weightBox";
			this->weightBox->Size = System::Drawing::Size(47, 22);
			this->weightBox->TabIndex = 16;
			// 
			// endBox
			// 
			this->endBox->Location = System::Drawing::Point(75, 212);
			this->endBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->endBox->Name = L"endBox";
			this->endBox->Size = System::Drawing::Size(47, 22);
			this->endBox->TabIndex = 17;
			// 
			// addEdge
			// 
			this->addEdge->Location = System::Drawing::Point(12, 240);
			this->addEdge->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addEdge->Name = L"addEdge";
			this->addEdge->Size = System::Drawing::Size(172, 39);
			this->addEdge->TabIndex = 18;
			this->addEdge->Text = L"Add";
			this->addEdge->UseVisualStyleBackColor = true;
			this->addEdge->Click += gcnew System::EventHandler(this, &Form1::AddEdgeClick);
			// 
			// DijkstraLbl
			// 
			this->DijkstraLbl->AutoSize = true;
			this->DijkstraLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->DijkstraLbl->Location = System::Drawing::Point(9, 320);
			this->DijkstraLbl->Name = L"DijkstraLbl";
			this->DijkstraLbl->Size = System::Drawing::Size(127, 17);
			this->DijkstraLbl->TabIndex = 19;
			this->DijkstraLbl->Text = L"Dijkstra\'s algorithm";
			// 
			// treeDijkstra
			// 
			this->treeDijkstra->Location = System::Drawing::Point(104, 339);
			this->treeDijkstra->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->treeDijkstra->Name = L"treeDijkstra";
			this->treeDijkstra->Size = System::Drawing::Size(80, 60);
			this->treeDijkstra->TabIndex = 21;
			this->treeDijkstra->Text = L"Spanning tree";
			this->treeDijkstra->UseVisualStyleBackColor = true;
			this->treeDijkstra->Click += gcnew System::EventHandler(this, &Form1::treeDijkstra_Click);
			// 
			// KruskalLbl
			// 
			this->KruskalLbl->AutoSize = true;
			this->KruskalLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->KruskalLbl->Location = System::Drawing::Point(9, 421);
			this->KruskalLbl->Name = L"KruskalLbl";
			this->KruskalLbl->Size = System::Drawing::Size(127, 17);
			this->KruskalLbl->TabIndex = 22;
			this->KruskalLbl->Text = L"Kruskal\'s algorithm";
			// 
			// treeKruskal
			// 
			this->treeKruskal->Location = System::Drawing::Point(104, 441);
			this->treeKruskal->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->treeKruskal->Name = L"treeKruskal";
			this->treeKruskal->Size = System::Drawing::Size(80, 60);
			this->treeKruskal->TabIndex = 24;
			this->treeKruskal->Text = L"Spanning tree";
			this->treeKruskal->UseVisualStyleBackColor = true;
			this->treeKruskal->Click += gcnew System::EventHandler(this, &Form1::treeKruskal_Click);
			// 
			// nextKruskal
			// 
			this->nextKruskal->Location = System::Drawing::Point(12, 441);
			this->nextKruskal->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->nextKruskal->Name = L"nextKruskal";
			this->nextKruskal->Size = System::Drawing::Size(80, 60);
			this->nextKruskal->TabIndex = 23;
			this->nextKruskal->Text = L"Next \r\nstep";
			this->nextKruskal->UseVisualStyleBackColor = true;
			this->nextKruskal->Click += gcnew System::EventHandler(this, &Form1::nextKruskal_Click);
			// 
			// cleanBtm
			// 
			this->cleanBtm->Location = System::Drawing::Point(12, 595);
			this->cleanBtm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cleanBtm->Name = L"cleanBtm";
			this->cleanBtm->Size = System::Drawing::Size(172, 39);
			this->cleanBtm->TabIndex = 25;
			this->cleanBtm->Text = L"Clean";
			this->cleanBtm->UseVisualStyleBackColor = true;
			this->cleanBtm->Click += gcnew System::EventHandler(this, &Form1::CleanClick);
			// 
			// verticesUpDown
			// 
			this->verticesUpDown->Location = System::Drawing::Point(12, 38);
			this->verticesUpDown->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->verticesUpDown->Name = L"verticesUpDown";
			this->verticesUpDown->Size = System::Drawing::Size(69, 22);
			this->verticesUpDown->TabIndex = 28;
			// 
			// edgesUpDown
			// 
			this->edgesUpDown->Location = System::Drawing::Point(115, 38);
			this->edgesUpDown->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->edgesUpDown->Name = L"edgesUpDown";
			this->edgesUpDown->Size = System::Drawing::Size(69, 22);
			this->edgesUpDown->TabIndex = 29;
			// 
			// resetBtm
			// 
			this->resetBtm->Location = System::Drawing::Point(12, 549);
			this->resetBtm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->resetBtm->Name = L"resetBtm";
			this->resetBtm->Size = System::Drawing::Size(172, 39);
			this->resetBtm->TabIndex = 30;
			this->resetBtm->Text = L"Reset";
			this->resetBtm->UseVisualStyleBackColor = true;
			this->resetBtm->Click += gcnew System::EventHandler(this, &Form1::ResetClick);
			// 
			// startDijBox
			// 
			this->startDijBox->Location = System::Drawing::Point(29, 367);
			this->startDijBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->startDijBox->Name = L"startDijBox";
			this->startDijBox->Size = System::Drawing::Size(47, 22);
			this->startDijBox->TabIndex = 32;
			// 
			// startDijLbl
			// 
			this->startDijLbl->AutoSize = true;
			this->startDijLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->startDijLbl->Location = System::Drawing::Point(34, 346);
			this->startDijLbl->Name = L"startDijLbl";
			this->startDijLbl->Size = System::Drawing::Size(38, 17);
			this->startDijLbl->TabIndex = 31;
			this->startDijLbl->Text = L"Start";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1005, 671);
			this->Controls->Add(this->startDijBox);
			this->Controls->Add(this->startDijLbl);
			this->Controls->Add(this->resetBtm);
			this->Controls->Add(this->edgesUpDown);
			this->Controls->Add(this->verticesUpDown);
			this->Controls->Add(this->cleanBtm);
			this->Controls->Add(this->treeKruskal);
			this->Controls->Add(this->nextKruskal);
			this->Controls->Add(this->KruskalLbl);
			this->Controls->Add(this->treeDijkstra);
			this->Controls->Add(this->DijkstraLbl);
			this->Controls->Add(this->addEdge);
			this->Controls->Add(this->endBox);
			this->Controls->Add(this->weightBox);
			this->Controls->Add(this->startBox);
			this->Controls->Add(this->weightLbl);
			this->Controls->Add(this->endLbl);
			this->Controls->Add(this->startLbl);
			this->Controls->Add(this->setEdgeLbl);
			this->Controls->Add(this->maxBox);
			this->Controls->Add(this->minBox);
			this->Controls->Add(this->random);
			this->Controls->Add(this->weightRangesLbl);
			this->Controls->Add(this->edgeLbl);
			this->Controls->Add(this->verticesLbl);
			this->Controls->Add(this->gViewer1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form1";
			this->Text = L"Graphs";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->verticesUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->edgesUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		static unsigned int vertices = 0;
		static unsigned int edges = 0;
		static float minRange;
		System::String^ minRangeText;
		static float maxRange;
		System::String^ maxRangeText;
		static System::String^ startText = "0";

		Graph ^g;
		Graph ^t;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 startDijBox->Text = "0";
				 g = gcnew Graph("graph");
				 t = gcnew Graph("tree");
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
				 
				 delete gViewer1->Graph;
				 g = gcnew Graph("graph");
				 g->GraphAttr->EdgeAttr->ArrowHeadAtTarget = Microsoft::Glee::Drawing::ArrowStyle::None;
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
			 
	private: System::Void createFile() {
				 using namespace std;
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

				 graph << n << ' ' << m;

				 int N, K;
				 float weight;
				 for (int j = 0; j < m; j++) {
					 graph << endl;
					 input >> N;
					 input >> K;
					 input >> weight;
					 graph << N << ' ' << K << ' ' << weight;
				 }
				 input.close();
				 graph.close();
			  }

	private: int createProcRandom(System::String^ pathToExec) {
				 System::String^ verticesText = System::Convert::ToString(vertices);
				 System::String^ edgesText = System::Convert::ToString(edges);

				 System::String^ fullCommandLineStr = System::String::Concat(pathToExec, " ");
				 fullCommandLineStr = System::String::Concat(fullCommandLineStr, verticesText, " ");
				 fullCommandLineStr = System::String::Concat(fullCommandLineStr, edgesText, " ");
				 fullCommandLineStr = System::String::Concat(fullCommandLineStr, minRangeText, " ");
				 fullCommandLineStr = System::String::Concat(fullCommandLineStr, maxRangeText);
				 if (pathToExec == "Dijkstra_sample.exe"){
					 startText = startDijBox->Text;
					 fullCommandLineStr = System::String::Concat(fullCommandLineStr, " ", startText);
				 }
				 IntPtr hglob = Marshal::StringToHGlobalAnsi(fullCommandLineStr);
				 char* fullCommandLine = static_cast<char*>(hglob.ToPointer());
				
				 STARTUPINFO si;
				 PROCESS_INFORMATION pi;
				 ZeroMemory(&pi, sizeof(pi));
				 ZeroMemory(&si, sizeof(STARTUPINFO));

				 if (CreateProcess(0, fullCommandLine, 0, 0, TRUE, 0, 0, 0, &si, &pi))
					 WaitForSingleObject(pi.hProcess, INFINITE);
				 else {
					 CloseHandle(pi.hProcess);
					 CloseHandle(pi.hThread);
					 return -1;
				 }
				 
				 DWORD exitCode;					 
				 GetExitCodeProcess(pi.hProcess, &exitCode);
				 if (exitCode) {
					 System::String^ message = "Error!\nSomething went wrong!";
					 System::String^ caption = "Error";
					 MessageBox::Show(message, caption, MessageBoxButtons::OK, MessageBoxIcon::Question);
					 return -2;
				 }
				 CloseHandle(pi.hProcess);
				 CloseHandle(pi.hThread);
				 return 0;
			 }

	private: int createProcFile(System::String^ pathToExec, System::String^ sourseGraph) {
				 System::String^ fullCommandLineStr = System::String::Concat(pathToExec, " ", 	sourseGraph);	 
				 if (pathToExec == "Dijkstra_sample.exe"){
					 startText = startDijBox->Text;
					 fullCommandLineStr = System::String::Concat(fullCommandLineStr, " ", startText);
				 }
				 IntPtr hglob = Marshal::StringToHGlobalAnsi(fullCommandLineStr);
				 char* fullCommandLine = static_cast<char*>(hglob.ToPointer());
				
				 STARTUPINFO si;
				 PROCESS_INFORMATION pi;
				 ZeroMemory(&pi, sizeof(pi));
				 ZeroMemory(&si, sizeof(STARTUPINFO));

				 if (CreateProcess(0, fullCommandLine, 0, 0, TRUE, 0, 0, 0, &si, &pi))
					 WaitForSingleObject(pi.hProcess, INFINITE);
				 else {
					 CloseHandle(pi.hProcess);
					 CloseHandle(pi.hThread);
					 return -1;
				 }

				 DWORD exitCode;					 
				 GetExitCodeProcess(pi.hProcess, &exitCode);
				 if (exitCode) {
					 System::String^ message = "Error!\nSomething went wrong!";
					 System::String^ caption = "Error";
					 MessageBox::Show(message, caption, MessageBoxButtons::OK, MessageBoxIcon::Question);
					 return -2;
				 }
				 CloseHandle(pi.hProcess);
				 CloseHandle(pi.hThread);
				 return 0;
			 }
	
	private: System::Void random_Click(System::Object^  sender, System::EventArgs^  e) {
				 nextKruskal->Enabled = true;
				 treeKruskal->Enabled = true;
				 vertices = (unsigned int)verticesUpDown->Value;
				 edges = (unsigned int)edgesUpDown->Value;
				 try {
					 minRangeText = minBox->Text;
					 minRange = (float)(Convert::ToDouble(minRangeText));
					 maxRangeText = maxBox->Text;
					 maxRange = (float)(Convert::ToDouble(maxRangeText));
				 }
				 catch(...) {
					 System::String^ message = "Error!\nInvalid ranges!";
					 System::String^ caption = "Error";
					 MessageBox::Show(message, caption, MessageBoxButtons::OK, MessageBoxIcon::Question);
					 return;
				 }

				 System::String^ pathToExec1 = "Kruskal_sample.exe";
				 if (createProcRandom(pathToExec1))
					 return;
				 System::String^ pathToExec2 = "Dijkstra_sample.exe";
				 if (createProcRandom(pathToExec2))
					 return;
				 graphUpd();
			 };
	
	private: System::Void AddEdgeClick(System::Object^  sender, System::EventArgs^  e) {
				 nextKruskal->Enabled = true;
				 treeKruskal->Enabled = true;
				 using namespace std;
				 int newN;
				 int newK;
				 float newWeight;
				 try {
					 newN = (int)(Convert::ToInt32(startBox->Text));
					 newK = (int)(Convert::ToInt32(endBox->Text));
					 newWeight = (float)(Convert::ToDouble(weightBox->Text));
				 }
				 catch(...) {
					 System::String^ message = "Error!\nInvalid parametrs for edge!";
					 System::String^ caption = "Error";
					 MessageBox::Show(message, caption, MessageBoxButtons::OK, MessageBoxIcon::Question);
					 return;
				 }

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
				
				 vertices = n;
				 edges = m + 1;

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

				 System::String^ sourseGraph = "graph.txt";
			 	 System::String^ pathToExec1 = "Kruskal_sample.exe";
				 if (createProcFile(pathToExec1, sourseGraph))
					 return;
				 System::String^ pathToExec2 = "Dijkstra_sample.exe";
				 if (createProcFile(pathToExec2, sourseGraph))
					 return;
				 graphUpd();
			 }

	private: System::Void treeKruskal_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!gViewer1->Graph)
					 try {
						 random_Click(sender, e);
					 }
					 catch(...) {
						 return;
					 }
				 ResetClick(sender, e);
				 Graph ^g = gViewer1->Graph;
				 for (int i = 0; i < vertices - 1; i++)
					 nextKruskal_Click(sender, e);
				 nextKruskal->Enabled = false;
				 treeKruskal->Enabled = false;
			 }

	private: System::Void nextKruskal_Click(System::Object^  sender, System::EventArgs^  e) {
				 using namespace std;
				 ifstream input("tree.txt");
				 int n, m;
				 input >> n;
				 input >> m;
				 vertices = n;
				 edges = m;
				 
				 if (!gViewer1->Graph)
					 try {
						 random_Click(sender, e);
					 }
					 catch(...) {
						 return;
					 }
				 Graph ^g = gViewer1->Graph;
				 g->GraphAttr->EdgeAttr->ArrowHeadAtTarget = Microsoft::Glee::Drawing::ArrowStyle::None;

				 int N, K;
				 float weight;
				 for (int i = 0; i < edges; i++){
					 input >> N;
					 input >> K;
					 input >> weight;
				 }
				 while(!input.eof()){
					 input >> N;
					 input >> K;
					 input >> weight;
					 for (int i = 0; i < g->Edges->Count; i++) {
						 Edge^ edge = g->Edges[i];
						 if ((g->Edges[i]->Source == System::Convert::ToString(N)) && (g->Edges[i]->Target == System::Convert::ToString(K)) ||
							  (g->Edges[i]->Source == System::Convert::ToString(K)) && (g->Edges[i]->Target == System::Convert::ToString(N)))
							  
							 if (g->Edges[i]->Attr->Color != Microsoft::Glee::Drawing::Color::Red){
								 g->Edges[i]->Attr->Color = Microsoft::Glee::Drawing::Color::Red;
								 g->Edges[i]->Attr->LineWidth = 2;
								 gViewer1->Graph = g;
								 input.close();
								 return;
							 }
					 }
				 }
				 nextKruskal->Enabled = false;
				 treeKruskal->Enabled = false;
				 gViewer1->Graph = g;
				 input.close(); 
			 }

	private: System::Void ResetClick(System::Object^  sender, System::EventArgs^  e) {
				 nextKruskal->Enabled = true;
				 treeKruskal->Enabled = true;
				 graphUpd();
			 }

	private: System::Void CleanClick(System::Object^  sender, System::EventArgs^  e) {
				 nextKruskal->Enabled = true;
				 treeKruskal->Enabled = true;
				 delete gViewer1->Graph;
				 Graph ^g = gcnew Graph("graph");
				 gViewer1->Graph = g;
			 }
	
	private: System::Void treeDijkstra_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!gViewer1->Graph)
					 try {
						 random_Click(sender, e);
					 }
					 catch(...) {
						 return;
					 }
				 ResetClick(sender, e);
				 
				 createFile();
				 System::String^ sourseGraph = "graph.txt";
				 System::String^ pathToExec2 = "Dijkstra_sample.exe";
				 createProcFile(pathToExec2, sourseGraph);

				 using namespace std;
				 ifstream input("ways.txt");
				 int n, m, s;
				 input >> n;
				 input >> m;
				 input >> s;
				 vertices = n;
				 edges = m;

				 Graph ^g = gViewer1->Graph;
				 g->GraphAttr->EdgeAttr->ArrowHeadAtTarget = Microsoft::Glee::Drawing::ArrowStyle::None;

				 int N, K;
				 float weight;
				 for (int i = 0; i < edges; i++){
					 input >> N;
					 input >> K;
					 input >> weight;
				 }
				 
				 float dist;
				 int up;
				 while(!input.eof()){
					 input >> N;
					 input >> dist;
					 input >> up;

					 Node^ node = g->FindNode(System::Convert::ToString(N));
					 node->Attr->Label  = System::String::Concat(System::Convert::ToString(N), " : ", System::Convert::ToString(dist));
					 node->Attr->Fillcolor = Microsoft::Glee::Drawing::Color::White;

					 for (int i = 0; i < g->Edges->Count; i++) {
						 Edge^ edge = g->Edges[i];
						 if ((g->Edges[i]->Source == System::Convert::ToString(N)) && (g->Edges[i]->Target == System::Convert::ToString(up))) {
							 g->Edges[i]->Attr->ArrowHeadAtSource = Microsoft::Glee::Drawing::ArrowStyle::Normal;
							 g->Edges[i]->Attr->LineWidth = 2;
							 g->Edges[i]->Attr->Color = Microsoft::Glee::Drawing::Color::Green;
						 }
						 if ((g->Edges[i]->Source == System::Convert::ToString(up)) && (g->Edges[i]->Target == System::Convert::ToString(N))){
							 g->Edges[i]->Attr->ArrowHeadAtTarget = Microsoft::Glee::Drawing::ArrowStyle::Normal;
							 g->Edges[i]->Attr->LineWidth = 2;
							 g->Edges[i]->Attr->Color = Microsoft::Glee::Drawing::Color::Green;
						 }
					 }
				 }
				 g->FindNode(System::Convert::ToString(s))->Attr->Fillcolor = Microsoft::Glee::Drawing::Color::Yellow;
				 gViewer1->Graph = g;
				 input.close(); 
			 }
};
}

