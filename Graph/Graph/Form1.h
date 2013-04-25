#pragma once
#include <msclr\marshal_cppstd.h>
#include <string>
#include "GraphType.h"

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	struct Vertex {
		string name;
		int x;
		int y;
		
		bool operator==(Vertex v) {
			return (name == v.name);
		}

		void operator=(Vertex v) {
			name = v.name;
			x = v.x;
			y = v.y;
		}
	};

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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


	private: System::Windows::Forms::TextBox^  vertexName;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  vertexX;
	private: System::Windows::Forms::TextBox^  vertexY;

	private: System::Windows::Forms::TextBox^  weight;
	private: System::Windows::Forms::TextBox^  toVertex;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  fromVertex;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  quitToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  vertexToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addUpdateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  edgeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addUpdateToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  analyzeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  isConnectedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  minimumSpanningTreeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  shortestPathToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  adjMatrixTextBox;
	private: System::Windows::Forms::Button^  prev;
	private: System::Windows::Forms::Button^  next;
	private: System::Windows::Forms::ToolStripMenuItem^  resetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  depthFirstSearchToolStripMenuItem;


			 GraphType<Vertex, int>* graph;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->vertexName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->vertexX = (gcnew System::Windows::Forms::TextBox());
			this->vertexY = (gcnew System::Windows::Forms::TextBox());
			this->weight = (gcnew System::Windows::Forms::TextBox());
			this->toVertex = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->fromVertex = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vertexToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addUpdateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->edgeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addUpdateToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->analyzeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->isConnectedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->minimumSpanningTreeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->shortestPathToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->adjMatrixTextBox = (gcnew System::Windows::Forms::TextBox());
			this->prev = (gcnew System::Windows::Forms::Button());
			this->next = (gcnew System::Windows::Forms::Button());
			this->depthFirstSearchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// vertexName
			// 
			this->vertexName->Location = System::Drawing::Point(738, 39);
			this->vertexName->Name = L"vertexName";
			this->vertexName->Size = System::Drawing::Size(115, 20);
			this->vertexName->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(666, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Vertex Label";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(666, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Vertex X:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(666, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Vertex Y:";
			// 
			// vertexX
			// 
			this->vertexX->Location = System::Drawing::Point(738, 58);
			this->vertexX->Name = L"vertexX";
			this->vertexX->Size = System::Drawing::Size(115, 20);
			this->vertexX->TabIndex = 6;
			// 
			// vertexY
			// 
			this->vertexY->Location = System::Drawing::Point(738, 76);
			this->vertexY->Name = L"vertexY";
			this->vertexY->Size = System::Drawing::Size(115, 20);
			this->vertexY->TabIndex = 7;
			// 
			// weight
			// 
			this->weight->Location = System::Drawing::Point(738, 139);
			this->weight->Name = L"weight";
			this->weight->Size = System::Drawing::Size(115, 20);
			this->weight->TabIndex = 15;
			// 
			// toVertex
			// 
			this->toVertex->Location = System::Drawing::Point(738, 121);
			this->toVertex->Name = L"toVertex";
			this->toVertex->Size = System::Drawing::Size(115, 20);
			this->toVertex->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(666, 139);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Weight:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(666, 121);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"To Vertex:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(666, 105);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"From Vertex:";
			// 
			// fromVertex
			// 
			this->fromVertex->Location = System::Drawing::Point(738, 102);
			this->fromVertex->Name = L"fromVertex";
			this->fromVertex->Size = System::Drawing::Size(115, 20);
			this->fromVertex->TabIndex = 10;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->fileToolStripMenuItem, 
				this->vertexToolStripMenuItem, this->edgeToolStripMenuItem, this->analyzeToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(867, 24);
			this->menuStrip1->TabIndex = 20;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->resetToolStripMenuItem, 
			this->loadToolStripMenuItem, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->quitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->DropDownClosed += gcnew System::EventHandler(this, &Form1::analyzeToolStripMenuItem_DropDownClosed);
			// 
			// resetToolStripMenuItem
			// 
			this->resetToolStripMenuItem->Name = L"resetToolStripMenuItem";
			this->resetToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->resetToolStripMenuItem->Text = L"New";
			this->resetToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::resetToolStripMenuItem_Click);
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->loadToolStripMenuItem->Text = L"Open File...";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::loadToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As...";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsToolStripMenuItem_Click);
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->quitToolStripMenuItem->Text = L"Quit";
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::quitToolStripMenuItem_Click);
			// 
			// vertexToolStripMenuItem
			// 
			this->vertexToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->addUpdateToolStripMenuItem, 
				this->deleteToolStripMenuItem});
			this->vertexToolStripMenuItem->Name = L"vertexToolStripMenuItem";
			this->vertexToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->vertexToolStripMenuItem->Text = L"Vertex";
			this->vertexToolStripMenuItem->DropDownClosed += gcnew System::EventHandler(this, &Form1::vertexToolStripMenuItem_DropDownClosed);
			// 
			// addUpdateToolStripMenuItem
			// 
			this->addUpdateToolStripMenuItem->Name = L"addUpdateToolStripMenuItem";
			this->addUpdateToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->addUpdateToolStripMenuItem->Text = L"Add/Update";
			this->addUpdateToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::addUpdateToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::deleteToolStripMenuItem_Click);
			// 
			// edgeToolStripMenuItem
			// 
			this->edgeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->addUpdateToolStripMenuItem1, 
				this->deleteToolStripMenuItem1});
			this->edgeToolStripMenuItem->Name = L"edgeToolStripMenuItem";
			this->edgeToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->edgeToolStripMenuItem->Text = L"Edge";
			this->edgeToolStripMenuItem->DropDownClosed += gcnew System::EventHandler(this, &Form1::vertexToolStripMenuItem_DropDownClosed);
			// 
			// addUpdateToolStripMenuItem1
			// 
			this->addUpdateToolStripMenuItem1->Name = L"addUpdateToolStripMenuItem1";
			this->addUpdateToolStripMenuItem1->Size = System::Drawing::Size(139, 22);
			this->addUpdateToolStripMenuItem1->Text = L"Add/Update";
			this->addUpdateToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::addUpdateToolStripMenuItem1_Click);
			// 
			// deleteToolStripMenuItem1
			// 
			this->deleteToolStripMenuItem1->Name = L"deleteToolStripMenuItem1";
			this->deleteToolStripMenuItem1->Size = System::Drawing::Size(139, 22);
			this->deleteToolStripMenuItem1->Text = L"Delete";
			this->deleteToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::deleteToolStripMenuItem1_Click);
			// 
			// analyzeToolStripMenuItem
			// 
			this->analyzeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->isConnectedToolStripMenuItem, 
				this->depthFirstSearchToolStripMenuItem, this->minimumSpanningTreeToolStripMenuItem, this->shortestPathToolStripMenuItem});
			this->analyzeToolStripMenuItem->Name = L"analyzeToolStripMenuItem";
			this->analyzeToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->analyzeToolStripMenuItem->Text = L"Analyze";
			this->analyzeToolStripMenuItem->DropDownClosed += gcnew System::EventHandler(this, &Form1::analyzeToolStripMenuItem_DropDownClosed);
			// 
			// isConnectedToolStripMenuItem
			// 
			this->isConnectedToolStripMenuItem->Name = L"isConnectedToolStripMenuItem";
			this->isConnectedToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->isConnectedToolStripMenuItem->Text = L"Is Connected\?";
			this->isConnectedToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::isConnectedToolStripMenuItem_Click);
			// 
			// minimumSpanningTreeToolStripMenuItem
			// 
			this->minimumSpanningTreeToolStripMenuItem->Name = L"minimumSpanningTreeToolStripMenuItem";
			this->minimumSpanningTreeToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->minimumSpanningTreeToolStripMenuItem->Text = L"Minimum Spanning Tree";
			// 
			// shortestPathToolStripMenuItem
			// 
			this->shortestPathToolStripMenuItem->Name = L"shortestPathToolStripMenuItem";
			this->shortestPathToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->shortestPathToolStripMenuItem->Text = L"Shortest Path";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// adjMatrixTextBox
			// 
			this->adjMatrixTextBox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->adjMatrixTextBox->Location = System::Drawing::Point(555, 271);
			this->adjMatrixTextBox->MaximumSize = System::Drawing::Size(600, 600);
			this->adjMatrixTextBox->Multiline = true;
			this->adjMatrixTextBox->Name = L"adjMatrixTextBox";
			this->adjMatrixTextBox->ReadOnly = true;
			this->adjMatrixTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->adjMatrixTextBox->Size = System::Drawing::Size(300, 300);
			this->adjMatrixTextBox->TabIndex = 21;
			// 
			// prev
			// 
			this->prev->Location = System::Drawing::Point(699, 242);
			this->prev->Name = L"prev";
			this->prev->Size = System::Drawing::Size(75, 23);
			this->prev->TabIndex = 22;
			this->prev->Text = L"<--";
			this->prev->UseVisualStyleBackColor = true;
			this->prev->Click += gcnew System::EventHandler(this, &Form1::prev_Click);
			// 
			// next
			// 
			this->next->Location = System::Drawing::Point(780, 242);
			this->next->Name = L"next";
			this->next->Size = System::Drawing::Size(75, 23);
			this->next->TabIndex = 23;
			this->next->Text = L"-->";
			this->next->UseVisualStyleBackColor = true;
			this->next->Click += gcnew System::EventHandler(this, &Form1::next_Click);
			// 
			// depthFirstSearchToolStripMenuItem
			// 
			this->depthFirstSearchToolStripMenuItem->Name = L"depthFirstSearchToolStripMenuItem";
			this->depthFirstSearchToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->depthFirstSearchToolStripMenuItem->Text = L"Depth First Search";
			this->depthFirstSearchToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::depthFirstSearchToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(867, 583);
			this->Controls->Add(this->next);
			this->Controls->Add(this->prev);
			this->Controls->Add(this->adjMatrixTextBox);
			this->Controls->Add(this->weight);
			this->Controls->Add(this->toVertex);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->fromVertex);
			this->Controls->Add(this->vertexY);
			this->Controls->Add(this->vertexX);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->vertexName);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Location and dimension constants
		static const int headX = 25;
		static const int headY = 45;
		//static const int nodeLength = 50;
		//static const int nodeHeight = 25;
		static const int arrowLength = 30;

		// Declare graphics and drawing objects
		static Graphics^ g;
		static Brush^ whiteBrush;
		static Pen^ blackPen;
		static SolidBrush^ blackBrush;
		static Pen^ redPen;
		static SolidBrush^ redBrush;
		static Drawing::Font^ arialFont;
		static StringFormat^ drawFormat;

		static String^ fileName;
		static int matrixOffset = 0;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->graph = new GraphType<Vertex, int>();
				 g = this->CreateGraphics();
				 whiteBrush = gcnew System::Drawing::SolidBrush(Color::White);
				 blackPen = gcnew System::Drawing::Pen(Color::Black);
				 redPen = gcnew System::Drawing::Pen(Color::Red);
				 blackBrush = gcnew System::Drawing::SolidBrush(Color::Black);
				 redBrush = gcnew System::Drawing::SolidBrush(Color::Red);
				 arialFont = gcnew System::Drawing::Font("Arial", 12);
				 drawFormat = gcnew System::Drawing::StringFormat();
			 }

	private: void drawGraph() {
				 //this->Refresh();
				 drawVertices();
				 drawEdges();
				 drawMatrix();
			 }

	private: void drawVertices() {
				 QueueType<Vertex> vertexQ;
				 this->graph->GetAllVertices(vertexQ);
				 while (!vertexQ.IsEmpty()) {
					 Vertex v;
					 vertexQ.DeQueue(v);
					 drawVertex(v, blackPen, blackBrush);
				 }
			 }

	private: void drawVertex(Vertex v, System::Drawing::Pen^ pen, System::Drawing::Brush^ brush) {
                     g->DrawEllipse(pen, v.x, v.y, 50, 50); //draws vertex
					 String^ drawString = gcnew String(v.name.c_str());
					 g->DrawString(drawString, arialFont, brush, (float)(v.x + 18), (float)(v.y + 17), drawFormat); //draws label
			 }

	private: void drawEdges() {
				 QueueType<Vertex> vertexQ;
				 this->graph->GetAllVertices(vertexQ);
				 while (!vertexQ.IsEmpty()) {
					 Vertex v;
					 vertexQ.DeQueue(v);
					 QueueType<Vertex> adjQ;
					 this->graph->GetToVertices(v, adjQ);
					 while (!adjQ.IsEmpty()) {
						 Vertex adjV;
						 adjQ.DeQueue(adjV);
						 drawEdge(v, adjV, blackPen, blackBrush);
					 }
				 }
			 }

	private: void drawEdge(Vertex v, Vertex adjV, System::Drawing::Pen^ pen, System::Drawing::Brush^ brush) {
				 int w = this->graph->GetWeight(v, adjV);
				 double theta;
				 int endY, endX, startY, startX;
				 endY = adjV.y + 25;
				 endX = adjV.x + 25;
				 startY = v.y + 25;
				 startX = v.x + 25;
				 theta = -atan2((double)(endY-startY), (double)(endX-startX));
				 double length = sqrt(pow((adjV.x - v.x), 2.0) + pow((adjV.y - v.y), 2.0)) - 25.0;
				 double tipX = -25.0, tipY = 0.0;
				 double baseX = -35.0, baseY = -10.0;
				 double topX = -35.0, topY = 10.0;
				 //draw line
				 g->DrawLine(pen,
					 (int)((-length * cos(theta)) + (0 * sin(theta)) + (double)endX),
					 (int)((length * sin(theta)) + (0 * cos(theta)) + (double)endY),
					 (int)((tipX * cos(theta)) + (tipY * sin(theta)) + (double)endX),
					 (int)((-tipX * sin(theta)) + (tipY * cos(theta)) + (double)endY));
				 //draw arrow
				 g->DrawLine(pen,
					 (int)((baseX * cos(theta)) + (baseY * sin(theta)) + (double)endX),
					 (int)((-baseX * sin(theta)) + (baseY * cos(theta)) + (double)endY),	
					 (int)((tipX * cos(theta)) + (tipY * sin(theta)) + (double)endX),
					 (int)((-tipX * sin(theta)) + (tipY * cos(theta)) + (double)endY));
				 g->DrawLine(pen,
					 (int)((topX * cos(theta)) + (topY * sin(theta)) + (double)endX),
					 (int)((-topX * sin(theta)) + (topY * cos(theta)) + (double)endY),	
					 (int)((tipX * cos(theta)) + (tipY * sin(theta)) + (double)endX),
					 (int)((-tipX * sin(theta)) + (tipY * cos(theta)) + (double)endY));
				 //draw weight
				 String^ weightStr = System::Convert::ToString(w);
				 g->DrawString(weightStr, arialFont, brush, 
					 (int)(((topX - 10.0) * cos(theta)) + (topY * sin(theta)) + (double)endX),
					 (int)((-(topX - 10.0) * sin(theta)) + (topY * cos(theta)) + (double)endY), drawFormat); //draws label
			 }

	private: void drawMatrix() {
				 String^ weightMatrixStr = "Label\tIndex";
				 for (int i = 0; i < this->graph->GetVerticesCount(); i++) {
					 if ((i >= matrixOffset) && (i < (matrixOffset + 4))) {
						 weightMatrixStr += "\t" + System::Convert::ToString(i);
					 }
				 }
				 weightMatrixStr += "\r\n";
				 int vIndex = 0;

				 QueueType<Vertex> vertexQ;
				 this->graph->GetAllVertices(vertexQ);
				 while (!vertexQ.IsEmpty()) {
					 Vertex v;
					 vertexQ.DeQueue(v);
					 String^ name = gcnew String(v.name.c_str());
					 weightMatrixStr += name + "\t" + System::Convert::ToString(vIndex++);
					 QueueType<Vertex> allQ;
					 this->graph->GetAllVertices(allQ);
					 int counter = 0;
					 while (!allQ.IsEmpty()) {
						 Vertex v2;
						 allQ.DeQueue(v2);
						 if ((counter >= matrixOffset) && (counter < (matrixOffset + 4))) {
							 weightMatrixStr += "\t" + System::Convert::ToString(this->graph->GetWeight(v, v2));
						 }
						 ++counter;
					 }
					 weightMatrixStr += "\r\n";
				 }

				 this->adjMatrixTextBox->Text = weightMatrixStr;
				 if (matrixOffset == 0)
					 prev->Enabled = false;
				 if ((matrixOffset + 4) < this->graph->GetVerticesCount())
					 next->Enabled = true;
				 if (matrixOffset > 0)
					 prev->Enabled = true;
				 if ((matrixOffset + 4) >= this->graph->GetVerticesCount())
					 next->Enabled = false;
			 }

