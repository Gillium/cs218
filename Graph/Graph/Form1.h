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
	private: System::Windows::Forms::Button^  btn_addVertex;

	private: System::Windows::Forms::TextBox^  vertexName;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  vertexX;
	private: System::Windows::Forms::TextBox^  vertexY;
	private: System::Windows::Forms::Button^  deleteVertex;
	private: System::Windows::Forms::Button^  addEdge;
	private: System::Windows::Forms::TextBox^  weight;
	private: System::Windows::Forms::TextBox^  toVertex;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  fromVertex;
	private: System::Windows::Forms::Button^  deleteEdge;
	private: System::Windows::Forms::Button^  isConnected;


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  quitToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

			 GraphType<Vertex, int>* graph;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_addVertex = (gcnew System::Windows::Forms::Button());
			this->vertexName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->vertexX = (gcnew System::Windows::Forms::TextBox());
			this->vertexY = (gcnew System::Windows::Forms::TextBox());
			this->deleteVertex = (gcnew System::Windows::Forms::Button());
			this->addEdge = (gcnew System::Windows::Forms::Button());
			this->weight = (gcnew System::Windows::Forms::TextBox());
			this->toVertex = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->fromVertex = (gcnew System::Windows::Forms::TextBox());
			this->deleteEdge = (gcnew System::Windows::Forms::Button());
			this->isConnected = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_addVertex
			// 
			this->btn_addVertex->Location = System::Drawing::Point(504, 29);
			this->btn_addVertex->Name = L"btn_addVertex";
			this->btn_addVertex->Size = System::Drawing::Size(144, 50);
			this->btn_addVertex->TabIndex = 0;
			this->btn_addVertex->Text = L"Add/Update Vertex";
			this->btn_addVertex->UseVisualStyleBackColor = true;
			this->btn_addVertex->Click += gcnew System::EventHandler(this, &Form1::btn_addVertex_Click);
			// 
			// vertexName
			// 
			this->vertexName->Location = System::Drawing::Point(726, 26);
			this->vertexName->Name = L"vertexName";
			this->vertexName->Size = System::Drawing::Size(115, 20);
			this->vertexName->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(654, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Vertex Label";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(654, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Vertex X:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(654, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Vertex Y:";
			// 
			// vertexX
			// 
			this->vertexX->Location = System::Drawing::Point(726, 45);
			this->vertexX->Name = L"vertexX";
			this->vertexX->Size = System::Drawing::Size(115, 20);
			this->vertexX->TabIndex = 6;
			// 
			// vertexY
			// 
			this->vertexY->Location = System::Drawing::Point(726, 63);
			this->vertexY->Name = L"vertexY";
			this->vertexY->Size = System::Drawing::Size(115, 20);
			this->vertexY->TabIndex = 7;
			// 
			// deleteVertex
			// 
			this->deleteVertex->Location = System::Drawing::Point(504, 85);
			this->deleteVertex->Name = L"deleteVertex";
			this->deleteVertex->Size = System::Drawing::Size(144, 50);
			this->deleteVertex->TabIndex = 8;
			this->deleteVertex->Text = L"Delete Vertex";
			this->deleteVertex->UseVisualStyleBackColor = true;
			this->deleteVertex->Click += gcnew System::EventHandler(this, &Form1::deleteVertex_Click);
			// 
			// addEdge
			// 
			this->addEdge->Location = System::Drawing::Point(504, 141);
			this->addEdge->Name = L"addEdge";
			this->addEdge->Size = System::Drawing::Size(144, 50);
			this->addEdge->TabIndex = 9;
			this->addEdge->Text = L"Add Edge";
			this->addEdge->UseVisualStyleBackColor = true;
			this->addEdge->Click += gcnew System::EventHandler(this, &Form1::addEdge_Click);
			// 
			// weight
			// 
			this->weight->Location = System::Drawing::Point(726, 175);
			this->weight->Name = L"weight";
			this->weight->Size = System::Drawing::Size(115, 20);
			this->weight->TabIndex = 15;
			// 
			// toVertex
			// 
			this->toVertex->Location = System::Drawing::Point(726, 157);
			this->toVertex->Name = L"toVertex";
			this->toVertex->Size = System::Drawing::Size(115, 20);
			this->toVertex->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(654, 175);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Weight:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(654, 157);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"To Vertex:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(654, 141);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"From Vertex:";
			// 
			// fromVertex
			// 
			this->fromVertex->Location = System::Drawing::Point(726, 138);
			this->fromVertex->Name = L"fromVertex";
			this->fromVertex->Size = System::Drawing::Size(115, 20);
			this->fromVertex->TabIndex = 10;
			// 
			// deleteEdge
			// 
			this->deleteEdge->Location = System::Drawing::Point(504, 197);
			this->deleteEdge->Name = L"deleteEdge";
			this->deleteEdge->Size = System::Drawing::Size(144, 50);
			this->deleteEdge->TabIndex = 16;
			this->deleteEdge->Tag = L"";
			this->deleteEdge->Text = L" Delete Edge";
			this->deleteEdge->UseVisualStyleBackColor = true;
			this->deleteEdge->Click += gcnew System::EventHandler(this, &Form1::deleteEdge_Click);
			// 
			// isConnected
			// 
			this->isConnected->Location = System::Drawing::Point(504, 253);
			this->isConnected->Name = L"isConnected";
			this->isConnected->Size = System::Drawing::Size(144, 50);
			this->isConnected->TabIndex = 17;
			this->isConnected->Tag = L"";
			this->isConnected->Text = L"Is Connected\?";
			this->isConnected->UseVisualStyleBackColor = true;
			this->isConnected->Click += gcnew System::EventHandler(this, &Form1::isConnected_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(867, 24);
			this->menuStrip1->TabIndex = 20;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->loadToolStripMenuItem, 
				this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->quitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fileToolStripMenuItem_Click);
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
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(867, 583);
			this->Controls->Add(this->isConnected);
			this->Controls->Add(this->deleteEdge);
			this->Controls->Add(this->weight);
			this->Controls->Add(this->toVertex);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->fromVertex);
			this->Controls->Add(this->addEdge);
			this->Controls->Add(this->deleteVertex);
			this->Controls->Add(this->vertexY);
			this->Controls->Add(this->vertexX);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->vertexName);
			this->Controls->Add(this->btn_addVertex);
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
		static Drawing::Font^ arialFont;
		static StringFormat^ drawFormat;

		static String^ fileName;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->graph = new GraphType<Vertex, int>();
				 g = this->CreateGraphics();
				 whiteBrush = gcnew System::Drawing::SolidBrush(Color::White);
				 blackPen = gcnew System::Drawing::Pen(Color::Black);
				 blackBrush = gcnew System::Drawing::SolidBrush(Color::Black);
				 arialFont = gcnew System::Drawing::Font("Arial", 12);
				 drawFormat = gcnew System::Drawing::StringFormat();
			 }
	private: System::Void btn_addVertex_Click(System::Object^  sender, System::EventArgs^  e) {
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

	private: void drawGraph() {
			 this->Refresh();
			 QueueType<Vertex> vertexQ;
			 this->graph->GetAllVertices(vertexQ);
			 while (!vertexQ.IsEmpty()) {
				Vertex v;
				vertexQ.DeQueue(v);
				g->DrawEllipse(blackPen, v.x, v.y, 50, 50);
				String^ drawString = gcnew String(v.name.c_str());
				g->DrawString(drawString, arialFont, blackBrush, (float)(v.x + 18), (float)(v.y + 17), drawFormat);
				QueueType<Vertex> adjQ;
				this->graph->GetToVertices(v, adjQ);
				while (!adjQ.IsEmpty()) {
					Vertex adjV;
					adjQ.DeQueue(adjV);
					int w = this->graph->GetWeight(v, adjV);
					g->DrawLine(blackPen, v.x + 25, v.y + 25, adjV.x + 25, adjV.y + 25);
				}
			 }
		}
	private: System::Void deleteVertex_Click(System::Object^  sender, System::EventArgs^  e) {
			 Vertex v;
			 v.name = msclr::interop::marshal_as<string>(this->vertexName->Text);
			 try {
				this->graph->DeleteVertex(v);
				
			 } catch(NotFound) {
				MessageBox::Show("Vertex Not Found!");
			 }

			 drawGraph();
		 }
	private: System::Void addEdge_Click(System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void deleteEdge_Click(System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void isConnected_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->graph->IsConnected())
				MessageBox::Show("Graph Is Connected!");
			 else
				MessageBox::Show("Graph Is Not Connected!");

			 drawGraph();
		 }
private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void fileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 drawGraph();
		 }
};
}

