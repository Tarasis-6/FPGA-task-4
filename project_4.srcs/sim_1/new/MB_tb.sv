`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/04/2026 07:08:26 PM
// Design Name: 
// Module Name: MB_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module MB_tb();

    reg clk_125_MHz = 0;

    reg reset_rtl_0 = 0;   
    reg  [5:0] btn_sw_tri_i;
    wire [3:0] LED_tri_o;


    design_2_wrapper dut (
        .clk_125_MHz        (clk_125_MHz),   
        .reset_rtl_0        (reset_rtl_0),
        .btn_sw_tri_i       (btn_sw_tri_i),
        .LED_tri_o          (LED_tri_o)
    );


    always #4 clk_125_MHz = ~clk_125_MHz;

    initial begin
        reset_rtl_0 = 0;
        btn_sw_tri_i = 6'b0;
        #400;
        reset_rtl_0 = 1;

        #600;

        $display("[%0t] Тест 1: btn=0011", $time);
        btn_sw_tri_i = 6'h04;
        #150000;
        btn_sw_tri_i = 6'h0;
        #150000;
        btn_sw_tri_i = 6'h08;
        #150000;
        btn_sw_tri_i = 6'h0;
        #10000;
        btn_sw_tri_i = 6'h08;
        #150000;
        btn_sw_tri_i = 6'h0;
        #10000;
        btn_sw_tri_i = 6'h08;
        #150000;
        btn_sw_tri_i = 6'h0;
        #10000;
        btn_sw_tri_i = 6'h80;
        #15000;
        btn_sw_tri_i = 6'h0;
        #1000;
        $finish;
    end



endmodule