private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->graph->MakeEmpty();
			 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 fileName = gcnew String(openFileDialog1->FileName);
				 System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(fileName);
				 int numVertices;
				 Int32::TryParse(sr->ReadLine(), numVertices);
				 for (int i = 0; i < numVertices; i++)
				 {
					 array<String^>^vertexData = (sr->ReadLine())->Split(':');
					 Vertex v;
					 String^ temp = vertexData[0];
					 v.name = msclr::interop::marshal_as<string>(temp);
					 v.x = System::Int32::Parse(vertexData[1]);
					 v.y = System::Int32::Parse(vertexData[2]);
					 this->graph->AddVertex(v);
				 }

				 while(sr->Peek() >= 0)
				 {
					 array<String^>^edgeData = (sr->ReadLine())->Split(':');
					 Vertex from, to;
					 int weight;
					 String^ temp = edgeData[0];
					 from.name = msclr::interop::marshal_as<string>(temp);
					 temp = edgeData[1];
					 to.name = msclr::interop::marshal_as<string>(temp);
					 weight = System::Int32::Parse(edgeData[2]);
					 this->graph->AddEdge(from, to, weight);
				 }

				 //MessageBox::Show(sr->ReadToEnd());
				 sr->Close();
				 drawGraph();
			 }
		 }

