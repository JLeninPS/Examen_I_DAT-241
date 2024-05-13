namespace Calculadora
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.lblRes = new System.Windows.Forms.Label();
            this.txtExpresion = new System.Windows.Forms.TextBox();
            this.btnIni = new System.Windows.Forms.Button();
            this.btnSalir = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblRes
            // 
            this.lblRes.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lblRes.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblRes.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.lblRes.Location = new System.Drawing.Point(38, 96);
            this.lblRes.Name = "lblRes";
            this.lblRes.Size = new System.Drawing.Size(399, 64);
            this.lblRes.TabIndex = 9;
            this.lblRes.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtExpresion
            // 
            this.txtExpresion.AcceptsReturn = true;
            this.txtExpresion.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.txtExpresion.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtExpresion.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.txtExpresion.Enabled = false;
            this.txtExpresion.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F);
            this.txtExpresion.ForeColor = System.Drawing.SystemColors.Window;
            this.txtExpresion.Location = new System.Drawing.Point(38, 50);
            this.txtExpresion.Name = "txtExpresion";
            this.txtExpresion.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.txtExpresion.Size = new System.Drawing.Size(399, 46);
            this.txtExpresion.TabIndex = 10;
            this.txtExpresion.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // btnIni
            // 
            this.btnIni.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.btnIni.Location = new System.Drawing.Point(111, 228);
            this.btnIni.Name = "btnIni";
            this.btnIni.Size = new System.Drawing.Size(253, 110);
            this.btnIni.TabIndex = 11;
            this.btnIni.Text = "INICIAR CALCULADORA";
            this.btnIni.UseVisualStyleBackColor = true;
            this.btnIni.Click += new System.EventHandler(this.btnIni_Click);
            // 
            // btnSalir
            // 
            this.btnSalir.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSalir.Location = new System.Drawing.Point(111, 353);
            this.btnSalir.Name = "btnSalir";
            this.btnSalir.Size = new System.Drawing.Size(253, 110);
            this.btnSalir.TabIndex = 12;
            this.btnSalir.Text = "SALIR";
            this.btnSalir.UseVisualStyleBackColor = true;
            this.btnSalir.Click += new System.EventHandler(this.btnSalir_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.ClientSize = new System.Drawing.Size(470, 519);
            this.Controls.Add(this.btnSalir);
            this.Controls.Add(this.btnIni);
            this.Controls.Add(this.txtExpresion);
            this.Controls.Add(this.lblRes);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label lblRes;
        private System.Windows.Forms.TextBox txtExpresion;
        private System.Windows.Forms.Button btnIni;
        private System.Windows.Forms.Button btnSalir;
    }
}

