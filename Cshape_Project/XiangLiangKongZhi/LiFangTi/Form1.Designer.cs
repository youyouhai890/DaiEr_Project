namespace LiFangTi
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose( bool disposing )
        {
            if ( disposing && ( components != null ) )
            {
                components.Dispose();
            }
            base.Dispose( disposing );
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.cbY = new System.Windows.Forms.CheckBox();
            this.cbZ = new System.Windows.Forms.CheckBox();
            this.cbX = new System.Windows.Forms.CheckBox();
            this.trackBar2 = new System.Windows.Forms.TrackBar();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.isLine = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).BeginInit();
            this.SuspendLayout();
            // 
            // cbY
            // 
            this.cbY.AutoSize = true;
            this.cbY.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.cbY.Location = new System.Drawing.Point(543, 60);
            this.cbY.Name = "cbY";
            this.cbY.Size = new System.Drawing.Size(42, 16);
            this.cbY.TabIndex = 7;
            this.cbY.Text = "cbY";
            this.cbY.UseVisualStyleBackColor = true;
            // 
            // cbZ
            // 
            this.cbZ.AutoSize = true;
            this.cbZ.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.cbZ.Location = new System.Drawing.Point(543, 93);
            this.cbZ.Name = "cbZ";
            this.cbZ.Size = new System.Drawing.Size(42, 16);
            this.cbZ.TabIndex = 6;
            this.cbZ.Text = "cbZ";
            this.cbZ.UseVisualStyleBackColor = true;
            // 
            // cbX
            // 
            this.cbX.AutoSize = true;
            this.cbX.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.cbX.Location = new System.Drawing.Point(543, 31);
            this.cbX.Name = "cbX";
            this.cbX.Size = new System.Drawing.Size(42, 16);
            this.cbX.TabIndex = 5;
            this.cbX.Text = "cbX";
            this.cbX.UseVisualStyleBackColor = true;
            this.cbX.CheckedChanged += new System.EventHandler(this.cbX_CheckedChanged);
            // 
            // trackBar2
            // 
            this.trackBar2.Location = new System.Drawing.Point(68, 31);
            this.trackBar2.Maximum = 1000;
            this.trackBar2.Minimum = 250;
            this.trackBar2.Name = "trackBar2";
            this.trackBar2.Size = new System.Drawing.Size(104, 45);
            this.trackBar2.TabIndex = 8;
            this.trackBar2.Value = 250;
            this.trackBar2.Scroll += new System.EventHandler(this.trackBar2_Scroll_1);
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick_1);
            // 
            // isLine
            // 
            this.isLine.AutoSize = true;
            this.isLine.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.isLine.Location = new System.Drawing.Point(441, 31);
            this.isLine.Name = "isLine";
            this.isLine.Size = new System.Drawing.Size(60, 16);
            this.isLine.TabIndex = 9;
            this.isLine.Text = "isLine";
            this.isLine.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(637, 469);
            this.Controls.Add(this.isLine);
            this.Controls.Add(this.trackBar2);
            this.Controls.Add(this.cbY);
            this.Controls.Add(this.cbZ);
            this.Controls.Add(this.cbX);
            this.DoubleBuffered = true;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint_1);
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox cbY;
        private System.Windows.Forms.CheckBox cbZ;
        private System.Windows.Forms.CheckBox cbX;
        private System.Windows.Forms.TrackBar trackBar2;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.CheckBox isLine;
    }
}