private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (File::Exists(fileName))
			 {
				 File::Delete(fileName);
			 }
			 StreamWriter^ sw = gcnew StreamWriter(fileName);
			 try
			 {
				 sw->WriteLine(System::Convert::ToString(this->graph->GetVerticesCount()));
				 QueueType<Vertex> vertices;
				 this->graph->GetAllVertices(vertices);
				 while (!vertices.IsEmpty())
				 {
					 Vertex v;
					 vertices.DeQueue(v);
					 String^ temp = gcnew String(v.name.c_str());
					 sw->WriteLine(temp + ":" + System::Convert::ToString(v.x) + ":" + System::Convert::ToString(v.y));
				 }

				 this->graph->GetAllVertices(vertices);
				 while (!vertices.IsEmpty())
				 {
					 Vertex v;
					 vertices.DeQueue(v);
					 QueueType<Vertex> adjQ;
					 this->graph->GetToVertices(v, adjQ);
					 while (!adjQ.IsEmpty()) {
						 Vertex adjV;
						 adjQ.DeQueue(adjV);
						 int w = this->graph->GetWeight(v, adjV);
						 String^ from = gcnew String(v.name.c_str());
						 String^ to = gcnew String(adjV.name.c_str());
						 sw->WriteLine(from + ":" + to + ":" + System::Convert::ToString(w));
					 }
				 }

			 }
			 finally
			 {
				 delete sw;
			 }
			 drawGraph();
		 }

