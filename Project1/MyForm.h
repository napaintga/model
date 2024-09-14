#pragma once
#include <corecrt_math.h>
#include <cmath>
#include <vector>
#include <iostream>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	int N;
	int N_Iter;
	int n;
	double eps;
	int KMax;
	const double Q = 0.000001;
	double R = 0;
	double A[6][6]; // матриця А 
	double B[6]; // вектор правої частини СЛАР 
	double X[6]; // вектор розв'язку 
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ A_matrix_dgv;
	private: System::Windows::Forms::DataGridView^ B_vector_dgv;
	protected:

	protected:

	private: System::Windows::Forms::DataGridView^ C_matrix_dgv;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ X_vector_dgv;



	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ BСreateGrid;
	private: System::Windows::Forms::Button^ BСlear;
	private: System::Windows::Forms::Button^ BСlose;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::NumericUpDown^ NUD_rozmir;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::RadioButton^ g;
	private: System::Windows::Forms::RadioButton^ n;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->A_matrix_dgv = (gcnew System::Windows::Forms::DataGridView());
			this->B_vector_dgv = (gcnew System::Windows::Forms::DataGridView());
			this->C_matrix_dgv = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->X_vector_dgv = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->BСreateGrid = (gcnew System::Windows::Forms::Button());
			this->BСlear = (gcnew System::Windows::Forms::Button());
			this->BСlose = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->NUD_rozmir = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->g = (gcnew System::Windows::Forms::RadioButton());
			this->n = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A_matrix_dgv))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_vector_dgv))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_matrix_dgv))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X_vector_dgv))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUD_rozmir))->BeginInit();
			this->SuspendLayout();
			// 
			// A_matrix_dgv
			// 
			this->A_matrix_dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->A_matrix_dgv->ColumnHeadersVisible = false;
			this->A_matrix_dgv->Location = System::Drawing::Point(8, 76);
			this->A_matrix_dgv->Name = L"A_matrix_dgv";
			this->A_matrix_dgv->RowHeadersVisible = false;
			this->A_matrix_dgv->RowHeadersWidth = 62;
			this->A_matrix_dgv->RowTemplate->Height = 28;
			this->A_matrix_dgv->Size = System::Drawing::Size(240, 150);
			this->A_matrix_dgv->TabIndex = 0;
			// 
			// B_vector_dgv
			// 
			this->B_vector_dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->B_vector_dgv->ColumnHeadersVisible = false;
			this->B_vector_dgv->Location = System::Drawing::Point(308, 76);
			this->B_vector_dgv->Name = L"B_vector_dgv";
			this->B_vector_dgv->RowHeadersVisible = false;
			this->B_vector_dgv->RowHeadersWidth = 62;
			this->B_vector_dgv->RowTemplate->Height = 28;
			this->B_vector_dgv->Size = System::Drawing::Size(240, 150);
			this->B_vector_dgv->TabIndex = 1;
			// 
			// C_matrix_dgv
			// 
			this->C_matrix_dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->C_matrix_dgv->ColumnHeadersVisible = false;
			this->C_matrix_dgv->Location = System::Drawing::Point(8, 304);
			this->C_matrix_dgv->Name = L"C_matrix_dgv";
			this->C_matrix_dgv->RowHeadersVisible = false;
			this->C_matrix_dgv->RowHeadersWidth = 62;
			this->C_matrix_dgv->RowTemplate->Height = 28;
			this->C_matrix_dgv->Size = System::Drawing::Size(240, 150);
			this->C_matrix_dgv->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Матриця А";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(764, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Вектор Х";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(361, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Вектор В";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(20, 281);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(203, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Згенерована LU-матриця";
			// 
			// X_vector_dgv
			// 
			this->X_vector_dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->X_vector_dgv->ColumnHeadersVisible = false;
			this->X_vector_dgv->Location = System::Drawing::Point(670, 76);
			this->X_vector_dgv->Name = L"X_vector_dgv";
			this->X_vector_dgv->ReadOnly = true;
			this->X_vector_dgv->RowHeadersVisible = false;
			this->X_vector_dgv->RowHeadersWidth = 62;
			this->X_vector_dgv->RowTemplate->Height = 28;
			this->X_vector_dgv->Size = System::Drawing::Size(240, 150);
			this->X_vector_dgv->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(690, 298);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 11;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(690, 352);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 12;
			// 
			// BСreateGrid
			// 
			this->BСreateGrid->Location = System::Drawing::Point(444, 503);
			this->BСreateGrid->Name = L"BСreateGrid";
			this->BСreateGrid->Size = System::Drawing::Size(124, 43);
			this->BСreateGrid->TabIndex = 13;
			this->BСreateGrid->Text = L"Обчислити";
			this->BСreateGrid->UseVisualStyleBackColor = true;
			this->BСreateGrid->Click += gcnew System::EventHandler(this, &MyForm::BСreateGrid_Click);
			// 
			// BСlear
			// 
			this->BСlear->Location = System::Drawing::Point(621, 503);
			this->BСlear->Name = L"BСlear";
			this->BСlear->Size = System::Drawing::Size(124, 43);
			this->BСlear->TabIndex = 14;
			this->BСlear->Text = L"Очистити";
			this->BСlear->UseVisualStyleBackColor = true;
			this->BСlear->Click += gcnew System::EventHandler(this, &MyForm::BСlear_Click);
			// 
			// BСlose
			// 
			this->BСlose->Location = System::Drawing::Point(800, 503);
			this->BСlose->Name = L"BСlose";
			this->BСlose->Size = System::Drawing::Size(124, 43);
			this->BСlose->TabIndex = 15;
			this->BСlose->Text = L"Закрити";
			this->BСlose->UseVisualStyleBackColor = true;
			this->BСlose->Click += gcnew System::EventHandler(this, &MyForm::BСlose_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(263, 503);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(124, 43);
			this->button4->TabIndex = 16;
			this->button4->Text = L"Встановити";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// NUD_rozmir
			// 
			this->NUD_rozmir->Location = System::Drawing::Point(90, 6);
			this->NUD_rozmir->Name = L"NUD_rozmir";
			this->NUD_rozmir->Size = System::Drawing::Size(120, 26);
			this->NUD_rozmir->TabIndex = 17;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(20, 12);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 20);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Розмір";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(569, 304);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(115, 20);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Точність Eps=";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(617, 355);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(57, 20);
			this->label7->TabIndex = 20;
			this->label7->Text = L"KMax=";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(608, 401);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(62, 20);
			this->label8->TabIndex = 22;
			this->label8->Text = L"N_Iter=";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(690, 401);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 26);
			this->textBox3->TabIndex = 21;
			// 
			// g
			// 
			this->g->AutoSize = true;
			this->g->Location = System::Drawing::Point(328, 337);
			this->g->Name = L"g";
			this->g->Size = System::Drawing::Size(76, 24);
			this->g->TabIndex = 23;
			this->g->TabStop = true;
			this->g->Text = L"Гауса";
			this->g->UseVisualStyleBackColor = true;
			// 
			// n
			// 
			this->n->AutoSize = true;
			this->n->Location = System::Drawing::Point(328, 384);
			this->n->Name = L"n";
			this->n->Size = System::Drawing::Size(103, 24);
			this->n->TabIndex = 24;
			this->n->TabStop = true;
			this->n->Text = L"Ньютона";
			this->n->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1035, 640);
			this->Controls->Add(this->n);
			this->Controls->Add(this->g);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->NUD_rozmir);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->BСlose);
			this->Controls->Add(this->BСlear);
			this->Controls->Add(this->BСreateGrid);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->X_vector_dgv);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->C_matrix_dgv);
			this->Controls->Add(this->B_vector_dgv);
			this->Controls->Add(this->A_matrix_dgv);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A_matrix_dgv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_vector_dgv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_matrix_dgv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X_vector_dgv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUD_rozmir))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		ref class Gauss {
		public:
			virtual bool GAUSS() {
				return 0;
			};
		};

		// Клас, що реалізує алгоритм Гауса
		ref class TGauss : public Gauss {
		public:
			//DataGridView^ C_matrix_dgv;
			bool GAUSS(double A[6][6], double B[6], int N, double X[6], DataGridView^ C_matrix_dgv) override {
				double C[6][6]; // робоча матриця C 
				int  k;
				double R;
				if (N == 1)
				{
					if (Math::Abs(A[1][1]) < 1E-7)
					{
						MessageBox::Show("Система вироджена");
						return false;
					}
					else
					{
						X[1] = B[1] / A[1][1];
					}
				}
				// Прямий хід алгоритму Гауса  
				for (int i = 1; i <= N - 1; i++)
				{
					k = i;
					R = Math::Abs(A[i][i]);
					for (int j = i + 1; j <= N; j++)
					{
						if (Math::Abs(A[j][i]) >= R)
						{
							k = j;
							R = Math::Abs(A[j][i]);
						}
					}
					if (R <= 1E-7)
					{
						MessageBox::Show("Система вироджена");
						return false;
					}
					if (k != i)
					{
						R = B[k];
						B[k] = B[i];
						B[i] = R;
						for (int j = i; j <= N; j++)
						{
							R = A[k][j];
							A[k][j] = A[i][j];
							A[i][j] = R;
						}
					}
					R = A[i][i];
					B[i] = B[i] / R;
					for (int j = 1; j <= N; j++)
						A[i][j] /= R;
					for (int k = i + 1; k <= N; k++)
					{
						R = A[k][i];
						B[k] = B[k] - R * B[i];
						A[k][i] = 0.0;
						for (int j = i + 1; j <= N; j++)
							A[k][j] = A[k][j] - R * A[i][j];
					}
				}


				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
					{
						C_matrix_dgv->Rows[i]->Cells[j]->Value = Convert::ToString(A[i + 1][j + 1]);
					}
				MessageBox::Show("Завершили прямий хід");
				if (Math::Abs(A[N][N]) <= 1E-7)
				{
					MessageBox::Show("Система вироджена");
					return false;
				}
				else {
					// Зворотний хід алгоритму Гауса 
					X[N] = B[N] / A[N][N];
					for (int i = N - 1; i >= 1; i--)
					{
						R = B[i];
						for (int j = i + 1; j <= N; j++)
							R -= A[i][j] * X[j];
						X[i] = R;
					}
					return true;
				}
			}
		};

		// Клас, що реалізує алгоритм Ньютона
		ref class TNewton : public TGauss {
		public:
			void GAUSS(double** A, double* b, double* x, int N) override {
				int k;
				double R;
				if (N == 1)
				{
					if (abs(A[0][0]) < 1E-7)
					{
						return;
					}
					else
					{
						x[0] = b[0] / A[0][0];
					}
				}
				// Прямий хід алгоритму Гауса 
				for (int i = 0; i < N - 1; i++)
				{
					k = i;
					R = abs(A[i][i]);
					for (int j = i + 1; j < N; j++)
					{
						if (abs(A[j][i]) >= R)
						{
							k = j;
							R = abs(A[j][i]);
						}
					}
					if (R <= 1E-7)
					{
						return;
					}
					if (k != i)
					{
						R = b[k];
						b[k] = b[i];
						b[i] = R;
						for (int j = i; j < N; j++)
						{
							R = A[k][j];
							A[k][j] = A[i][j];
							A[i][j] = R;
						}
					}
					R = A[i][i];

					b[i] = b[i] / R;
					for (int j = i + 1; j < N; j++)
						A[i][j] /= R;
					for (int k = i + 1; k < N; k++)
					{
						R = A[k][i];
						b[k] = b[k] - R * b[i];
						A[k][i] = 0.0;
						for (int j = i + 1; j < N; j++)
							A[k][j] = A[k][j] - R * A[i][j];
					}
				}

				if (abs(A[N - 1][N - 1]) <= 1E-7)
				{
					return;
				}
				// Зворотний хід алгоритму Гауса
				x[N - 1] = b[N - 1] / A[N - 1][N - 1];
				for (int i = N - 2; i >= 0; i--)
				{
					R = b[i];
					for (int j = i + 1; j < N; j++)
						R -= A[i][j] * x[j];
					x[i] = R;
				}
			}

			void FM(const double* X, double* F, int N)
			{
				F[0] = X[0] + System::Math::Exp(X[0] - 1.0) + System::Math::Pow(X[1] + X[2], 2) - 27.0;
				F[1] = X[0] * System::Math::Exp(X[1] - 2.0) + System::Math::Pow(X[2], 2) - 10.0;
				F[2] = X[2] + System::Math::Sin(X[1] - 2.0) + System::Math::Pow(X[1], 2) - 7.0;

			}

			void Jac(const double* X, double** Ja, int N)
			{
				double* Xp = new double[N];
				double* F = new double[N];
				double* Fp = new double[N];
				int i, j;
				FM(X, F, N); // обчислення значень вектору F від незбуреного вектору X
				const double Q = 1e-6; // величина збурення
				for (j = 0; j < N; j++)
				{
					for (i = 0; i < N; i++)
						Xp[i] = X[i]; // копіювання вектору X в тимчасовий вектор
					Xp[j] += Q; // збурення j-ї компоненти вектору X
					FM(Xp, Fp, N);
					for (i = 0; i < N; i++)
						Ja[i][j] = (Fp[i] - F[i]) / Q; // обчислення значень [i, j]-ї компоненти матриці Ja
				}
			}

		};

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		int shyr = A_matrix_dgv->Width - 10;
		N = Convert::ToInt32(NUD_rozmir->Value);
		if (g->Checked)
		{
			A_matrix_dgv->Visible = true;
			C_matrix_dgv->Visible = true;
			this->label6->Visible = false;
			this->label7->Visible = false;
			this->label8->Visible = false;
			this->textBox1->Visible = false;
			this->textBox2->Visible = false;
			this->textBox3->Visible = false;
			this->label1->Visible = true;
			this->label4->Visible = true;
			A_matrix_dgv->RowCount = N;
			A_matrix_dgv->ColumnCount = N;
			C_matrix_dgv->RowCount = N;
			C_matrix_dgv->ColumnCount = N;
			X_vector_dgv->RowCount = N;
			B_vector_dgv->RowCount = N;
			for (int i = 0; i < N; i++)
			{
				A_matrix_dgv->Columns[i]->Width = shyr / N;
				C_matrix_dgv->Columns[i]->Width = shyr / N;
			}
		}


		else if (n->Checked)
		{
			A_matrix_dgv->Visible = false;
			C_matrix_dgv->Visible = false;
			X_vector_dgv->RowCount = N;
			B_vector_dgv->RowCount = N;
			this->label1->Visible = false;
			this->label4->Visible = false;
			this->label1->Visible = false;
			this->label4->Visible = false;
			this->label6->Visible = true;
			this->label7->Visible = true;
			this->label8->Visible = true;
			this->textBox1->Visible = true;
			this->textBox2->Visible = true;
			this->textBox3->Visible = true;
		}
		else if (N == 0)
		{
			MessageBox::Show("Введіть розмір");
		}
		else {
			MessageBox::Show("Виберіть метод");
		}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		X_vector_dgv->ReadOnly = true; // Заборона введення даних у стовпець розв'язку
		//* Заборона додавання рядків у гріди матриці А та векторів В та Х.
		A_matrix_dgv->AllowUserToAddRows = false;
		C_matrix_dgv->AllowUserToAddRows = false;
		B_vector_dgv->AllowUserToAddRows = false;
		X_vector_dgv->AllowUserToAddRows = false;
		// Кількість стовпців і рядків матриці та векторів встановлюємо = 1
		A_matrix_dgv->ColumnCount = 1;
		A_matrix_dgv->RowCount = 1;
		C_matrix_dgv->ColumnCount = 1;
		C_matrix_dgv->RowCount = 1;
		X_vector_dgv->ColumnCount = 1;
		X_vector_dgv->RowCount = 1;
		B_vector_dgv->ColumnCount = 1;
		B_vector_dgv->RowCount = 1;
	}


	private: System::Void BСreateGrid_Click(System::Object^ sender, System::EventArgs^ e) {
		TGauss^ gauss = gcnew TGauss();
		N = Convert::ToInt32(NUD_rozmir->Value);
		if (g->Checked) {
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
				{
					A[i][j] = Convert::ToDouble(A_matrix_dgv->Rows[i - 1]->Cells[j - 1]->Value);
				}
			for (int j = 1; j <= N; j++) {
				B[j] = Convert::ToDouble(B_vector_dgv->Rows[j - 1]->Cells[0]->Value);
			}
			if (gauss->GAUSS(A, B, N, X, C_matrix_dgv) == true) {
				for (int i = 1; i <= N; i++) {
					X_vector_dgv->Rows[i - 1]->Cells[0]->Value = Convert::ToString(X[i]);
				}
				MessageBox::Show("Розв'язок знайдено");
			}
			else
			{
				MessageBox::Show("Система вироджена!");
				return;
			}
		}

		else if (n->Checked)
		{
			TNewton^ newton = gcnew TNewton();
			double* X = new double[N];
			double** Ja = new double* [N];
			double* F = new double[N];
			double* Dx = new double[N];
			double** A = new double* [N];
			double* B = new double[N];
			N = Convert::ToInt32(NUD_rozmir->Value);
			eps = Convert::ToDouble(textBox1->Text);
			KMax = Convert::ToInt32(textBox2->Text);

			for (int j = 0; j < N; j++) {
				X[j] = Convert::ToDouble(B_vector_dgv->Rows[j]->Cells[0]->Value);
			}

			for (int i = 0; i < N; i++) {
				A[i] = new double[N];
				Ja[i] = new double[N];
			}

			int N_Iter = 0;

			for (; N_Iter < KMax; N_Iter++) {
				newton->FM(X, F, N);
				newton->Jac(X, Ja, N);
				newton->GAUSS(Ja, F, Dx, N);

				double Dxm = 0;
				for (int i = 0; i < N; i++) {
					if (std::abs(Dx[i]) > Dxm) {
						Dxm = std::abs(Dx[i]);
					}
				}

				if (Dxm <= eps) {
					MessageBox::Show("Рішення знайдено");
					textBox3->Text = System::Convert::ToString(N_Iter + 1);
					for (int i = 0; i < N; i++) {
						if (X_vector_dgv->Rows->Count <= i)
							X_vector_dgv->Rows->Add();
						X_vector_dgv->Rows[i]->Cells[0]->Value = Convert::ToString(X[i]);
					}
					break;
				}

				for (int i = 0; i < N; i++) {
					X[i] -= Dx[i];
				}
			}

			if (N_Iter == KMax) {
				MessageBox::Show("Рішення не знайдено протягом " + KMax.ToString() + " ітерацій.");
			}
		}
		
	}



	private: System::Void BСlose_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();

	}
	private: System::Void BСlear_Click(System::Object^ sender, System::EventArgs^ e) {
		if (g->Checked)
		{
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
				{
					A_matrix_dgv->Rows[i]->Cells[j]->Value = "";
					C_matrix_dgv->Rows[i]->Cells[j]->Value = "";
				}
			for (int j = 0; j < N; j++)
			{
				B_vector_dgv->Rows[j]->Cells[0]->Value = "";
				X_vector_dgv->Rows[j]->Cells[0]->Value = "";
			}
		}
		else
		{
			for (int j = 0; j < N; j++)
			{
				B_vector_dgv->Rows[j]->Cells[0]->Value = "";
				X_vector_dgv->Rows[j]->Cells[0]->Value = "";
			}
			this->textBox1->Text = "";
			this->textBox2->Text = "";
			this->textBox3->Text = "";
		}

	}
	};
}