private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 fileName = gcnew String(saveFileDialog1->FileName);
				 if (File::Exists(fileName))
				 {
					 File::Delete(fileName);
				 }
				 StreamWriter^ sw = gcnew StreamWriter(fileName);
				 try
				 {
					 sw->WriteLine(System::Convert::ToString(this->graph->GetVerticesCount()));
					 QueueType<Vertex> vertices;
					 this->graph->GetAllVertices(vertices);
					 while (!vertices.IsEmpty())
					 {
						 Vertex v;
						 vertices.DeQueue(v);
						 String^ temp = gcnew String(v.name.c_str());
						 sw->WriteLine(temp + ":" + System::Convert::ToString(v.x) + ":" + System::Convert::ToString(v.y));
					 }

					 this->graph->GetAllVertices(vertices);
					 while (!vertices.IsEmpty())
					 {
						 Vertex v;
						 vertices.DeQueue(v);
						 QueueType<Vertex> adjQ;
						 this->graph->GetToVertices(v, adjQ);
						 while (!adjQ.IsEmpty()) {
							 Vertex adjV;
							 adjQ.DeQueue(adjV);
							 int w = this->graph->GetWeight(v, adjV);
							 String^ from = gcnew String(v.name.c_str());
							 String^ to = gcnew String(adjV.name.c_str());
							 sw->WriteLine(from + ":" + to + ":" + System::Convert::ToString(w));
						 }
					 }
				 }
				 finally
				 {
					 delete sw;
				 }
			 }
			 drawGraph();
		 }

private: System::Void quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }

private: System::Void addUpdateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (!String::IsNullOrWhiteSpace(this->vertexName->Text) &&
				 !String::IsNullOrWhiteSpace(this->vertexX->Text) &&
				 !String::IsNullOrWhiteSpace(this->vertexY->Text)) {
					 try{
						 Vertex v;
						 v.name = msclr::interop::marshal_as<string>(this->vertexName->Text);
						 if (this->graph->Search(v)) {
							 v.x = System::Int32::Parse(this->vertexX->Text);
							 v.y = System::Int32::Parse(this->vertexY->Text);
							 this->graph->UpdateVertex(v);
						 } else {
							 v.x = System::Int32::Parse(this->vertexX->Text);
							 v.y = System::Int32::Parse(this->vertexY->Text);
							 this->graph->AddVertex(v);
						 }

					 } catch(FormatException ^) {
						 MessageBox::Show("Must be an integer input for Vertex X and Vertex Y!");
					 }
			 } else
				 MessageBox::Show("Cannot leave inputs blank!");

			 drawGraph();
		 }

private: System::Void deleteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Vertex v;
			 v.name = msclr::interop::marshal_as<string>(this->vertexName->Text);
			 try {
				 this->graph->DeleteVertex(v);

			 } catch(NotFound) {
				 MessageBox::Show("Vertex Not Found!");
			 }

			 drawGraph();
		 }

private: System::Void addUpdateToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (!String::IsNullOrWhiteSpace(this->fromVertex->Text) &&
				 !String::IsNullOrWhiteSpace(this->toVertex->Text) &&
				 !String::IsNullOrWhiteSpace(this->weight->Text)) {
					 Vertex fv, tv;
					 fv.name = msclr::interop::marshal_as<string>(this->fromVertex->Text);

					 if (!this->graph->Search(fv)) {
						 MessageBox::Show("From Vertex Not Found!");
					 }
					 else {
						 tv.name = msclr::interop::marshal_as<string>(this->toVertex->Text);
						 if (!this->graph->Search(tv)) {
							 MessageBox::Show("To Vertex Not Found!");
						 } else {
							 try {
								 int w = System::Int32::Parse(this->weight->Text);
								 this->graph->AddEdge(fv, tv, w);
							 } catch(FormatException ^) {
								 MessageBox::Show("Must be an integer input for Weight!");
							 }
						 }
					 }
			 } else
				 MessageBox::Show("Cannot leave inputs blank!");

			 drawGraph();
		 }

private: System::Void deleteToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (!String::IsNullOrWhiteSpace(this->fromVertex->Text) &&
				 !String::IsNullOrWhiteSpace(this->toVertex->Text)) {
					 Vertex fv, tv;
					 fv.name = msclr::interop::marshal_as<string>(this->fromVertex->Text);
					 if (!this->graph->Search(fv)) {
						 MessageBox::Show("From Vertex Not Found!");
					 }
					 else {
						 tv.name = msclr::interop::marshal_as<string>(this->toVertex->Text);
						 if (!this->graph->Search(tv)) {
							 MessageBox::Show("To Vertex Not Found!");
						 } else {
							 this->graph->DeleteEdge(fv, tv);
						 }
					 }
			 } else
				 MessageBox::Show("Cannot leave inputs blank!");

			 drawGraph();
		 }

private: System::Void isConnectedToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->graph->IsConnected())
				 MessageBox::Show("Graph Is Connected!");
			 else
				 MessageBox::Show("Graph Is Not Connected!");

			 drawGraph();
		 }

private: System::Void vertexToolStripMenuItem_DropDownClosed(System::Object^  sender, System::EventArgs^  e) {
			 drawGraph();
		 }

private: System::Void edgeToolStripMenuItem_DropDownClosed(System::Object^  sender, System::EventArgs^  e) {
			 drawGraph();
		 }

private: System::Void analyzeToolStripMenuItem_DropDownClosed(System::Object^  sender, System::EventArgs^  e) {
			 drawGraph();
		 }

private: System::Void fileToolStripMenuItem_DropDownClosed(System::Object^  sender, System::EventArgs^  e) {
			 drawGraph();
		 }

private: System::Void prev_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (matrixOffset > 0) {
				 matrixOffset--;
				 drawGraph();
			 }
		 }

private: System::Void next_Click(System::Object^  sender, System::EventArgs^  e) {
			 if ((matrixOffset + 4) < this->graph->GetVerticesCount()) {
				 matrixOffset++;
				 drawGraph();
			 }
		 }

private: System::Void resetToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->graph->MakeEmpty();
			 drawGraph();
		 }

private: System::Void depthFirstSearchToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (!String::IsNullOrWhiteSpace(this->fromVertex->Text) &&
				 !String::IsNullOrWhiteSpace(this->toVertex->Text)) {
					 Vertex fv, tv;
					 fv.name = msclr::interop::marshal_as<string>(this->fromVertex->Text);
					 if (!this->graph->Search(fv)) {
						 MessageBox::Show("From Vertex Not Found!");
					 }
					 else {
						 tv.name = msclr::interop::marshal_as<string>(this->toVertex->Text);
						 if (!this->graph->Search(tv)) {
							 MessageBox::Show("To Vertex Not Found!");
						 } else {
							 try {
									QueueType<Vertex> vertexQ;
									this->graph->GetPath(fv, tv, vertexQ); //TODO: add enum param for DFS, BFS
									Vertex lastV;
									lastV.name = "";
									while (!vertexQ.IsEmpty()) {
										Vertex v;
										vertexQ.DeQueue(v);
										drawVertex(v, redPen, redBrush);
										if (lastV.name != "") {
											//draw an edge from lastV to v
											drawEdge(lastV, v, redPen, redBrush);
										}
										lastV.name = v.name;
										lastV.x = v.x;
										lastV.y = v.y;
									}
						     } catch(PathNotFound) {
								 MessageBox::Show("Path Not Found!");
							 }
						 }
					 }
			 } else
				 MessageBox::Show("Cannot leave inputs blank!");
		 }

};
}

